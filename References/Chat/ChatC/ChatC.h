// ChatC.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"		// �� ��ȣ


// CChatCApp:
// �� Ŭ������ ������ ���ؼ��� ChatC.cpp�� �����Ͻʽÿ�.
//

class CChatCApp : public CWinApp
{
public:
	CChatCApp();

// ������
	public:
	virtual BOOL InitInstance();

// ����

	DECLARE_MESSAGE_MAP()
};

extern CChatCApp theApp;
