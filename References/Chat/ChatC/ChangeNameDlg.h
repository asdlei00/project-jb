#pragma once


// CChangeNameDlg ��ȭ �����Դϴ�.

class CChangeNameDlg : public CDialog
{
	DECLARE_DYNAMIC(CChangeNameDlg)

public:
	CChangeNameDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CChangeNameDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CHANGENAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
};
