#pragma once
namespace CamCommon
{
	class BinaryRequestInfo : public RequestBodyInfo<char>
	{
	public:
		BinaryRequestInfo(){}
		BinaryRequestInfo(string key, char body) :RequestBodyInfo(key, body){

		}
		~BinaryRequestInfo(){}

	};
}



