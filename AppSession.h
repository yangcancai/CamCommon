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
			return 0;
		}
	};
}
