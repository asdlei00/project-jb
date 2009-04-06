// GaussianView.h : CGaussianView Ŭ������ �������̽�
//


#pragma once


class CGaussianView : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CGaussianView();
	DECLARE_DYNCREATE(CGaussianView)

// Ư���Դϴ�.
public:
	CGaussianDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CGaussianView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	BOOL rect_start;

	CRect m_rtMouse;

	void RenderMouseRect(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);

public:
	void RectImageCoordinate();	

	CDib m_View_Dib;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSelectsaveSelect();

public:
	LONG left, top;
};

#ifndef _DEBUG  // GaussianView.cpp�� ����� ����
inline CGaussianDoc* CGaussianView::GetDocument() const
   { return reinterpret_cast<CGaussianDoc*>(m_pDocument); }
#endif

