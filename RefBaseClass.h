#pragma once
#include "RefDynamicClass.h"
#include "ManagerClass.h"
namespace CamCommon
{
typedef void (*setValue)(void *baseClass, void* value);
class RefBaseClass : public Object
{
private:
	//DECLARE_CLASS(RefBaseClass)
	/*string RefBaseClassName;
	static RefDynamicClass* m_ClassNamedc;*/
public:
	RefBaseClass(Object * parent)
		:Object(parent){}
	RefBaseClass() {}
	virtual ~RefBaseClass() {}
	static void* createInstance() 
	{ 
		return new RefBaseClass(&ManagerClass::Instance()); 
	}
	virtual void registProperty() {}
	virtual void display() {}
	virtual void ExecuteCommand(void*, void*){}
	map<string, setValue> _propertyMap;

};

#define SYNTHESIZE(classType, varType, varName)                   \
public:                                                           \
	inline static void set##varName(void* cp, void* value){  \
	classType* tp = (classType*)cp;                               \
			tp->varName = (varType)value;                         \
	}                                                             \
	inline varType get##varName(void) const {                     \
	return varName;                                               \
	}

//IMPLEMENT_CLASS(RefBaseClass)
//RefDynamicClass* RefBaseClass::m_ClassNamedc = new RefDynamicClass("RefBaseClass", RefBaseClass::createInstance);
}
