// ServerSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatC.h"
#include "ServerSocket.h"


// CServerSocket

CServerSocket::CServerSocket()
: m_pWnd(NULL)
{
}

CServerSocket::~CServerSocket()
{
}


// CServerSocket ��� �Լ��Դϴ�.

void CServerSocket::OnAccept(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
//	m_pWnd->SendMessage(UM_ACCEPT);

	CSocket::OnAccept(nErrorCode);
}

void CServerSocket::Init(CWnd* pWnd, int nPortNum)
{
	m_pWnd=pWnd;
	Create(nPortNum);
	Listen();
}
