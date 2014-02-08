// properties.cpp : implementation file
//

#include "stdafx.h"
#include "law.h"
#include "properties.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cproperties dialog


Cproperties::Cproperties(CWnd* pParent /*=NULL*/)
	: CDialog(Cproperties::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cproperties)
	m_ino = 0;
	m_nam = _T("");
	m_perm = _T("");
	m_siz1 = 0.0f;
	m_siz2 = _T("");
	m_type = _T("");
	//}}AFX_DATA_INIT
}


void Cproperties::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cproperties)
	DDX_Text(pDX, inodeno, m_ino);
	DDX_Text(pDX, proname, m_nam);
	DDV_MaxChars(pDX, m_nam, 255);
	DDX_Text(pDX, permissions, m_perm);
	DDX_Text(pDX, prosize1, m_siz1);
	DDX_Text(pDX, prosize2, m_siz2);
	DDX_Text(pDX, protype, m_type);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cproperties, CDialog)
	//{{AFX_MSG_MAP(Cproperties)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cproperties message handlers

int Cproperties::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}

BOOL Cproperties::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CFont fon;
	int err=fon.CreatePointFont(120,"Monotype Corsiva");
	OnSetFont(&fon);
	// TODO: Add extra initialization here
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
