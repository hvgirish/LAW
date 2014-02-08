#if !defined(AFX_LEGED_H__668E0123_2502_4641_B56D_9ACB34910E2A__INCLUDED_)
#define AFX_LEGED_H__668E0123_2502_4641_B56D_9ACB34910E2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Leged.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeged dialog

class CLeged : public CDialog
{
// Construction
public:
	CLeged(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLeged)
	enum { IDD = IDD_LEGEND };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeged)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLeged)
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEGED_H__668E0123_2502_4641_B56D_9ACB34910E2A__INCLUDED_)
