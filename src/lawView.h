// lawView.h : interface of the CLawView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAWVIEW_H__5F0D28B2_A31F_438B_B0B0_0F28F48832F4__INCLUDED_)
#define AFX_LAWVIEW_H__5F0D28B2_A31F_438B_B0B0_0F28F48832F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "LeftView.h"
class CLawDoc;

class CLawView : public CListView
{
protected: // create from serialization only
	CLawView();
	DECLARE_DYNCREATE(CLawView)
	//void FillListView(DWORD Ino);
// Attributes
public:
	CLawDoc* GetDocument();
	BOOL CLawView::SetViewType(DWORD dwViewType);
	DWORD CLawView::GetViewType();
// Operations
public:
	
	/*int ReadIData(dir *d[],DWORD InodeNumber);
	int FirstIndirect(dir *d1[],DWORD Blocks2Read);
	int Direct(dir *d1[],DWORD Blocks2Read);*/
	int ReadIData(DWORD InodeNumber,dir *d[]=NULL);
	void FirstIndirect(DWORD Blocks2Read,dir *d[]=NULL);
	void Direct(DWORD Blocks2Read,dir *d[]=NULL);
	void FillBlocks(DWORD BlockNumber);
	void Recursive(dir *d[],HTREEITEM Parent,int DirCount);
	void DoubleIndirect(DWORD Blocks2Read);
	int Next2Dirs(dir *d[],int DirNum,char ReadBuf[],int Offset);
	void FillListView(DWORD Ino);
	void GetInodeData(inode **,DWORD );
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLawView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
CImageList m_listlar,m_listsma;
CPoint m_ptMsg;
CString m_szMsg;

// Generated message map functions
protected:
	//{{AFX_MSG(CLawView)
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnProperties();
	afx_msg void OnExportfile();
	afx_msg void OnARefresh();
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in lawView.cpp
inline CLawDoc* CLawView::GetDocument()
   { return (CLawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAWVIEW_H__5F0D28B2_A31F_438B_B0B0_0F28F48832F4__INCLUDED_)
