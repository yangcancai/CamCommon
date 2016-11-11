#pragma once
#include <string>
using namespace std;
namespace CamCommon
{
	class IRequestInfo{
	public:
		IRequestInfo(){};
		virtual ~IRequestInfo() = 0{};
		virtual string Key() = 0;
	};
	template<class TRequestBody>
	class IRequestBodyInfo : public IRequestInfo
	{
	public:
		IRequestBodyInfo(){};
		virtual ~IRequestBodyInfo() = 0{};
		virtual TRequestBody Body() = 0;
	};
	template<class TRequestBody, class TRequestHeader>
	class IRequestAllInfo :public IRequestBodyInfo<TRequestBody>{
	public:
		IRequestAllInfo(){}
		virtual ~IRequestAllInfo() = 0{};
		virtual TRequestHeader Header() = 0;
	};
}

