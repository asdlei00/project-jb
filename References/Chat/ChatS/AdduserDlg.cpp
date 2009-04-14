// AdduserDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatS.h"
#include "AdduserDlg.h"


// CAdduserDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CAdduserDlg, CDialog)
CAdduserDlg::CAdduserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdduserDlg::IDD, pParent)
	, m_strId(_T(""))
	, m_strPass(_T(""))
	, m_strName(_T(""))
{
}

CAdduserDlg::~CAdduserDlg()
{
}

void CAdduserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strId);
	DDX_Text(pDX, IDC_EDIT2, m_strPass);
	DDX_Text(pDX, IDC_EDIT3, m_strName);
}


BEGIN_MESSAGE_MAP(CAdduserDlg, CDialog)
END_MESSAGE_MAP()


// CAdduserDlg �޽��� ó�����Դϴ�.

void CAdduserDlg::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	UpdateData(TRUE);

	if(m_strId.IsEmpty() || m_strPass.IsEmpty() || m_strName.IsEmpty())
	{
		AfxMessageBox(_T("�ʿ��� ������ �Է����� �ʾҽ��ϴ�."));
	}
	else if(strlen(m_strId)>20 || strlen(m_strId)<3){
		AfxMessageBox(_T("���̵�� 3�� �̻�, 20�� ���Ϸ� �Է����ֽʽÿ�."));
	}
	else if(strlen(m_strPass)>20 || strlen(m_strPass)<3){
		AfxMessageBox(_T("��й�ȣ�� 3�� �̻�, 20�� ���Ϸ� �Է����ֽʽÿ�."));
	}
	else if(strlen(m_strName)>100){
		AfxMessageBox(_T("��ȭ���� 100�� ���Ϸ� �Է����ֽʽÿ�."));
	}
	else{
		CDialog::OnOK();
	}
}