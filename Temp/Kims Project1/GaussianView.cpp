// GaussianView.cpp : CGaussianView Ŭ������ ����
//

#include "stdafx.h"
#include "Gaussian.h"
#include "Dib.h"

#include "GaussianDoc.h"
#include "GaussianView.h"

#include "RGBBYTE.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGaussianView

IMPLEMENT_DYNCREATE(CGaussianView, CScrollView)

BEGIN_MESSAGE_MAP(CGaussianView, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_SELECTSAVE_SELECT, &CGaussianView::OnSelectsaveSelect)
END_MESSAGE_MAP()

// CGaussianView ����/�Ҹ�

CGaussianView::CGaussianView()
:	rect_start(TRUE)
,	m_rtMouse(0)
,	left(0)
,	top(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CGaussianView::~CGaussianView()
{
}

BOOL CGaussianView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CGaussianView �׸���

void CGaussianView::OnDraw(CDC* pDC)
{
	CGaussianDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if( pDoc->m_Dib.IsValid() )
		pDoc->m_Dib.Draw(pDC->m_hDC);

	RenderMouseRect(pDC);

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}

void CGaussianView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	CGaussianDoc* pDoc = GetDocument();
	if( pDoc->m_Dib.IsValid() )
	{
		sizeTotal.cx = pDoc->m_Dib.GetWidth();
		sizeTotal.cy = pDoc->m_Dib.GetHeight();
	}
	else
		sizeTotal.cx = sizeTotal.cy = 50;

	SetScrollSizes(MM_TEXT, sizeTotal);

	ResizeParentToFit(TRUE);
}


// CGaussianView �μ�

BOOL CGaussianView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CGaussianView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CGaussianView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CGaussianView ����

#ifdef _DEBUG
void CGaussianView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CGaussianView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CGaussianDoc* CGaussianView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGaussianDoc)));
	return (CGaussianDoc*)m_pDocument;
}
#endif //_DEBUG


// CGaussianView �޽��� ó����
void CGaussianView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	if( nFlags == MK_LBUTTON )
	{
		LONG tx, ty;
		if( point.x > left && point.y > top )
		{
			m_rtMouse.left = left;
			m_rtMouse.top = top;
			m_rtMouse.right = point.x;
			m_rtMouse.bottom = point.y;
		}
		else if(left > point.x && point.y > top )
		{
			m_rtMouse.left = point.x;
			m_rtMouse.right = left;
			m_rtMouse.top = top;
			m_rtMouse.bottom = point.y;
		}
		else if( left > point.x && top > point.y )
		{
			m_rtMouse.left = point.x;
			m_rtMouse.right = left;
			m_rtMouse.top = point.y;
			m_rtMouse.bottom = top;
		}
		else
		{
			m_rtMouse.left = left;
			m_rtMouse.right = point.x;
			m_rtMouse.top = point.y;
			m_rtMouse.bottom = top;

		}

		InvalidateRect(NULL, false);
	}	

	CScrollView::OnMouseMove(nFlags, point);
}

void CGaussianView::RenderMouseRect(CDC* pDC)
{ 
	pDC->MoveTo(m_rtMouse.left, m_rtMouse.top);
	pDC->LineTo(m_rtMouse.right, m_rtMouse.top);
	pDC->LineTo(m_rtMouse.right, m_rtMouse.bottom);
	pDC->LineTo(m_rtMouse.left, m_rtMouse.bottom);
	pDC->LineTo(m_rtMouse.left, m_rtMouse.top);
}

void CGaussianView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	left = point.x;
	top = point.y;

	CScrollView::OnLButtonDown(nFlags, point);
}

void CGaussianView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_rtMouse = 0;
	Invalidate(FALSE);

	CScrollView::OnRButtonDown(nFlags, point);
}

void CGaussianView::RectImageCoordinate()
{
	if( m_rtMouse == 0 )
	{
		AfxMessageBox(_T("�����ϰ� ���� �簢 ������ �����Ͻʽÿ�."));
		return;
	}

	CGaussianDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	register int i, j;
	int w = m_rtMouse.Width();
	int h = m_rtMouse.Height();

	CDib dib2;
	dib2 = pDoc->m_Dib;
	if( dib2.GetBitCount() == 8 )
	{
		m_View_Dib.CreateGrayImage(w, h);

		BYTE** ptr1 = m_View_Dib.GetPtr();
		BYTE** ptr2 = dib2.GetPtr();

		for( j = 0; j < h; j++ )
		for( i = 0; i < w; i++ )
		{
			ptr1[j][i] = ptr2[m_rtMouse.top+j][m_rtMouse.left+i];
		}
	}
	else if( dib2.GetBitCount() == 24 )
	{
		m_View_Dib.CreateRGBImage(w, h);

		RGBBYTE** ptr1 = m_View_Dib.GetRGBPtr();
		RGBBYTE** ptr2 = dib2.GetRGBPtr();

		for( j = 0; j < h; j++ )
		for( i = 0; i < w; i++ )
		{
			ptr1[j][i].r = ptr2[m_rtMouse.top+j][m_rtMouse.left+i].r;
			ptr1[j][i].g = ptr2[m_rtMouse.top+j][m_rtMouse.left+i].g;
			ptr1[j][i].b = ptr2[m_rtMouse.top+j][m_rtMouse.left+i].b;
		}
	}
}
BOOL CGaussianView::OnEraseBkgnd(CDC* pDC)
{
	CBrush br;
	br.CreateHatchBrush(HS_DIAGCROSS, RGB(200, 200, 200));
	FillOutsideRect(pDC, &br);

	return TRUE;
}

void CGaussianView::OnSelectsaveSelect()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	RectImageCoordinate();

	CGaussianDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	AfxNewImage(m_View_Dib);

	CDib dib = pDoc->m_Dib;
	pDoc->m_Dib = m_View_Dib;

	AfxGetMainWnd()->SendMessage(WM_COMMAND, ID_FILE_SAVE_AS);

	pDoc->m_Dib = dib;

}
