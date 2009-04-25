
// M-ClientView.h : CMClientView Ŭ������ �������̽�
//


#pragma once
#include "afxwin.h"


class CMClientView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CMClientView();
	DECLARE_DYNCREATE(CMClientView)

public:
	enum{ IDD = IDD_MCLIENT_FORM };

// Ư���Դϴ�.
public:
	CMClientDoc* GetDocument() const;

// �۾��Դϴ�.
public:
	CBrush m_Brush;

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CMClientView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

public:
	void SetLoginStatus(bool bLogin);

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CEdit m_editID;
	CEdit m_editPW;
	CButton m_btnRegisterID;
	CButton m_CheckID;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CButton m_chkboxRememberID;
	CButton m_chkboxOffline;
	CButton m_btnLogin;
};

#ifndef _DEBUG  // M-ClientView.cpp�� ����� ����
inline CMClientDoc* CMClientView::GetDocument() const
   { return reinterpret_cast<CMClientDoc*>(m_pDocument); }
#endif

