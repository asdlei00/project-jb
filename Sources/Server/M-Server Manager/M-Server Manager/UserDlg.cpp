// UserDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "M-Server Manager.h"
#include "UserDlg.h"


// CUserDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CUserDlg, CDialog)

CUserDlg::CUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserDlg::IDD, pParent)
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserDlg, CDialog)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CUserDlg �޽��� ó�����Դϴ�.

BOOL CUserDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CDialog::OnEraseBkgnd(pDC);
}
