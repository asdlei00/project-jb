
// M-ClientDoc.cpp : CMClientDoc Ŭ������ ����
//

#include "stdafx.h"
#include "M-Client.h"

#include "M-ClientDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMClientDoc

IMPLEMENT_DYNCREATE(CMClientDoc, CDocument)

BEGIN_MESSAGE_MAP(CMClientDoc, CDocument)
END_MESSAGE_MAP()


// CMClientDoc ����/�Ҹ�

CMClientDoc::CMClientDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CMClientDoc::~CMClientDoc()
{
}

BOOL CMClientDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CMClientDoc serialization

void CMClientDoc::Serialize(CArchive& ar)
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


// CMClientDoc ����

#ifdef _DEBUG
void CMClientDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMClientDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMClientDoc ���
