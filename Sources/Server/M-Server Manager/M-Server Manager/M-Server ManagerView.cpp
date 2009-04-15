
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
END_MESSAGE_MAP()

// CMServerManagerView ����/�Ҹ�

CMServerManagerView::CMServerManagerView()
	: CFormView(CMServerManagerView::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMServerManagerView::~CMServerManagerView()
{
}

void CMServerManagerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
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
