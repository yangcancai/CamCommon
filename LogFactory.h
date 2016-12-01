#pragma once
#include "common.h"
#include "Log.h"
namespace CamCommon{
	class LogFactory
	{
	public:
		static Log& GetInstance();
	private:
		LogFactory();
		~LogFactory();
	};
}
