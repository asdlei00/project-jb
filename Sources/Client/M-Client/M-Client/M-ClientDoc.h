
// M-ClientDoc.h : CMClientDoc Ŭ������ �������̽�
//


#pragma once


class CMClientDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMClientDoc();
	DECLARE_DYNCREATE(CMClientDoc)

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
	virtual ~CMClientDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};


