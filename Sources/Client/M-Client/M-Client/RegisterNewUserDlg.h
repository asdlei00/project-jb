#pragma once


// CRegisterNewUserDlg 대화 상자입니다.

class CRegisterNewUserDlg : public CDialog
{
	DECLARE_DYNAMIC(CRegisterNewUserDlg)

public:
	CRegisterNewUserDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CRegisterNewUserDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_REGISTER_NEW_USER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
