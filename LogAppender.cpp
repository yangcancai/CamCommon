#include "LogAppender.h"
#include <io.h>
namespace CamCommon{
	LogAppender::LogAppender(string& name,string& fileName) :_name(name),_fileName(fileName), _flags(O_CREAT | O_APPEND | O_WRONLY), _mode(00644)
	{
		_flags |= O_TRUNC;
		_fd = ::open(_fileName.c_str(), _flags, _mode);
	}
	LogAppender::~LogAppender()
	{
		if (_fd != -1) {
			::close(_fd);
			_fd = -1;
		}
	}
	void LogAppender::Appender(string& msg){
		if (!::write(_fd, msg.data(), msg.length())) {
		}
	}
	string& LogAppender::Name(){
		return _name;
	}
}