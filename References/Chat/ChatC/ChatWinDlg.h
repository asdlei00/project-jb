#pragma once
#include "afxwin.h"


// CChatWinDlg ��ȭ �����Դϴ�.

class CChatWinDlg : public CDialog
{
	DECLARE_DYNAMIC(CChatWinDlg)

public:
	CChatWinDlg(CChatCDlg* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CChatWinDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CHATWIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void PostNcDestroy();

	DECLARE_MESSAGE_MAP()
public:
	int m_nSel;

	CEdit m_ctrlEdit2;
	CEdit m_ctrlEdit;
	CEdit m_ctrlData;

	CString m_strEdit2;
	CString m_strEdit;
	CString m_strData;
	CString m_strId;
	CString m_strName;
	CString m_strDestid;
	
	afx_msg void OnClose();
	afx_msg void OnSend();
	void ViewMessage(CString name, CString message);
};
