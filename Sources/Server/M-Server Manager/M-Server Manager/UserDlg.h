#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "afxwin.h"

// CUserDlg ��ȭ �����Դϴ�.

class CUserDlg : public CDialog
{
	DECLARE_DYNAMIC(CUserDlg)

public:
	CUserDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CUserDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_USER };

public:
	void Init();

	void AddList(char* pszID, char* pszNick, char* pszState);
	void DelList(char* pszID);
	void UpdateList(char* pszID, char* pszNick, char* pszState);
	void ClearList();

	void SetUserCount(int nIndex);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CColorListCtrl m_listctrlUser;
	virtual BOOL OnInitDialog();
	CEdit m_editUserCount;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
