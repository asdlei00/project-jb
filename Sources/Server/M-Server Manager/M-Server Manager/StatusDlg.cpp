// StatusDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "M-Server Manager.h"
#include "StatusDlg.h"


// CStatusDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CStatusDlg, CDialog)

CStatusDlg::CStatusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStatusDlg::IDD, pParent)
{

}

CStatusDlg::~CStatusDlg()
{
}

void CStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editStatus);
	DDX_Control(pDX, IDC_EDIT2, m_editLoginID);
	DDX_Control(pDX, IDC_EDIT3, m_editLoginTime);
}


BEGIN_MESSAGE_MAP(CStatusDlg, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &CStatusDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CStatusDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CStatusDlg::OnEnChangeEdit3)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CStatusDlg �޽��� ó�����Դϴ�.

void CStatusDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CStatusDlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CStatusDlg::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

BOOL CStatusDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_editStatus.SetWindowTextA("Server is not running...");

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CStatusDlg::OnRun(CString strID)
{
	CTime Time;

	Time = CTime::GetCurrentTime();

	CString strTime;

	strTime.Format("%d�� %d�� %d�� - %d�� : %d�� : %d��", Time.GetYear(), Time.GetMonth(), Time.GetDay(), Time.GetHour(), Time.GetMinute(), Time.GetSecond());

	m_editStatus.SetWindowTextA("Server is running...");
	m_editLoginID.SetWindowTextA(strID);
	m_editLoginTime.SetWindowTextA(strTime);

	CString strLog;

	strLog.Format("%s is just loged in...", strID);
	g_sToolMgr.GetLog()->AddLog(LOG_TYPE_TOOLWORK, strLog);
}

HBRUSH CStatusDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.

	int nRet = pWnd->GetDlgCtrlID();

	if(nRet == IDC_STATIC)
	{
		pDC->SetTextColor(RGB(255, 255, 255));

		hbr = (HBRUSH) GetStockObject(NULL_BRUSH);
		SetBkMode(pDC->m_hDC, TRANSPARENT);
	}
	else if(nRet == IDC_STATIC_SERVER_STATUS)
	{
		SetTextColor(pDC->m_hDC, RGB(0, 128, 255));
		pDC->SetBkColor(RGB(255, 255, 255));
		//SetBkMode(pDC->m_hDC, TRANSPARENT);
		//hbr = (HBRUSH) GetStockObject(WHITE_BRUSH);
	}

	return hbr;
}

BOOL CStatusDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CRect rt;
	GetClientRect(rt);

	pDC->FillSolidRect(rt, RGB(80, 80, 80));
	
	return true;

	//return CDialog::OnEraseBkgnd(pDC);
}
