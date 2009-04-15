#pragma once
#include "afxcmn.h"
#include "resource.h"
#include "CustomControl.h"

// CLogDlg ��ȭ �����Դϴ�.

class CLogDlg : public CDialog
{
	DECLARE_DYNAMIC(CLogDlg)

public:
	CLogDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CLogDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_LOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

protected:
	bool m_bColor;

	void Init();
	void AddList(int nIndex, char* pszTime, char* pszType, char* pszContext);
	void DelList(int nIndex);
	void ClearList();

public:
	CColorListCtrl m_listctrlLog;
	virtual BOOL OnInitDialog();
};
