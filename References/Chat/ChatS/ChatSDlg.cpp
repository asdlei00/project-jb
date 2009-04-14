// ChatSDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ChatS.h"
#include "ChatSDlg.h"
#include "AdduserDlg.h"
#include "Data.h"
#include "Mgr.h"
#include "flag.h"
#include ".\chatsdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
int clntNumber=0;
#endif


// CChatSDlg ��ȭ ����


CChatSDlg::CChatSDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatSDlg::IDD, pParent)
	, m_strList2(_T(""))
	, m_strList1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_LBString(pDX, IDC_LIST2, m_strList2);
	DDX_LBString(pDX, IDC_LIST1, m_strList1);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList1);
	DDX_Control(pDX, IDC_LIST2, m_ctrlList2);
}

BEGIN_MESSAGE_MAP(CChatSDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
END_MESSAGE_MAP()


// CChatSDlg �޽��� ó����

BOOL CChatSDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	// �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, FALSE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, TRUE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	// ���α׷� �����. (�ϳ��� ����)
	HANDLE hMutex = CreateMutex(NULL, TRUE, "�޽��� ����");
	if(GetLastError() == ERROR_ALREADY_EXISTS)
	{
		CloseHandle(hMutex);
		AfxMessageBox("���α׷��� �̹� �������Դϴ�.", MB_ICONSTOP);
		//return FALSE;
		ExitProcess(1);
	}

	// ����Ʈ�ڽ� �ʱ�ȭ
	m_ctrlList2.InsertColumn(0,"���̵�",LVCFMT_LEFT,60);
	m_ctrlList2.InsertColumn(1,"��ȭ��",LVCFMT_LEFT,99); 
	m_ctrlList2.InsertColumn(2,"����",LVCFMT_LEFT,60);
	m_ctrlList2.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	// �������� �ʱ�ȭ (���簴ü,��Ʈ��ȣ)
	m_ServerSocket.Init(this,3666);
	m_ctrlList1.AddString(_T("*** ������ ����Ǿ����ϴ� ***"));

	// ��� ����Ʈ
	list.Init(this); // �������Ʈ �ʱ�ȭ

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸����� 
// �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
// �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CChatSDlg::OnPaint() 
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
HCURSOR CChatSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CChatSDlg::OnBnClickedButton1() // ����� �߰�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CAdduserDlg dlg;
	if(dlg.DoModal() == IDOK)
	{
		if(list.Addmember(dlg.m_strId,dlg.m_strPass,dlg.m_strName)){
			// ����߰��� ���� ��� ���̾�α׿� ǥ��..
			m_ctrlList2.InsertItem(list.m_Membernum-1, dlg.m_strId);
			m_ctrlList2.SetItemText(list.m_Membernum-1, 1, dlg.m_strName);
			m_ctrlList2.SetItemText(list.m_Membernum-1, 2, "��������");
		}
		else
		{
			AfxMessageBox(_T("���� ���̵� �̹� �����մϴ�."));
		}
	}
}
void CChatSDlg::OnBnClickedButton2() // ����� ����
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	POSITION pos = m_ctrlList2.GetFirstSelectedItemPosition();

	if(!pos)
	{
		AfxMessageBox(_T("������ ���̵� �������ֽʽÿ�."));
	}
	else 
	{
		UpdateData(TRUE);
		
		int nSel = m_ctrlList2.GetNextSelectedItem(pos);
		CString id = list.GetMemberID(nSel);

		CString str; str.Format("%s - ���� �����Ͻðڽ��ϱ�?", id);
		if(AfxMessageBox(str,MB_YESNO) == IDYES){
			if(list.Delmember(id)){
				//������ �����Ұ��
				//ȭ�鿡�� ����
				while(pos = m_ctrlList2.GetFirstSelectedItemPosition()){
					int nSelItem = m_ctrlList2.GetNextSelectedItem(pos);
					m_ctrlList2.DeleteItem(nSelItem);
				}
				
			}
			else
			{
				AfxMessageBox(_T("���̵� ���� ����"));
			}
		}
	}
}

void CChatSDlg::ShowMember(int i, CString id, CString name)
{
	m_ctrlList2.InsertItem(i, id);
	m_ctrlList2.SetItemText(i, 1, name);
	m_ctrlList2.SetItemText(i, 2, "��������");
}

void CChatSDlg::OnAccept()
{
	// �����ͼ��� ����
	m_pDataSocket = new CDataSocket(this);

	// �������ϰ� �����ͼ����� ������� ��
	if(!m_ServerSocket.Accept(*m_pDataSocket))
	{
		AfxMessageBox(_T("Ŭ���̾�Ʈ ���� ����"));
		return;
	}

	// ����Ʈ�� �����߰�..
	m_ListDataSocks.AddTail(m_pDataSocket);

	// �����ͼ���, archive �ʱ�ȭ
	m_pDataSocket->Init(this);

	// �˸�
	CString str;
	str.Format("* ���ο� Ŭ���̾�Ʈ�� �����߽��ϴ�.");
	m_ctrlList1.AddString(str);
	m_ctrlList1.SetCurSel(m_ctrlList1.GetCount()-1);

	return;
}
void CChatSDlg::OnReceive(CDataSocket *pDataSocket)
{
	// ��� ���ۿ� �ִ� �����͸� ���� ������ ������ �ݺ�
	do {
		//������ ����
		CData data;
		*pDataSocket >> data;

		CString str;

		//���ŵ� ������ ó��
		switch(data.m_flag)
		{
		case D_LOGIN:
			//////// �α��� ��û
			str.Format("%s - ���� ���� ����", data.m_strId);
			m_ctrlList1.AddString(str);
			m_ctrlList1.SetCurSel(m_ctrlList1.GetCount()-1);
			Receive_LOGIN(pDataSocket, &data);
			break;

		case D_MOD_NAME:
			//////// ��ȭ�� ���� ��û
			str.Format("%s - ��ȭ�� ����", data.m_strId);
			m_ctrlList1.AddString(str);
			m_ctrlList1.SetCurSel(m_ctrlList1.GetCount()-1);
			Receive_MOD_NAME(pDataSocket, data.m_strId, data.m_strName);
			break;

		case D_JOIN_MEMBER:
			//////// ȸ������ ��û
			str.Format("%s - ���Կ�û", data.m_strId);
			m_ctrlList1.AddString(str);
			m_ctrlList1.SetCurSel(m_ctrlList1.GetCount()-1);
			Receive_JOIN_MEMBER(pDataSocket, data.m_strId, data.m_strPass, data.m_strName);
			break;

		case D_MESSAGE:
			//////// ä�� �޽����� ���� ���
			Receive_MESSAGE(pDataSocket, &data);
			break;

		case D_ADD_MYLIST :
			//////// ��ȭ��� �߰��� �� ���
			Receive_ADD_MYLIST(pDataSocket, data.m_strId, data.m_strDestId);
			break;

		case D_DEL_MYLIST:
			//////// ��ȭ��� ������ �� ���
			Receive_DEL_MYLIST(pDataSocket, &data);
			break;

		default : 
			break;
		}
	} while(!(*pDataSocket).m_pArIn -> IsBufferEmpty());
	return;
}

void CChatSDlg::OnDisconnectClient(CDataSocket* pDataSocket){

	// Ŭ���̾�Ʈ�� ������ ������ �� ó��

	// �����ͼ��� ����Ʈ���� ã��
	POSITION pos;
	pos=m_ListDataSocks.Find(pDataSocket);
	CString id = pDataSocket->m_id;

	if(pDataSocket->m_id != ""){
		// ����â�� �α׾ƿ� ǥ��
		CString str;
		str.Format("%s - �α׾ƿ�",id);
		m_ctrlList1.AddString(str);
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount()-1);

		// ����Ʈ�� �������� ǥ��
		int nSel = list.ExistMember(id);
		m_ctrlList2.SetItemText(nSel,2,"��������");

		// ��������� �������� ���·� ����
		list.SetMemberOnline(id, false, NULL);

		// ���ӵ� ����鿡�� �α׾ƿ� �˸�
		Send_LOGOUT_MEMBER(id);
	}
	// �����ͼ��� ����Ʈ���� ����
	m_ListDataSocks.RemoveAt(pos);
}

void CChatSDlg::Receive_LOGIN(CDataSocket * pDataSocket, CData * pData)
{
	//////// �α��� ��û
	CString str;
	bool tf=false;
	int nSel = list.ExistMember(pData->m_strId);
	if (nSel == -1)
	{
		// ���̵� �������� ���� ��� (�������)
		CString str;
		str.Format("%s - �α��� ����(�������� �ʴ� ���̵�)", pData->m_strId);
		m_ctrlList1.AddString(str);
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount()-1);
		// ���и޽��� ����
		(*pData).Setdata(D_LOGIN_RESULT,false);
	}
	else {
		// ���̵� ������ ���
		//��� �˻�
		if(list.CheckPass(pData->m_strId, pData->m_strPass))
		{
			if(list.GetMemberOnline(pData->m_strId) == false)
			{
				str.Format("%s - �α��� ����", pData->m_strId);
				tf=true;
			}
			else
			{
				// �̹� �α��� �Ǿ� �ִ� ���..
				// ���� �α��� �Ǿ� �ִ� ������ ����
				Send_LOGOUT(pData->m_strId);

				str.Format("%s - �ߺ� �α���, ���� ���� ����", pData->m_strId);
				tf=true;
			}
		}
		else
		{
			str.Format("%s - �α��� ����(�߸��� ��й�ȣ)", pData->m_strId);
		}
	}

	///// ��� ó��
	if(tf) // �α��� ����
	{
		// �����ͼ��� ����Ʈ�� �߰�
		pDataSocket->m_id = pData->m_strId;

		// ��������� �¶��� ���·� ����
		list.SetMemberOnline(pData->m_strId, true, pDataSocket);

		// ����Ʈ�� ǥ��
		nSel = list.ExistMember(pData->m_strId);
		m_ctrlList2.SetItemText(nSel,2,"�¶���");

		// ���� ��� ����
		CString id=pData->m_strId;
		(*pData).Setdata( D_LOGIN_RESULT, true, id, list.GetMemberName(id) );

	}
	else // �α��� ����
	{
		// ���� ��� ����
		(*pData).Setdata(D_LOGIN_RESULT,false);
	}
	m_ctrlList1.AddString(str); // ����â�� ���
	m_ctrlList1.SetCurSel(m_ctrlList1.GetCount()-1);
	Send_LOGIN_RESULT(pDataSocket, pData); // ��� ����
}

void CChatSDlg::Send_LOGIN_RESULT(CDataSocket * pDataSocket, CData * pData)
{
	int nSel;
	if(pData->m_result == true)
	{
		nSel = list.ExistMember(pData->m_strId);
		int listnum = list.GetMemberMylistnum(nSel);
		// ��ȭ��� ����Ʈ ������ ����
		pData->m_mylistnum = listnum;
		for(int i=0;i<listnum ; i++)
		{
			pData->m_mylist[i] = list.GetMemberMylist(nSel, i);
		}
	}
	
	// �α��� ��� ����
	*pDataSocket << *pData;

	// �α����� ���������� �߰� �۾�
	if(pData->m_result == true)
	{
		// ���� �α����� �������, �̹� �α��� �Ǿ��ִ� ��� �˸�
		Send_LOGIN_MEMBER_INIT(pDataSocket);

		// ��ȭ����� �����ڿ��� �α����� �˸�
		Send_LOGIN_MEMBER(pDataSocket, pData->m_strId, list.GetMemberName(nSel));
	}
}

void CChatSDlg::Receive_MESSAGE(CDataSocket * pDataSocket, CData * pData)
{
	//////// ä�� �޽����� �������� ���

	// ��� ���̵� �¶������� Ȯ��
	if( list.GetMemberOnline(pData->m_strDestId) ) 
	{
		// �¶����϶�
		Send_MESSAGE(pData->m_strId, pData->m_strName, pData->m_strData, pData->m_strDestId);
	}
	else
	{
		// �¶����� �ƴҶ�
		Send_MESSAGE_FAIL(pDataSocket);
	}
}

void CChatSDlg::Receive_MOD_NAME(CDataSocket * pDataSocket, CString id, CString name)
{
	// ��� ã��
	int nSel = list.ExistMember(id);
	if (nSel != -1)
	{
		// ������ ����
		list.ModMemberName(nSel, name);

		// ����Ʈ�� ��ȭ�� ����
		m_ctrlList2.SetItemText(nSel,1,name);

		// ������ �˸�..
		Send_LOGIN_MEMBER(pDataSocket, id, name);
	}
}

void CChatSDlg::Send_MESSAGE(CString id, CString name, CString message, CString destid)
{
	////////// ä�� �޽��� ����!
	CDataSocket * pDataSocket;
	CData data;

	CString str; str.Format("%s : %s",id, message);
	m_ctrlList1.AddString(str);
	m_ctrlList1.SetCurSel(m_ctrlList1.GetCount()-1);
	
	// ��� ����� �����ͼ��� ���� -_-;;
	if( (pDataSocket=list.GetMemberSocket(destid)) != NULL)
	{
		data.Setdata(D_MESSAGE, true, id, name, message, destid);
		*pDataSocket << data;
	}
}

void CChatSDlg::Send_MESSAGE_FAIL(CDataSocket * pDataSocket)
{
	CData data;
	data.Setdata(D_MESSAGE_FAIL);
	*pDataSocket << data;
}

void CChatSDlg::Send_LOGIN_MEMBER_INIT(CDataSocket * pDataSocket)
{
	//////// �ڽ��� ��ȭ��� ��, �α�Ǿ��ִ� ����� �����ͼ��� ���� -_-;;
	CDataSocket * p;
	CData data;
	// �α�Ǿ��ִ� ����� �����ͼ��� ���� -_-;;
	for(int i=0;i<list.m_Membernum;i++)
	{
		// ���� �α��� ������� �̹� �¶����� ������� ����Ʈ�� ����.
		p=list.GetMemberSocket(i);
		if((p != NULL) && (p!=pDataSocket))
		{
			data.Setdata(D_LOGIN_MEMBER, true, list.GetMemberID(i), list.GetMemberName(i));
			*pDataSocket << data;
		}
	}
}

void CChatSDlg::Send_LOGIN_MEMBER(CDataSocket * pDataSocket, CString id, CString name)
{
	//////// ��ȭ����� �����ڵ鿡�� �α����� �˸�
	CDataSocket * p;
	CData data;
	// �α�Ǿ��ִ� ����� �����ͼ��� ���� -_-;;
	for(int i=0;i<list.m_Membernum;i++)
	{
		p=list.GetMemberSocket(i);
		if( (p != NULL) && (p!=pDataSocket) )
		{
			// �̹� �¶����� ����鿡�� ��� �α��� �Ѱ��� �˸�.
			data.Setdata(D_LOGIN_MEMBER, true, id, name);
			*p << data;
		}
	}
}

void CChatSDlg::Send_LOGOUT_MEMBER(CString id)
{
	CDataSocket * p;
	CData data;
	// �α�Ǿ��ִ� ����� �����ͼ��� ���� -_-;;
	for(int i=0;i<list.m_Membernum;i++)
	{
		p=list.GetMemberSocket(i);
		if(p != NULL)
		{
			// �̹� �¶����� ����鿡�� ��� �α׾ƿ� �Ѱ��� �˸�.
			data.Setdata(D_LOGOUT_MEMBER,true,id);
			*p << data;
		}
	}
}

void CChatSDlg::Send_LOGOUT(CString id)
{
	// �ش� ���̵��� ������ ������ ����
	CDataSocket * p;
	CData data;
	
	for(int i=0;i<list.m_Membernum;i++)
	{
		if(list.GetMemberID(i) == id)
		{
			// �α׾ƿ��϶�� �޽��� ����
			p = list.GetMemberSocket(i);
			data.Setdata(D_LOGOUT,true);
			*p << data;
			break;
		}
	}
}

void CChatSDlg::Receive_ADD_MYLIST(CDataSocket * pDataSocket, CString id, CString destid)
{
	// ��� ã��
	int nSel = list.ExistMember(id);
	int nSel2 = list.ExistMember(destid);
	int nSel3 = list.GetMemberMylistExist(nSel, destid);
	CData data;

	CString str;
	str.Format("%s - ��ȭ��� %s �߰� ��û", id, destid);
	m_ctrlList1.AddString(str);
	m_ctrlList1.SetCurSel(m_ctrlList1.GetCount()-1);

	if (nSel != -1 && nSel2 != -1 && nSel3 == -1 && nSel != nSel2)
	{
		str.Format("%s - ��ȭ��� %s �߰� ����", id, destid);
		m_ctrlList1.AddString(str);
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount()-1);

		// ������ ����
		list.AddMemberMylist(nSel, destid);

		// ��ȭ��� �߰� ���� ��� ����
		data.Setdata(D_ADD_MYLIST, true, destid);
		*pDataSocket << data;

		// ���� �߰��� ��ȭ��밡 �α��� �Ǿ��ִ� ���, ��ȭ��밡 �α����ߴٰ� ����
		if(list.GetMemberOnline(nSel2))
		{
			data.Setdata(D_LOGIN_MEMBER, true, list.GetMemberID(nSel2), list.GetMemberName(nSel2));
			*pDataSocket << data;
		}
	}
	else 
	{
		// ���̵� �������� �ʴ� ��� �Ǵ� ��ȭ��븦 �̹� �߰��ߴ� ���.
		// ���� ��� ����
		data.Setdata(D_ADD_MYLIST,false);
		*pDataSocket << data;
	}
}

void CChatSDlg::Receive_DEL_MYLIST(CDataSocket * pDataSocket, CData * pData)
{
	// ��� ã��
	int nSel = list.ExistMember(pData->m_strId);
	int nSel3 = list.GetMemberMylistExist(nSel, pData->m_strDestId);

	if (nSel != -1 && nSel3 != -1)
	{
		CString str;
		str.Format("%s - ��ȭ��� %s ����", pData->m_strId, pData->m_strDestId);
		m_ctrlList1.AddString(str);
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount()-1);

		// ������ ����
		list.DelMemberMylist(nSel, pData->m_strDestId);
	}
}
void CChatSDlg::Receive_JOIN_MEMBER(CDataSocket * pDataSocket, CString id, CString pass, CString name)
{
	/// ȸ������ ��û��..
	CData data;

	if(list.Addmember(id,pass,name)){
		// ����߰��� ���� ��� ���̾�α׿� ǥ��..
		m_ctrlList2.InsertItem(list.m_Membernum-1, id);
		m_ctrlList2.SetItemText(list.m_Membernum-1, 1, name);
		m_ctrlList2.SetItemText(list.m_Membernum-1, 2, "��������");
		data.Setdata(D_JOIN_RESULT,true,id);

		CString str; str.Format("%s - ȸ������", id);
		m_ctrlList1.AddString(str);
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount()-1);
	}
	else
	{
		data.Setdata(D_JOIN_RESULT,false,id);
	}
	* pDataSocket << data;
}
