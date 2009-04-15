/* 
	Author				: ������(Bill) (kjh_900@hanmail.net)	
	Release Date		: 2008. 10. 17.
	Project	Name		: WinSock Manager
	Version				: 1.02.10

	Test PC				: CPU - Pentium(R) 4 2.40Ghz, RAM - 1 GB Graphic - Radeon 9600
	Test OS				: Windows XP Professional + SP2
	Test Application	: Visual Studio 2003 + D3D 9.0c(Dec 2006)
	
	Contents

	WinSock Manager Header

	2008 �� Copyright MIS Corporation. All Rights Reserved.
*/

#pragma once

#include "ServerSock.h"
#include "ClientSock.h"
#include "Convertor.h"

/*
	Structure : ELINFO structure

	Release Date		: 2008. 10. 28.
	Version				: 1.00.07
*/

typedef struct _ELINFO
{
	ELID			_ID;				// EL ID
	int				_nLowestFloor;		// ������
	ELRECVINFO		_Info;				// EL Recv Info
	ELSENDINFO		_ELSendInfo;		// EL Send Info
	bool			_bConnect;			// ���� ����

	char			_szELState[32];		// EL ���� �ؽ�Ʈ
	char			_szAptIndex[16];	// �� �ؽ�Ʈ
	char			_szELIndex[16];		// ȣ�� �ؽ�Ʈ
	char			_szELFloor[16];		// EL �� �ؽ�Ʈ
	char			_szELDir[16];		// EL ���� �ؽ�Ʈ

	// EL ���� �ؽ�Ʈ ����
	bool			SetText()
	{
		bool bChange = false;
		char szTemp[64], szTemp2[64];

		strcpy(szTemp, _szELState);

		sprintf(_szELState, "%c%c", _Info._byELState[0],
									_Info._byELState[1]);

		// ��� �̻�
		if(strcmp(_szELState, "00") == 0) 
		{
			strcpy(szTemp2, _szELState);
			sprintf(_szELState, "NET ERROR");
		}
		// �ڵ� ����(���� ����)
		else if(strcmp(_szELState, "01") == 0) 
		{
			strcpy(szTemp2, _szELState);
			sprintf(_szELState, "NORMAL");
		}
		// ���� ����(������)
		else if(strcmp(_szELState, "02") == 0) 
		{
			strcpy(szTemp2, _szELState);
			sprintf(_szELState, "REPARING");
		}
		// ���� ����(�̻���)
		else if(strcmp(_szELState, "03") == 0) 
		{
			strcpy(szTemp2, _szELState);
			sprintf(_szELState, "MOVING");
		}
		// �ҹ� ����
		else if(strcmp(_szELState, "04") == 0) 
		{
			strcpy(szTemp2, _szELState);
			sprintf(_szELState, "FIRE");
		}
		// �°��� ����
		else if(strcmp(_szELState, "05") == 0) 
		{
			strcpy(szTemp2, _szELState);
			sprintf(_szELState, "ERROR");
		}
		// ��ŷ ����
		else if(strcmp(_szELState, "06") == 0) 
		{
			strcpy(szTemp2, _szELState);
			sprintf(_szELState, "PARKING");
		}
		// ����
		else if(strcmp(_szELState, "07") == 0) 
		{
			strcpy(szTemp2, _szELState);
			sprintf(_szELState, "FULL");
		}
		else 
		{
			strcpy(szTemp2, _szELState);
			sprintf(_szELState, "NET ERROR");
		}

		if(strcmp(szTemp2, szTemp) != 0) bChange = true;

		sprintf(_szAptIndex, "%c%c%c%c", _ID._byAptIndex[0],
										_ID._byAptIndex[1],
										_ID._byAptIndex[2],
										_ID._byAptIndex[3]);

		sprintf(_szELIndex, "%c%c", _ID._byELIndex[0],
									_ID._byELIndex[1]);

		strcpy(szTemp, _szELFloor);

		sprintf(_szELFloor, "%c%c", _Info._byFloor[0],
									_Info._byFloor[1]);

		if(strcmp(_szELFloor, szTemp) != 0) bChange = true;

		strcpy(szTemp, _szELDir);

		// None
		if(_Info._byDirection == 0x30) sprintf(_szELDir, "STOP");
		// Up
		else if(_Info._byDirection == 0x31) sprintf(_szELDir, "UP");
		// Down
		else if(_Info._byDirection == 0x32) sprintf(_szELDir, "DOWN");

		if(strcmp(_szELDir, szTemp) != 0) bChange = true;

		return bChange;
	}

	_ELINFO() 
	{
		_bConnect = false;

		strcpy(_szELState, "��� �̻�");
		strcpy(_szAptIndex, "-");
		strcpy(_szELIndex, "-");
		strcpy(_szELFloor, "-");
		strcpy(_szELDir, "-");
	}

	_ELINFO(ELID ID, int nLowestFloor, ELSENDINFO ELSendInfo)
	{
		_bConnect = false;

		_ID = ID;
		_nLowestFloor = nLowestFloor;
		_ELSendInfo = ELSendInfo;

		strcpy(_szELState, "��� �̻�");
		strcpy(_szAptIndex, "-");
		strcpy(_szELIndex, "-");
		strcpy(_szELFloor, "-");
		strcpy(_szELDir, "-");
	}
}ELINFO, *PELINFO;

/*
	Structure : WPINFO structure

	Release Date		: 2008. 10. 28.
	Version				: 1.00.07
*/

typedef struct _WPINFO
{
	WPID			_ID;				// WP ID
	CClientSock*	_pSock;				// WP Socket
	WPRECVINFO		_Info;				// WP Recv Info

	char			_szClass[32];		// ���е� ����(Ȩ��, �����) �ؽ�Ʈ
	char			_szAptIndex[16];	// �� �ؽ�Ʈ
	char			_szELIndex[16];		// ȣ�� �ؽ�Ʈ
	char			_szFloor[16];		// �� �ؽ�Ʈ
	char			_szCallDir[16];		// �� ���� �ؽ�Ʈ

	bool			_bConnected;		// ���� �� �������� �ƴ��� üũ
	int				_nTime;				// ������ �ð�
	bool			_bArrived;			// ���������Ͱ� ���ϴ� ������ �����ߴ��� üũ
	bool			_bInList;			// ����Ʈ ��Ʈ�ѿ� �ִ��� ������ üũ
	int				_nSendFailCnt;		// Send Fail ī����
	BYTE			_bySend[1024];		// ���������� �� ��û ���� ������

	// WP ���� �ؽ�Ʈ ����
	bool			SetText(BYTE* pbyData, BYTE byClass, BYTE* pbyFloor)
	{
		/*if(pbyData[0] != 'S' || pbyData[1] != 'H' || pbyData[2] != 'V')
		{
			return false;
		}*/

		/*if(pbyData[13] != 'E' || pbyData[14] != 'T' || pbyData[15] != 'X')
		{
			return false;
		}*/

		char szClass[16], szDir[16];

		bool bChange = false;
		char szTemp[64];

		if(byClass == 0x30)
			strcpy(szClass, "HOMECALL");
		else if(byClass == 0x31)
			strcpy(szClass, "NOT HOME");
		else
			strcpy(szClass, "HOMECALL");

		strcpy(_szClass, szClass);

		strcpy(szTemp, _szCallDir);

		BYTE byData = pbyData[WE_CALL_PTR];

		if(pbyData[WE_CALL_PTR] == 1)
			strcpy(_szCallDir, "UP");
		else if(pbyData[WE_CALL_PTR] == -1 || pbyData[WE_CALL_PTR] == 255)
			strcpy(_szCallDir, "DOWN");
		else	
			strcpy(_szCallDir, "-");
		
		if(strcmp(_szCallDir, szTemp) != 0) bChange = true;

		strcpy(_szClass, szClass);

		/*sprintf(_szText, "[����] %s [��] %c%c%c%c [ȣ��] %c%c [��] %c%c [�� ����] %s", szClass,
																						pbyData[WE_APTINDEX_PTR],
																						pbyData[WE_APTINDEX_PTR+1],
																						pbyData[WE_APTINDEX_PTR+2],
																						pbyData[WE_APTINDEX_PTR+3],
																						pbyData[WE_INDEX_PTR],
																						pbyData[WE_INDEX_PTR+1],
																						pbyData[WE_FLOOR_PTR],
																						pbyData[WE_FLOOR_PTR+1],
																						szDir);*/

		char Temp[64];

		sprintf(Temp, "%c%c%c%c", pbyData[WE_APTINDEX_PTR],
								  pbyData[WE_APTINDEX_PTR+1],
								  pbyData[WE_APTINDEX_PTR+2],
								  pbyData[WE_APTINDEX_PTR+3]);
		strcpy(_szAptIndex, Temp);

		sprintf(Temp, "%c%c", pbyData[WE_INDEX_PTR],
								  pbyData[WE_INDEX_PTR+1]);
		strcpy(_szELIndex, Temp);

		if(pbyFloor == NULL) return bChange;

		sprintf(Temp, "%c%c", pbyFloor[0], pbyFloor[1]);
		strcpy(_szFloor, Temp);

		return bChange;
	}

	// ���� �ð��� ����
	void			SetCurTime()
	{
		CTime Time = CTime::GetCurrentTime();   

		int nHour = Time.GetHour();
		int nMin = Time.GetMinute();
		int nSec = Time.GetSecond();

		int nCurTime = (nHour * 3600) + (nMin * 60) + nSec;

		_nTime = nCurTime;
	}

	_WPINFO() 
	{
		_bConnected = true;
		_bArrived = false;
		_bInList = true;

		_nSendFailCnt = 0;
	}

	_WPINFO(WPID ID, CClientSock* pSock)
	{
		_ID = ID;
		_pSock = pSock;
		_bConnected = true;
		_bArrived = false;
		_bInList = true;

		SetCurTime();

		_nSendFailCnt = 0;
	}
}WPINFO, *PWPINFO;

typedef map<int, CServerSock*>					SERVERSOCK_MAP;
typedef map<int, CServerSock*>::iterator		SERVERSOCK_MAP_IT;
typedef map<int, CServerSock*>::value_type		SERVERSOCK_MAP_VALUE;

typedef map<int, WPINFO>						WPINFO_MAP;
typedef map<int, WPINFO>::iterator				WPINFO_MAP_IT;
typedef map<int, WPINFO>::value_type			WPINFO_MAP_VALUE;

typedef map<int, ELINFO>						ELINFO_MAP;
typedef map<int, ELINFO>::iterator				ELINFO_MAP_IT;
typedef map<int, ELINFO>::value_type			ELINFO_MAP_VALUE;

#define SERVER_PORT		4332
#define EL_PORT			2999

/*
	Class : WinSock Manager Class

	Release Date		: 2008. 10. 17.
	Version				: 1.03.03
*/

class CWinSockMgr
{
private:
	// Server Socket
	//SERVERSOCK_MAP		m_mapServerSock;		// ���� ���� ��
	//int					m_nServerSockCnt;		// ���� ���� �� ī����
	CServerSock				m_ServerSock;		// ���� ����	
	
	// Wallpad Info(Homecall)
	WPINFO_MAP			m_mapWPInfo;			// ���е� ���� ��
	int					m_nWPInfoCnt;			// ���е� ���� �� ī����
	int					m_nWPSockCnt;			// ���е� ���� ī����(���� ���ϸ�)

	// Elevator Info
	ELINFO_MAP			m_mapELInfo;			// EL ���� ��
	int					m_nELInfoCnt;			// EL ���� �� ī����

	bool				m_bELConnect;			// Check the connection status whether it is connected or not.
	CClientSock*		m_pELSocket;			// EL �����κ��� ���� �� ������ �ۼ����� ���� ����

	int					m_nSelectIndex;			// ���õ� EL �ε���

public:
	int					m_nWPAcceptCnt;			// WP ���� ī����
	int					m_nWPDiscCnt;			// WP ���� ���� ī����
	int					m_nELCallCnt;			// EL �� ��û ī����
	int					m_nELArriveCnt;			// EL ���� �Ϸ� ī����
	int					m_nIOCnt;				// �� ����� ȣ�� ī����

public:
	BYTE				m_byServerID[17];		// ���� ���̵�(17 Byte)

public:
	ELINFO_MAP*			GetELInfo() { return &m_mapELInfo; }
	ELINFO*				GetELInfo(ELID ID);
	ELINFO*				GetELInfo(BYTE* pbyELIndex);

	WPINFO_MAP*			GetWPInfo() { return &m_mapWPInfo; }

	int					GetELSize() { return m_mapELInfo.size(); }
	int					GetWPSize() { return m_mapWPInfo.size(); }

	bool				GetELConnect() { return m_bELConnect; }

	int					GetSelectIndex() { return m_nSelectIndex; }

public:
	void				SetELConnect(bool bConnect) { m_bELConnect = bConnect; }
	
	void				SetServerID(CString strServerID);

public:
	// ���� ���� �߰�
	void				AddServerSock(int nIndex, int nPort);
	// ���е� ���� �߰�
	void				AddWPInfo(WPINFO WPInfo);
	// EL ���� �߰�
	void				AddELInfo(BYTE* pbyAptIndex, BYTE* pbyELIndex, int nLowestFloor);

	// ���� ���� ����(Wp ī���� �ʿ�)
	void				DelServerSock(int nIndex);
	// ���е� ���� ����(WP ID �ʿ�)
	void				DelWPInfo(WPID ID);
	// EL ���� ����(EL ID �ʿ�)
	void				DelELInfo(ELID ID);
	// EL ���� ����(EL ī���� �ʿ�)
	void				DelELInfo(int nCnt);

	// ���� ���� Ŭ����
	void				ClearServerSock();
	// ���е� ���� Ŭ����
	void				ClearWPInfo();
	// EL ���� Ŭ����
	void				ClearELInfo();

public:
	// ���� �Ŵ��� �ʱ�ȭ
	void				Init(int nHomeCnt = 0, int nELCnt = 0, int nServerCnt = 1);
	// ���� ���� �ʱ�ȭ
	void				InitServerSock(int nServerCnt = 1);
	// EL �ʱ�ȭ
	void				InitEL();

	// ���� �����ͷκ��� �ϳ��� EL �������� ����
	bool				ExtractELInfoFromData(BYTE* pTemp, BYTE* pbyData, int nIndex);
	// ��� ���е�� ���� ����
	bool				SendToHome(BYTE* pbyData, BYTE* pbyAptIndex, int nLowestFloor, char* pszRealFloor, BYTE byELDir);
	// ��� EL�� ���� ����
	void				SendToEL(BYTE* pbyData, BYTE* pbyELIndex, PWPRECVINFO pWPRecvInfo, bool bHome = true);
	// �⺻ EL ���� EL�� Send
	void				SendDefaultELInfo();
	// EL ���� ������ ��û(2.5)
	void				SendELCallReq(PWPINFO pWPInfo);

	// ���� �Ŵ��� Ŭ����
	void				Clear();

	// ������ üũ(����, �ٿ��ݿ� ���� �м��� ���Ͽ� �߰�)
	bool				CheckFrame(BYTE* pbyFrame);

	// WP ������ ���� �α�
	void				WPRecvLog(BYTE* pbyAptIndex, BYTE* pbyFloor, BYTE* pbyELLine, BYTE* pbyData);

	// �̹� ���� WP �� �ִ��� üũ(�ӽ� �������� ���)
	bool				HasSameWP(BYTE* pbyAptIndex, BYTE* pbyFloor, BYTE* pbyELLine);

	// �̹� ���� WP IP �� �ִ��� üũ(�ӽ� �������� ���)
	bool				HasSameIP(CClientSock* pClient);

public:
	// ���� ����
	void				OnReceive(SOCKET Socket, int nTag);
	// ���� ����(���е�)
	bool				OnReceiveFromHome(SOCKET Socket);
	// ���� ����(EL)
	bool				OnReceiveFromEL(SOCKET Socket);
	// EL ��� ����
	void				UpdateEL();

	// ���� ����
	void				OnAccept();
	// ����
	bool				OnConnect();
	// ����(���� �ʿ�)
	bool				OnConnect(SOCKET Socket);
	// EL ���� ����
	void				OnCloseEL(SOCKET Socket);
	// WP ���� ����
	void				OnCloseWP(SOCKET Socket);


public:
	// The basic constructor
	CWinSockMgr();

	// The basic destructor
	~CWinSockMgr();
};