
// M-Server ManagerDoc.h : CMServerManagerDoc Ŭ������ �������̽�
//


#pragma once


class CMServerManagerDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMServerManagerDoc();
	DECLARE_DYNCREATE(CMServerManagerDoc)

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
	virtual ~CMServerManagerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};


