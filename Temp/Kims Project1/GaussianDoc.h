// GaussianDoc.h : CGaussianDoc Ŭ������ �������̽�
//


#pragma once
#include "dib.h"


class CGaussianDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CGaussianDoc();
	DECLARE_DYNCREATE(CGaussianDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �����Դϴ�.
public:
	virtual ~CGaussianDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	CDib m_Dib;
	afx_msg void OnWindowDuplicate();
};


