// AddMylistDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatC.h"
#include "AddMylistDlg.h"
#include ".\addmylistdlg.h"


// CAddMylistDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CAddMylistDlg, CDialog)
CAddMylistDlg::CAddMylistDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddMylistDlg::IDD, pParent)
	, m_strId(_T(""))
{
}

CAddMylistDlg::~CAddMylistDlg()
{
}

void CAddMylistDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strId);
}


BEGIN_MESSAGE_MAP(CAddMylistDlg, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CAddMylistDlg �޽��� ó�����Դϴ�.

void CAddMylistDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	if(strlen(m_strId) < 3)
	{
		AfxMessageBox(_T("�ʿ��� ������ �Է����� �ʾҽ��ϴ�."));
		return;
	}
	OnOK();
}
