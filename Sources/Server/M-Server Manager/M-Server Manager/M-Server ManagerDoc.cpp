
// M-Server ManagerDoc.cpp : CMServerManagerDoc Ŭ������ ����
//

#include "stdafx.h"
#include "M-Server Manager.h"

#include "M-Server ManagerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMServerManagerDoc

IMPLEMENT_DYNCREATE(CMServerManagerDoc, CDocument)

BEGIN_MESSAGE_MAP(CMServerManagerDoc, CDocument)
END_MESSAGE_MAP()


// CMServerManagerDoc ����/�Ҹ�

CMServerManagerDoc::CMServerManagerDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CMServerManagerDoc::~CMServerManagerDoc()
{
}

BOOL CMServerManagerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CMServerManagerDoc serialization

void CMServerManagerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}


// CMServerManagerDoc ����

#ifdef _DEBUG
void CMServerManagerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMServerManagerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMServerManagerDoc ���
