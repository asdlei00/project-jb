#pragma once


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
};
