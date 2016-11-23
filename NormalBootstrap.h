#pragma once
#include "IBootstrap.h"
namespace CamCommon{
	class NormalBootstrap : public IBootstrap
	{
	public:
		NormalBootstrap();
		~NormalBootstrap();
		void Init();
		bool Start();
		void Stop();
		void Loop();
		void AddServer(IAppServer *);
		void* GetEventBase();
	};
}

