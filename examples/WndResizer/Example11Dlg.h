#pragma once

// CExample11Dlg

class CExample11Dlg : public CPropertySheet
{
	DECLARE_DYNAMIC(CExample11Dlg)

public:
	CExample11Dlg(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CExample11Dlg(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CExample11Dlg();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
private:
	CWndResizer m_resizer;
};
