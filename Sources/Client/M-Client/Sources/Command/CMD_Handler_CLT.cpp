#include "stdAfx.h"
#include "CMD_Handler_CLT.h"
#include "Client_MSG.h"

CCMDHandlerCLT::CCMDHandlerCLT()
{

}

CCMDHandlerCLT::~CCMDHandlerCLT()
{

}

MSG_RET CCMDHandlerCLT::CMD_CLT_Handle(MSG_DATA msgData)
{
	MSG_RET ret;

	switch(msgData.msgHeader.nCommandData)
	{
	case CD_CONNECT_RET_TO_CLIENT:
		{
	
		}
		break;

	case CD_ADD_ID_REQ_TO_MAIN:
		{
			
		}
		break;		

	case CD_ADD_FRIEND_REQ_TO_MAIN:
		{

		}
		break;

	case CD_ADD_ID_RET_TO_CLIENT:
		{
			ret = MSG_Add_ID_Ack(msgData);	
		}
		break;

	case CD_ADD_FRIEND_RET_TO_CLIENT:
		{

		}
		break;

	case CD_ID_CHECK_RET_TO_CLIENT:
		{
			ret = MSG_ID_Check_Ack(msgData);
		}
		break;
	}

	return ret;
}