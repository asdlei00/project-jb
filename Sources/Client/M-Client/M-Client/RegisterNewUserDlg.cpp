// RegisterNewUserDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "M-Client.h"
#include "RegisterNewUserDlg.h"


// CRegisterNewUserDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRegisterNewUserDlg, CDialog)

CRegisterNewUserDlg::CRegisterNewUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegisterNewUserDlg::IDD, pParent)
{

}

CRegisterNewUserDlg::~CRegisterNewUserDlg()
{
}

void CRegisterNewUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editID);
	DDX_Control(pDX, IDC_EDIT2, m_editPasswords);
	DDX_Control(pDX, IDC_EDIT3, m_editPasswords2);
}


BEGIN_MESSAGE_MAP(CRegisterNewUserDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CRegisterNewUserDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CRegisterNewUserDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CRegisterNewUserDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &CRegisterNewUserDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CRegisterNewUserDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CRegisterNewUserDlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CRegisterNewUserDlg �޽��� ó�����Դϴ�.

void CRegisterNewUserDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	// Check ID

	CString strID;
	m_editID.GetWindowTextA(strID);

	if(strID == "") 
	{
		AfxMessageBox("ID �� �Է��Ͻʽÿ�.");
		return;
	}

	MSG_ID_Check_Req(strID.GetBuffer(0));

	//m_bCheckID = true;
}

void CRegisterNewUserDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	// ���� �߰�

	if(!g_sToolMgr.m_bConnected) return;
	
	if(!m_bCheckID)
	{
		AfxMessageBox("ID üũ�� �Ͻʽÿ�.");
		return;
	}

	CString strID;
	CString strPW1, strPW2;

	m_editID.GetWindowTextA(strID);
	m_editPasswords.GetWindowTextA(strPW1);
	m_editPasswords2.GetWindowTextA(strPW2);

	if(strPW1 == "")
	{
		AfxMessageBox("��й�ȣ�� �Է��ϼ���.");
		return;
	}

	if(strPW1 != strPW2)
	{
		AfxMessageBox("��й�ȣ�� ���� �ʽ��ϴ�.");
		return;
	}

	MSG_Add_ID_Req(strID.GetBuffer(0), strPW1.GetBuffer(0));

	OnOK();
}

void CRegisterNewUserDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CRegisterNewUserDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	m_bCheckID = false;
	m_editID.Invalidate();
}

void CRegisterNewUserDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	m_editPasswords.Invalidate();
}

void CRegisterNewUserDlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	m_editPasswords2.Invalidate();
}

BOOL CRegisterNewUserDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	m_bCheckID = false;
	m_editPasswords.SetLimitText(MAX_PASSWORD_SIZE);
	m_editPasswords2.SetLimitText(MAX_PASSWORD_SIZE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
