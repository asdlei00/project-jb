/* 
	Author				: ������(Bill) (kjh_900@hanmail.net)	
	Release Date		: 2009. 04. 28.
	Project	Name		: Server Manager Message
	Version				: 1.00.01

	Test PC				: CPU - Pentium(R) 4 2.40Ghz, RAM - 1 GB Graphic - Radeon 9600
	Test OS				: Windows XP Professional + SP3
	Test Application	: Visual Studio 2008 + SP1
	
	Contents

	Server Manager Message Header

	2009 �� Copyright MIS Corporation. All Rights Reserved.
*/

#pragma once

// ������ �޽��� ����
void MSG_SendToServer(CClientSock* pSock, const char* pszSend);

// �޽����� �ε����� ���� �Ľ��Ѵ�
void MSG_Seperator(int nIndex, const char* msg, char* pOut);

// ���̵� üũ(���Խÿ�)
void MSG_ID_Check_Ack(MSG_DATA msgData, CClientSock* pSock);

// ���� �߰�
void MSG_Add_ID_Ack(MSG_DATA msgData, CClientSock* pSock);

// �α���
void MSG_Login_Ack(MSG_DATA msgData, CClientSock* pSock);