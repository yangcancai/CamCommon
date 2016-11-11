#pragma once
#include "IRequestInfo.h"
#include <string>
using namespace std;
namespace CamCommon
{
	template<class TRequestBody>
	class RequestBodyInfo :public IRequestBodyInfo<TRequestBody>
	{
	public:
		RequestBodyInfo(){
		}
		RequestBodyInfo(string key, TRequestBody body){
			this->_body = body;
			this->_key = key;
		}
		~RequestBodyInfo(){
		}
		string Key(){
			return this->_key;
		}
		TRequestBody Body(){
			return this->_body;
		}
	private:
		TRequestBody _body;
		string _key;
	};

	template<class TRequestBody, class TRequestHeader>
	class RequestAllInfo :public IRequestAllInfo<TRequestBody, TRequestHeader>
	{
	public:
		RequestAllInfo(){
		}
		RequestAllInfo(string key, TRequestHeader header, TRequestBody body){
			this->_body = body;
			this->_key = key;
			this->_header = header;
		}
		~RequestAllInfo(){
		}
		string Key(){
			return this->_key;
		}
		TRequestBody Body(){
			return this->_body;
		}
		TRequestHeader Header(){
			return this->_header;
		}
	private:
		TRequestBody _body;
		string _key;
		TRequestHeader _header;
	};
}


