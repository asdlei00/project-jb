// ReqAddFriendDlg.cpp : implementation file
//

#include "stdafx.h"
#include "M-Client.h"
#include "ReqAddFriendDlg.h"


// CReqAddFriendDlg dialog

IMPLEMENT_DYNAMIC(CReqAddFriendDlg, CDialogSkin)

CReqAddFriendDlg::CReqAddFriendDlg(CWnd* pParent /*=NULL*/)
	: CDialogSkin(CReqAddFriendDlg::IDD, pParent)
{

}

CReqAddFriendDlg::~CReqAddFriendDlg()
{
}

void CReqAddFriendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogSkin::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_editMessage);
	DDX_Control(pDX, IDOK, m_btnAccept);
	DDX_Control(pDX, IDCANCEL, m_btnDeny);
	DDX_Control(pDX, IDC_BUTTON1, m_btnLater);
}


BEGIN_MESSAGE_MAP(CReqAddFriendDlg, CDialogSkin)
	ON_BN_CLICKED(IDOK, &CReqAddFriendDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CReqAddFriendDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CReqAddFriendDlg::OnBnClickedLater)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CReqAddFriendDlg message handlers

void CReqAddFriendDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CReqAddFriendDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CReqAddFriendDlg::OnBnClickedLater()
{
	// TODO: Add your control notification handler code here
}

BOOL CReqAddFriendDlg::OnInitDialog()
{
	CDialogSkin::OnInitDialog();

	// TODO:  Add extra initialization here

	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CReqAddFriendDlg::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogSkin::OnPaint() for painting messages

	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogSkin::OnPaint();
	}
}

BOOL CReqAddFriendDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CDialogSkin::OnEraseBkgnd(pDC);
}

HBRUSH CReqAddFriendDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	/*HBRUSH hbr = CDialogSkin::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;*/

	pDC->SetBkMode(TRANSPARENT); 

	HBRUSH hbr = CDialogSkin::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here

	int nRet = pWnd->GetDlgCtrlID();

	if(nRet == IDC_STATIC)
	{
		CRect rc;

		pDC->SetTextColor(RGB(255, 255, 255));

		hbr = (HBRUSH) GetStockObject(NULL_BRUSH);
		SetBkMode(pDC->m_hDC, TRANSPARENT);
	}

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}