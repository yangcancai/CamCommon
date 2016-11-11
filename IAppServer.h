#pragma once
#include <string>
using namespace std;
namespace CamCommon
{
	class IAppSession;
	class IAppServer
	{
	public:
		IAppServer(){};
		virtual ~IAppServer() = 0{};
		// find the session 
		virtual IAppSession* GetSession(string sessionID) = 0;
		// register new session
		virtual bool RegisterAppSession(IAppSession* session) = 0;
		// remove session
		virtual bool RemoveAppSession(string sessionID) = 0;
		// Starts this server instance
		// return true if start successful,else false
		virtual bool Start() = 0;
		// Stops the server instance.
		virtual void Stop() = 0;
		// Gets the name.
		virtual string Name() = 0;
		// Gets the session count.
		virtual int SessionCount() = 0;
	};
}

