#if !defined(AFX_PARTINFO_H__587D7C01_5CED_46CD_84F0_1E073D3E14B1__INCLUDED_)
#define AFX_PARTINFO_H__587D7C01_5CED_46CD_84F0_1E073D3E14B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PartInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPartInfo dialog

class CPartInfo : public CDialog
{
// Construction
public:
	CPartInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPartInfo)
	enum { IDD = IDD_PARTINFO };
	long	m_part;
	long	m_start;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPartInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPartInfo)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARTINFO_H__587D7C01_5CED_46CD_84F0_1E073D3E14B1__INCLUDED_)
