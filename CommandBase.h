#pragma once
#include "ICommand.h"
namespace CamCommon
{
	template<class TAppSession, class TRequestInfo>
	class CommandBase : public ICommand<TAppSession, TRequestInfo>
	{
	public:
		CommandBase(){}
		~CommandBase(){}
		string Name(){ return ""; }
		void ExecuteCommand(TAppSession session, TRequestInfo requestInfo){}
	};
}
