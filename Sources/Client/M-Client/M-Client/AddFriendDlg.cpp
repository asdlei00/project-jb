// AddFriendDlg.cpp : implementation file
//

#include "stdafx.h"
#include "M-Client.h"
#include "AddFriendDlg.h"


// CAddFriendDlg dialog

IMPLEMENT_DYNAMIC(CAddFriendDlg, CDialogSkin)

CAddFriendDlg::CAddFriendDlg(CWnd* pParent /*=NULL*/)
	: CDialogSkin(CAddFriendDlg::IDD, pParent)
{

}

CAddFriendDlg::~CAddFriendDlg()
{
}

void CAddFriendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogSkin::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editFriendID);
	DDX_Control(pDX, IDC_EDIT2, m_editMessage);
}


BEGIN_MESSAGE_MAP(CAddFriendDlg, CDialogSkin)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDOK, &CAddFriendDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddFriendDlg::OnBnClickedIDCheck)
	ON_EN_CHANGE(IDC_EDIT1, &CAddFriendDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CAddFriendDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CAddFriendDlg message handlers

BOOL CAddFriendDlg::OnInitDialog()
{
	CDialogSkin::OnInitDialog();

	// TODO:  Add extra initialization here

	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	CString strMessage;

	strMessage.Format("�ȳ��ϼ���. %s �Դϴ�.", g_sToolMgr.GetLoginID());
	m_editMessage.SetWindowTextA(strMessage);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CAddFriendDlg::OnPaint()
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

BOOL CAddFriendDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CDialogSkin::OnEraseBkgnd(pDC);
}

HBRUSH CAddFriendDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void CAddFriendDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	CString strID, strMessage;

	m_editFriendID.GetWindowTextA(strID);
	m_editMessage.GetWindowTextA(strMessage);

	if(strID == "")
	{
		AfxMessageBox("ģ�� ID �� �Է��ϼ���.");

		return;
	}

	if(strMessage == "")
	{
		AfxMessageBox("��û �޽����� �Է��ϼ���.");

		return;
	}

	MSG_Add_Friend_Req(g_sToolMgr.GetLoginID(), strID.GetBuffer(0), strMessage.GetBuffer(0));
}

void CAddFriendDlg::OnBnClickedIDCheck()
{
	// TODO: Add your control notification handler code here
}

void CAddFriendDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogSkin::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	m_editFriendID.Invalidate();
}

void CAddFriendDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogSkin::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	m_editMessage.Invalidate();
}
