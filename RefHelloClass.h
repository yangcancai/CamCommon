#pragma once
#include "RefBaseClass.h"
#include "ManagerClass.h"
namespace CamCommon
{
	class RefHelloClass : public RefBaseClass, public Object
	{
	public:
		DECLARE_CLASS(RefHelloClass)
		SYNTHESIZE(RefHelloClass, int*, _pValue)
			RefHelloClass(Object * obj) :Object(obj){}
		RefHelloClass(){}
		virtual ~RefHelloClass(){
			DELETE_CLASS(RefHelloClass);
		}
		static void* createInstance()
		{
			return new RefHelloClass(&ManagerClass::Instance());
		}
		virtual void registProperty()
		{
			_propertyMap.insert(pair<string, setValue>("set_pValue", set_pValue));
		}
		virtual void display()
		{
			cout << *get_pValue() << endl;
		}
	protected:
		int *_pValue;
	};
	IMPLEMENT_CLASS(RefHelloClass);

}