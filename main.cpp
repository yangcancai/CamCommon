#include "IAppSession.h"
#include "IAppServer.h"
#include "RefBaseClass.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG   
#include "vld.h"
#endif
#include "Object.h"  
#include "ManagerClass.h"
#include "SmartPtr.h"
using namespace std;
using namespace CamCommon;
namespace CamCommon
{
	class Student :public Object
	{
	public:
		Student(Object * parent = NULL)
			:Object(parent){
			++new_count;
		}
		~Student()
		{
			++delete_count;
		}
		static int new_count;
		static int delete_count;
	private:
		int stu_id;
	};
	int Student::new_count = 0;
	int Student::delete_count = 0;
	class  HelloWorld
	{
	public:
		HelloWorld(int a) :_a(a){}
		~HelloWorld(){}
		int a(){ return _a; }
	private:
		int _a;
	};
}
int main(){

	RefBaseClass* pVar = (RefBaseClass*)RefClassFactory::sharedClassFactory().createClassByName("RefHelloClass");
	int v = 5;
	pVar->registProperty();
	pVar->_propertyMap["set_pValue"](pVar, &v);
	pVar->display();
	pVar = (RefBaseClass*)RefClassFactory::sharedClassFactory().createClassByName("EchoTos");
    pVar->ExecuteCommand(NULL,NULL);
	v = 5;
	pVar->registProperty();
	pVar->_propertyMap["set_pValue"](pVar,&v);
	pVar->display();
	{
		Student* s = new Student(&ManagerClass::Instance());
	}
	cout << Student::new_count << endl;
	cout << Student::delete_count << endl;

	// SmartPtr
	SmartPtr<int> p(new int(5));
	cout << *p << endl;

	SmartPtr<HelloWorld> hello(new HelloWorld(88));
	cout << hello->a() << endl;
	SmartPtr<HelloWorld> hello1 = hello;
	hello1 = hello;
	SmartPtr<HelloWorld> hello3 = hello;
	SmartPtr<HelloWorld> hello4(new HelloWorld(88));
	hello3 = hello4;
	getchar();
	return 0;
}