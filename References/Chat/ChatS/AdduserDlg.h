#pragma once
#include "afxwin.h"


// CAdduserDlg ��ȭ �����Դϴ�.

class CAdduserDlg : public CDialog
{
	DECLARE_DYNAMIC(CAdduserDlg)

public:
	CAdduserDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAdduserDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ADDUSERDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

protected:
	virtual void OnOK();

public:
	CString m_strId;
	CString m_strPass;
	CString m_strName;
};

