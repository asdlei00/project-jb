// ChatCDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ChatC.h"
#include "ChatCDlg.h"
#include "Connectdlg.h"
#include "Data.h"
#include "flag.h"
#include "ChangeNameDlg.h"
#include "AddMylistDlg.h"
#include "joindlg.h"
#include "ChatWinDlg.h"
#include "AboutDlg.h"
#include ".\chatcdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChatCDlg ��ȭ ����



CChatCDlg::CChatCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatCDlg::IDD, pParent)
	, m_strEdit1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, ID_CHANGENAME, m_ctrlChangename);
	DDX_Control(pDX, ID_CONNECT, m_ctrlConnect);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList1);
	DDX_Control(pDX, IDC_EDIT1, m_ctrlEdit1);
	DDX_Text(pDX, IDC_EDIT1, m_strEdit1);
	DDX_Control(pDX, ID_ADDMYLIST, m_ctrlAddmylist);
	DDX_Control(pDX, ID_JOIN, m_ctrlJoin);
	DDX_Control(pDX, ID_DELMYLIST, m_ctrlDelmylist);
}

BEGIN_MESSAGE_MAP(CChatCDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(ID_CONNECT, OnConnect)
	ON_BN_CLICKED(ID_CHANGENAME, OnChangename)
	ON_BN_CLICKED(ID_ADDMYLIST, OnAddmylist)
	ON_BN_CLICKED(ID_JOIN, OnJoin)
	ON_BN_CLICKED(ID_LOGOUT, OnLogout)
	ON_BN_CLICKED(ID_DELMYLIST, OnDelmylist)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnNMDblclkList1)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CChatCDlg �޽��� ó����

BOOL CChatCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	// �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, FALSE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, TRUE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	InitLogout();

	m_ctrlList1.InsertColumn(0,_T("���̵�"),LVCFMT_LEFT,60);
	m_ctrlList1.InsertColumn(1,_T("��ȭ��"),LVCFMT_LEFT,99);
	m_ctrlList1.InsertColumn(2,_T("����"),LVCFMT_LEFT,60);
	m_ctrlList1.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_pDataSocket = new CDataSocket(this);

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸����� 
// �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
// �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CChatCDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�. 
HCURSOR CChatCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CChatCDlg::OnConnect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	// ���� ip ���̵� ����� �Է��ϴ� ��ȭ����
	CConnectDlg dlg;
	if(dlg.DoModal() != IDOK) return;

	// Ŭ���̾�Ʈ ���� ����
	if(!m_pDataSocket->Create())
	{
		AfxMessageBox(_T("Ŭ���̾�Ʈ ���� ���� ����"));
		return;
	}

	// ������ ���� ��û
	if(!m_pDataSocket->Connect(dlg.m_strServerIP, 3666)) // ���������ǿ� ��Ʈ��ȣ
	{
		AfxMessageBox(_T("������ ã�� �� �����ϴ�."));
		m_pDataSocket->Close();
		return;
	}

	// Ŭ���̾�Ʈ ���� �ʱ�ȭ
	m_pDataSocket->Init(this);

	// ID�� ��й�ȣ Ȯ��
	Send_LOGIN(dlg.m_strId,dlg.m_strPass);
}

void CChatCDlg::OnChangename()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CChangeNameDlg dlg;

	if(dlg.DoModal() != IDOK) return;

	// ȭ�鿡 ��ȭ�� ����
	m_strName = dlg.m_strName;
	CString str; str.Format(_T("%s - %s"), m_strId, m_strName);
	m_strEdit1 = str;
	UpdateData(FALSE);

	// �������� ����
	Send_MOD_NAME(dlg.m_strName);
}

void CChatCDlg::OnAddmylist()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CAddMylistDlg dlg;

	if(dlg.DoModal() != IDOK) return;

	// ����Ʈ �߰� ������ ����
	if(m_mylistnum < 100)
	{
		Send_ADD_MYLIST(dlg.m_strId);
	}
	else
	{
		AfxMessageBox(_T("��ȭ��� ����� �� ���� �� �̻� �߰��� �� �����ϴ�."));
	}
}

void CChatCDlg::OnReceive(CDataSocket *pDataSocket)
{
	// ��� ���ۿ� �ִ� �����͸� ���� ������ ������ �ݺ�
	do {
		CString str;
		CData data;
		*pDataSocket >> data; //������ ����

		//���ŵ� ������ ǥ��
		///////////////////////////
		switch(data.m_flag){
		case D_LOGIN_RESULT :
			///////// �α��� ��û ���
			Receive_LOGIN_RESULT(&data);
			break;

		case D_LOGIN_MEMBER :
			///////// ��ȭ��� �α��� �˸�
			Receive_LOGIN_MEMBER(data.m_strId, data.m_strName);
			break;

		case D_LOGOUT_MEMBER :
			///////// ��ȭ��� �α׾ƿ� �˸�
			Receive_LOGOUT_MEMBER(data.m_strId);
			break;

		case D_MOD_NAME :
			///////// ��ȭ��� ��ȭ�� ����
			Receive_LOGIN_MEMBER(data.m_strId, data.m_strName);
			break;

		case D_MESSAGE :
			///////// ��ȭ �޽��� ����
			Receive_MESSAGE(data.m_strId, data.m_strName, data.m_strData);
			break;

		case D_ADD_MYLIST :
			if(data.m_result){
				// ��ȭ����߰��� �������� ���..
				Receive_ADD_MYLIST(data.m_strId);}
			else { AfxMessageBox(_T("��ȭ��� �߰��� ���� ���߽��ϴ�")); }
			break;

		case D_LOGOUT :
			///////// ���� �α׾ƿ�
			str.Format(_T("�ٸ� ������ �α��� �Ͽ����Ƿ� �α׾ƿ� �˴ϴ�."));
			AfxMessageBox(str);
			OnDisconnectClient(pDataSocket);
			break;

		case D_JOIN_RESULT :
			///////// ȸ�� ���� ��û ���
			if(data.m_result)
			{
				str.Format(_T("%s : ȸ�� ���Կ� �����߽��ϴ�."),data.m_strId);
				AfxMessageBox(str);
			}
			else
			{
				str.Format(_T("%s : ȸ�� ���Կ� �����߽��ϴ�.\n�̹� �����ϴ� ���̵��Դϴ�."),data.m_strId);
				AfxMessageBox(str);
			}

			break;

		case D_MESSAGE_FAIL :
			AfxMessageBox(_T("�޽��� ���� ����"));
			break;

		default :
			AfxMessageBox(_T("�� �� ���� �����͸� �����߽��ϴ�."));
			break;
		}
	} while(!(*pDataSocket).m_pArIn->IsBufferEmpty());
}

void CChatCDlg::OnDisconnectClient(CDataSocket* pDataSocket)
{
	m_pDataSocket->Close();

	InitLogout();
}

void CChatCDlg::Send_LOGIN(CString id, CString pass)
{
	CData data;
	data.SetLogindata(D_LOGIN, id, pass);

	*m_pDataSocket << data;
}

void CChatCDlg::Receive_LOGIN_RESULT(CData * pData)
{
	if(pData->m_result) 
	{
		// �α��� ����

		for(int i=0;i<100;i++)
		{
			m_pDlg[i] = NULL;
			m_mylistonline[i]=false;
		}

		// ��ư,��� Ȱ��ȭ
		InitLogin();

		// �ڱ� ���̵�, �̸� ����
		m_strId = pData->m_strId;
		m_strName = pData->m_strName;

		// ȭ�鿡 �ڱ� ��ȭ�� ǥ��
		CString str; str.Format(_T("%s - %s"), m_strId, m_strName);
		m_strEdit1 = str;
		UpdateData(FALSE);

		// ��� ��� ����Ʈ ���̱�
		m_mylistnum = pData->m_mylistnum;
		for(int i=0;i<m_mylistnum;i++){
			m_mylist[i] = pData->m_mylist[i]; // ����Ʈ�� ����..
			m_ctrlList1.InsertItem(i, pData->m_mylist[i]);
			m_ctrlList1.SetItemText(i, 1, "");
			m_ctrlList1.SetItemText(i, 2, _T("��������"));
		}
	}
	else
	{
		// �α��� ����
		AfxMessageBox(_T("�α��� ����"));
		m_pDataSocket->Close();
	}
}

void CChatCDlg::Receive_MESSAGE(CString id, CString name, CString message)
{
	// �ε��� ����
	int nSel=-1;
	for(int i=0;i<m_mylistnum;i++)
	{
		if(m_mylist[i] == id)
		{
			nSel = i;
			break;
		}
	}

	//////// ������ �� ����Ʈ�� ���� ���
	if(nSel==-1)
	{
		CString str;
		// ��ȭ��밡 �� á�� ���� ��ȭ��� ����� ���� �ʰ� �׳� �����ش�..
		if(m_mylistnum>=100)
		{
			str.Format(_T("%s ...���� ��:\n%s"),id,message);
			AfxMessageBox(str);
			return;
		}

		str.Format(_T("%s �κ��� �޽����� �����߽��ϴ�.\n��ȭ ���� ����Ͻðڽ��ϱ�?"), id);
		if(AfxMessageBox(str,MB_YESNO) != IDYES)
		{
			// ��ȭ���� ������� �ʾ��� ���.. �޽����� �ܼ��� �����ش�.
			str.Format(_T("%s ...���� ��:\n%s"),id,message);
			AfxMessageBox(str);
			return;
		}

		/// ������ ��ȭ��� �߰� ����..
		Send_ADD_MYLIST(id);

		// �ӽ÷� ��ȭâ ����;
		nSel = m_mylistnum;
		m_mylist[nSel] = id;
		m_mylistonline[nSel] = true;
		m_pDlg[nSel] = NULL;
	}

	/////// â ����..
	CreateChatWin(nSel);

	// ȭ�鿡 �޽��� �Ѹ�..
	m_pDlg[nSel]->ViewMessage(name,message);

	// ��Ŀ��
	m_pDlg[nSel]->SetFocus();
}

void CChatCDlg::Send_MESSAGE(CString dest_id, CString message)
{
	CData data;
	data.Setdata(D_MESSAGE, true, m_strId, m_strName, message, dest_id);
	*m_pDataSocket << data;
}

void CChatCDlg::Send_MOD_NAME(CString name)
{
	CData data;
	data.Setdata(D_MOD_NAME , true , m_strId, name);
	*m_pDataSocket << data;
}


void CChatCDlg::Send_ADD_MYLIST(CString dest_id)
{
	CData data;
	data.Setdata(D_ADD_MYLIST, true, m_strId, "" , "" , dest_id);
	*m_pDataSocket << data;
}

void CChatCDlg::Send_DEL_MYLIST(CString dest_id)
{
	CData data;
	data.Setdata(D_DEL_MYLIST, true, m_strId, "" , "" , dest_id);
	*m_pDataSocket << data;
}

void CChatCDlg::Receive_ADD_MYLIST(CString id)
{
	// ȸ���߰��� �������� ���..

	// ����Ʈ�� �߰�
	m_mylist[m_mylistnum] = id;

	// ȭ�鿡 ǥ��
	m_ctrlList1.InsertItem(m_mylistnum, id);
	m_ctrlList1.SetItemText(m_mylistnum, 1, "");
	m_ctrlList1.SetItemText(m_mylistnum, 2, _T("��������"));

	m_mylistnum++; // �ε��� ����..
}

void CChatCDlg::OnChatting()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CChatCDlg::Receive_LOGIN_MEMBER(CString id, CString name)
{
	int nSel=0;
	// �ε��� ã��
	
	for(int i=0;i<m_mylistnum;i++){
		if(m_mylist[i] == id)
		{
			nSel = i;
			m_mylistonline[nSel]=true;
			// ȭ�鿡 ǥ��
			m_ctrlList1.SetItemText(nSel, 1, name);
			m_ctrlList1.SetItemText(nSel, 2, _T("�¶���"));
			break;
		}
	}
}

void CChatCDlg::Receive_LOGOUT_MEMBER(CString id)
{
	int nSel=0;
	// �ε��� ã��
	for(int i=0;i<m_mylistnum;i++){
		if(m_mylist[i] == id)
		{
			nSel=i;
			m_mylistonline[nSel]=false;
			// ȭ�鿡 ǥ��
			m_ctrlList1.SetItemText(nSel, 1, "");
			m_ctrlList1.SetItemText(nSel, 2, _T("��������"));
			
			// ��ȭâ�� �������� ��� ��ȭâ ��Ȱ��ȭ
			if(m_pDlg[nSel] != NULL) m_pDlg[nSel]->m_ctrlEdit.EnableWindow(FALSE);
			break;
		}
	}
}

void CChatCDlg::OnLogout()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(AfxMessageBox(_T("�α׾ƿ� �Ͻðڽ��ϱ�?"),MB_YESNO) == IDYES)
	{
		OnDisconnectClient(m_pDataSocket);
	}
}

void CChatCDlg::OnJoin()// ȸ������
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CJoinDlg dlg;

	if(dlg.DoModal() != IDOK) return;

	Send_JOIN_MEMBER(dlg.id, dlg.pass, dlg.name, dlg.serverip);
}

void CChatCDlg::OnDelmylist()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	POSITION pos = m_ctrlList1.GetFirstSelectedItemPosition();

	if(!pos)
	{
		AfxMessageBox(_T("������ ���̵� �������ֽʽÿ�."));
	}
	else 
	{
		UpdateData(TRUE);
		
		int nSel = m_ctrlList1.GetNextSelectedItem(pos);
		CString id = m_mylist[nSel];

		CString str; str.Format(_T("%s - ���� �����Ͻðڽ��ϱ�?"), id);
		if(AfxMessageBox(str,MB_YESNO) == IDYES)
		{
			// �����۾� (����)
			Send_DEL_MYLIST(id);

			// ����Ʈ���� ����
			for(int i=nSel;i<m_mylistnum-1;i++)
			{
				m_mylist[i] = m_mylist[i+1];
			}
			m_mylistnum--;

			// ȭ�鿡�� ����
			while(pos = m_ctrlList1.GetFirstSelectedItemPosition()){
				int nSelItem = m_ctrlList1.GetNextSelectedItem(pos);
				m_ctrlList1.DeleteItem(nSelItem);
			}
		}
	}
}

void CChatCDlg::InitLogin(void)
{
	//// �α��� ������ ���� ȭ��
	// �޴� ����
	CMenu *pMenu = GetMenu();
	pMenu->EnableMenuItem(ID_LOGOUT,FALSE);
	pMenu->EnableMenuItem(ID_CHANGENAME,FALSE);
	pMenu->EnableMenuItem(ID_ADDMYLIST,FALSE);
	pMenu->EnableMenuItem(ID_CONNECT,TRUE);
	pMenu->EnableMenuItem(ID_JOIN,TRUE);

	// ��ư,��� ����
	m_ctrlConnect.ShowWindow(FALSE);
	m_ctrlJoin.ShowWindow(FALSE);
	m_ctrlChangename.ShowWindow(TRUE);
	m_ctrlAddmylist.ShowWindow(TRUE);
	m_ctrlDelmylist.ShowWindow(TRUE);
	m_ctrlList1.ShowWindow(TRUE);
	m_ctrlEdit1.ShowWindow(TRUE);
}

void CChatCDlg::InitLogout()
{
	//// �α׾ƿ� ������ ���� ȭ��
	// �޴� ����
	CMenu *pMenu = GetMenu();
	pMenu->EnableMenuItem(ID_LOGOUT,TRUE);
	pMenu->EnableMenuItem(ID_CHANGENAME,TRUE);
	pMenu->EnableMenuItem(ID_ADDMYLIST,TRUE);
	pMenu->EnableMenuItem(ID_CONNECT,FALSE);
	pMenu->EnableMenuItem(ID_JOIN,FALSE);
	
	// ��� �����
	m_ctrlList1.DeleteAllItems();

	// ��ư,��� ����
	m_ctrlConnect.ShowWindow(TRUE);
	m_ctrlJoin.ShowWindow(TRUE);
	m_ctrlChangename.ShowWindow(FALSE);
	m_ctrlAddmylist.ShowWindow(FALSE);
	m_ctrlDelmylist.ShowWindow(FALSE);
	m_ctrlList1.ShowWindow(FALSE);
	m_ctrlEdit1.ShowWindow(FALSE);
}

void CChatCDlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	POSITION pos = m_ctrlList1.GetFirstSelectedItemPosition();
	int nSel = m_ctrlList1.GetNextSelectedItem(pos);

	// �������� ��ȭ��븦 Ŭ���ϸ� �ƹ��ϵ� �Ͼ�� ����.
	if(m_mylistonline[nSel] == false) return;

	// â ����..
	CreateChatWin(nSel);

	*pResult = 0;
}
void CChatCDlg::ChatWinDestroy(CChatWinDlg * p)
{
	for(int i=0;i<100;i++)
	{
		if(p == m_pDlg[i])
		{
			m_pDlg[i] = NULL;
			break;
		}
	}
}
void CChatCDlg::CreateChatWin(int nSel)
{
	if(m_pDlg[nSel] != NULL && m_mylistonline[nSel]==true)
	{
		// ��ȭ���ڰ� �̹� ��µǾ� �ִ� ���
		m_pDlg[nSel]->SetFocus();
	}
	else if(m_mylistonline[nSel]==true)
	{
		// ��ȭ���ڰ� ��µǾ� ���� ���� ���
		m_pDlg[nSel] = new CChatWinDlg;
		m_pDlg[nSel]->Create(IDD_CHATWIN, this);
		m_pDlg[nSel]->m_nSel = nSel;
		m_pDlg[nSel]->m_strId = m_strId;
		m_pDlg[nSel]->ShowWindow(SW_SHOW);
		m_pDlg[nSel]->m_strName = m_strName; // ���̸�
		m_pDlg[nSel]->m_strDestid = m_mylist[nSel]; // ������̵� ����
		m_pDlg[nSel]->m_strEdit2 = m_mylist[nSel]; // ������̵� ȭ�鿡 ǥ��
		//���� ���̵� â ���� ǥ��
		m_pDlg[nSel]->SetWindowText(m_mylist[nSel]);
	}
	m_pDlg[nSel]->UpdateData(FALSE);
}

void CChatCDlg::OnAppAbout()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CAboutDlg dlg;
	dlg.DoModal();
}

void CChatCDlg::Send_JOIN_MEMBER(CString id, CString pass, CString name, CString serverip)
{
	CDataSocket sock;
	CData data;

	//////// �ӽ� ���� ����
	// Ŭ���̾�Ʈ ���� ����
	if(!sock.Create())
	{
		AfxMessageBox(_T("Ŭ���̾�Ʈ ���� ���� ����"));
		return;
	}
	// ������ ���� ��û
	if(!sock.Connect(serverip, 3666)) // ���������ǿ� ��Ʈ��ȣ
	{
		AfxMessageBox(_T("������ ã�� �� �����ϴ�."));
		sock.Close();
		return;
	}
	// Ŭ���̾�Ʈ ���� �ʱ�ȭ
	sock.Init(this);

	//////// ������ ����
	data.Setdata(D_JOIN_MEMBER, true, id, name, "", "", pass);
	sock << data;

	AfxMessageBox(_T("�α��� �� �ּ���.."));
	::Sleep(1000);

	// ��������
	sock.Close();
}

void CChatCDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	delete m_pDataSocket;
}
