// Example11Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "WndResizerApp.h"
#include "Example11Dlg.h"

// This is an example to demonstrate how to resize modeless property sheet
// For more information on modeless property sheet: http://msdn.microsoft.com/en-US/library/139z22ye(v=vs.100).aspx

// CExample11Dlg

IMPLEMENT_DYNAMIC(CExample11Dlg, CPropertySheet)

CExample11Dlg::CExample11Dlg(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
  :CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CExample11Dlg::CExample11Dlg(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
  :CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CExample11Dlg::~CExample11Dlg()
{
}

BEGIN_MESSAGE_MAP(CExample11Dlg, CPropertySheet)
  ON_WM_SIZE()
END_MESSAGE_MAP()

// CExample11Dlg message handlers

BOOL CExample11Dlg::OnInitDialog()
{
  BOOL bResult = CPropertySheet::OnInitDialog();

  BOOL bOk = FALSE;
  bOk = m_resizer.Hook(this);

  ASSERT( bOk);

  CRect rc;
  GetClientRect(&rc);
  rc.DeflateRect(10, 10, 10, 20); // bottom is 20 because we need space to draw the resize grip
  GetTabControl()->MoveWindow(&rc);

  bOk = m_resizer.SetAnchor(GetTabControl()->GetDlgCtrlID(), ANCHOR_ALL);
  ASSERT( bOk);

  m_resizer.SetShowResizeGrip( TRUE  );

  // this is a HACK
  // try commenting out this, you will notice
  // that initially the property pages don't show up properly. then
  // resizing the dialog using mouse fixes the problem.
  if (GetActivePage() != NULL)
  {
    SetActivePage(GetActivePage() );
  }
  // end of HACK
  return bResult;
}

void CExample11Dlg::OnSize(UINT nType, int cx, int cy)
{
  CPropertySheet::OnSize(nType, cx, cy);

  // following part is needed due to
  // the fact that CTabCtrl does not automatically resize the
  // CPropertyPages when it is being resized
  if (GetActivePage() != NULL)
  {
    SetActivePage(GetActivePage() );
  }
}