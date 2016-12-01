#include "RollingAppender.h"

namespace CamCommon{
	RollingAppender::RollingAppender(string& name,string& fileName) :LogAppender(name,fileName)
	{
		
	}
	RollingAppender::~RollingAppender()
	{
	}
}
