// AccountDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "M-Server Manager.h"
#include "AccountDlg.h"


// CAccountDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CAccountDlg, CDialogSkin)

CAccountDlg::CAccountDlg(CWnd* pParent /*=NULL*/)
	: CDialogSkin(CAccountDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CAccountDlg::~CAccountDlg()
{
}

void CAccountDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogSkin::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editUserID);
	DDX_Control(pDX, IDC_EDIT2, m_editUserPasswords);
	DDX_Control(pDX, IDC_EDIT3, m_editAccountID);
	DDX_Control(pDX, IDC_EDIT4, m_editPasswords);
	DDX_Control(pDX, IDC_EDIT7, m_editPasswords2);
}


BEGIN_MESSAGE_MAP(CAccountDlg, CDialogSkin)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_SYSCOMMAND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON1, &CAccountDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CAccountDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CAccountDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CAccountDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CAccountDlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT7, &CAccountDlg::OnEnChangeEdit7)
END_MESSAGE_MAP()


// CAccountDlg �޽��� ó�����Դϴ�.

void CAccountDlg::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CDialogSkin::OnPaint()��(��) ȣ������ ���ʽÿ�.

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

BOOL CAccountDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CDialogSkin::OnEraseBkgnd(pDC);
}

BOOL CAccountDlg::OnInitDialog()
{
	CDialogSkin::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CAccountDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialogSkin::OnSysCommand(nID, lParam);
}

HBRUSH CAccountDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
		//m_chkboxRefresh.GetClientRect(rc);

		//pDC->BitBlt(0, 0, rc.right - rc.left, rc.bottom - rc.top, pWnd->GetDC(), rc.left, rc.top, SRCCOPY);
		//HGDIOBJ hBrush = GetStockObject(NULL_BRUSH);

		pDC->SetTextColor(RGB(255, 255, 255));
		//pDC->SetBkColor(RGB(255, 255, 255));

		hbr = (HBRUSH) GetStockObject(NULL_BRUSH);
		SetBkMode(pDC->m_hDC, TRANSPARENT);

		//return (HBRUSH) hBrush;
	}
	else if(nRet == IDC_STATIC_ACCOUNT ||
		    nRet == IDC_STATIC_NEW_ACCOUNT)
	{
		//pDC->SetTextColor(RGB(255, 255, 255));

		//hbr = (HBRUSH) GetStockObject(NULL_BRUSH);
		//SetBkMode(pDC->m_hDC, TRANSPARENT);

		SetTextColor(pDC->m_hDC, RGB(0, 128, 255));
		SetBkMode(pDC->m_hDC, TRANSPARENT);
		//hbr = (HBRUSH) GetStockObject(WHITE_BRUSH);
	}

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}

void CAccountDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	CString strID, strPW;

	m_editUserID.GetWindowTextA(strID);
	m_editUserPasswords.GetWindowTextA(strPW);

	if(strID == "")
	{
		AfxMessageBox("Enter the ID");
		return;
	}

	if(!g_sToolMgr.GetSQLMgr()->IsValidIDFromDB(strID))
	{
		AfxMessageBox("Cannot find ID");
	}
	else
	{
		if(!g_sToolMgr.GetSQLMgr()->IsValidPWFromDB(strID, strPW))
			AfxMessageBox("Incorrect passwords");
		else
		{
			CString strID;
			m_editUserID.GetWindowTextA(strID);

			g_sToolMgr.GetDialogMgr()->m_StatusDlg.OnRun(strID);

			g_sToolMgr.SetUserID(strID.GetBuffer(0));
			g_sToolMgr.SetAccountActived(true);

			g_sToolMgr.SetRun(true);

			OnOK();
		}
	}
}

void CAccountDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogSkin::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	m_editUserID.Invalidate();
}

void CAccountDlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogSkin::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	m_editUserPasswords.Invalidate();
}

void CAccountDlg::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogSkin::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	m_editAccountID.Invalidate();
}

void CAccountDlg::OnEnChangeEdit4()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogSkin::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	m_editPasswords.Invalidate();
}

void CAccountDlg::OnEnChangeEdit7()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogSkin::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	m_editPasswords2.Invalidate();
}
