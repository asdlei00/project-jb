#include "stdAfx.h"
#include "ToolMgr.h"

HRESULT	CToolMgr::InitToolMgr(HWND hWnd)
{
	m_hWnd = hWnd;

	m_Log.AddLog(LOG_TYPE_TOOLWORK, "���� �� �ʱ�ȭ �۾� ����...");

	m_WinSockMgr.InitWinSockMgr();

	m_Log.AddLog(LOG_TYPE_TOOLWORK, "���� �� �ʱ�ȭ �۾� ��...");

	return S_OK;
}

void CToolMgr::ReleaseToolMgr()
{
	m_Log.AddLog(LOG_TYPE_TOOLWORK, "���� �� ������...");

	sToolMgr.DestroyInstance();
}

void CToolMgr::SetLogView(bool bLogView)
{
	if(bLogView) m_Log.EnableLog();
	else m_Log.DisableLog();
}