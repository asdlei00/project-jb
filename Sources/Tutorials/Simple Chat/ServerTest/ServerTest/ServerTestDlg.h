// ServerTestDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "ServerSock.h"
#include "ClientSock.h"

#define SERVER_PORT		5555

typedef struct _CLIENTKEY
{
	char szKey[256];
}CLIENTKEY, *PCLIENTKEY;

typedef struct _CLIENTINFO
{
	CLIENTKEY Key;
	CClientSock* pSock;
}CLIENTINFO, *PCLIENTINFO;

/*typedef map<char*, CLIENTINFO>				CINFO_MAP;
typedef map<char*, CLIENTINFO>::iterator	CINFO_MAP_IT;
typedef map<char*, CLIENTINFO>::value_type	CINFO_MAP_VALUE;*/

typedef map<int, CLIENTINFO>				CINFO_MAP;
typedef map<int, CLIENTINFO>::iterator		CINFO_MAP_IT;
typedef map<int, CLIENTINFO>::value_type	CINFO_MAP_VALUE;

// CServerTestDlg ��ȭ ����
class CServerTestDlg : public CDialog
{
// ����
public:
	CServerTestDlg(CWnd* pParent = NULL);	// ǥ�� ������
	~CServerTestDlg();

// ��ȭ ���� ������
	enum { IDD = IDD_SERVERTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����

private:
	CServerSock	m_Server;
	CINFO_MAP m_mapClient;

	void AddClient(PCLIENTINFO Client);
	void DelClient(int nIndex);
	void ClearClient();

	LRESULT OnClientAccept(WPARAM wParam, LPARAM lParam);
	LRESULT OnClientReceive(WPARAM wParam, LPARAM lParam);
	LRESULT OnClientClose(WPARAM wParam, LPARAM lParam);

	void SendAllClient(WPARAM wParam, const char* pszText);

// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listboxText;
};
