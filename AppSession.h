#pragma once
#include "IAppSession.h"
namespace CamCommon
{
	class AppSession :public IAppSession
	{
	public:
		AppSession();
		~AppSession();
		IAppServer* GetAppServer(){
			return _server;
		}
		void SetAppServer(IAppServer* server){
			_server = server;
		}
		void SetSessionID(const string& sessionID){
			_sessionID = sessionID;
		}
		string SessionID(){
			return _sessionID;
		}
	private:
		IAppServer* _server;
		 string _sessionID;
	};
}
