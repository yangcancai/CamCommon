
#include "RefClassFactory.h"
using namespace CamCommon;

RefClassFactory::RefClassFactory()
{
}


RefClassFactory::~RefClassFactory()
{
	cout << "ff" << endl;
}
void* RefClassFactory::createClassByName(string className)
{
	map<string, createClass>::const_iterator iter;
	iter = _classMap.find(className);
	if (iter == _classMap.end())
	{
		return NULL;
	}
	else
	{
		return iter->second();
	}
}
void RefClassFactory::registClass(string name, createClass method)
{
	_classMap.insert(pair<string,createClass>(name,method));
}
RefClassFactory& RefClassFactory::sharedClassFactory()
{
	 static RefClassFactory _sharedFactory;
	 return _sharedFactory;
}

