#include "stdafx.h"
#include "WinSockMgr.h"

CWinSockMgr::CWinSockMgr()
{
	
}	

CWinSockMgr::~CWinSockMgr()
{

}

void CWinSockMgr::InitServerSock()
{
	g_sToolMgr.GetLog()->AddLog(LOG_TYPE_CONN, "���� ���� �ʱ�ȭ...");

	m_ServerSock.Close();
	m_ServerSock.Create(MAIN_SERVER_PORT);
	m_ServerSock.Listen();

	g_sToolMgr.GetLog()->AddLog(LOG_TYPE_CONN, "���� ���� ����...");

	m_bServerRun = true;
}

void CWinSockMgr::CloseServerSock()
{
	m_ServerSock.Close();

	g_sToolMgr.GetLog()->AddLog(LOG_TYPE_CONN, "���� ���� ����...");

	m_bServerRun = false;
}

bool CWinSockMgr::ConnectToServerMgr()
{
	if(m_bServerMgrConnect) 
	{
		g_sToolMgr.GetLog()->AddLog(LOG_TYPE_CONN, "�̹� ���� �Ŵ����� ���� �Ǿ� �����Ƿ� ���� �õ��� �����...");

		return false;
	}

	CloseServerMgrSock();

	if(m_ServerMgrSock.Connect(m_szServerMgrIP, MAIN_SERVER_PORT) != SOCKET_ERROR)
	{
		g_sToolMgr.GetLog()->AddLog(LOG_TYPE_CONN, "���� �Ŵ����� ���� ����...");
		m_bServerMgrConnect = true;
	}
	else g_sToolMgr.GetLog()->AddLog(LOG_TYPE_CONN, "���� �Ŵ����� ���� ����...");

	return true;
}

void CWinSockMgr::CloseServerMgrSock()
{
	g_sToolMgr.GetLog()->AddLog(LOG_TYPE_CONN, "���� �Ŵ��� ���� ���� ����...");

	m_ServerMgrSock.Close();
	m_bServerMgrConnect = false;
}

HRESULT CWinSockMgr::InitWinSockMgr(char* pszServerMgrIP)
{
	g_sToolMgr.GetLog()->AddLog(LOG_TYPE_TOOLWORK, "���� ������ �ʱ�ȭ �۾� ����...");

	m_bServerRun = false;

	InitServerSock();

	g_sToolMgr.GetLog()->AddLog(LOG_TYPE_TOOLWORK, "���� ������ �ʱ�ȭ �۾� ��...");

	strcpy(m_szServerMgrIP, pszServerMgrIP);

	m_bServerMgrConnect = false;

	return S_OK;
}