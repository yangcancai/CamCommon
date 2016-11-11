#pragma once
namespace CamCommon
{
	class AppServer : public IAppServer
	{
	public:
		AppServer();
		~AppServer();
		IAppSession* GetSession(string sessionID);
		bool RegisterAppSession(IAppSession* session);
		bool RemoveAppSession(string sessionID);
	};
}
