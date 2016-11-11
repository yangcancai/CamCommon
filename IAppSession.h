#pragma once
namespace CamCommon
{
	class IAppServer;
	class IAppSession
	{
	public:
		IAppSession(){}
		virtual ~IAppSession() = 0{}
		virtual IAppServer* GetAppServer() = 0;
	};
}

