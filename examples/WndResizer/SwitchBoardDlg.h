#pragma once
#include "Example08Dlg.h"
#include "Example11Dlg.h"

// CSwitchBoardDlg dialog

class CSwitchBoardDlg : public CDialog
{
  DECLARE_DYNAMIC(CSwitchBoardDlg)

public:
  CSwitchBoardDlg(CWnd* pParent = NULL);   // standard constructor
  virtual ~CSwitchBoardDlg();

// Dialog Data
  enum { IDD = IDD_SWITCH_BOARD_DLG };

protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

  DECLARE_MESSAGE_MAP()
private:
  afx_msg void OnDestroy();
private:
  CExample11Dlg * m_pModelessSheet;
  CExample08APpg * m_pPageA;
  CExample08BPpg * m_pPageB;
  void DestroyPropertyModelessSheet();
private:
  afx_msg void OnBnClickedButtonEx1();
  afx_msg void OnBnClickedButtonEx2();
  afx_msg void OnBnClickedButtonEx3();
  afx_msg void OnBnClickedButtonEx4();
  afx_msg void OnBnClickedButtonEx5();
  afx_msg void OnBnClickedButtonEx6();
  afx_msg void OnBnClickedButtonEx7();
  afx_msg void OnBnClickedButtonEx8();
  afx_msg void OnBnClickedButtonTest();
  afx_msg void OnBnClickedButtonEx9();
  afx_msg void OnBnClickedButtonEx10();
  afx_msg void OnBnClickedButtonEx11();
};
