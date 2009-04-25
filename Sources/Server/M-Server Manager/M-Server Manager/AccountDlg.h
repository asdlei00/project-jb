#pragma once
#include "afxwin.h"


// CAccountDlg ��ȭ �����Դϴ�.

class CAccountDlg : public CDialogSkin
{
	DECLARE_DYNAMIC(CAccountDlg)

public:
	CAccountDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAccountDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_ACCOUNT };

	HICON m_hIcon;

	bool m_bActived;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton1();
	CEdit m_editUserID;
	CEdit m_editUserPasswords;
	CEdit m_editAccountID;
	CEdit m_editPasswords;
	CEdit m_editPasswords2;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit7();
};
