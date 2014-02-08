#if !defined(AFX_PROPERTIES_H__1386707E_12B3_474A_A11E_3A3B97E462D7__INCLUDED_)
#define AFX_PROPERTIES_H__1386707E_12B3_474A_A11E_3A3B97E462D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// properties.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cproperties dialog

class Cproperties : public CDialog
{
// Construction
public:
	Cproperties(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cproperties)
	enum { IDD = IDD_PROPERTIES };
	DWORD	m_ino;
	CString	m_nam;
	CString	m_perm;
	float	m_siz1;
	CString	m_siz2;
	CString	m_type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cproperties)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cproperties)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTIES_H__1386707E_12B3_474A_A11E_3A3B97E462D7__INCLUDED_)
