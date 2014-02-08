// lawDoc.cpp : implementation of the CLawDoc class
//

#include "stdafx.h"
#include "law.h"

#include "lawDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLawDoc

IMPLEMENT_DYNCREATE(CLawDoc, CDocument)

BEGIN_MESSAGE_MAP(CLawDoc, CDocument)
	//{{AFX_MSG_MAP(CLawDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLawDoc construction/destruction

CLawDoc::CLawDoc()
{
	// TODO: add one-time construction code here
	//SetTitle("LAW");
	
}

CLawDoc::~CLawDoc()
{
}

BOOL CLawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLawDoc serialization

void CLawDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLawDoc diagnostics

#ifdef _DEBUG
void CLawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLawDoc commands
