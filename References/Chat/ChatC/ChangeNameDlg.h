#pragma once


// CChangeNameDlg 대화 상자입니다.

class CChangeNameDlg : public CDialog
{
	DECLARE_DYNAMIC(CChangeNameDlg)

public:
	CChangeNameDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CChangeNameDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CHANGENAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
};
