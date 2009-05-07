/* 
	Author				: ������(Bill) (kjh_900@hanmail.net)	
	Release Date		: 2009. 04. 28.
	Project	Name		: Client Message
	Version				: 1.00.03

	Test PC				: CPU - Pentium(R) 4 2.40Ghz, RAM - 1 GB Graphic - Radeon 9600
	Test OS				: Windows XP Professional + SP3
	Test Application	: Visual Studio 2008 + SP1
	
	Contents

	Client Message Header

	2009 �� Copyright MIS Corporation. All Rights Reserved.
*/

#pragma once

#include "Common_Define.h"

void MSG_Seperator(int nIndex, const char* msg, char* pOut);

// ������ �޽��� ����
void MSG_SendToServer(const char* pszSend);

// ���� ������
void MSG_Exit_Server_Req(const char* pszID);

// ���̵� üũ(���Խÿ�)
void MSG_ID_Check_Req(const char* pszID);
MSG_RET MSG_ID_Check_Ack(MSG_DATA msgData);

// ���� ����
void MSG_Add_ID_Req(const char* pszID, const char* pszPasswords);
MSG_RET MSG_Add_ID_Ack(MSG_DATA msgData);

// �α���
void MSG_Login_Req(const char* pszID, const char* pszPasswords, const char* pszServer);
MSG_RET MSG_Login_Ack(MSG_DATA msgData);

// ģ�� �߰�
void MSG_Add_Friend_Req(const char* pszID, const char* pszFriendID, const char* pszMessage);
MSG_RET MSG_Add_Friend_Ack(MSG_DATA msgData);