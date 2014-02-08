// lawDoc.h : interface of the CLawDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAWDOC_H__AC45A360_A975_4F3F_9A4F_2E87AD5B50B1__INCLUDED_)
#define AFX_LAWDOC_H__AC45A360_A975_4F3F_9A4F_2E87AD5B50B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLawDoc : public CDocument
{
protected: // create from serialization only
	CLawDoc();
	DECLARE_DYNCREATE(CLawDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLawDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLawDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAWDOC_H__AC45A360_A975_4F3F_9A4F_2E87AD5B50B1__INCLUDED_)
