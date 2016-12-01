#pragma once
#include "LogAppender.h"
namespace CamCommon{
	class RollingAppender : LogAppender
	{
	public:
		RollingAppender(string& name,string& fileName);
		~RollingAppender();
	};
}

