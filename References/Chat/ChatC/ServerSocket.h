#pragma once

//#define UM_ACCEPT (WM_USER+10)

// CServerSocket ��� ����Դϴ�.

class CServerSocket : public CSocket
{
public:
	CServerSocket();
	virtual ~CServerSocket();
	virtual void OnAccept(int nErrorCode);
	void Init(CWnd* pWnd, int nPortNum);
protected:
	CWnd *m_pWnd;
};


