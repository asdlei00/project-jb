#pragma once

#include "resource.h"

// CUserDlg ��ȭ �����Դϴ�.

class CUserDlg : public CDialog
{
	DECLARE_DYNAMIC(CUserDlg)

public:
	CUserDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CUserDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_USER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
