#include "stdafx.h"
#include "WinSockMgr.h"

CWinSockMgr::CWinSockMgr()
{
	
}	

CWinSockMgr::~CWinSockMgr()
{
	ReleaseWinSockMgr();
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

void CWinSockMgr::ReleaseWinSockMgr()
{
	ClearUser();
	CloseServerMgrSock();
	CloseServerSock();
}

HRESULT CWinSockMgr::AddUser(USERINFO UserInfo)
{
	m_mapUserSock.insert(USERINFO_MAP_VALUE(m_nUserCount++, UserInfo));

	return S_OK;
}

HRESULT CWinSockMgr::DelUser(int nIndex)
{
	USERINFO_MAP_IT it = m_mapUserSock.begin();

	for( ; it != m_mapUserSock.end(); it++)
	{
		/*if(it->second._ID == ID)
		{
			it->second._pSock->Close();
			SAFE_DELETE(it->second._pSock);
			m_mapWPInfo.erase(it);

			return;
		}*/
	}

	return S_OK;
}

void CWinSockMgr::ClearUser()
{
	USERINFO_MAP_IT it = m_mapUserSock.begin();

	for( ; it != m_mapUserSock.end(); it++)
	{
		SAFE_DELETE(it->second.pSock);
		/*if(it->second._ID == ID)
		{
			it->second._pSock->Close();
			SAFE_DELETE(it->second._pSock);
			m_mapWPInfo.erase(it);

			return;
		}*/
	}

	m_mapUserSock.clear();
}

void CWinSockMgr::OnAccept()
{
	if(m_mapUserSock.size() >= MAX_CLIENT_COUNT) return;

	CClientSock* pClientSock = new CClientSock;

	// ���� Ŭ���̾�Ʈ ���� ����
	m_ServerSock.Accept(*pClientSock);

	CString strIP;	
	int nPort;

	pClientSock->GetPeerName(strIP, (UINT &) nPort);

	CString str;

	str.Format("SOCKET : [%d] - (%s : %d) ���� ���ӵ�", pClientSock->m_hSocket, strIP, nPort);
	g_sToolMgr.GetLog()->AddLog(LOG_TYPE_CONN, str.GetBuffer(0));

	USERINFO UserInfo;

	UserInfo.pSock = pClientSock;

	AddUser(UserInfo);

	str.Format("SOCKET : [%d] - (%s : %d) ���� ���� ���� �Ϸ�", pClientSock->m_hSocket, strIP, nPort);
	g_sToolMgr.GetLog()->AddLog(LOG_TYPE_CONN, str.GetBuffer(0));
}