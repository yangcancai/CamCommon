#pragma once
#include "common.h"
#include "LogAppender.h"
#include "IMutex.h"
#pragma warning(disable:4996)
namespace CamCommon{
	class  Log
	{
	public:
		Log();
		~Log();
		void AddAppender(LogAppender& appender);
		void Info(const char* stringFormat, ...);
		void RemoveAppender(const string& name);
	private:
		string Format(const char* stringFormat, va_list args);
		void Append(string& msg);
		void Write();
		void Write(string& msg);
		void Push(string& msg);
		LockFreeQueue<string> _q;
		string _fileName;
		int _fd;
		int _flags;
		int _mode;
		std::map<string, LogAppender> _mapAppender;
		CMutex _mapMutex;
	};
}
