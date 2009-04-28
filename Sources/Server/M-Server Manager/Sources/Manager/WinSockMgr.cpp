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

HRESULT CWinSockMgr::AddMServer(MSERVERINFO MServerInfo)
{
	if(m_nMServerCount > MAX_INT_SIZE) m_nMServerCount = 0;

	m_mapMServer.insert(MSERVERINFO_MAP_VALUE(m_nMServerCount++, MServerInfo));

	return S_OK;
}

HRESULT CWinSockMgr::DelMServer(char* pszIP)
{
	MSERVERINFO_MAP_IT it = m_mapMServer.begin();

	for( ; it != m_mapMServer.end(); it++)
	{
		if(strcmp(it->second.szIP, pszIP) == 0)
		{
			it->second.pSock->Close();
			SAFE_DELETE(it->second.pSock);
			m_mapMServer.erase(it);

			return S_OK;
		}
	}

	return E_FAIL;
}

void CWinSockMgr::ClearMServer()
{
	MSERVERINFO_MAP_IT it = m_mapMServer.begin();

	for( ; it != m_mapMServer.end(); it++)
	{
		it->second.pSock->Close();
		SAFE_DELETE(it->second.pSock);
	}

	m_mapMServer.clear();
}

HRESULT CWinSockMgr::InitWinSockMgr()
{
	g_sToolMgr.GetLog()->AddLog(LOG_TYPE_TOOLWORK, "���� ������ �ʱ�ȭ �۾� ����...");

	m_bServerRun = false;

	InitServerSock();

	g_sToolMgr.GetLog()->AddLog(LOG_TYPE_TOOLWORK, "���� ������ �ʱ�ȭ �۾� ��...");

	m_nMServerCount = 0;

	return S_OK;
}

void CWinSockMgr::ReleaseWinSockMgr()
{
	ClearMServer();
	CloseServerSock();
}

void CWinSockMgr::OnAccept()
{
	CClientSock* pClientSock = new CClientSock;

	// M-Server ���� ����
	m_ServerSock.Accept(*pClientSock);

	// ���� ���� ���°� �ƴϸ� ���� ���� �� �ٷ� ����(������ �� ���� ����)
	if(!g_sToolMgr.GetRun())
	{
		pClientSock->Close();
		SAFE_DELETE(pClientSock);

		return;
	}

 	CString strIP;	
	int nPort;

	pClientSock->GetPeerName(strIP, (UINT &) nPort);

	CString str;

	str.Format("SOCKET : [%d] - (%s : %d) M-Server ���ӵ�", pClientSock->m_hSocket, strIP, nPort);
	g_sToolMgr.GetLog()->AddLog(LOG_TYPE_CONN, str.GetBuffer(0));

	MSERVERINFO MServerInfo;

	MServerInfo.pSock = pClientSock;
	strcpy(MServerInfo.szIP, strIP);

	AddMServer(MServerInfo);

	str.Format("SOCKET : [%d] - (%s : %d) M-Server ���� ���� �Ϸ�", pClientSock->m_hSocket, strIP, nPort);
	g_sToolMgr.GetLog()->AddLog(LOG_TYPE_CONN, str.GetBuffer(0));
}

void CWinSockMgr::OnReceive(SOCKET Socket, int nTag)
{
	MSERVERINFO_MAP_IT it = m_mapMServer.begin();
  
	for(int i = 0; it != m_mapMServer.end(); i++, it++)
	{
		if(it->second.pSock->m_hSocket != Socket) continue;
		
		char recv[512];

		int nRet = it->second.pSock->Receive(recv, 512);

		if(nRet <= SOCKET_ERROR) 
		{	
			return;
		}

		if(strlen(recv) <= 32)
		{
			if(strcmp(recv, "CONNECT_REQ") == 0)
			{
				it->second.pSock->Send("CONNECT_ACK", 16);	
			}
			//else it->second.pSock->Send("CONNECT_NAK", 16);	
		}
		else 
		{
			m_MSGParser.ParseMSG(recv);
		}
	}
}

void CWinSockMgr::OnClose(SOCKET Socket, int nTag)
{
	/*MSERVERINFO_MAP_IT it = m_mapMServer.begin();
  
	for(int i = 0; it != m_mapMServer.end(); i++, it++)
	{
		if(it->second.pSock->m_hSocket != Socket) continue;

		it->second.pSock->Close();
		DelMServer(it->second.szIP);

		return;
	}*/
}