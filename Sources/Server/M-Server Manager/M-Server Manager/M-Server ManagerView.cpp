
// M-Server ManagerView.cpp : CMServerManagerView 클래스의 구현
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
END_MESSAGE_MAP()

// CMServerManagerView 생성/소멸

CMServerManagerView::CMServerManagerView()
	: CFormView(CMServerManagerView::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

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
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

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
	// 스크롤 크기를 뷰의 크기로 맞추어 줌.
	SetScaleToFitSize(rcClient.Size());

	m_Brush.CreateSolidBrush(RGB(64, 64, 64)); 

	CRect rtTab;

	m_stcTab.GetWindowRect(&rtTab);
	ScreenToClient(&rtTab);

	m_mfcTab.Create(CMFCTabCtrl::STYLE_3D_VS2005, rtTab, this, 1, CMFCTabCtrl::LOCATION_BOTTOM);

	g_sToolMgr.InitToolMgr(m_hWnd);
	g_sToolMgr.GetDialogMgr()->InitDialogMgr(&m_mfcTab);

	m_mfcTab.AddTab(&g_sToolMgr.GetDialogMgr()->m_LogDlg, "Logs", 0, FALSE);
	m_mfcTab.AddTab(&g_sToolMgr.GetDialogMgr()->m_UserDlg, "Users", 1, FALSE);

	OnTabColor();
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


// CMServerManagerView 진단

#ifdef _DEBUG
void CMServerManagerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMServerManagerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMServerManagerDoc* CMServerManagerView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMServerManagerDoc)));
	return (CMServerManagerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMServerManagerView 메시지 처리기

HBRUSH CMServerManagerView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	//return hbr;
	return m_Brush;
}

void CMServerManagerView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.	

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
