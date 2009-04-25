
// M-ServerView.h : CMServerView Ŭ������ �������̽�
//


#pragma once


class CMServerView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CMServerView();
	DECLARE_DYNCREATE(CMServerView)

public:
	enum{ IDD = IDD_MSERVER_FORM };

// Ư���Դϴ�.
public:
	CMServerDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CMServerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // M-ServerView.cpp�� ����� ����
inline CMServerDoc* CMServerView::GetDocument() const
   { return reinterpret_cast<CMServerDoc*>(m_pDocument); }
#endif
