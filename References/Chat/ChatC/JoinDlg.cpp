// JoinDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatC.h"
#include "JoinDlg.h"
#include ".\joindlg.h"


// CJoinDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CJoinDlg, CDialog)
CJoinDlg::CJoinDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJoinDlg::IDD, pParent)
	, pass(_T(""))
	, id(_T(""))
	, name(_T(""))
	, serverip(_T(""))
{
	CFile file;
	if(file.Open(_T("serverip.conf"), CFile::modeRead))
	{
		CArchive ar(&file, CArchive::load);
		ar >> serverip;
		ar.Close();
	}
	else
	{
		serverip = "127.0.0.1";
	}
}

CJoinDlg::~CJoinDlg()
{
}

void CJoinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, 1006, pass);
	DDX_Text(pDX, 1005, id);
	DDX_Text(pDX, 1007, name);
	DDX_Text(pDX, IDC_EDIT1, serverip);
}


BEGIN_MESSAGE_MAP(CJoinDlg, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CJoinDlg �޽��� ó�����Դϴ�.

void CJoinDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if(id.IsEmpty() || pass.IsEmpty() || name.IsEmpty())
	{
		AfxMessageBox(_T("�ʿ��� ������ �Է����� �ʾҽ��ϴ�."));
	}
	else if(strlen(id)>20 || strlen(id)<3){
		AfxMessageBox(_T("���̵�� 3�� �̻�, 20�� ���Ϸ� �Է����ֽʽÿ�."));
	}
	else if(strlen(pass)>20 || strlen(pass)<3){
		AfxMessageBox(_T("��й�ȣ�� 3�� �̻�, 20�� ���Ϸ� �Է����ֽʽÿ�."));
	}
	else if(strlen(name)>100){
		AfxMessageBox(_T("��ȭ���� 100�� ���Ϸ� �Է����ֽʽÿ�."));
	}
	else{
		CDialog::OnOK();
	}
}
