#pragma once


// CAddMylistDlg ��ȭ �����Դϴ�.

class CAddMylistDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddMylistDlg)

public:
	CAddMylistDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAddMylistDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ADDMYLISTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strId;
	afx_msg void OnBnClickedOk();
};
