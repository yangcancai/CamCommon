#pragma once
#include "common.h"
namespace CamCommon
{
	class IAppServer;
	class IAppSession
	{
	public:
		IAppSession(){}
		virtual ~IAppSession() = 0{}
		virtual IAppServer* GetAppServer() = 0;
		virtual void SetAppServer(IAppServer* server) = 0;
		virtual string SessionID() = 0;
		virtual void SetSessionID(const string& sessionID) = 0;
	};
}

