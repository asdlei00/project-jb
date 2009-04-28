
// M-ClientView.cpp : CMClientView Ŭ������ ����
//

#include "stdafx.h"
#include "M-Client.h"

#include "M-ClientDoc.h"
#include "M-ClientView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMClientView

IMPLEMENT_DYNCREATE(CMClientView, CFormView)

BEGIN_MESSAGE_MAP(CMClientView, CFormView)
	ON_WM_CTLCOLOR()
	ON_EN_CHANGE(IDC_EDIT1, &CMClientView::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMClientView::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMClientView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMClientView::OnBnClickedButton2)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_MESSAGE(WM_CLIENT_RECEIVE, OnClientReceive)
	ON_MESSAGE(WM_CLIENT_CONNECT, OnClientConnect)
	ON_MESSAGE(WM_CLIENT_CLOSE, OnClientClose)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMClientView ����/�Ҹ�

CMClientView::CMClientView()
	: CFormView(CMClientView::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMClientView::~CMClientView()
{
}

void CMClientView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editID);
	DDX_Control(pDX, IDC_EDIT2, m_editPW);
	DDX_Control(pDX, IDC_BUTTON1, m_btnRegisterID);
	DDX_Control(pDX, IDC_BUTTON2, m_CheckID);
	DDX_Control(pDX, IDC_CHECK2, m_chkboxRememberID);
	DDX_Control(pDX, IDC_CHECK1, m_chkboxOffline);
	DDX_Control(pDX, IDC_BUTTON3, m_btnLogin);
}

BOOL CMClientView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CMClientView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CRect rcClient;
	GetClientRect(&rcClient);
	GetParentFrame()->RecalcLayout();
	// ��ũ�� ũ�⸦ ���� ũ��� ���߾� ��.
	SetScaleToFitSize(rcClient.Size());

	m_Brush.CreateSolidBrush(RGB(192, 192, 192)); 

	Init();
}

void CMClientView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMClientView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CMClientView ����

#ifdef _DEBUG
void CMClientView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMClientView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMClientDoc* CMClientView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMClientDoc)));
	return (CMClientDoc*)m_pDocument;
}
#endif //_DEBUG


// CMClientView �޽��� ó����

HBRUSH CMClientView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.

	int nRet = pWnd->GetDlgCtrlID();

	if(nRet == IDC_STATIC_ID ||
	   nRet == IDC_STATIC_PASSWORDS)
	{
		pDC->SetTextColor(RGB(32, 32, 32));

		hbr = (HBRUSH) GetStockObject(NULL_BRUSH);
		SetBkMode(pDC->m_hDC, TRANSPARENT);
	}

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;

	//return m_Brush;
}

void CMClientView::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CFormView::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CMClientView::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CFormView::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CMClientView::SetLoginStatus(bool bLogin)
{
	if(!bLogin)
	{
		GetDlgItem(IDC_STATIC_ID)->ShowWindow(false);
		GetDlgItem(IDC_STATIC_PASSWORDS)->ShowWindow(false);

		m_editID.ShowWindow(false);
		m_editPW.ShowWindow(false);
		m_btnRegisterID.ShowWindow(false);
		m_CheckID.ShowWindow(false);
	}
	else
	{
		GetDlgItem(IDC_STATIC_ID)->ShowWindow(true);
		GetDlgItem(IDC_STATIC_PASSWORDS)->ShowWindow(true);

		m_editID.ShowWindow(true);
		m_editPW.ShowWindow(true);
		m_btnRegisterID.ShowWindow(true);
		m_CheckID.ShowWindow(true);
	}
}

void CMClientView::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	// Register ID
}

void CMClientView::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

BOOL CMClientView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CRect rt;
	GetClientRect(rt);

	pDC->FillSolidRect(rt, RGB(192, 192, 192));

	return true;

	//return CFormView::OnEraseBkgnd(pDC);
}

void CMClientView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	/*RECT rt;

	GetClientRect(&rt);
	//GetWindowRect(GetDesktopWindow(), &rt);

	int nWidth = rt.right - rt.left;
	int nHeight = rt.bottom - rt.top;

	int nX = rt.left + nWidth / 2 - (CFG_DIALOG_WIDTH / 2)*/
}

LRESULT CMClientView::OnClientReceive(WPARAM wParam, LPARAM lParam)
{

	return S_OK;
}

LRESULT CMClientView::OnClientConnect(WPARAM wParam, LPARAM lParam)
{

	return S_OK;
}

LRESULT CMClientView::OnClientClose(WPARAM wParam, LPARAM lParam)
{

	return S_OK;
}

void CMClientView::Init()
{
	g_sToolMgr.InitToolMgr(m_hWnd);

	LoadServerConfig();

	SetTimer(1, 1000, NULL);
}

HRESULT CMClientView::LoadServerConfig()
{
	char buff[256];
	char temp[256];

	GetStringFromConfig("Server_Config", "INFO", "COUNT", buff);

	for(int i = 0; i < atoi(buff); i++)
	{
		sprintf(temp, "SERVER#%d", i + 1);

		GetStringFromConfig("Server_Config", "LISTS", temp, buff);

		strcpy(g_sToolMgr.m_ServerList[i].szServerIP, buff);
	}

	return S_OK;
}

void CMClientView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	if(!g_sToolMgr.m_bConnected)
	{
		/*int i = 0;
		int nCnt = 0;

		while(1)
		{
			if(g_sToolMgr.GetWinSockMgr()->GetServerSock()->Connect(g_sToolMgr.m_ServerList[i].szServerIP, 
				                                                    MIDDLE_SERVER_PORT))
			{
				strcpy(g_sToolMgr.m_ServerIP, g_sToolMgr.m_ServerList[i].szServerIP);
				g_sToolMgr.m_bConnected = true;
				return;
			}

			if(++i > MAX_SERVER_LIST) 
			{
				nCnt++;
				i = 0;
			}

			if(nCnt > MAX_RE_CONNECTION)
			{
				AfxMessageBox("No server to connect now...");
				return;
			}
		}*/
	}

	CFormView::OnTimer(nIDEvent);
}
