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
	DDX_Control(pDX, IDC_LIST1, m_listctrlUser);
	DDX_Control(pDX, IDC_EDIT1, m_editUserCount);
}


BEGIN_MESSAGE_MAP(CUserDlg, CDialog)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CUserDlg �޽��� ó�����Դϴ�.

BOOL CUserDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CRect rt;
	GetClientRect(rt);

	pDC->FillSolidRect(rt, RGB(80, 80, 80));
	
	return true;
}

void CUserDlg::Init()
{
	m_listctrlUser.m_bColor = true;

	m_listctrlUser.InsertColumn(0, "ID", LVCFMT_CENTER, 100);
	m_listctrlUser.InsertColumn(1, "Nick", LVCFMT_CENTER, 300);
	m_listctrlUser.InsertColumn(2, "State", LVCFMT_CENTER, 150);

	SetUserCount(0);
}

void CUserDlg::AddList(char* pszID, char* pszNick, char* pszState)
{
	int nIndex = m_listctrlUser.GetItemCount();

	m_listctrlUser.SetRedraw(FALSE);

	DelList(pszID);

	//if(nIndex < 0 || nIndex > m_listctrlUser.GetItemCount()) return;

	m_listctrlUser.InsertItem(nIndex, pszID, 0);

	m_listctrlUser.SetItemText(nIndex, 1, pszNick);
	m_listctrlUser.SetItemText(nIndex, 2, pszState);

	m_listctrlUser.SetRedraw(TRUE);
	m_listctrlUser.Invalidate();
}

void CUserDlg::DelList(char* pszID)
{
	int nSize = m_listctrlUser.GetItemCount();

	for(int i = 0; i < nSize; i++)
	{
		char szItem[256];

		m_listctrlUser.GetItemText(i, 0, szItem, 256);

		if(strcmp(pszID, szItem) == 0)
		{
			m_listctrlUser.DeleteItem(i);

			m_listctrlUser.SetRedraw(TRUE);
			m_listctrlUser.Invalidate();
	
			return;
		}
	}
}

void CUserDlg::UpdateList(char* pszID, char* pszNick, char* pszState)
{
	int nSize = m_listctrlUser.GetItemCount();

	for(int i = 0; i < nSize; i++)
	{
		char szItem[256];

		m_listctrlUser.GetItemText(i, 0, szItem, 256);

		if(strcmp(pszID, szItem) == 0)
		{
			m_listctrlUser.SetItemText(i, 1, pszNick);
			m_listctrlUser.SetItemText(i, 2, pszState);

			m_listctrlUser.SetRedraw(TRUE);
			m_listctrlUser.Invalidate();
	
			return;
		}
	}
}

void CUserDlg::ClearList()
{
	m_listctrlUser.DeleteAllItems();
}

void CUserDlg::SetUserCount(int nIndex)
{
	CString strCount;

	strCount.Format("%d", nIndex);
	m_editUserCount.SetWindowTextA(strCount);
}

BOOL CUserDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

HBRUSH CUserDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	pDC->SetBkMode(TRANSPARENT); 

	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here

	int nRet = pWnd->GetDlgCtrlID();

	if(nRet == IDC_STATIC)
	{
		CRect rc;

		pDC->SetTextColor(RGB(255, 255, 255));

		hbr = (HBRUSH) GetStockObject(NULL_BRUSH);
		SetBkMode(pDC->m_hDC, TRANSPARENT);

		//return (HBRUSH) hBrush;
	}

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}
