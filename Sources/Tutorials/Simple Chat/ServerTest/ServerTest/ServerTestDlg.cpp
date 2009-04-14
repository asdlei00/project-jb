// ServerTestDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ServerTest.h"
#include "ServerTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� ������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ����

// ����
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CServerTestDlg ��ȭ ����



CServerTestDlg::CServerTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listboxText);
}

BEGIN_MESSAGE_MAP(CServerTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_SERVER_ACCEPT, OnClientAccept)
	ON_MESSAGE(WM_CLIENT_RECEIVE, OnClientReceive)
	ON_MESSAGE(WM_CLIENT_CLOSE, OnClientClose)
END_MESSAGE_MAP()


// CServerTestDlg �޽��� ó����

BOOL CServerTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	// �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
	g_MainhWnd = m_hWnd;

	m_Server.Create(SERVER_PORT);
	m_Server.Listen();

	char name[255];
	CString strIP;
	PHOSTENT hostinfo;

	// �ڽ��� IP �˱�
	if(gethostname(name, sizeof(name)) == 0) 
	{ 
		if((hostinfo = gethostbyname(name)) != NULL) 
		{ 
			strIP = inet_ntoa (*(struct in_addr *) *hostinfo->h_addr_list); 
		} 
	}

	CString str;
	str.Format("%s : %d ���� �ʱ�ȭ ����...", strIP, SERVER_PORT);

	m_listboxText.AddString(str);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

void CServerTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸����� 
// �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
// �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CServerTestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�. 
HCURSOR CServerTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CServerTestDlg::AddClient(PCLIENTINFO pClient)
{
	if(pClient == NULL) return;

	static int nCount = 0;

	//m_mapClient.insert(CINFO_MAP_VALUE(pClient->Key.szKey, *pClient));
	m_mapClient.insert(CINFO_MAP_VALUE(nCount++, *pClient));
}

void CServerTestDlg::DelClient(int nIndex)
{
	
}

void CServerTestDlg::ClearClient()
{

}

LRESULT CServerTestDlg::OnClientAccept(WPARAM wParam, LPARAM lParam)
{
	CClientSock* pClient = new CClientSock;
	//pClient->m_hWnd = m_hWnd;

	m_Server.Accept(*pClient);

	/*if(!pClient->m_bConnect) 
	{
		pClient->Close();
		SAFE_DELETE(pClient);
		return E_FAIL;
	}*/

	CString strIP;	
	int nPort;

	pClient->GetPeerName(strIP, (UINT &) nPort);

	CString str;
	str.Format("[%s : %d] Ŭ���̾�Ʈ ���� ����...", strIP, nPort);

	CLIENTINFO ClientInfo;

	ClientInfo.pSock = pClient;
	//strcpy(ClientInfo.Key.szKey, str.GetBuffer(0));

	m_listboxText.AddString(str);

	AddClient(&ClientInfo);

	return S_OK;
}

LRESULT CServerTestDlg::OnClientReceive(WPARAM wParam, LPARAM lParam)
{
	CINFO_MAP_IT it = m_mapClient.begin();

	for(int i = 0; it != m_mapClient.end(); i++, it++)
	{
		if(it->second.pSock->m_hSocket != wParam) continue;

		CString str;

		char buff[256];
		memset(buff, 0, 256);

		int nRet = it->second.pSock->Receive(buff, 256);

		m_listboxText.AddString(buff);
		m_listboxText.SetTopIndex(m_listboxText.GetCount()-1);

		SendAllClient(wParam, buff);

		return S_OK;
	}

	return E_FAIL;
}

void CServerTestDlg::SendAllClient(WPARAM wParam, const char* pszText)
{
	CINFO_MAP_IT it = m_mapClient.begin();

	for(int i = 0; it != m_mapClient.end(); i++, it++)
	{
		if(it->second.pSock->m_hSocket == wParam) continue;

		CString strText;
		strText.Format("%s", pszText);

		it->second.pSock->Send(strText, 256);
	}
}

LRESULT CServerTestDlg::OnClientClose(WPARAM wParam, LPARAM lParam)
{
	CString str;
	str.Format("[%d] Ŭ���̾�Ʈ ���� ����...", wParam);

	m_listboxText.AddString(str);

	return S_OK;
}
