// Gaussian.h : Gaussian ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CGaussianApp:
// �� Ŭ������ ������ ���ؼ��� Gaussian.cpp�� �����Ͻʽÿ�.
//

class CDib;
class CGaussianApp : public CWinApp
{
public:
	CGaussianApp();
	~CGaussianApp();

public:
	CMultiDocTemplate* m_pImageDocTemplate;
	CDib* m_pNewDib;


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGaussianApp theApp;
void AfxNewImage(CDib& dib);