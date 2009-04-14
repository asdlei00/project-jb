// DataSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChatC.h"
#include "DataSocket.h"
#include "Data.h"
#include "ChatCDlg.h"


// CDataSocket

CDataSocket::CDataSocket()
{
}

CDataSocket::CDataSocket(CChatCDlg * dlg)
{
	m_pDlg = dlg;
}

CDataSocket::~CDataSocket()
{
}


// CDataSocket ��� �Լ��Դϴ�.

void CDataSocket::Init(CChatCDlg * dlg)
{
	m_pDlg = dlg;
	m_pFile = new CSocketFile(this);
	m_pArIn = new CArchive(m_pFile, CArchive::load);
	m_pArOut = new CArchive(m_pFile, CArchive::store);
}

void CDataSocket::Send(CData * pData)
{
	if(m_pArOut != NULL)
		pData->Serialize(*m_pArOut);
}

void CDataSocket::Receive(CData * pData)
{
	if(m_pArIn != NULL)
		pData->Serialize(*m_pArIn);
}

void CDataSocket::operator <<(CData & data)
{
	Send(&data);
	Flush();
}

void CDataSocket::operator >>(CData & data)
{
	Receive(&data);
}

void CDataSocket::Flush()
{
	if(m_pArOut!=NULL)
		m_pArOut->Flush();
}

void CDataSocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if(m_pArIn == NULL) return;
	m_pDlg->OnReceive(this);

	CSocket::OnReceive(nErrorCode);
}

void CDataSocket::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if(m_pFile != NULL){
		delete m_pFile;
		m_pFile = NULL;
	}
	if(m_pArIn != NULL){
		m_pArIn->Abort();
		delete m_pArIn;
		m_pArIn = NULL;
	}
	if(m_pArOut != NULL){
		m_pArOut->Abort();
		delete m_pArOut;
		m_pArOut = NULL;
	}

	m_pDlg->OnDisconnectClient(this);

	CSocket::OnClose(nErrorCode);
}
