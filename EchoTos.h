#pragma once
#include "CommandBase.h"
#include "AppSession.h"
#include "RequestInfo.h"
#include "ManagerClass.h"
namespace CamCommon
{
	class EchoTos :public CommandBase<AppSession, RequestBodyInfo<char>>, public  Object
	{
	public:
		DECLARE_CLASS(EchoTos)
		SYNTHESIZE(EchoTos, int*, _pValue)
			EchoTos(Object *obj) :Object(obj){}
		EchoTos(){}
		virtual ~EchoTos(){
			DELETE_CLASS(EchoTos);
		}
		static void* createInstance()
		{
			return new EchoTos(&ManagerClass::Instance());
		}
		virtual void registProperty()
		{
			_propertyMap.insert(pair<string, setValue>("set_pValue", set_pValue));
		}
		virtual void display()
		{
			cout << *get_pValue() << endl;
		}
		void ExecuteCommand(AppSession session, RequestBodyInfo<char> requestInfo){
			cout << "ExecuteCommand" << endl;
		}
		void ExecuteCommand(void* p, void* pp){
			cout << "ExecuteCommand" << endl;
		}
	private:
		int* _pValue;
	};
	IMPLEMENT_CLASS(EchoTos)

}