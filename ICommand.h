#pragma once
#include "RefBaseClass.h"
namespace CamCommon
{
	template<class TAppSession, class TRequestInfo>
	class ICommand : public RefBaseClass
	{
	public:
		ICommand(){};
		virtual ~ICommand() = 0{};
		virtual string Name() = 0;
		virtual void ExecuteCommand(TAppSession session, TRequestInfo requestInfo) = 0;
	};
}

