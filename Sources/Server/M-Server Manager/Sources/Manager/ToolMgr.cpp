#include "stdAfx.h"
#include "ToolMgr.h"

HRESULT	CToolMgr::InitToolMgr(HWND hWnd)
{
	m_hWnd = hWnd;

	m_Log.AddLog("���� �Ŵ��� �� �ʱ�ȭ �۾� ����...");

	m_Log.AddLog("���� �Ŵ��� �� �ʱ�ȭ �۾� ��...");

	return S_OK;
}

void CToolMgr::ReleaseToolMgr()
{
	sToolMgr.DestroyInstance();
}