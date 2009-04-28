
// M-Server ManagerView.cpp : CMServerManagerView Ŭ������ ����
//

#include "stdafx.h"
#include "M-Server Manager.h"

#include "M-Server ManagerDoc.h"
#include "M-Server ManagerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMServerManagerView

IMPLEMENT_DYNCREATE(CMServerManagerView, CFormView)

BEGIN_MESSAGE_MAP(CMServerManagerView, CFormView)
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_COMMAND(ID_ACCOUNT_MANAGE, &CMServerManagerView::OnAccountManage)
	ON_COMMAND(ID_BUTTON_ACCOUNT_MANAGE_256, &CMServerManagerView::OnButtonAccountManage256)
	ON_COMMAND(ID_BUTTON_RUN, &CMServerManagerView::OnButtonRun)
	ON_COMMAND(ID_BUTTON_STOP, &CMServerManagerView::OnButtonStop)
	ON_MESSAGE(WM_CLIENT_RECEIVE, OnClientReceive)
	ON_MESSAGE(WM_CLIENT_CONNECT, OnClientConnect)
	ON_MESSAGE(WM_CLIENT_CLOSE, OnClientClose)
	ON_MESSAGE(WM_SERVER_ACCEPT, OnClientAccept)
END_MESSAGE_MAP()

// CMServerManagerView ����/�Ҹ�

CMServerManagerView::CMServerManagerView()
	: CFormView(CMServerManagerView::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMServerManagerView::~CMServerManagerView()
{
	g_sToolMgr.ReleaseToolMgr();
}

void CMServerManagerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_stcTab);
}

BOOL CMServerManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CMServerManagerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CRect rcClient;
	GetClientRect(&rcClient);
	GetParentFrame()->RecalcLayout();
	// ��ũ�� ũ�⸦ ���� ũ��� ���߾� ��.
	SetScaleToFitSize(rcClient.Size());

	m_Brush.CreateSolidBrush(RGB(64, 64, 64)); 

	CRect rtTab;

	m_stcTab.GetWindowRect(&rtTab);
	ScreenToClient(&rtTab);

	m_mfcTab.Create(CMFCTabCtrl::STYLE_3D_VS2005, rtTab, this, 1, CMFCTabCtrl::LOCATION_BOTTOM);

	g_sToolMgr.InitToolMgr(m_hWnd);
	g_sToolMgr.GetDialogMgr()->InitDialogMgr(&m_mfcTab);

	m_mfcTab.AddTab(&g_sToolMgr.GetDialogMgr()->m_StatusDlg, "Status", 0, FALSE);
	m_mfcTab.AddTab(&g_sToolMgr.GetDialogMgr()->m_LogDlg, "Logs", 1, FALSE);
	m_mfcTab.AddTab(&g_sToolMgr.GetDialogMgr()->m_UserDlg, "Users", 2, FALSE);

	OnTabColor();

	// ���� ���� â�� ���ʷ� ��� ���� �� ���� �߰��� �� �� �ֵ��� �Ѵ�
	g_sToolMgr.GetDialogMgr()->m_AccountDlg.DoModal();
}

void CMServerManagerView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMServerManagerView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CMServerManagerView ����

#ifdef _DEBUG
void CMServerManagerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMServerManagerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMServerManagerDoc* CMServerManagerView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMServerManagerDoc)));
	return (CMServerManagerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMServerManagerView �޽��� ó����

HBRUSH CMServerManagerView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	//return hbr;
	return m_Brush;
}

void CMServerManagerView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.	

	CMFCTabCtrl* pTab = (CMFCTabCtrl *) GetDlgItem(IDC_TAB1);

	if(pTab->GetSafeHwnd())
	{
		CRect rcClient;
		GetClientRect(&rcClient);

		pTab->SetWindowPos(NULL, 0, 0, rcClient.Width(), rcClient.Height(), SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
	}

	if(!m_mfcTab.GetSafeHwnd()) return;

	CRect rcClient;
	GetClientRect(&rcClient);

	m_mfcTab.SetWindowPos(NULL, 0, 0, rcClient.Width(), rcClient.Height(), SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
}

void CMServerManagerView::OnTabColor() 
{
	UpdateData();
	
	CArray<COLORREF, COLORREF> arColors;

	arColors.Add(RGB (121, 210, 231));
	arColors.Add(RGB (190, 218, 153));
	arColors.Add(RGB (255, 170, 100));

	m_mfcTab.EnableAutoColor(TRUE);
	m_mfcTab.SetAutoColors(arColors);
}

void CMServerManagerView::OnAccountManage()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}

void CMServerManagerView::OnButtonAccountManage256()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	g_sToolMgr.GetDialogMgr()->m_AccountDlg.DoModal();
}

void CMServerManagerView::OnButtonRun()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	if(g_sToolMgr.IsAccountActived())
	{
		g_sToolMgr.SetRun(true);	

		g_sToolMgr.GetDialogMgr()->m_StatusDlg.OnRun(g_sToolMgr.GetUserID());
	}
	else g_sToolMgr.GetDialogMgr()->m_AccountDlg.DoModal();
}

void CMServerManagerView::OnButtonStop()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	g_sToolMgr.SetRun(false);

	g_sToolMgr.GetDialogMgr()->m_StatusDlg.m_editStatus.SetWindowTextA("Server is not running...");
}

LRESULT CMServerManagerView::OnClientReceive(WPARAM wParam, LPARAM lParam)
{

	return S_OK;
}

LRESULT CMServerManagerView::OnClientConnect(WPARAM wParam, LPARAM lParam)
{

	return S_OK;
}

LRESULT CMServerManagerView::OnClientClose(WPARAM wParam, LPARAM lParam)
{

	return S_OK;
}

LRESULT CMServerManagerView::OnClientAccept(WPARAM wParam, LPARAM lParam)
{
	if(!g_sToolMgr.GetRun()) return E_FAIL;

	g_sToolMgr.GetWinSockMgr()->OnAccept();

	return S_OK;
}

LRESULT CMServerManagerView::OnClientNetDown(WPARAM wParam, LPARAM lParam)
{

	return S_OK;
}