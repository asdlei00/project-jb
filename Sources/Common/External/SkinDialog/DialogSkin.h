#pragma once

#include "memdc.h"

// CDialogSkin dialog

class CDialogSkin : public CDialog
{
	DECLARE_DYNAMIC(CDialogSkin)

public:
	CDialogSkin(CWnd* pParent = NULL);   // standard constructor
	CDialogSkin(UINT uResourceID, CWnd* pParent);
	virtual ~CDialogSkin();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	CRect m_rtTop; //Ÿ��Ʋ ��Ʈ
	CRect m_rtLeft; //���� ���� ��Ʈ
	CRect m_rtRight; //������ ���� ��Ʈ
	CRect m_rtBottom; //�ϴ� ���� ��Ʈ

	CBitmap m_frmLeftOfTitle, m_frmCenterOfTitle, m_frmRightOfTitle; //Ÿ��Ʋ�� ���� ��Ʈ�� �̹���
	BITMAP m_bmLeftOfTitle, m_bmCenterOfTitle, m_bmRightOfTitle; //Ÿ��Ʋ�� ���� ��Ʈ�� �̹��� ����

	CBitmap m_frmLeftBorder, m_frmRightBorder; //���� ������ ������ ���� ��Ʈ�� �̹���
	CBitmap m_frmLeftOfBottom, m_frmCenterOfBottom, m_frmRightOfBottom;
	CBitmap frmGrayLeft, frmGrayCen, frmGrayRight;
	CBitmap m_frmGrayLeftBorder, m_frmGrayRightBorder;
	CBitmap frmGrayBottomLeft, frmGrayBottomCen, frmGrayBottomRight;

	//�� �ý��� ��ư ��Ʈ���̹���
	CBitmap m_btnNormal[4];   //0 : Min  1 : Max  2 : Close  3 : Max In Maximize
	CBitmap m_btnActive[4];  //0 : Min  1 : Max  2 : Close  3 : Max In Maximize
	CBitmap m_btnOver[4];    //0 : Min  1 : Max  2 : Close  3 : Max In Maximize
	CBitmap m_btnDisable[4]; //0 : Min  1 : Max  2 : Close  3 : Max In Maximize
	
	//�� �ý��� ��ư ��Ʈ�� ����
	BITMAP bmClose, bmMin, bmMax;
	//�� �ý��� ��ư ��������
	HRGN m_hRgnClose, m_hRgnMin, m_hRgnMax;

	LONG m_WindowStyle; //�������� ��Ÿ����? (�ý��۹�ư ũ����)

	BOOL m_IsUseXPTheme; //������ �׸��� ���°�

	int m_nBorderThickness;
	int m_nCaptionThickness;

public:
	bool m_bActive; //�����찡 ��Ƽ������ΰ�.

	int m_x, m_y;
	unsigned short m_nNcButtonOver; //� �ý��۹�ư���� ���콺�� �ö��ִ°�
	unsigned short m_bBtnActive; //��ý��� ��ư�� ���ȴ°� None  : 0  Min   : 1  Max   : 2   Close : 3

	CString m_szWindowText;
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	afx_msg void OnPaint();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnNcPaint();
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	void SetLoadImage(void);
	void DrawMinMaxCloseButton(CMemDCEx *pMemDC);

protected:
	int GetThemeType(void);
};
