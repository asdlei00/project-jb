
// ClientDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "ClientSock.h"

#define SERVER_PORT		5555

// CClientDlg ��ȭ ����
class CClientDlg : public CDialog
{
// �����Դϴ�.
public:
	CClientDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	~CClientDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

private:
	CClientSock m_Client;
	bool m_bConnected;

	LRESULT OnClientConnected(WPARAM wParam, LPARAM lParam);
	LRESULT OnClientReceive(WPARAM wParam, LPARAM lParam);

// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CEdit m_editIP;
	CListBox m_listboxText;
	CEdit m_editText;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnUpdateEdit2();
	CEdit m_editNickName;
	afx_msg void OnBnClickedButton2();
};
