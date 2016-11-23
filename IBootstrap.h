#pragma once
#include <vector>
#include "common.h"
#include "IAppServer.h"
namespace CamCommon
{
	class IBootstrap
	{
	public:
		IBootstrap(){}
		~IBootstrap(){}
		virtual void Init() = 0;
		virtual bool Start() = 0;
		virtual void Stop() = 0;
		virtual void AddServer(IAppServer *) = 0;
		virtual void Loop() = 0;
		virtual void * GetEventBase() = 0;
	protected:
		std::vector<IAppServer *> AppServers;
		struct event_base* _base;
	};
}

