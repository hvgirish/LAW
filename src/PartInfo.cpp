// PartInfo.cpp : implementation file
//

#include "stdafx.h"
#include "law.h"
#include "PartInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPartInfo dialog


CPartInfo::CPartInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CPartInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPartInfo)
	m_part = 0;
	m_start = 0;
	//}}AFX_DATA_INIT
}


void CPartInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPartInfo)
	DDX_Text(pDX, IDC_PART_SIZE, m_part);
	DDX_Text(pDX, IDC_START_OFF, m_start);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPartInfo, CDialog)
	//{{AFX_MSG_MAP(CPartInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
extern DRIVE_LAYOUT_INFORMATION *buffer;
/////////////////////////////////////////////////////////////////////////////
// CPartInfo message handlers

BOOL CPartInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	extern int i;
	m_part=buffer->PartitionEntry[i]->PartitionLength;
	m_start=buffer->PartitionEntry[i]->StartingOffset;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
