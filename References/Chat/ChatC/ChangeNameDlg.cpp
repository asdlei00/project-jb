// ChangeNameDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatC.h"
#include "ChangeNameDlg.h"


// CChangeNameDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CChangeNameDlg, CDialog)
CChangeNameDlg::CChangeNameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeNameDlg::IDD, pParent)
	, m_strName(_T(""))
{
}

CChangeNameDlg::~CChangeNameDlg()
{
}

void CChangeNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strName);
}


BEGIN_MESSAGE_MAP(CChangeNameDlg, CDialog)
END_MESSAGE_MAP()


// CChangeNameDlg �޽��� ó�����Դϴ�.
