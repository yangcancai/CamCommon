#pragma once
#include <string>
#include <map>
#include <iostream>
using namespace std;
namespace CamCommon
{
	typedef void* (*createClass)(void);
	class RefClassFactory
	{
	public:
		void* createClassByName(string className);
		void registClass(string name, createClass method);
		static RefClassFactory& sharedClassFactory();
	private:
		RefClassFactory();
		virtual ~RefClassFactory();
		map<string, createClass> _classMap;
	};
}

