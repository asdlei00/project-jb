
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
	//HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	//return hbr;

	return m_Brush;
}
