
// M-ServerDoc.cpp : CMServerDoc Ŭ������ ����
//

#include "stdafx.h"
#include "M-Server.h"

#include "M-ServerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMServerDoc

IMPLEMENT_DYNCREATE(CMServerDoc, CDocument)

BEGIN_MESSAGE_MAP(CMServerDoc, CDocument)
END_MESSAGE_MAP()


// CMServerDoc ����/�Ҹ�

CMServerDoc::CMServerDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CMServerDoc::~CMServerDoc()
{
}

BOOL CMServerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CMServerDoc serialization

void CMServerDoc::Serialize(CArchive& ar)
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


// CMServerDoc ����

#ifdef _DEBUG
void CMServerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMServerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMServerDoc ���
