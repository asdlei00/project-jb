// GaussianDoc.cpp : CGaussianDoc Ŭ������ ����
//

#include "stdafx.h"
#include "Gaussian.h"

#include "GaussianDoc.h"
#include "GaussianView.h"
#include "FileNewDlg.h"
#include "MainFrm.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGaussianDoc

IMPLEMENT_DYNCREATE(CGaussianDoc, CDocument)

BEGIN_MESSAGE_MAP(CGaussianDoc, CDocument)
	ON_COMMAND(ID_WINDOW_DUPLICATE, &CGaussianDoc::OnWindowDuplicate)
END_MESSAGE_MAP()


// CGaussianDoc ����/�Ҹ�

CGaussianDoc::CGaussianDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
}

CGaussianDoc::~CGaussianDoc()
{
}

BOOL CGaussianDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	BOOL bSuccess = TRUE;

	if( theApp.m_pNewDib != NULL )
	{
		m_Dib.Copy(theApp.m_pNewDib);
		theApp.m_pNewDib = NULL;
	}
	else
	{
		CFileNewDlg dlg;
		if( dlg.DoModal() == IDOK )
		{
			if( dlg.m_nType == 0 ) // �׷��̽����� �̹���
				bSuccess = m_Dib.CreateGrayImage(dlg.m_nWidth, dlg.m_nHeight);
			else // Ʈ��Į�� �̹���
				bSuccess = m_Dib.CreateRGBImage(dlg.m_nWidth, dlg.m_nHeight);
		}
		else
		{
			bSuccess = FALSE;
		}
	}

	return bSuccess;

}

// CGaussianDoc serialization

void CGaussianDoc::Serialize(CArchive& ar)
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


// CGaussianDoc ����

#ifdef _DEBUG
void CGaussianDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGaussianDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGaussianDoc ���

BOOL CGaussianDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if(!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	return m_Dib.Load(lpszPathName);
}

BOOL CGaussianDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	return m_Dib.Save(lpszPathName);
}

void CGaussianDoc::OnWindowDuplicate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	AfxNewImage(m_Dib);
}
