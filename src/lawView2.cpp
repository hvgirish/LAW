// lawView.cpp : implementation of the CLawView class
//

#include "stdafx.h"
#include "law.h"
#include "properties.h"
#include "lawDoc.h"
#include "lawView.h"
#include "math.h"
#include "io.h"
#include "fcntl.h"
#include "errno.h"
#include "sys/stat.h"
#include "Progress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLawView

IMPLEMENT_DYNCREATE(CLawView, CListView)

BEGIN_MESSAGE_MAP(CLawView, CListView)
	//{{AFX_MSG_MAP(CLawView)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_A_PROPERTIES, OnProperties)
	ON_COMMAND(ID_EXPORTFILE, OnExportfile)
	ON_COMMAND(ID_A_REFRESH, OnARefresh)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLawView construction/destruction

CLawView::CLawView()
{
	// TODO: add construction code here
	m_ptMsg = CPoint(0,0);
}

CLawView::~CLawView()
{
}

BOOL CLawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLawView drawing

void CLawView::OnDraw(CDC* pDC)
{
	/*CLawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);*/
	pDC->TextOut(m_ptMsg.x,m_ptMsg.y,m_szMsg);
	/*CListCtrl& refCtrl = GetListCtrl();
	refCtrl.InsertItem(0, "Item!");*/
	// TODO: add draw code for native data here
}

void CLawView::OnInitialUpdate()
{
	

	extern CLawApp theApp;
	//extern int cnt;
	int i=0;
	HICON h[4];
	h[0]=AfxGetApp()->LoadIcon(IDI_ICON5);
	h[1]=AfxGetApp()->LoadIcon(IDI_ICON7);
	h[2]=AfxGetApp()->LoadIcon(IDI_ICON8);
	h[3]=AfxGetApp()->LoadIcon(IDI_ICON6);
	m_listlar.Create(32,32,1,3,1 );
	m_listsma.Create(16,16,1,3,1 );
	
	for(int j=0;j<4;j++){
		m_listlar.Add(h[j]);
		m_listsma.Add(h[j]);
	}
	
	CListCtrl & ctr = GetListCtrl();
	
	ctr.SetImageList(&m_listlar,LVSIL_NORMAL);
	ctr.SetImageList(&m_listsma,LVSIL_SMALL);
	

	CListView::OnInitialUpdate();
	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
}

/////////////////////////////////////////////////////////////////////////////
// CLawView diagnostics

#ifdef _DEBUG
void CLawView::AssertValid() const
{
	CListView::AssertValid();
}

void CLawView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CLawDoc* CLawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLawDoc)));
	return (CLawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLawView message handlers
void CLawView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: add code to react to the user changing the view style of your window
}


  BOOL CLawView::SetViewType(DWORD dwViewType)
    {
		dwViewType |= LVS_SORTASCENDING;
	  return(ModifyStyle(LVS_TYPEMASK,dwViewType & LVS_TYPEMASK));
    }

    DWORD CLawView::GetViewType()
    {
	return(GetStyle() & LVS_TYPEMASK);
    }

DWORD BlockNosPerBlock=0;
extern inode *Inode;
extern CLawApp theApp;
extern int flag; 
int DirNum=0;
//flag = 0;
int CLawView::ReadIData(DWORD InodeNumber,dir *d1[]){
	
	//ally's working algo
	/*extern CLawApp theApp;
	char *ReadInode=new char[theApp.BlockSize];
	BOOL bResult;
	DWORD size,NewOffset;
	int DirCnt=0;

	unsigned long BlockGNumber = ((InodeNumber - 1) / theApp.InodesPerGroup);
		//BlockGNumber--;
	unsigned long InodeIndex = ((InodeNumber - 1) % theApp.InodesPerGroup);
		//InodeIndex--;
	
		theApp.num.quad = theApp.QuadOff + (theApp.GDesc[BlockGNumber]->bg_inode_table * theApp.BlockSize);
				
		char* temp6=new char[sizeof(inode)]; 
		int InBNumber = (InodeIndex) / (theApp.BlockSize / (sizeof(inode)));
		int InIndex = (InodeIndex ) % (theApp.BlockSize / (sizeof(inode)));
			
		theApp.num.quad += (InBNumber * theApp.BlockSize);
		NewOffset = SetFilePointer(theApp.dsk,theApp.num.low,&(theApp.num.high),FILE_BEGIN);

		bResult = ReadFile(
				theApp.dsk,               // handle of file to read
				(LPVOID)ReadInode,   // pointer to buffer that receives data
				theApp.BlockSize,	// number of bytes to read
				&size,				// pointer to number of bytes read
				(LPOVERLAPPED)NULL // pointer to structure for data
				);             //workin readfile

		DWORD e = ((InIndex)*(sizeof(inode))),t=0;
		DWORD z = e + sizeof(inode);
		for( ; e < z ; e++,t++){
			temp6[t]=ReadInode[e];
		}
			
		Inode=(inode *)temp6;

		DWORD Blocks2Read = ((Inode->i_blocks * 512) / theApp.BlockSize);
								
		int Dirnum;
		
		DWORD DirsPerBlock = (theApp.BlockSize / 32);

#define FirstLimit DirsPerBlock + 12
#define DoubleLimit (DirsPerBlock * DirsPerBlock) + FirstLimit
#define TripleLimit (DirsPerBlock * DirsPerBlock *DirsPerBlock ) + DoubleLimit

		if(Blocks2Read <= 12)
				Dirnum=Direct(d1,Blocks2Read);
		else
			if(Blocks2Read > 12 && Blocks2Read <= FirstLimit ){
				flag = 3;
				Direct(d1,12);
				flag=1;
				Dirnum=FirstIndirect(d1,Blocks2Read);
				flag=0;
			}
		delete []ReadInode;
		return Dirnum;*/
	char *ReadInode=new char[theApp.BlockSize];BOOL bResult;
	DWORD size,NewOffset;int DirCnt=0;

	unsigned long BlockGNumber = ((InodeNumber - 1) / theApp.InodesPerGroup);
	unsigned long InodeIndex = ((InodeNumber - 1) % theApp.InodesPerGroup);

	theApp.num.quad = theApp.QuadOff + (theApp.GDesc[BlockGNumber]->bg_inode_table * theApp.BlockSize);
				
	char* temp6=new char[sizeof(inode)]; 
	int InBNumber = (InodeIndex) / (theApp.BlockSize / (sizeof(inode)));
	int InIndex = (InodeIndex ) % (theApp.BlockSize / (sizeof(inode)));
	
	theApp.num.quad += (InBNumber * theApp.BlockSize);
	NewOffset = SetFilePointer(theApp.dsk,theApp.num.low,&(theApp.num.high),FILE_BEGIN);
	
	bResult = ReadFile(
			theApp.dsk,               // handle of file to read
			(LPVOID)ReadInode,   // pointer to buffer that receives data
			theApp.BlockSize,	// number of bytes to read
			&size,				// pointer to number of bytes read
			(LPOVERLAPPED)NULL // pointer to structure for data
			);             //workin readfile
		
	DWORD e = ((InIndex)*(sizeof(inode))),t=0;
	DWORD z = e + sizeof(inode);
	for( ; e < z ; e++,t++){
		temp6[t]=ReadInode[e];
	}
	
	Inode=(inode *)temp6;
	//printf("Inode Of the File Successfully Read\n");
	//_getch();
	if(!d1){
		LPCTSTR lpDirectoryName=".\\";                 
		ULARGE_INTEGER lpFreeBytesAvailableToCaller,lpTotalNumberOfBytes;
		ULARGE_INTEGER lpTotalNumberOfFreeBytes; 
		BOOL dandan = GetDiskFreeSpaceEx(
					lpDirectoryName, // pointer to the directory name
					&lpFreeBytesAvailableToCaller, // receives the number of bytes on
                                             // disk available to the caller
					&lpTotalNumberOfBytes,    // receives the number of bytes on disk
					&lpTotalNumberOfFreeBytes // receives the free bytes on disk
					);
		if(Inode->i_size > lpTotalNumberOfFreeBytes.QuadPart){
			AfxMessageBox("No Enuf Disk Space to Perform Write Operation !!!");
			//_getch();
			return 0;
		}
	}//if (!d1)
			
	DWORD Blocks2Read = ((Inode->i_blocks * 512) / theApp.BlockSize);
	if(!Blocks2Read||Inode->i_size ==0)
		return -1;
	
	//void FirstIndirect(DWORD Blocks2Read);
	//void DoubleIndirect(DWORD Blocks2Read);
	
	//int Direct(DWORD Blocks2Read);
	BlockNosPerBlock = (theApp.BlockSize / sizeof(DWORD));
	flag = 0;
#define FirstLimit BlockNosPerBlock + 13
#define DoubleLimit (BlockNosPerBlock * BlockNosPerBlock) + FirstLimit
	if(Blocks2Read <= 12)
		Direct(Blocks2Read,d1);
	else{
		Direct(12,d1);
		if(Blocks2Read > 12 && Blocks2Read <= FirstLimit ){
			Blocks2Read-=13;
			flag = 1;
			FirstIndirect(Blocks2Read,d1);
		}	
		else
			if(Blocks2Read > FirstLimit && Blocks2Read <= DoubleLimit){
				flag = 2;
				Blocks2Read-=13;
				DoubleIndirect(Blocks2Read);
				flag=0;	
			}
	}		
		
	if(d1){
		DirCnt=DirNum;
		DirNum=0;
		/*int j=0;
		for(j=0;j<DirNum;j++){
			if(d1[j]->file_type == 2)//{
				//printf("%d : %s\n",j+1,d1[j]->name);
				DirCnt++;
			/*}
			else
				//printf("File %d : %s\n",j+1,d1[j]->name);
		}*/
	}
	//fflush(stdout);
	delete []ReadInode;
	return DirCnt;
}



DWORD *BlockNumbersFI;
DWORD *BlockNumbersDI;
int BlockNum=0;
int fptr;

void CLawView::Direct(DWORD Blocks2Read,dir *d1[]){		
	//all's working direct
	/*int var0=0,var1=0,var2=0;
		DWORD NewOffset,size;BOOL bResult;
		extern CLawApp theApp;static int DirNum=0;
		//Reading the dataBlock Dir contents
		if(flag == 0 || flag == 3)
			DirNum=0;
		int ocnt = 0;
		int cnt=0;

		char *ReadDir=new char[theApp.BlockSize];
		do{
			if(flag == 0 || flag ==3)
				theApp.num.quad = theApp.QuadOff + (Inode->i_block[var0++] * theApp.BlockSize );
			else
				if(flag == 1)
					theApp.num.quad = theApp.QuadOff + (BlockNumbers[var1++] * theApp.BlockSize);

			NewOffset = SetFilePointer(theApp.dsk,theApp.num.low,&(theApp.num.high),FILE_BEGIN);

			bResult = ReadFile(theApp.dsk,
				(LPVOID)ReadDir,
				theApp.BlockSize,
				&size,
				NULL);
			int Offset=0;
			for(int k=0 ; k < (theApp.BlockSize/12) ; k=k++ ){
				if(k == 0)
					Offset=0;
				else
					if(Offset >= theApp.BlockSize)
						break;
				
				ocnt=0;
				cnt=Next2Dirs(d1,DirNum,ReadDir,Offset);
				
				if(ocnt == cnt)
					break;//to avoid looping till 1024 entries...

				Offset+=d1[DirNum]->rec_len;
				
				if(cnt!=-1)
					DirNum+=cnt;
			}
			Blocks2Read--;
		}while(Blocks2Read !=0);
		
		delete []ReadDir;
		return DirNum;*/
		int var0=0,var1=0;
		extern CLawApp theApp;
		DWORD NewOffset,size;BOOL bResult;
		//Reading the dataBlock Dir contents
		int ocnt = 0;
		if(flag==0 && d1/*|| flag ==3*/)
			DirNum=0;
		//int Next2Dirs(dir *d[],int DirNum,char ReadBuf[],int Offset);
		char *ReadDir=new char[theApp.BlockSize];int cnt=0;
		do{
			if(flag == 0)
				theApp.num.quad = theApp.QuadOff + (Inode->i_block[var0++] * theApp.BlockSize );
			else
				if(flag == 1 || flag == 2 || flag == 4)
					theApp.num.quad = theApp.QuadOff + (BlockNumbersFI[var1++] * theApp.BlockSize);

			NewOffset = SetFilePointer(theApp.dsk,theApp.num.low,&(theApp.num.high),FILE_BEGIN);
			
				bResult = ReadFile(theApp.dsk,
					(LPVOID)ReadDir,
					theApp.BlockSize,
					&size,
					NULL);
			if(d1){
				int Offset=0;
				for(int k=0 ; k<1024 ; k++ ){
					if(k == 0)
						Offset=0;
					else
						if(Offset >= theApp.BlockSize)
							break;
					
					ocnt=0;
					cnt=Next2Dirs(d1,DirNum,ReadDir,Offset);
					
					Offset+=d1[DirNum]->rec_len;
				
					if(cnt!=-1)
						DirNum+=cnt;
					if(ocnt == cnt)
						break;//to avoid looping till 1024 entries...
				}//end for 
			}
			else{
				int err=0;
				if(theApp.BlockSize >= Inode->i_size)
					err=_write(fptr,ReadDir,Inode->i_size);
				else{
					err=_write(fptr,ReadDir,theApp.BlockSize);
					Inode->i_size-=theApp.BlockSize;
				}
				if(err == -1)
					if(errno == EBADF)
						AfxMessageBox("Specified file already exists!!");
					else
						if(errno == ENOSPC)
							AfxMessageBox("No Enuf Disk Space to Perform Operation!!");
				// add No more code
			}
			Blocks2Read--;
		}
		while(Blocks2Read !=0);
		delete []ReadDir;
		flag=0;
		//return DirNum;
}

void CLawView::FirstIndirect(DWORD Blocks2Read ,dir *d1[]){
	//ally's working code
	/*BlockNumbers=new DWORD[theApp.BlockSize/sizeof(DWORD)];
	FillBlocks(Inode->i_block[12]);
	flag = 1;
	
	Blocks2Read-=13;
	
	int DirCnt=Direct(d1,Blocks2Read);
	flag=0;
	delete []BlockNumbers;
	return DirCnt;*/
	BlockNumbersFI=new DWORD[theApp.BlockSize/sizeof(DWORD)];
	//void FillBlocks(DWORD BlockNumber);
	if(flag == 1 || flag == 2)
		FillBlocks(Inode->i_block[12]);
	else
		if(flag == 4)
			FillBlocks(BlockNumbersDI[BlockNum++]);
	if(d1){
		Direct(Blocks2Read,d1);
		flag =0;
		delete []BlockNumbersFI;
	}
	else{
		Direct(Blocks2Read);
		delete []BlockNumbersFI;
	}
}

void CLawView::FillBlocks(DWORD BlockNumber){
	//ally's working version
	/*DWORD NewOffset,size;
	extern CLawApp theApp;
	BOOL bResult;
	theApp.num.quad = theApp.QuadOff + (BlockNumber * theApp.BlockSize);
	NewOffset=SetFilePointer(theApp.dsk,theApp.num.low,&(theApp.num.high),FILE_BEGIN);
	
	bResult = ReadFile(theApp.dsk,
		(LPVOID)BlockNumbers,
		(theApp.BlockSize),
		&size,
		NULL);*/
	DWORD NewOffset,size;
	BOOL bResult;
	theApp.num.quad = theApp.QuadOff + (BlockNumber * theApp.BlockSize);
	NewOffset=SetFilePointer(theApp.dsk,theApp.num.low,&(theApp.num.high),FILE_BEGIN);
	if(flag == 2 || flag == 1 || flag ==4)
		bResult = ReadFile(theApp.dsk,
			(LPVOID)BlockNumbersFI,
			theApp.BlockSize,
			&size,
			NULL);
	else
		if( flag == 3){
			bResult = ReadFile(theApp.dsk,
				(LPVOID)BlockNumbersDI,
				theApp.BlockSize,
				&size,
				NULL);
			flag = 4;
		}
}

void CLawView::DoubleIndirect(DWORD Blocks2Read){
	
	//void FillBlocks(DWORD BlockNumber);
	
	BlockNumbersDI=new DWORD[theApp.BlockSize/sizeof(DWORD)];
	
	FirstIndirect(BlockNosPerBlock);

	Blocks2Read-=(BlockNosPerBlock+2);
	flag = 3;
	
	FillBlocks(Inode->i_block[13]);

	DWORD Blocks2R=(Blocks2Read/BlockNosPerBlock);
	
	if((Blocks2Read % BlockNosPerBlock) != 0)
		Blocks2R++;
	
	for(int i=0;i<Blocks2R;i++){
		if(Blocks2Read < BlockNosPerBlock)
			FirstIndirect(Blocks2Read);
		else{
			FirstIndirect(BlockNosPerBlock);
			//continue;
			Blocks2Read--;
			Blocks2Read-=BlockNosPerBlock;
		}
	}
	BlockNum=0;
	delete []BlockNumbersDI;
	flag =0;
	//return 0;
}

int CLawView::Next2Dirs(dir *d[],int DirNum,char ReadBuf[],int Offset){
	
	char *temp1=new char[sizeof(dir)];

	int cnt=0;
	int l=Offset; 
	int nlen=ReadBuf[l+6];
	int reclen=ReadBuf[l+5];
	int k=0;
	reclen<<=8;
	reclen|=ReadBuf[l+4];

	if(nlen <= 0 && (reclen <= 8 || reclen == theApp.BlockSize))
		return 0;// terribly fuking observation
	else 
		if((nlen <=0 || nlen > 255) && (reclen > 8 && reclen <264 )){//reclen is valid nlen invalid
			for(int j=0;j<reclen;j++)
				temp1[j]=ReadBuf[l++];
			temp1[--j]=NULL;
		}
	else
		if((nlen > 0 && nlen <= 255) && (reclen <= 8 || reclen > (theApp.BlockSize-12)) ){// nlen is valid reclen invalid
			for(int j=0;j<8;j++)
				temp1[j]=ReadBuf[l++];
			while(j < (8+nlen))
				temp1[j++]=ReadBuf[l++];
			temp1[j]=NULL;
		}
	else
		if((nlen > 0 && nlen <=255) && (reclen > 8 && (reclen < 264 || reclen < (theApp.BlockSize-12)))){
			k=0;
			if((reclen > 8) && (reclen < 264 ))
				for(int j=Offset;j<(Offset+reclen);j++)
					temp1[k++]=ReadBuf[j];
			else
				for(int j=0;j<263;j++)
					temp1[j]=ReadBuf[l++];
			temp1[8+nlen]=NULL;
		}
			
		d[DirNum]=(dir *)temp1;
		if(d[DirNum]->inode == 0)
			return -1; // deleted entry.. aha observation
	 	if((d[DirNum]->inode <= 0) && (d[DirNum]->file_type <= 0) 
			&& (d[DirNum]->name_len <= 0 ) && (d[DirNum]->rec_len <= 0  ) 
			&& (strcmp(d[DirNum]->name,"0")) )
			return 0;

		if(d[DirNum]->file_type == 2)
			cnt--;
		else
			cnt++;
		return cnt;// return value used to trap the old cnt==cnt in main
}
int objno;

void CLawView::FillListView(DWORD Ino){
		
	dir *d[8000];
	int DirCnt = objno = ReadIData(Ino,d);
	CListCtrl & ctr = GetListCtrl();
	ctr.DeleteAllItems();
	int imgIndex=2;
	for(int i=0;i<DirCnt;i++){
		if(d[i]->file_type==1)
			imgIndex=1;
		else if(d[i]->file_type==0)
			imgIndex=2;
		else if(d[i]->file_type==3||d[i]->file_type==4)
			imgIndex=0;
		else 
			if(d[i]->file_type == 7)
				imgIndex=3;
		ctr.InsertItem(i,d[i]->name,imgIndex);
		ctr.SetItemData(i,d[i]->inode);
	}
}


void CLawView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	extern DWORD Ino;
	//extern int updflag;
	/*if(!updflag){
	FillListView(2);
	updflag=1;
	}
	else*/

	FillListView(Ino);
	
}
	



void CLawView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu FileMenu;
	m_ptMsg = point;
	ScreenToClient(&m_ptMsg);

	FileMenu.LoadMenu(ID_POPUP);
	CMenu *pPopup = FileMenu.GetSubMenu(0);
	pPopup->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,
		point.x,
		point.y,
		this);

		
}
inode *getinode  ;
/*
*/
void CLawView::OnProperties() 
{
	// TODO: Add your command handler code here
	int first=0,index=-1;
	POSITION pos;
	//inode *getinode /*= new inode*/;
	DWORD lisino=0;
	//inode getinode;
	CString mnam;
	CListCtrl & ctr = GetListCtrl();
	if(!first)
	{
		pos = ctr.GetFirstSelectedItemPosition();
		first=1;
	}
	
		index = ctr.GetNextItem(-1,LVNI_SELECTED);
	//	getitem
	if(index!=-1)
	{
		lisino = ctr.GetItemData(index);
		GetInodeData(&getinode,lisino);

		Cproperties prop;	
		prop.m_nam = ctr.GetItemText(index,0);
		prop.m_ino = lisino;
		prop.m_siz1 = getinode->i_size;
		prop.m_siz2 = "bytes";
		if(getinode->i_size > pow(2,10) && getinode->i_size < pow(2,20) )
		{
			prop.m_siz1 = getinode->i_size / pow(2,10);
			prop.m_siz2 = "Kb";
		}
		else
			if(getinode->i_size > pow(2,20) && getinode->i_size < pow(2,30) )
			{
				prop.m_siz1 = getinode->i_size / pow(2,20);
				prop.m_siz2 = "Mb";
			}
		else if(getinode->i_size > pow(2,30) )
		{
			prop.m_siz1 = getinode->i_size / pow(2,30);
			prop.m_siz2 = "Gb";
		}
		CString typ;
		char perm1[4]="---";
		char perm2[4]="---";
		char perm3[4]="---";
		int imode = getinode->i_mode;
		int tmask = imode & 0xF000;
		int pmask1 = imode & 0x01C0;
		int pmask2 = imode & 0x0038;
		int pmask3 = imode & 0x0007;
		if(tmask == 0xC000)
			typ = "Socket file";
		else if(tmask == 0xA000)
			typ = "Symbolic Link file";
		else if(tmask == 0x8000)
			typ = "Regular File";
		else if(tmask == 0x6000)
			typ = "Block Device file";
		else if(tmask == 0x2000)
			typ = "Character Device file" ;
		else if(tmask == 0x1000)
			typ = "FIFO file";
		prop.m_type = typ;
	
		
		if(pmask1 == 384)
			strcpy(perm1,"rw-");
		else if(pmask1 == 64)
			strcpy(perm1,"--x");
		else if(pmask1 == 128)
			strcpy(perm1,"-w-");
		else if(pmask1 == 256)
			strcpy(perm1,"r--");
		else if(pmask1 == 192)
			strcpy(perm1 , "-wx");
		else if(pmask1 == 320)
			strcpy(perm1 , "r-x");
		else if(pmask1 == 448)
			strcpy(perm1 , "rwx");
		
		if(pmask2 == 8)
			strcpy(perm2 , "--x");
		else if(pmask2 == 16)
			strcpy(perm2 , "-w-");
		else if(pmask2 == 32)
			strcpy(perm2 , "r--");
		else if(pmask2 == 48)
			strcpy(perm2 , "rw-");
		else if(pmask2 == 40)
			strcpy(perm2 , "r-x");
		else if(pmask2 == 24)
			strcpy(perm2 , "-wx");
		else if(pmask2 == 56)
			strcpy(perm2 , "rwx");

		if(pmask3 == 1)
			strcpy(perm3 , "--x");
		else if(pmask3 == 2)
			strcpy(perm3 , "-w-");
		else if(pmask3 == 4)
			strcpy(perm3 , "r--");
		else if(pmask3 == 3)
			strcpy(perm3 , "-wx");
		else if(pmask3 == 5)
			strcpy(perm3 , "r-x");
		else if(pmask3 == 6)
			strcpy(perm3 , "rw-");
		else if(pmask3 == 7)
			strcpy(perm3 , "rwx");
		
		prop.m_perm = (LPCTSTR) perm1;
		prop.m_perm += (LPCTSTR) perm2;
		prop.m_perm += (LPCTSTR) perm3;
		prop.DoModal();
	}
	else
	{
		AfxMessageBox("No file selected to perform requested operation");
	}
	
}


void CLawView::OnExportfile() 
{
	// TODO: Add your command handler code here
	
	
	CListCtrl &ctr = GetListCtrl();
	int index=-1;
	index = ctr.GetNextItem(-1,LVNI_SELECTED);
	if(index!=-1)
	{
	DWORD InodeNumber = ctr.GetItemData(index);
	CFileDialog sev(FALSE,NULL,ctr.GetItemText(index,0),OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"All Files(*.*)|*.*||");
	//CFileDialog sev(FALSE);
	int sevret=sev.DoModal();
	if(sevret==IDOK){
		_unlink((LPCTSTR)sev.m_ofn.lpstrFile);
	fptr = _open( (LPCTSTR)sev.m_ofn.lpstrFile, _O_RDWR | _O_CREAT | 
_O_EXCL | _O_BINARY,_S_IWRITE);
	int ret=ReadIData(InodeNumber);
	_close(fptr);
	if(ret==-1){
		MessageBox("File size is zero..... Not Saved","Warning!!");
		_close(fptr);
		_unlink((LPCTSTR)sev.m_ofn.lpstrFile);		
		return;
	}
	else{
		AfxMessageBox("File succesfully saved");
	
	}
		//AfxMessageBox("Successfull Write!!");
	
	
	
	}	
	}//end of if
	else
	{
		AfxMessageBox("No file selected to perform requested operation");
	}
	
}

void CLawView::GetInodeData(inode **getinode,DWORD lisino)
{
	extern CLawApp theApp;
	char *ReadInode=new char[theApp.BlockSize];
	BOOL bResult;
	DWORD size,NewOffset;
	int DirCnt=0;

	unsigned long BlockGNumber = ((lisino - 1) / theApp.InodesPerGroup);
		//BlockGNumber--;
	unsigned long InodeIndex = ((lisino - 1) % theApp.InodesPerGroup);
		//InodeIndex--;
	
		theApp.num.quad = theApp.QuadOff + (theApp.GDesc[BlockGNumber]->bg_inode_table * theApp.BlockSize);
				
		char* temp6=new char[sizeof(inode)]; 
		int InBNumber = (InodeIndex) / (theApp.BlockSize / (sizeof(inode)));
		int InIndex = (InodeIndex ) % (theApp.BlockSize / (sizeof(inode)));
			
		theApp.num.quad += (InBNumber * theApp.BlockSize);
		NewOffset = SetFilePointer(theApp.dsk,theApp.num.low,&(theApp.num.high),FILE_BEGIN);

		bResult = ReadFile(
				theApp.dsk,               // handle of file to read
				(LPVOID)ReadInode,   // pointer to buffer that receives data
				theApp.BlockSize,	// number of bytes to read
				&size,				// pointer to number of bytes read
				(LPOVERLAPPED)NULL // pointer to structure for data
				);             //workin readfile

		DWORD e = ((InIndex)*(sizeof(inode))),t=0;
		DWORD z = e + sizeof(inode);
		for( ; e < z ; e++,t++){
			temp6[t]=ReadInode[e];
		}
		//temp6[t]=NULL;
		//memcpy(getinode,temp6,strlen(temp6));	
		*getinode=(inode *)temp6;
}


void CLawView::OnARefresh() 
{
	// TODO: Add your command handler code here
	CListCtrl &ctr = GetListCtrl();
	int index=-1;
	char a[50] = "notepad.exe ";
	index = ctr.GetNextItem(-1,LVNI_SELECTED);
	if(index!=-1)
	{
	_unlink((LPCTSTR)ctr.GetItemText(index,0));		
	DWORD InodeNumber = ctr.GetItemData(index);
	fptr = _open( (LPCTSTR)ctr.GetItemText(index,0), _O_RDWR | _O_CREAT | 
_O_EXCL | _O_BINARY,_S_IWRITE);
	int ret=ReadIData(InodeNumber);
	_close(fptr);
	if(ret==-1){
		MessageBox("File size is zero!!","Warning!!");
		_close(fptr);
		_unlink((LPCTSTR)ctr.GetItemText(index,0));		
		return;
	}
	
	strcat(a,((LPCTSTR)ctr.GetItemText(index,0)));
	WinExec(a,SW_MAXIMIZE);
	
	}
	else
	{
		AfxMessageBox("No file selected to perform requested operation");
	}
	_unlink((LPCTSTR)ctr.GetItemText(index,0));		
}

void CLawView::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CListCtrl &ctr = GetListCtrl();
	int index=-1;
	index = ctr.GetNextItem(-1,LVNI_SELECTED);
	if(index!=-1)
	{
	DWORD InodeNumber = ctr.GetItemData(index);
	remove((LPCTSTR)ctr.GetItemText(index,0));
	char temp[60]="explorer.exe ";
	fptr = _open( (LPCTSTR)ctr.GetItemText(index,0), _O_RDWR | _O_CREAT | 
	_O_EXCL | _O_BINARY,_S_IWRITE);
	int ret=ReadIData(InodeNumber);
	_close(fptr);
	if(ret!=-1){
		strcat(temp,(LPCTSTR)ctr.GetItemText(index,0));
		WinExec(temp,SW_MAXIMIZE); 
		//	remove((LPCTSTR)ctr.GetItemText(index,0));
	}
	else{
		AfxMessageBox("Can't open empty file");
		remove((LPCTSTR)ctr.GetItemText(index,0));
		}
	}
	
	//remove((LPCTSTR)ctr.GetItemText(index,0));
	*pResult = 0;
}

