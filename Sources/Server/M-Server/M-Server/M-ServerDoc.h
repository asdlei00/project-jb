
// M-ServerDoc.h : CMServerDoc Ŭ������ �������̽�
//


#pragma once


class CMServerDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMServerDoc();
	DECLARE_DYNCREATE(CMServerDoc)

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
	virtual ~CMServerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};


