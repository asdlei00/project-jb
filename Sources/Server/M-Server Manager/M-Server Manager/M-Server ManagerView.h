
// M-Server ManagerView.h : CMServerManagerView Ŭ������ �������̽�
//


#pragma once

#include "LogDlg.h"
#include "UserDlg.h"
#include "afxwin.h"

class CMServerManagerView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CMServerManagerView();
	DECLARE_DYNCREATE(CMServerManagerView)

public:
	enum{ IDD = IDD_MSERVERMANAGER_FORM };

// Ư���Դϴ�.
public:
	CMServerManagerDoc* GetDocument() const;

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
	virtual ~CMServerManagerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CMFCTabCtrl	m_mfcTab;

	void OnTabColor(); 

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CStatic m_stcTab;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // M-Server ManagerView.cpp�� ����� ����
inline CMServerManagerDoc* CMServerManagerView::GetDocument() const
   { return reinterpret_cast<CMServerManagerDoc*>(m_pDocument); }
#endif

