// LogDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "M-Server Manager.h"
#include "LogDlg.h"


// CLogDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CLogDlg, CDialog)

CLogDlg::CLogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLogDlg::IDD, pParent)
{

}

CLogDlg::~CLogDlg()
{
}

void CLogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrlLog);
}


BEGIN_MESSAGE_MAP(CLogDlg, CDialog)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CLogDlg �޽��� ó�����Դϴ�.

void CLogDlg::Init()
{
	m_listctrlLog.m_bColor = true;

	m_listctrlLog.InsertColumn(0, "Time", LVCFMT_CENTER, 150);
	m_listctrlLog.InsertColumn(1, "Type", LVCFMT_CENTER, 150);
	m_listctrlLog.InsertColumn(2, "Context", LVCFMT_CENTER, 700);
}

void CLogDlg::AddList(int nIndex, char* pszTime, char* pszType, char* pszContext)
{
	m_listctrlLog.SetRedraw(FALSE);

	DelList(nIndex);

	if(nIndex < 0 || nIndex > m_listctrlLog.GetItemCount()) return;

	m_listctrlLog.InsertItem(nIndex, pszTime, 0);

	m_listctrlLog.SetItemText(nIndex, 1, pszType);
	m_listctrlLog.SetItemText(nIndex, 2, pszContext);

	m_listctrlLog.SetRedraw(TRUE);
	m_listctrlLog.Invalidate();
}

void CLogDlg::DelList(int nIndex)
{
	if(nIndex < 0 || nIndex > m_listctrlLog.GetItemCount()) return;

	m_listctrlLog.DeleteItem(nIndex);

	m_listctrlLog.SetRedraw(TRUE);
	m_listctrlLog.Invalidate();
}

void CLogDlg::ClearList()
{
	m_listctrlLog.DeleteAllItems();
}

BOOL CLogDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

BOOL CLogDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CDialog::OnEraseBkgnd(pDC);
}
