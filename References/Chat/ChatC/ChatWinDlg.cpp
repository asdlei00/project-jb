// ChatWinDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatC.h"
#include "ChatWinDlg.h"
#include "ChatCDlg.h"
#include "DataSocket.h"
#include ".\chatwindlg.h"


// CChatWinDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CChatWinDlg, CDialog)
CChatWinDlg::CChatWinDlg(CChatCDlg* pParent /*=NULL*/)
	: CDialog(CChatWinDlg::IDD, pParent)
	, m_strDestid(_T(""))
	, m_strData(_T(""))
	, m_strEdit(_T(""))
{
}

CChatWinDlg::~CChatWinDlg()
{
}

void CChatWinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ctrlEdit);
	DDX_Control(pDX, IDC_EDIT2, m_ctrlEdit2);
	DDX_Control(pDX, ID_CHATDATA, m_ctrlData);
	DDX_Text(pDX, IDC_EDIT1, m_strEdit);
	DDX_Text(pDX, IDC_EDIT2, m_strEdit2);
}


BEGIN_MESSAGE_MAP(CChatWinDlg, CDialog)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_BN_CLICKED(ID_SEND, OnSend)
END_MESSAGE_MAP()


// CChatWinDlg �޽��� ó�����Դϴ�.

void CChatWinDlg::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// ��޸��� ��ȭ���� �ݱ�
	DestroyWindow();
}

void CChatWinDlg::PostNcDestroy()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	// �������� �Ҵ� ���� �޸� ����

	((CChatCDlg *)AfxGetMainWnd()) -> ChatWinDestroy(this);
	delete this;

	CDialog::PostNcDestroy();
}


void CChatWinDlg::OnSend()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	// �Է� ������ �ִ��� Ȯ��
	if(m_strEdit == "") return;

	// ������ �޽��� ����
	((CChatCDlg *)AfxGetMainWnd()) -> Send_MESSAGE(m_strDestid, m_strEdit);

	// �ڽ��� â�� ǥ��
	ViewMessage(m_strName, m_strEdit);

	// ����Ʈ�ڽ��ʱ�ȭ
	m_strEdit = "";
	UpdateData(FALSE);

	// ����Ʈ�ڽ��� ��Ŀ��
	m_ctrlEdit.SetFocus();
}

void CChatWinDlg::ViewMessage(CString name, CString message)
{
	// ��ġ�� �� �Ʒ���.
	int n = m_ctrlData.GetWindowTextLength();
	m_ctrlData.SetSel(n,n);

	// ���
	CString str; str.Format("��* %s ..���� �� :", name); 
	m_ctrlData.ReplaceSel(str);
	m_ctrlData.ReplaceSel("\r\n"); // ����
	m_ctrlData.ReplaceSel(message);
	m_ctrlData.ReplaceSel("\r\n"); // ����
	UpdateData(FALSE);

	// ��ġ�� �� �Ʒ���.
	n = m_ctrlData.GetWindowTextLength();
	m_ctrlData.SetSel(n,n);
}
