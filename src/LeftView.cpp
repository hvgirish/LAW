// LeftView.cpp : implementation of the CLeftView class
//

#include "stdafx.h"
#include "law.h"

#include "lawDoc.h"
#include "LeftView.h"
#include "lawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CTreeView)

BEGIN_MESSAGE_MAP(CLeftView, CTreeView)
	//{{AFX_MSG_MAP(CLeftView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, OnItemexpanded)
	ON_NOTIFY_REFLECT(NM_CLICK, OnClick)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftView construction/destruction

CLeftView::CLeftView()
{
	// TODO: add construction code here

}

CLeftView::~CLeftView()
{
}

BOOL CLeftView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style|= (TVS_HASBUTTONS|TVS_HASLINES|TVS_LINESATROOT);
	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLeftView drawing

void CLeftView::OnDraw(CDC* pDC)
{
	CLawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}
HTREEITEM *hand=new HTREEITEM[10000];
int k=0,usrInode=0;
HTREEITEM Root,delh;

void CLeftView::OnInitialUpdate()
{
	extern CLawApp theApp;
	
	
	CTreeCtrl & ctr = GetTreeCtrl();
	HICON h[2];
	h[0] = AfxGetApp()->LoadIcon(IDI_ICON3);
	m_tree.Create(20,20,ILC_COLOR16,1,1);
	h[1] = AfxGetApp()->LoadIcon(IDI_ICON4);
	m_tree.Add(h[0]);
	m_tree.Add(h[1]);
	ctr.SetImageList(&m_tree,TVSIL_NORMAL);
	
	TVINSERTSTRUCTA roo;
	int mas = (TVIF_CHILDREN | TVIF_IMAGE | TVIF_SELECTEDIMAGE | 
	 TVIF_TEXT | TVIF_STATE); 
	roo.hInsertAfter = TVI_SORT;
	roo.hParent = TVI_ROOT;
	roo.item.cChildren = 1;
	roo.item.mask = mas;
	roo.item.iImage = 1;
	roo.item.iSelectedImage = 0;
	roo.item.pszText = "/";
	roo.item.state = TVIS_EXPANDEDONCE;
	int smas = (TVIS_OVERLAYMASK | TVIS_STATEIMAGEMASK  
 | TVIS_USERMASK  );
	roo.item.stateMask = smas;
	Root = ctr.InsertItem(&roo);
	ctr.SetItemData(Root,2);
	
	CTreeView::OnInitialUpdate();
}


inode *Inode;
extern CLawApp theApp;
int flag =0; 

int CLeftView::ReadInodeData(dir *d1[],DWORD InodeNumber){
	
	extern CLawApp theApp;
	char *ReadInode=new char[theApp.BlockSize];
	BOOL bResult;
	DWORD size,NewOffset;
	int DirCnt=0;

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
		return Dirnum;
}



DWORD *BlockNumbers;


int CLeftView::Direct(dir *d1[],DWORD Blocks2Read){		
		int var0=0,var1=0,var2=0;
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
			int err = GetLastError();
			bResult = ReadFile(theApp.dsk,
				(LPVOID)ReadDir,
				theApp.BlockSize,
				&size,
				NULL);
			err = GetLastError();	
			int Offset=0;
			for(int k=0 ; k < (theApp.BlockSize/12) ; k=k++ ){
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
			}
			Blocks2Read--;
		}while(Blocks2Read !=0);
		int k=DirNum;
		delete []ReadDir;
		flag=0;
		return k;
}

int CLeftView::FirstIndirect(dir *d1[],DWORD Blocks2Read ){
	
	BlockNumbers=new DWORD[theApp.BlockSize/sizeof(DWORD)];
	FillBlocks(Inode->i_block[12]);
	flag = 1;
	
	Blocks2Read-=13;
	
	int DirCnt=Direct(d1,Blocks2Read);
	flag=0;
	delete []BlockNumbers;
	return DirCnt;
}

void CLeftView::FillBlocks(DWORD BlockNumber){
	
	DWORD NewOffset,size;
	extern CLawApp theApp;
	BOOL bResult;
	theApp.num.quad = theApp.QuadOff + (BlockNumber * theApp.BlockSize);
	NewOffset=SetFilePointer(theApp.dsk,theApp.num.low,&(theApp.num.high),FILE_BEGIN);
	
	bResult = ReadFile(theApp.dsk,
		(LPVOID)BlockNumbers,
		(theApp.BlockSize/sizeof(DWORD)),
		&size,
		NULL);
}

int CLeftView::Next2Dirs(dir *d[],int DirNum,char ReadBuf[],int Offset){

	char *temp1=new char[sizeof(dir)];
	int cnt=0;
	int l=Offset; //d[DirNum]=new dir;
	int nlen=ReadBuf[l+6];
	int reclen=ReadBuf[l+5];
	int k=0;
	reclen<<=8;
	reclen|=ReadBuf[l+4];

	if(nlen <= 0 && reclen <= 8)
		return 0;// terrible observation
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
			
		if((d[DirNum]->inode <= 0) && (d[DirNum]->file_type <= 0) 
			&& (d[DirNum]->name_len <= 0 ) && (d[DirNum]->rec_len <= 0  ) 
			&& (strcmp(d[DirNum]->name,"0")) )
			return 0;

		if(d[DirNum]->file_type != 2)
			cnt--;
		else
			cnt++;
		return cnt;
		
}

/////////////////////////////////////////////////////////////////////////////
// CLeftView diagnostics

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CLawDoc* CLeftView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLawDoc)));
	return (CLawDoc*)m_pDocument;
}





#endif //_DEBUG
DWORD Ino=2;
int dirflag=0;
/////////////////////////////////////////////////////////////////////////////
// CLeftView message handlers

void CLeftView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CTreeCtrl & ctr = GetTreeCtrl();
	HTREEITEM handle = NULL;
	dir *d[500],*d1[500];int i=2;
	TVINSERTSTRUCTA tritem;
	tritem.hInsertAfter = TVI_SORT;
	handle = ctr.GetSelectedItem();
	int smas = (TVIS_OVERLAYMASK | TVIS_STATEIMAGEMASK  
 | TVIS_USERMASK  );

	if(handle!=NULL){
		
	Ino = ctr.GetItemData(handle);
		
	int mas = (TVIF_CHILDREN | TVIF_IMAGE | TVIF_SELECTEDIMAGE | 
TVIF_STATE | TVIF_TEXT ); 
	
	tritem.hParent = handle;
	tritem.item.iSelectedImage = 0;
	tritem.item.iImage = 1;
	tritem.item.cChildren = 0;
	tritem.item.mask = mas;
	int DirCnt = ReadInodeData(d,Ino);
	if(DirCnt > 2)
	{	
		for(int j=0;j<DirCnt;j++)
		{
			HTREEITEM h=ctr.GetChildItem(handle);
			if(h==NULL) break;
			ctr.DeleteItem(h);
		}
		while(i < DirCnt)
		{
			int DirCnt = ReadInodeData(d1,d[i]->inode);
			if(DirCnt > 2 )
				tritem.item.cChildren = 1;
			else
				tritem.item.cChildren = 0;
			tritem.item.pszText = d[i]->name;
			tritem.item.state = TVIS_EXPANDEDONCE;
			tritem.item.stateMask = smas;
			hand[k++] = ctr.InsertItem(&tritem);
			ctr.SetItemData(hand[k-1],d[i]->inode);
			i++;
		}
			
	}
	
	CLawDoc *c=GetDocument();
	c->UpdateAllViews(this);
	}
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	*pResult = 0;
}

void CLeftView::OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult) 
{
	
	// TODO: Add your control notification handler code here
	
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	*pResult = 0;
}



void CLeftView::OnClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}


void CLeftView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	HTREEITEM h = NULL;
	CTreeCtrl & ctr = GetTreeCtrl();
	TVHITTESTINFO phit;
	phit.pt = point;
	phit.flags = TVHT_ONITEMBUTTON;
	phit.hItem = NULL;
	h = ctr.HitTest(&phit);
	
	if(h!=NULL){
		ctr.Select(h,TVGN_CARET);	
	}
	
	CTreeView::OnLButtonDown(nFlags, point);
}
