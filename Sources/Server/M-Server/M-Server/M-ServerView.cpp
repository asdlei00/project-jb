
// M-ServerView.cpp : CMServerView Ŭ������ ����
//

#include "stdafx.h"
#include "M-Server.h"

#include "M-ServerDoc.h"
#include "M-ServerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMServerView

IMPLEMENT_DYNCREATE(CMServerView, CFormView)

BEGIN_MESSAGE_MAP(CMServerView, CFormView)
END_MESSAGE_MAP()

// CMServerView ����/�Ҹ�

CMServerView::CMServerView()
	: CFormView(CMServerView::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMServerView::~CMServerView()
{
}

void CMServerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMServerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CMServerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CMServerView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMServerView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CMServerView ����

#ifdef _DEBUG
void CMServerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMServerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMServerDoc* CMServerView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMServerDoc)));
	return (CMServerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMServerView �޽��� ó����
