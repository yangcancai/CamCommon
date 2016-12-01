#include "LogFactory.h"
#include <io.h>
namespace CamCommon{
	LogFactory::LogFactory()
	{
	}
	LogFactory::~LogFactory()
	{
	}
	Log& LogFactory::GetInstance(){
		static Log log;
		return log;
	}
}
