#pragma once
#include "IBootstrap.h"
#include "IMutex.h"
#include "common.h"
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
		bool Start(int port);
		void Stop();
		string Name();
		int SessionCount();
		void Setup(IBootstrap* boot);
		bool Listen(int port);
		struct event_base* GetEventBase();
	private:
		struct evconnlistener *_listener;
		struct event_base *_base;
		IBootstrap* _boot;
		map<string, IAppSession*> _mapSession;
		CMutex lock;
	};
}


