#pragma once
#include "afxwin.h"


// CRegisterNewUserDlg ��ȭ �����Դϴ�.

class CRegisterNewUserDlg : public CDialog
{
	DECLARE_DYNAMIC(CRegisterNewUserDlg)

public:
	CRegisterNewUserDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRegisterNewUserDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_REGISTER_NEW_USER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

	bool m_bCheckID;

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	CEdit m_editID;
	CEdit m_editPasswords;
	CEdit m_editPasswords2;
};
