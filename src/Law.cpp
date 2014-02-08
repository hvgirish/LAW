// law.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "law.h"
#include "lawView.h"
#include "MainFrm.h"
#include "lawDoc.h"
#include "LeftView.h"
#include "winbase.h"
#include "winioctl.h"
#include "math.h"
#include "process.h"
#include "Splashm.h"
#include <dos.h>
#include <direct.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLawApp

BEGIN_MESSAGE_MAP(CLawApp, CWinApp)
	//{{AFX_MSG_MAP(CLawApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLawApp construction

CLawApp::CLawApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CLawApp object

CLawApp theApp;
DRIVE_LAYOUT_INFORMATION *buffer;
int i;
/////////////////////////////////////////////////////////////////////////////
// CLawApp initialization

BOOL CLawApp::InitInstance()
{
	// CG: The following block was added by the Splash Screen component.
\
	{
\
		CCommandLineInfo cmdInfo;
\
		ParseCommandLine(cmdInfo);
\

\
		CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);
\
	}
	/*CLeged ha;
	//ha.DoModal();
	ha.Create(IDD_LEGEND);
	ha.ShowWindow(SW_SHOW);
	//CWnd *windo = ha.SetFocus();
	//Sleep(9000);
	//ha.OnKillFocus(windo);
	//ha.DestroyWindow();
	//m_pMainWnd = this;*/
	struct super{
	_U32 s_inodes_count;					/* Inodes count */
    _U32 s_blocks_count;					/* Blocks count */
    _U32 s_r_blocks_count;					/* Reserved blocks count */
    _U32 s_free_blocks_count;				/* Free blocks count */
    _U32 s_free_inodes_count;				/* Free inodes count */
    _U32 s_first_data_block;				/* First Data Block */
    _U32 s_log_block_size;					/* Block size */
    _S32 s_log_frag_size;					/* Fragment size */
    _U32 s_blocks_per_group;				/* # Blocks per group */
    _U32 s_frags_per_group;					/* # Fragments per group */
    _U32 s_inodes_per_group;				/* # Inodes per group */
    _U32 s_mtime;						/* Mount time */
    _U32 s_wtime;        					/* Write time */
    _U16 s_mnt_count;						/* Mount count */
    _S16 s_max_mnt_count;					/* Maximal mount count */
    _U16 s_magic;						/* Magic signature */
    _U16 s_state;						/* File system state */
    _U16 s_errors;						/* Behaviour when detecting error     _U16 s_minor_rev_level;	6*2 = 12				/* Minor revision level */
    _U32 s_lastcheck;						/* time of last check */
    _U32 s_checkinterval;					/* max. time between checks */
    _U32 s_creator_os;						/* OS */
    _U32 s_rev_level;						/* Revision level */
    _U16 s_def_resuid;						/* Default uid for reserved block*/
    _U16 s_def_resgid;						/* Default gid for reserved block */

    /* These fields are for EXT2_DYNAMIC_REV superblocks only. */
    _U32 s_first_ino; 		/* First non-reserved inode */
    _U16 s_inode_size; 		/* size of inode structure */
    _U16 s_block_group_nr; 	/* block group # of this superblock */
    _U32 s_feature_compat; 	/* compatible feature set */
    _U32 s_feature_incompat; 	/* incompatible feature set */
    _U32 s_feature_ro_compat; 	/* readonly-compatible feature set */
    _U32 s_pad[230];	/* Padding to the end of the block */
		};


		struct super *s;
		unsigned int found=0; 
		char *ReadSuper=new char[4096],*ReadGD;
		DWORD bufsize,size;
		
		bufsize=sizeof(DRIVE_LAYOUT_INFORMATION)+32*sizeof(PARTITION_INFORMATION);
		buffer=(DRIVE_LAYOUT_INFORMATION *)malloc(bufsize);
		dsk=CreateFile("\\\\.\\PHYSICALDRIVE0",
					GENERIC_READ,
					FILE_SHARE_READ,
					NULL,
					OPEN_EXISTING,
				    0,
					NULL);
		
		BOOL val=DeviceIoControl(dsk,
						IOCTL_DISK_GET_DRIVE_LAYOUT,
						NULL,
						0,
						buffer,
						bufsize,
						&size,
						(LPOVERLAPPED)NULL);
		
		
		for(i=0;i<buffer->PartitionCount;i++){
				if(buffer->PartitionEntry[i].RecognizedPartition==TRUE && buffer->PartitionEntry[i].PartitionType==0x83){
					found = 1;	
					//AfxMessageBox("LINUX Found in hda !!!" );
					break;
				}
		}
		

		if(!found)
		{
			dsk=CreateFile("\\\\.\\PHYSICALDRIVE1",
					GENERIC_READ,
					FILE_SHARE_READ,
					NULL,
					OPEN_EXISTING,
				    0,
					NULL);
		
		BOOL val=DeviceIoControl(dsk,
						IOCTL_DISK_GET_DRIVE_LAYOUT,
						NULL,
						0,
						buffer,
						bufsize,
						&size,
						(LPOVERLAPPED)NULL);
		
		
		for(i=0;i<buffer->PartitionCount;i++){
				if(buffer->PartitionEntry[i].RecognizedPartition==TRUE && buffer->PartitionEntry[i].PartitionType==0x83){
					found = 2;	
					//AfxMessageBox("LINUX Found in hdb !!!" );
					break;
				}
		}
		}//end of if(!found)
		
		if( found == 0 ) {
			AfxMessageBox( "LINUX Not Found On Any Of Your Hard Disks !!!" );
			exit(0);
		}
		DWORD NewOffset=0; 
		QuadOff=buffer->PartitionEntry[i].StartingOffset.QuadPart;
		
		num.quad=QuadOff+1024;

		NewOffset=SetFilePointer(dsk,num.low,&(num.high),FILE_BEGIN);

		//reading super block
		BOOL bResult = ReadFile( 
		 dsk,               
		 (LPVOID)ReadSuper,   
		 1024,				//since its superblock,1024 bytes are read
		 &size,				// pointer to number of bytes read
		 (LPOVERLAPPED)NULL // pointer to structure for data
		);             //workin readfile
				
		//Remember after a read operation, pointer is set to the 
		//position after the last read 
		s=(struct super *)ReadSuper;
		 BlockSize = (1024 << s->s_log_block_size);
		ReadGD=new char[BlockSize];
		num.quad=QuadOff+BlockSize;
		BlocksPerGroup = s->s_blocks_per_group;
		InodesPerGroup = s->s_inodes_per_group;
		BlocksCount = s->s_blocks_count;
		 
		NewOffset=SetFilePointer(dsk,num.low,&(num.high),FILE_BEGIN);
		
		//reading group descriptor table
		bResult = ReadFile(
		 dsk,               // handle of file to read
		 (LPVOID)ReadGD,   // pointer to buffer that receives data
		 BlockSize,	// number of bytes to read
		 &size,				// pointer to number of bytes read
		 (LPOVERLAPPED)NULL // pointer to structure for data
		);             //workin readfile
		

		
		//void GetGds(group *GDesc[],int GDNum,char ReadGD[],int Offset);
		int GOffset=0,GdCount = BlocksCount/BlocksPerGroup;
		if(BlocksCount % BlocksPerGroup != 0)
			GdCount++;
		for(unsigned int g=0; g < GdCount;g++){
			theApp.GetGds(GDesc,g,ReadGD,GOffset);
			GOffset+=32;
		}
		
		delete []ReadSuper;
		delete []ReadGD;
 

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CLawDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CLeftView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

void CLawApp::GetGds(group *GDesc[],int GDNum,char ReadGD[],int Offset){
		
	char *temp1=new char[sizeof(group)];
	int k=0;
	
	for(int j=Offset;j<(Offset+sizeof(group));j++,k++){
		temp1[k]=ReadGD[j];
	}
	GDesc[GDNum]=(group *)temp1;
}





/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual BOOL OnInitDialog();
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CLawApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CLawApp message handlers


BOOL CLawApp::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following lines were added by the Splash Screen component.
	if (CSplashWnd::PreTranslateAppMessage(pMsg))
		return TRUE;

	return CWinApp::PreTranslateMessage(pMsg);
}

BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();	// CG:  This was added by System Info Component.

	// CG: Following block was added by System Info Component.
	{
		CString strFreeDiskSpace;
		CString strFreeMemory;
		CString strFmt;

		// Fill available memory
		MEMORYSTATUS MemStat;
		MemStat.dwLength = sizeof(MEMORYSTATUS);
		GlobalMemoryStatus(&MemStat);
		strFmt.LoadString(CG_IDS_PHYSICAL_MEM);
		strFreeMemory.Format(strFmt, MemStat.dwTotalPhys / 1024L);

		//TODO: Add a static control to your About Box to receive the memory
		//      information.  Initialize the control with code like this:
		 //SetDlgItemText(IDC_PHYSICAL_MEM, strFreeMemory);

		// Fill disk free information
		struct _diskfree_t diskfree;
		int nDrive = _getdrive(); // use current default drive
		if (_getdiskfree(nDrive, &diskfree) == 0)
		{
			strFmt.LoadString(CG_IDS_DISK_SPACE);
			strFreeDiskSpace.Format(strFmt,
				(DWORD)diskfree.avail_clusters *
				(DWORD)diskfree.sectors_per_cluster *
				(DWORD)diskfree.bytes_per_sector / (DWORD)1024L,
				nDrive-1 + _T('A'));
		}
		else
			strFreeDiskSpace.LoadString(CG_IDS_DISK_SPACE_UNAVAIL);

		//TODO: Add a static control to your About Box to receive the memory
		//      information.  Initialize the control with code like this:
		//SetDlgItemText(IDC_DISK_SPACE, strFreeDiskSpace);
	}

	return TRUE;	// CG:  This was added by System Info Component.

}
