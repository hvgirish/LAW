// LeftView.h : interface of the CLeftView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEFTVIEW_H__ED38C168_B92C_4F3E_9825_773C1E0CAF8E__INCLUDED_)
#define AFX_LEFTVIEW_H__ED38C168_B92C_4F3E_9825_773C1E0CAF8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "law.h"
//#include "lawView.h"
class CLawDoc;
//class CLawView;
class CLeftView : public CTreeView
{
protected: // create from serialization only
	CLeftView();
	DECLARE_DYNCREATE(CLeftView)

// Attributes
public:
	CLawDoc* GetDocument();
	int Next2Dirs(dir *d[],int DirNum,char ReadBuf[],int Offset);	
	int ReadInodeData(dir *d[],DWORD InodeNumber);
	int FirstIndirect(dir *d1[],DWORD Blocks2Read);
	int Direct(dir *d1[],DWORD Blocks2Read);
	void FillBlocks(DWORD BlockNumber);
	void Recursive(dir *d[],HTREEITEM Parent,int DirCount);
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLeftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
CImageList m_tree;
// Generated message map functions
protected:
	//{{AFX_MSG(CLeftView)
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LeftView.cpp
inline CLawDoc* CLeftView::GetDocument()
   { return (CLawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTVIEW_H__ED38C168_B92C_4F3E_9825_773C1E0CAF8E__INCLUDED_)
