#pragma once
#include "common.h"
#pragma warning(disable:4996)
namespace CamCommon{
	class LogAppender
	{
	public:
		LogAppender(string& name,string& fileName);
		~LogAppender();
		void Appender(string& msg);
		string& Name();
	private:
		string _fileName;
		string _name;
		int _flags;
		int _mode;
		int _fd;
	};
}

