// Data.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatS.h"
#include "Data.h"

// CData

CData::CData()
: m_strData(_T("")),
m_strDestId(_T("")),
m_strId(_T("")),
m_strName(_T("")),
m_strPass(_T("")),
m_mylistnum(0)
{
}

CData::~CData()
{
}


// CData ��� �Լ��Դϴ�.

void CData::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code ��Ʈ��ũ�� �۽�
		ar << m_flag;
		ar << m_result;
		ar << m_strId;
		ar << m_strPass;
		ar << m_strName;
		ar << m_strData;
		ar << m_strDestId;
		ar << m_mylistnum;
		for(int i=0;i<m_mylistnum;i++){
			ar << m_mylist[i];
		}
	}
	else
	{	// loading code ��Ʈ��ũ���� ����
		ar >> m_flag;
		ar >> m_result;
		ar >> m_strId;
		ar >> m_strPass;
		ar >> m_strName;
		ar >> m_strData;
		ar >> m_strDestId;
		ar >> m_mylistnum;
		for(int i=0;i<m_mylistnum;i++){
			ar >> m_mylist[i];
		}
	}
}

void CData::Setdata(int flag, bool result, CString id, CString name, CString data, CString dest_id, CString pass)
{
	m_flag=flag;
	m_strId=id;
	m_strName=name;
	m_strData=data;
	m_strDestId=dest_id;
	m_strPass=pass;
	m_result=result;
}

void CData::SetLogindata(int flag, CString id, CString pass)
{
	m_flag=flag;
	m_strId=id;
	m_strName="";
	m_strData="";
	m_strDestId="";
	m_strPass=pass;
	m_result=true;
}

