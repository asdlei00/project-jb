// ChatSDlg.h : ��� ����
//
#pragma once

#include "afxwin.h"
#include "DataSocket.h"
#include "Mgr.h"
#include "resource.h"

class CServerSocket;
class CDataSocket;
class CMgr;
class CData;

// CChatSDlg ��ȭ ����
class CChatSDlg : public CDialog
{
// ����
public:
	CChatSDlg(CWnd* pParent = NULL);	// ǥ�� ������

	// ��ȭ ���� ������
	enum { IDD  = IDD_CHATS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

	DECLARE_MESSAGE_MAP()

private:
	CString m_strList2;
	CString m_strList1;
	CListBox m_ctrlList1;
	CListCtrl m_ctrlList2;

	CMgr list;
	CObList m_ListDataSocks;

public:
	void OnAccept();
	void OnReceive(CDataSocket * pDataSocket);
	void OnDisconnectClient(CDataSocket * pDataSocket);

	CServerSocket m_ServerSocket;
	CDataSocket * m_pDataSocket;

	void ShowMember(int i, CString id, CString name);

	void Receive_LOGIN(CDataSocket * pDataSocket, CData * pData);
	void Receive_MESSAGE(CDataSocket * pDataSocket, CData * pData);
	void Receive_MOD_NAME(CDataSocket * pDataSocket, CString id, CString name);
	void Receive_ADD_MYLIST(CDataSocket * pDataSocket, CString id, CString destid);
	void Receive_DEL_MYLIST(CDataSocket * pDataSocket, CData * pData);

	void Send_LOGIN_RESULT(CDataSocket * pDataSocket, CData * pData);
	void Send_MESSAGE(CString id, CString name, CString message, CString destid);
	void Send_MESSAGE_FAIL(CDataSocket * pDataSocket);
	void Send_LOGIN_MEMBER_INIT(CDataSocket * pDataSocket);
	void Send_LOGIN_MEMBER(CDataSocket * pDataSocket, CString id, CString name);
	void Send_LOGOUT_MEMBER(CString id);
	void Send_LOGOUT(CString id);

	void Receive_JOIN_MEMBER(CDataSocket * pDataSocket, CString id, CString pass, CString name);
};

