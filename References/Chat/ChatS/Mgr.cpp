#include "StdAfx.h"
#include "mgr.h"
#include "member.h"
#include "ChatSDlg.h"
#include ".\mgr.h"

CMgr::CMgr(void)
{
}

CMgr::~CMgr(void)
{
}

int CMgr::ExistMember(CString id)
{
	// ���̵� �����ϴ��� �˻�..
	int nSel=-1;
	for(int i=0;i<m_Membernum;i++){
		if(strcmp(m_Memberlist[i].GetID(), id)==0){
			nSel=i;
			break;
		}
	}
	return nSel;
}

bool CMgr::Addmember(CString id, CString pass, CString name) // ��� �߰�.
{
	// ���� ���̵� �����ϴ��� �˻�
	if(m_Membernum==0 || ExistMember(id) == -1)
	{
		// ���Ͽ� �߰�
		CFile file;
		if(file.Open(_T("Memberdata.dat"), CFile::modeWrite))
		{
			//����Ʈ�� ����
			m_Memberlist[m_Membernum].Setmember(id, pass, name);
			m_Memberlist[m_Membernum].m_mylistnum = 0;
			m_Membernum++;
			

			//���Ͽ� ����
			CArchive ar(&file, CArchive::store);
			Serialize(ar);
			ar.Close();
		}
		else {
			AfxMessageBox(_T("���Ͽ� ���� ����"));
		}
	}
	else
	{
		// ���̵� �̹� �����ϴ� ��� ����߰� ����
		return false;
	}
	return true;
}

bool CMgr::Delmember(CString id)
{
	// ��ȣ ã��
	int nSel=ExistMember(id);

	CFile file;
	if(file.Open(_T("Memberdata.dat"), CFile::modeWrite))
	{
		//����Ʈ���� ����
		for(int i=nSel;i<m_Membernum-1;i++){
			m_Memberlist[i].Setmember (m_Memberlist[i+1].m_id, m_Memberlist[i+1].m_pass, m_Memberlist[i+1].m_name);
		}

		m_Membernum --;

		//���Ͽ� ����
		CArchive ar(&file, CArchive::store);
		Serialize(ar);
		ar.Close();
		return true;
	}
	return false;
}

void CMgr::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar << m_Membernum;
		for(int i=0;i<m_Membernum;i++){
			ar << m_Memberlist[i].m_id;
			ar << m_Memberlist[i].m_pass;
			ar << m_Memberlist[i].m_name;
			ar << m_Memberlist[i].m_mylistnum;
			for(int j=0;j<m_Memberlist[i].m_mylistnum;j++)
			{
				ar << m_Memberlist[i].m_mylist[j];
			}
		}
	}
	else
	{	// loading code
		ar >> m_Membernum;
		for(int i=0;i<m_Membernum;i++){
			ar >> m_Memberlist[i].m_id;
			ar >> m_Memberlist[i].m_pass;
			ar >> m_Memberlist[i].m_name;
			ar >> m_Memberlist[i].m_mylistnum;
			for(int j=0;j<m_Memberlist[i].m_mylistnum;j++)
			{
				ar >> m_Memberlist[i].m_mylist[j];
			}
		}
	}
}

bool CMgr::Init(CChatSDlg *p)
{
	CFile file;
	if(file.Open(_T("Memberdata.dat"), CFile::modeRead))
	{
		// ������ �̹� ������ ��� �б���
		CArchive ar(&file, CArchive::load);
		Serialize(ar);
		for(int i=0;i<m_Membernum;i++){
			// ���̾�α׿� ǥ��
			p->ShowMember(i,m_Memberlist[i].GetID(), m_Memberlist[i].GetName());
		}
		ar.Close();
	}
	else {
		// ������ ���� ��� ���� ����
		file.Open(_T("Memberdata.dat"), CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);

		m_Membernum = 0;
		Serialize(ar); 
		ar.Close();
	}
	return true;
}

bool CMgr::CheckPass(CString id, CString pass)
{
	int nSel=ExistMember(id);

	if(strcmp(m_Memberlist[nSel].m_pass , pass) == 0) return true;

	return false;
}

void CMgr::ModMemberName(int nSel, CString name)
{
	// ������ ����
	m_Memberlist[nSel].m_name = name;

	// ���Ͽ� ����
	CFile file;
	if(file.Open(_T("Memberdata.dat"), CFile::modeWrite))
	{
		CArchive ar(&file, CArchive::store);
		Serialize(ar);
		ar.Close();
	}
}

void CMgr::SetMemberOnline(CString id, bool online, CDataSocket * pDataSocket)
{
	// ��ȣ ã��
	int nSel=ExistMember(id);
	if(nSel==-1) return;

	m_Memberlist[nSel].m_online = online;
	m_Memberlist[nSel].m_pDataSocket = pDataSocket;
}

CString CMgr::GetMemberName(CString id)
{
	int nSel=ExistMember(id);
	return m_Memberlist[nSel].GetName();
}

bool CMgr::GetMemberOnline(CString id)
{
	// ��ȣ ã��
	int nSel=ExistMember(id);
	if(nSel==-1) return false;

	return m_Memberlist[nSel].m_online;
}

CDataSocket * CMgr::GetMemberSocket(CString id)
{
	// ��ȣ ã��
	int nSel=ExistMember(id);
	if(nSel==-1) return NULL;

	return m_Memberlist[nSel].m_pDataSocket;
}

void CMgr::AddMemberMylist(int nSel, CString destId) // ��ȭ��� �߰��ؼ� ����.
{
	// �̹� �ִ� �������.. Ȯ��
	// ������ ����
	m_Memberlist[nSel].Addmylist(destId);

	// ���Ͽ� ����
	CFile file;
	if(file.Open(_T("Memberdata.dat"), CFile::modeWrite))
	{
		CArchive ar(&file, CArchive::store);
		Serialize(ar);
		ar.Close();
	}
}

void CMgr::DelMemberMylist(int nSel, CString destId) // ��ȭ��� �����ؼ� ����.
{
	// ������ ����
	m_Memberlist[nSel].Delmylist(destId);

	// ���Ͽ� ����
	CFile file;
	if(file.Open(_T("Memberdata.dat"), CFile::modeWrite))
	{
		CArchive ar(&file, CArchive::store);
		Serialize(ar);
		ar.Close();
	}
}
CDataSocket * CMgr::GetMemberSocket(int nSel)
{
	return m_Memberlist[nSel].m_pDataSocket;
}

CString CMgr::GetMemberID(int nSel)
{
	return m_Memberlist[nSel].m_id;
}

CString CMgr::GetMemberName(int nSel)
{
	return m_Memberlist[nSel].m_name;
}

bool CMgr::GetMemberOnline(int nSel)
{
	return m_Memberlist[nSel].m_online;
}


int CMgr::GetMemberMylistnum(int nSel)
{
	return m_Memberlist[nSel].m_mylistnum;
}

CString CMgr::GetMemberMylist(int nSel, int nSel2)
{
	return m_Memberlist[nSel].m_mylist[nSel2];
}

int CMgr::GetMemberMylistExist(int nSel, CString id)
{
	int n = m_Memberlist[nSel].m_mylistnum;
	// ����Ʈ�� ���̵� �����ϴ��� �˻�..
	int nSel2=-1;
	for(int i=0;i<n;i++){
		if(strcmp(m_Memberlist[nSel].m_mylist[i], id)==0){
			nSel2=i;
			break;
		}
	}
	return nSel2;
}
