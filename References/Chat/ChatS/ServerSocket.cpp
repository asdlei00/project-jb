// ServerSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatS.h"
#include "ServerSocket.h"
#include "ChatSDlg.h"

// CServerSocket

CServerSocket::CServerSocket()
{
}
CServerSocket::CServerSocket(CChatSDlg * dlg)
{
	m_pDlg = dlg;
}
CServerSocket::~CServerSocket()
{
}


// CServerSocket ��� �Լ��Դϴ�.

void CServerSocket::OnAccept(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	m_pDlg->OnAccept();

	CSocket::OnAccept(nErrorCode);
}

void CServerSocket::Init(CChatSDlg *dlg, int nPortNum)
{
	m_pDlg = dlg;
	Create(nPortNum); // �������ϻ���
	Listen(); // ������
}
