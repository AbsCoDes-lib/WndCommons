// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WndResizerApp.h"
#include "TestDlg.h"


// CTestDlg dialog

IMPLEMENT_DYNAMIC(CTestDlg, CDialog)

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CTestDlg::IDD, pParent)
{

}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
    ON_WM_PAINT()
END_MESSAGE_MAP()


// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog()
{
  CDialog::OnInitDialog();


  BOOL bOk = FALSE;

  bOk = m_resizer.Hook(this);
  ASSERT( bOk);

  m_resizer.SetAutoHandlePaint(FALSE);

  m_resizer.SetShowResizeGrip(TRUE);

  bOk = m_resizer.InvokeOnResized();
  ASSERT( bOk);

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}


void CTestDlg::OnPaint()
{
	TRACE("CTestDlg::OnPaint()\n");
    CPaintDC dc(this); // device context for painting

    CRect rect(10, 20, 60, 60);
    CBrush brush(RGB(0,0,0));
    dc.FillRect(rect, &brush);
	m_resizer.Draw(&dc);

}
