#pragma once


// CJoinDlg ��ȭ �����Դϴ�.

class CJoinDlg : public CDialog
{
	DECLARE_DYNAMIC(CJoinDlg)

public:
	CJoinDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CJoinDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_JOINDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString pass;
	CString id;
	CString name;
	CString serverip;
};
