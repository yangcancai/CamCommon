#include "Log.h"
#include <io.h>

namespace CamCommon{
Log::Log()
{

}
Log::~Log()
{
}
void Log::AddAppender(LogAppender& Appender){
	string name = Appender.Name();
	CLock lock(_mapMutex);
	_mapAppender.insert(std::pair<string,LogAppender>(name,Appender));
}
void Log::RemoveAppender(const string& name){
	CLock lock(_mapMutex);
	std::map<string,LogAppender>::iterator it= _mapAppender.find(name);
	if (it != _mapAppender.end()){
		_mapAppender.erase(it);
	}
}
void Log::Info(const char* stringFormat, ...){
	va_list va;
	va_start(va, stringFormat);
	string msg = Format(stringFormat, va);
	Append(msg);
	va_end(va);
}
void Log::Append(string& msg){
	// push to queue
	Push(msg);
	// write to disk
	// Write(msg);
}
void Log::Push(string& msg){
	int try_count = 0;
	while (!_q.push(msg)){
		try_count++;
		// try 100 
		if (try_count > 100){
			break;
		}
	}
}
void Log::Write(){
	// 
	const string*  msg = _q.pop();
	// write to disk
	if (msg != NULL){
		Write((string)*msg);
	}
}
// write to disk
void Log::Write(string& msg){
	//
	CLock lock(_mapMutex);
	{
		for (map<string, LogAppender>::iterator i = _mapAppender.begin(); i != _mapAppender.end(); ++i)
		{
			i->second.Appender(msg);
		}
	}
}
string Log::Format(const char* format, va_list args){
	size_t size = 1024;
	char* buffer = new char[size];

	while (1) {
		va_list args_copy;

#if defined(_MSC_VER) || defined(__BORLANDC__)
		args_copy = args;
#else
		va_copy(args_copy, args);
#endif

		int n = _vsnprintf(buffer, size, format, args_copy);

		va_end(args_copy);

		// If that worked, return a string.
		if ((n > -1) && (static_cast<size_t>(n) < size)) {
			std::string s(buffer);
			delete[] buffer;
			return s;
		}

		// Else try again with more space.
		size = (n > -1) ?
			n + 1 :   // ISO/IEC 9899:1999
			size * 2; // twice the old size

		delete[] buffer;
		buffer = new char[size];
	}
}
}
