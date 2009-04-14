// ConnectDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatC.h"
#include "ConnectDlg.h"
#include ".\connectdlg.h"


// CConnectDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CConnectDlg, CDialog)
CConnectDlg::CConnectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConnectDlg::IDD, pParent)
	, m_strId(_T(""))
	, m_strPass(_T(""))
	, m_strServerIP(_T(""))
{
	CFile file;
	if(file.Open(_T("serverip.conf"), CFile::modeRead))
	{
		CArchive ar(&file, CArchive::load);
		ar >> m_strServerIP;
		ar.Close();
	}
	else
	{
		m_strServerIP = "127.0.0.1";
	}
}
CConnectDlg::~CConnectDlg()
{
	CFile file;
	if(file.Open(_T("serverip.dat"), CFile::modeCreate | CFile::modeWrite))
	{
		CArchive ar(&file, CArchive::store);
		ar << m_strServerIP;
		ar.Close();
	}
}

void CConnectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strServerIP);
	DDX_Text(pDX, IDC_EDIT2, m_strId);
	DDX_Text(pDX, IDC_EDIT3, m_strPass);
}


BEGIN_MESSAGE_MAP(CConnectDlg, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CConnectDlg �޽��� ó�����Դϴ�.

void CConnectDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	if(strlen(m_strId) < 3 || strlen(m_strId) > 20 || strlen(m_strPass) < 3 || m_strServerIP == "")
	{
		AfxMessageBox(_T("�ٽ� �Է��� �ֽʽÿ�"));
		return;
	}
	OnOK();
}
