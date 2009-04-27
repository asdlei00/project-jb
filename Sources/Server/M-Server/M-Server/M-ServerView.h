
// M-ServerView.h : CMServerView 클래스의 인터페이스
//


#pragma once


class CMServerView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMServerView();
	DECLARE_DYNCREATE(CMServerView)

public:
	enum{ IDD = IDD_MSERVER_FORM };

// 특성입니다.
public:
	CMServerDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CMServerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	LRESULT OnClientReceive(WPARAM wParam, LPARAM lParam);
	LRESULT OnClientConnect(WPARAM wParam, LPARAM lParam);
	LRESULT OnClientClose(WPARAM wParam, LPARAM lParam);
	LRESULT OnClientAccept(WPARAM wParam, LPARAM lParam);
	LRESULT OnClientNetDown(WPARAM wParam, LPARAM lParam);

public:
	void Init();

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // M-ServerView.cpp의 디버그 버전
inline CMServerDoc* CMServerView::GetDocument() const
   { return reinterpret_cast<CMServerDoc*>(m_pDocument); }
#endif

