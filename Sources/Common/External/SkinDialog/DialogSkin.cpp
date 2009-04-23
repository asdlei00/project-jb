// DialogSkin.cpp : implementation file

#include "stdafx.h"
#include "resource.h"
#include "DialogSkin.h"

// CDialogSkin dialog

IMPLEMENT_DYNAMIC(CDialogSkin, CDialog)

CDialogSkin::CDialogSkin(CWnd* pParent /*=NULL*/)
{
	m_szWindowText = _T("");
	m_x = 0;
	m_y = 0;
	m_bBtnActive = 0;
	m_bActive = true;
	m_IsUseXPTheme = false;
	m_nNcButtonOver = 0;

	if(GetThemeType() == 1)
		m_IsUseXPTheme = TRUE;

	SetLoadImage();
}

CDialogSkin::CDialogSkin(UINT uResourceID, CWnd* pParent)
: CDialog(uResourceID, pParent)
{
	m_szWindowText = _T("");
	m_x = 0;
	m_y = 0;
	m_bBtnActive = 0;
	m_bActive = true;
	m_IsUseXPTheme = false;
	m_nNcButtonOver = 0;

	//Theme ��Ÿ��Ȯ��
	if(GetThemeType() == 1)
		m_IsUseXPTheme = TRUE;

	SetLoadImage();
}

CDialogSkin::~CDialogSkin()
{
}

void CDialogSkin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDialogSkin, CDialog)
	ON_WM_PAINT()
	ON_WM_ACTIVATE()
	ON_WM_ERASEBKGND()
	ON_WM_NCPAINT()
	ON_WM_NCACTIVATE()
	ON_WM_SIZE()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CDialogSkin message handlers
void CDialogSkin::OnPaint()
{
	CPaintDC dc(this); // device context for painting
}

BOOL CDialogSkin::OnInitDialog()
{
	CDialog::OnInitDialog();	

	// �������� �ý��� �ڽ��� ǥ������ �ʱ� ���� ������ ��Ÿ���� ������
	ModifyStyle( WS_SYSMENU, 0);	

	// ������ �þ�� �ܸӸ�..
	// �ȱ����̰� �Ϸ���... ������ Ÿ��Ʋ�� �޸𸮿� �־��ٰ�
	// ���� �Ѹ��� �ִ� �� ����� Paint���� �ٽ� ���� �ߴ�.
	GetWindowText(m_szWindowText);
	//SetWindowText(L"");

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDialogSkin::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CDialog::OnActivate(nState, pWndOther, bMinimized);


	switch( nState )
	{
	case WA_INACTIVE:
		m_bActive = false;
		OnNcPaint();
		break;
	case WA_ACTIVE:
	case WA_CLICKACTIVE:
		m_bActive = true;
		OnNcPaint();
		break;
	default:
		OnNcPaint();
		break;
	}
}

void CDialogSkin::SetLoadImage(void)
{
	// Ÿ��Ʋ �� �̹��� �ε�
	// XP �׸� ������ �̸� �̷���.
	if (m_IsUseXPTheme)
	{
		m_frmLeftOfTitle.LoadBitmap(IDB_FRM_TOP_LEFT);
		m_frmCenterOfTitle.LoadBitmap(IDB_FRM_TOP_CEN);
		m_frmRightOfTitle.LoadBitmap(IDB_FRM_TOP_RIGHT);

		frmGrayLeft.LoadBitmap(IDB_FRM_GRAY_TOP_LEFT);
		frmGrayCen.LoadBitmap(IDB_FRM_GRAY_TOP_CEN);
		frmGrayRight.LoadBitmap(IDB_FRM_GRAY_TOP_RIGHT);
		
		//nPlusPos = 3;	// Xp �׸��� �� ���Ƽ�.. �̸�����ߵǾ�.
	}
	else
	{
		m_frmLeftOfTitle.LoadBitmap(IDB_OLDFRM_LEFT);
		m_frmCenterOfTitle.LoadBitmap(IDB_OLDFRM_CEN);
		m_frmRightOfTitle.LoadBitmap(IDB_OLDFRM_RIGHT);

		frmGrayLeft.LoadBitmap(IDB_FRM_GRAY_OLDTOP_LEFT);
		frmGrayCen.LoadBitmap(IDB_FRM_GRAY_OLDTOP_CEN);
		frmGrayRight.LoadBitmap(IDB_FRM_GRAY_OLDTOP_RIGHT);
	}

	m_frmLeftBorder.LoadBitmap(IDB_FRM_RIGHT_BORDER);
	m_frmRightBorder.LoadBitmap(IDB_FRM_RIGHT_BORDER);

	m_frmLeftOfBottom.LoadBitmap(IDB_FRM_BOTTOM_LEFT);
	m_frmCenterOfBottom.LoadBitmap(IDB_FRM_BOTTOM_RIGHT);
	m_frmRightOfBottom.LoadBitmap(IDB_FRM_BOTTOM_RIGHT);

	m_frmLeftOfTitle.GetObject(sizeof(BITMAP), &m_bmLeftOfTitle);
	m_frmCenterOfTitle.GetObject(sizeof(BITMAP), &m_bmCenterOfTitle);
	m_frmRightOfTitle.GetObject(sizeof(BITMAP), &m_bmRightOfTitle);

	m_frmGrayLeftBorder.LoadBitmap(IDB_FRM_GRAY_LEFT_BORDER);
	m_frmGrayRightBorder.LoadBitmap(IDB_FRM_GRAY_RIGHT_BORDER);

	frmGrayBottomLeft.LoadBitmap(IDB_FRM_GRAY_BOTTOM_LEFT);
	frmGrayBottomCen.LoadBitmap(IDB_FRM_GRAY_BOTTOM_CEN);
	frmGrayBottomRight.LoadBitmap(IDB_FRM_GRAY_BOTTOM_RIGHT);

	// ��ư��
	//Max in Maximize
	m_btnNormal[3].LoadBitmap(IDB_FRM_BTN_MAX1);
	m_btnActive[3].LoadBitmap(IDB_FRM_BTN_MAX1_ACTIVE);
	m_btnOver[3].LoadBitmap(IDB_FRM_BTN_MAX1_OVER);
	m_btnDisable[3].LoadBitmap(IDB_FRM_BTN_MAX1_DISABLE);

	m_btnNormal[2].LoadBitmap(IDB_FRM_BTN_CLOSE);
	m_btnActive[2].LoadBitmap(IDB_FRM_BTN_CLOSE_ACTIVE);
	m_btnOver[2].LoadBitmap(IDB_FRM_BTN_CLOSE_OVER);
	m_btnDisable[2].LoadBitmap(IDB_FRM_BTN_CLOSE_DISABLE);

	m_btnNormal[2].GetObject(sizeof(BITMAP), &bmClose);

	m_btnNormal[1].LoadBitmap(IDB_FRM_BTN_MAX);
	m_btnActive[1].LoadBitmap(IDB_FRM_BTN_MAX_ACTIVE);
	m_btnOver[1].LoadBitmap(IDB_FRM_BTN_MAX_OVER);
	m_btnDisable[1].LoadBitmap(IDB_FRM_BTN_MAX_DISABLE);

	m_btnNormal[1].GetObject(sizeof(BITMAP), &bmMax);

	m_btnNormal[0].LoadBitmap(IDB_FRM_BTN_MIN);
	m_btnActive[0].LoadBitmap(IDB_FRM_BTN_MIN_ACTIVE);
	m_btnOver[0].LoadBitmap(IDB_FRM_BTN_MIN_OVER);
	m_btnDisable[0].LoadBitmap(IDB_FRM_BTN_MIN_DISABLE);

	m_btnNormal[1].GetObject(sizeof(BITMAP), &bmMin);
}

void CDialogSkin::DrawMinMaxCloseButton(CMemDCEx *pMemDC = NULL)
{
	if(pMemDC == NULL)
	{
		pMemDC = (CMemDCEx *)GetWindowDC();
	}
	CDC ButtonDC[3];

	ButtonDC[0].CreateCompatibleDC(pMemDC); //Min
	ButtonDC[1].CreateCompatibleDC(pMemDC); //Max
	ButtonDC[2].CreateCompatibleDC(pMemDC); //Close

	int i;


	int x = m_x - bmClose.bmWidth;
	
	if(m_bBtnActive != 0) //��ư�� ����������
	{
		if(((m_bBtnActive - 1) == 1) && (m_WindowStyle & WS_MAXIMIZE)) //��ü ȭ�鿡�� MAX��ư
			ButtonDC[m_bBtnActive - 1].SelectObject(&(m_btnActive[3]));
		else
			ButtonDC[m_bBtnActive - 1].SelectObject(&(m_btnActive[m_bBtnActive - 1]));
	}
	else if(m_nNcButtonOver != 0) //��ư�� ���콺�� �ö�����
	{
		if(((m_nNcButtonOver - 1) == 1) && (m_WindowStyle & WS_MAXIMIZE)) //��ü ȭ�鿡�� MAX��ư
			ButtonDC[m_nNcButtonOver - 1].SelectObject(&(m_btnOver[3]));
		else
			ButtonDC[m_nNcButtonOver - 1].SelectObject(&(m_btnOver[m_nNcButtonOver - 1]));
	}

	for(i = 0; i < 3; i++)
	{
		if((i == m_bBtnActive - 1) || (i == m_nNcButtonOver -1))
			continue;

		if( ((i == 0) && !(m_WindowStyle & WS_MINIMIZEBOX)) || ((i == 1 ) && !(m_WindowStyle & WS_MAXIMIZEBOX)) )
		{
			if((i == 1) && (m_WindowStyle & WS_MAXIMIZE)) //��ü ȭ�鿡�� MAX��ư
				ButtonDC[i].SelectObject(m_btnDisable[3]);
			else
				ButtonDC[i].SelectObject(m_btnDisable[i]);
		}
		else
		{
			if((i == 1) && (m_WindowStyle & WS_MAXIMIZE)) //��ü ȭ�鿡�� MAX��ư
				ButtonDC[i].SelectObject(m_bActive? m_btnNormal[3] : m_btnDisable[3]);
			else
				ButtonDC[i].SelectObject(m_bActive? m_btnNormal[i] : m_btnDisable[i]);
		}
	}

	pMemDC->TransparentBlt(x, m_y + 2, bmClose.bmWidth, bmClose.bmHeight, &(ButtonDC[2]),
		0, 0, bmClose.bmWidth, bmClose.bmHeight, RGB(255, 0, 255));

	if((m_WindowStyle & WS_MAXIMIZEBOX) || (m_WindowStyle & WS_MINIMIZEBOX))
	{
		pMemDC->TransparentBlt(x-2-bmMax.bmWidth, m_y + 2, bmMax.bmWidth, bmMax.bmHeight, &(ButtonDC[1]),
			0, 0, bmMax.bmWidth, bmMax.bmHeight, RGB(255, 0, 255));
		pMemDC->TransparentBlt(x-4-bmMax.bmWidth-bmMin.bmWidth, m_y + 2, bmMin.bmWidth, bmMin.bmHeight, &(ButtonDC[0]),
			0, 0, bmMin.bmWidth, bmMin.bmHeight, RGB(255, 0, 255));
	}	
}

BOOL CDialogSkin::OnEraseBkgnd(CDC* pDC)
{
	CRect rectBackground;
	GetClientRect(rectBackground);
	//GetWindowRect(rectBackground);

	// Default
	//pDC->FillSolidRect(rectBackground, RGB(226, 233, 245));

	// Black Style
	pDC->FillSolidRect(rectBackground, RGB(80, 80, 80));
	
	return true;
}

void CDialogSkin::OnNcPaint()
{
	CDC* pDC = GetWindowDC();

	CDC bitmapDC;
	bitmapDC.CreateCompatibleDC(pDC);

	CMemDCEx mDC(pDC, &m_rtTop);
	CMemDCEx mLeftDC(pDC, &m_rtLeft);
	CMemDCEx mRightDC(pDC, &m_rtRight);
	CMemDCEx mBottomDC(pDC, &m_rtBottom);

	// Active
	if (m_bActive)
	{
		// ���.. Ÿ��Ʋ
		bitmapDC.SelectObject(&m_frmCenterOfTitle); //���
		mDC.StretchBlt(0, 0, m_rtTop.Width(), m_rtTop.Height(), &bitmapDC,
			0, 0, m_bmCenterOfTitle.bmWidth, m_bmCenterOfTitle.bmHeight, SRCCOPY);

		bitmapDC.SelectObject(&m_frmLeftOfTitle); //����
		//mDC.BitBlt(0, m_rtTop.top, m_bmLeftOfTitle.bmWidth, m_bmLeftOfTitle.bmHeight, &bitmapDC, 0, 0, SRCCOPY);
		mDC.StretchBlt(0, 0, m_bmLeftOfTitle.bmWidth, m_rtTop.Height(), &bitmapDC,
			0, 0, m_bmLeftOfTitle.bmWidth, m_bmLeftOfTitle.bmHeight, SRCCOPY);

		bitmapDC.SelectObject(&m_frmRightOfTitle); //������
		//mDC.BitBlt(skinCen + m_bmLeftOfTitle.bmWidth, m_rtTop.top, m_bmRightOfTitle.bmWidth, m_bmRightOfTitle.bmHeight, &bitmapDC, 0, 0, SRCCOPY);
		mDC.StretchBlt(m_rtTop.right - m_bmRightOfTitle.bmWidth, 0, m_bmRightOfTitle.bmWidth, m_rtTop.Height(), &bitmapDC,
			0, 0, m_bmRightOfTitle.bmWidth, m_bmRightOfTitle.bmHeight, SRCCOPY);
		///////////////////////////////////////////////////////////////////////////////////////////////////

		// ���� ����
		bitmapDC.SelectObject(&m_frmLeftBorder);
		mLeftDC.StretchBlt(0, m_rtLeft.top, m_rtLeft.right, m_rtLeft.Height(), &bitmapDC, 0, 0, 3, 1, SRCCOPY);

		// ������ ����
		bitmapDC.SelectObject(&m_frmRightBorder);
		mRightDC.StretchBlt(m_rtRight.left, m_rtRight.top, m_rtRight.Width(), m_rtRight.Height(), &bitmapDC, 0, 0, 3, 1, SRCCOPY);

		// �ϴ� ����
		bitmapDC.SelectObject(&m_frmCenterOfBottom); //�߾�
		mBottomDC.StretchBlt(0, m_rtBottom.top, m_rtBottom.right, m_rtBottom.Height(), &bitmapDC,
			0, 0, 1, 3, SRCCOPY); //�߾�

		bitmapDC.SelectObject(&m_frmLeftOfBottom); //����
		//mBottomDC.BitBlt(0, m_rtBottom.top, 3, 4, &bitmapDC, 0, 0, SRCCOPY); //����
		mBottomDC.StretchBlt(0, m_rtBottom.top, m_rtLeft.right, m_rtBottom.Height(), &bitmapDC,
			0, 0, 3, 3, SRCCOPY);

		bitmapDC.SelectObject(&m_frmRightOfBottom); //������
		//mBottomDC.BitBlt(nBorderLeftGap, nBorderHeight, 3, 3, &bitmapDC, 0, 0, SRCCOPY); //������
		mBottomDC.StretchBlt(m_rtRight.left, m_rtBottom.top, m_rtRight.Width(), m_rtBottom.Height(), &bitmapDC,
			0, 0, 3, 3, SRCCOPY);
	}
	else
	{
		// ���.. Ÿ��Ʋ
		bitmapDC.SelectObject(&frmGrayCen); //���
		mDC.StretchBlt(0, 0, m_rtTop.Width(), m_rtTop.Height(), &bitmapDC,
			0, 0, m_bmCenterOfTitle.bmWidth, m_bmCenterOfTitle.bmHeight, SRCCOPY);

		bitmapDC.SelectObject(&frmGrayLeft); //����
		//mDC.BitBlt(0, m_rtTop.top, m_bmLeftOfTitle.bmWidth, m_bmLeftOfTitle.bmHeight, &bitmapDC, 0, 0, SRCCOPY);
		mDC.StretchBlt(0, 0, m_bmLeftOfTitle.bmWidth, m_rtTop.Height(), &bitmapDC,
			0, 0, m_bmLeftOfTitle.bmWidth, m_bmLeftOfTitle.bmHeight, SRCCOPY);

		bitmapDC.SelectObject(&frmGrayRight); //������
		//mDC.BitBlt(skinCen + m_bmLeftOfTitle.bmWidth, m_rtTop.top, m_bmRightOfTitle.bmWidth, m_bmRightOfTitle.bmHeight, &bitmapDC, 0, 0, SRCCOPY);
		mDC.StretchBlt(m_rtTop.right - m_bmRightOfTitle.bmWidth, 0, m_bmRightOfTitle.bmWidth, m_rtTop.Height(),&bitmapDC,
			0, 0, m_bmRightOfTitle.bmWidth, m_bmRightOfTitle.bmHeight, SRCCOPY);
		//////////////////////////////////////////////////////////////////////////////

		// ���� ����
		bitmapDC.SelectObject(&m_frmGrayLeftBorder);
		mLeftDC.StretchBlt(0, m_rtLeft.top, m_rtLeft.right, m_rtLeft.Height(), &bitmapDC, 0, 0, 3, 1, SRCCOPY);

		// ������ ����
		bitmapDC.SelectObject(&m_frmGrayRightBorder);
		mRightDC.StretchBlt(m_rtRight.left, m_rtRight.top, m_rtRight.Width(), m_rtRight.Height(), &bitmapDC, 0, 0, 3, 1, SRCCOPY);

		// �ϴ� ����
		bitmapDC.SelectObject(&frmGrayBottomLeft); //�߾�
		mBottomDC.StretchBlt(0, m_rtBottom.top, m_rtBottom.right, m_rtBottom.Height(), &bitmapDC,
			0, 0, 1, 3, SRCCOPY); //�߾�

		bitmapDC.SelectObject(&frmGrayBottomLeft); //����
		//mBottomDC.BitBlt(0, nBorderHeight, 3, 3, &bitmapDC, 0, 0, SRCCOPY);
		mBottomDC.StretchBlt(0, m_rtBottom.top, m_rtLeft.right, m_rtBottom.Height(), &bitmapDC,
			0, 0, 3, 3, SRCCOPY);

		bitmapDC.SelectObject(&frmGrayBottomLeft); //������
		//mBottomDC.BitBlt(nBorderLeftGap, nBorderHeight, 3, 3, &bitmapDC, 0, 0, SRCCOPY);
		mBottomDC.StretchBlt(m_rtRight.left, m_rtBottom.top, m_rtRight.Width(), m_rtBottom.Height(), &bitmapDC,
			0, 0, 3, 3, SRCCOPY);
	}

	CFont font;
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	int nPlusPos = 0;

	if (m_IsUseXPTheme == TRUE)
	{
		lf.lfHeight  = 16;
		nPlusPos	+= 3;
	}
	else
	{
		lf.lfHeight = 13;
	}

	lf.lfWeight = FW_BOLD;
	wsprintf(lf.lfFaceName, "Tahoma");
	font.CreateFontIndirect(&lf);
	CFont* def_font = mDC.SelectObject(&font);
	mDC.SetBkMode(TRANSPARENT);
	mDC.SetTextColor(RGB(0, 0, 0));
	mDC.TextOut(15, 5 + nPlusPos, m_szWindowText);	// ����
	mDC.SetTextColor(RGB(255, 255, 255));
	mDC.TextOut(14, 4 + nPlusPos, m_szWindowText);	// ���
	mDC.SelectObject(def_font);
	font.DeleteObject();

	DrawMinMaxCloseButton(&mDC);
}

BOOL CDialogSkin::OnNcActivate(BOOL bActive)
{
	switch( bActive )
	{
	case WA_INACTIVE:
		m_bActive = false;
		OnNcPaint();
		break;
	case WA_ACTIVE:
	case WA_CLICKACTIVE:
		m_bActive = true;
		OnNcPaint();
		break;
	}

	return true;
	//return CDialog::OnNcActivate(bActive);
}

int CDialogSkin::GetThemeType(void)
{
	HKEY openKey;
	wchar_t pszValue[_MAX_PATH];	// ���� ��ȯ�� ���� 		
	DWORD dwType	= REG_SZ;		// ã�°��� TYPE 
	DWORD dwCount	= _MAX_PATH;	// ��ȯ�� ���� ���� 

	// �׸��� ������ ����ִ� Path ��ġ
	CString szRegPath(L"Software\\Microsoft\\Windows\\CurrentVersion\\ThemeManager\\");
	memset(pszValue, 0, sizeof(pszValue));

	RegOpenKey(HKEY_CURRENT_USER, szRegPath, &openKey);
	RegQueryValueEx(openKey, "ThemeActive", 0, &dwType, (LPBYTE)pszValue, &dwCount);
	RegCloseKey(openKey);	

	return _wtoi(pszValue);
}

BOOL CDialogSkin::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	if(	pMsg->message == WM_SYSKEYDOWN && pMsg->wParam == VK_F4 ||
		pMsg->wParam == VK_ESCAPE || 
		pMsg->wParam == VK_RETURN )
	{
		return TRUE;
	}
	else if( pMsg->message == WM_NCLBUTTONDOWN ||	// None Client �������� ���콺 ���� ��ư�� ���� ���� ��
			 pMsg->message == WM_NCMOUSEMOVE ||		// None Client �������� ���콺�� �̵��� ��
			 pMsg->message == WM_LBUTTONUP ||		// None Client ������ �ƴѰ����� ���콺 ���� ��ư�� �������� ���
			 pMsg->message == WM_NCLBUTTONUP ||		// None Client �������� ���콺 ���� ��ư�� �������� ���
			 pMsg->message == WM_NCMOUSELEAVE )		// None Client ������ �ƴѰ����� ���콺�� �̵����� ���
	{

		CRect rtWinRect;
		GetWindowRect(&rtWinRect);

		int x = pMsg->pt.x - rtWinRect.left;
		int y = pMsg->pt.y - rtWinRect.top;

		// �ش� ������ �ö󰡸�
		// None  : 0
		// Min   : 1
		// Max   : 2 
		// Close : 3
		switch( pMsg->message )
		{
		case WM_NCLBUTTONDOWN:
			if (PtInRegion(m_hRgnClose, x + bmClose.bmWidth, y)) //Close
			{
				SetCapture();
				m_bBtnActive = 3;
				DrawMinMaxCloseButton();
				return TRUE;
				//OnCancel();
			}
			else if(PtInRegion(m_hRgnMax, x + bmMax.bmWidth, y) && (m_WindowStyle & WS_MAXIMIZEBOX)) //Max
			{
				SetCapture();
				m_bBtnActive = 2;
				DrawMinMaxCloseButton();
				return TRUE;
			}
			else if(PtInRegion(m_hRgnMin, x + bmMin.bmWidth, y) && (m_WindowStyle & WS_MINIMIZEBOX)) //Min
			{
				SetCapture();
				m_bBtnActive = 1;
				DrawMinMaxCloseButton();
				//OnNcPaint();
				return TRUE;
			}
			else
			{
				m_bBtnActive = 0;
				if(m_WindowStyle & WS_MAXIMIZE)
					return TRUE;
			}
			break;
		case WM_NCMOUSEMOVE :
			if (PtInRegion(m_hRgnClose, x + bmClose.bmWidth, y)) //Close
			{
				if (m_nNcButtonOver != 3)
				{
					m_nNcButtonOver = 3;
					//OnNcPaint();
					DrawMinMaxCloseButton();
				}		
			}	
			else if(PtInRegion(m_hRgnMax, x + bmMax.bmWidth, y) && (m_WindowStyle & WS_MAXIMIZEBOX)) //Max
			{
				if(m_nNcButtonOver != 2)
				{
					m_nNcButtonOver = 2;
					//OnNcPaint();
					DrawMinMaxCloseButton();
				}
			}
			else if(PtInRegion(m_hRgnMin, x + bmMin.bmWidth, y) && (m_WindowStyle & WS_MINIMIZEBOX)) //Min
			{
				if(m_nNcButtonOver != 1)
				{
					m_nNcButtonOver = 1;
					//OnNcPaint();
					DrawMinMaxCloseButton();
				}
			}
			else
			{
				if(m_nNcButtonOver != 0)
				{
					m_nNcButtonOver = 0;
					DrawMinMaxCloseButton();
					//OnNcPaint();
				}
			}
			break;
		case WM_LBUTTONUP:
		case WM_NCLBUTTONUP:
			if(m_bBtnActive != 0)
			{
				ReleaseCapture();
			}

			if (PtInRegion(m_hRgnClose, x + bmClose.bmWidth, y)) //Close
			{
				if(m_bBtnActive == 3)
				{
					PostMessage(WM_CLOSE);
				}
			}
			else if(PtInRegion(m_hRgnMax, x + bmMax.bmWidth, y) && (m_WindowStyle & WS_MAXIMIZEBOX)) //MAX
			{
				if(m_bBtnActive == 2)
				{
					if( IsZoomed() )
						ShowWindow(SW_RESTORE);
					else
						ShowWindow(SW_MAXIMIZE);
				}
			}
			else if(PtInRegion(m_hRgnMin, x + bmMin.bmWidth, y) && (m_WindowStyle & WS_MINIMIZEBOX)) //Min
			{
				if(m_bBtnActive == 1)
				{
					if( IsIconic())
						ShowWindow(SW_RESTORE);
					else
						ShowWindow(SW_MINIMIZE);
				}
			}
			else
			{
				m_nNcButtonOver = 0;
				m_bBtnActive = 0;
				//OnNcPaint();
				DrawMinMaxCloseButton();
			}
			m_bBtnActive = 0;
			break;
		case WM_NCMOUSELEAVE:
			m_nNcButtonOver = 0;
			DrawMinMaxCloseButton();
			//OnNcPaint();
			break;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CDialogSkin::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	//���̾�α��� ��Ÿ���� Ȯ���Ѵ�.
	m_WindowStyle = GetWindowLong(GetSafeHwnd(), GWL_STYLE);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	CRect WindowRect;
	GetWindowRect(&WindowRect);

	//m_rtTop = WindowRect;
	m_rtTop.top		 = 0;
	m_rtTop.left	 = 0;
	m_rtTop.bottom	 = m_nCaptionThickness;
	m_rtTop.right	= WindowRect.right - WindowRect.left;

	m_y = GetSystemMetrics(SM_CYFRAME) + m_IsUseXPTheme?3:0;
	m_x = (WindowRect.right - WindowRect.left) - m_y;

	if((m_WindowStyle & WS_MAXIMIZE))
	{
		m_y += 1;
	}

	int x = m_x;

	// ������ ������� �ƴ��� Ȯ�����ֱ� ���� ���� ����
	m_hRgnClose		= CreateRectRgn(x, m_y + 2, x + bmClose.bmWidth, m_y + bmClose.bmHeight + 2);
	x -= 2 + bmMax.bmWidth;
	m_hRgnMax		= CreateRectRgn(x, m_y + 2, x + bmMax.bmWidth, m_y + bmMax.bmHeight + 2);
	x -= 2 + bmMin.bmWidth;
	m_hRgnMin		= CreateRectRgn(x, m_y + 2, x + bmMin.bmWidth, m_y + bmMin.bmHeight + 2);
	

	int nBorderHeight	= WindowRect.bottom - WindowRect.top - m_nBorderThickness + 2;

	m_rtLeft.SetRect(0, m_rtTop.bottom, m_nBorderThickness, nBorderHeight);
	m_rtRight.SetRect(m_rtTop.right - m_nBorderThickness, m_rtTop.bottom - 3, m_rtTop.right, nBorderHeight);
	m_rtBottom.SetRect(0, nBorderHeight - 2, m_rtTop.right, nBorderHeight + m_nBorderThickness);	
	
	m_bBtnActive = 0;
	m_nNcButtonOver = 0;
}

int CDialogSkin::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	m_WindowStyle = GetWindowLong(GetSafeHwnd(), GWL_STYLE);
	m_nBorderThickness = GetSystemMetrics(SM_CXDLGFRAME);
	if(m_WindowStyle & WS_SIZEBOX)
	{
		m_nBorderThickness += GetSystemMetrics(SM_CXBORDER);
	}
	m_nCaptionThickness = GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYDLGFRAME);// + GetSystemMetrics(SM_CYEDGE);// //m_bmLeftOfTitle.bmHeight+m_rtTop.top;
	if(m_WindowStyle & WS_SIZEBOX)
		m_nCaptionThickness += GetSystemMetrics(SM_CYBORDER);
	return 0;
}
