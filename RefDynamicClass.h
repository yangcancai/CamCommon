#pragma once
#include "RefClassFactory.h"
namespace CamCommon
{
	class RefDynamicClass
	{
	public:
		RefDynamicClass(string name, createClass method)
		{
			RefClassFactory::sharedClassFactory().registClass(name, method);
		}
		~RefDynamicClass(){}
	};
#define DECLARE_CLASS(className) \
	string className##Name;        \
	static RefDynamicClass* m_className##dc;

#define IMPLEMENT_CLASS(className) \
	RefDynamicClass* className::m_className##dc = \
	new RefDynamicClass(#className, className::createInstance);

#define DELETE_CLASS(className) \
	if (m_className##dc != NULL){ \
	delete m_className##dc;}
}
