#include "IAppSession.h"
#include "IAppServer.h"
#include "RefBaseClass.h"
#include "AppServer.h"
#include "AppSession.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG   
#include "vld.h"
#endif
#include "Object.h"  
#include "ManagerClass.h"
#include "SmartPtr.h"
#include "BootstrapFactory.h"
#include "concurrentqueue.h"
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib,"log4cpp.lib")
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
void testlog(){
	log4cpp::Appender *appender1 = new log4cpp::OstreamAppender("console", &std::cout);
	appender1->setLayout(new log4cpp::BasicLayout());

	log4cpp::Appender *appender2 = new log4cpp::FileAppender("default", "program.log");
	appender2->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category& root = log4cpp::Category::getRoot();
	root.setPriority(log4cpp::Priority::WARN);
	root.addAppender(appender1);

	log4cpp::Category& sub1 = log4cpp::Category::getInstance(std::string("sub1"));
	sub1.addAppender(appender2);

	// use of functions for logging messages
	root.error("root error");
	root.info("root info");
	sub1.error("sub1 error");
	sub1.warn("sub1 warn");

	// printf-style for logging variables
	root.warn("%d + %d == %s ?", 1, 1, "two");

	// use of streams for logging messages
	root << log4cpp::Priority::ERROR << "Streamed root error";
	root << log4cpp::Priority::INFO << "Streamed root info";
	sub1 << log4cpp::Priority::ERROR << "Streamed sub1 error";
	sub1 << log4cpp::Priority::WARN << "Streamed sub1 warn";

	// or this way:
	root.errorStream() << "Another streamed error";
	getchar();
}
void properties(){
	std::string initFileName = "log4cpp.properties";
	log4cpp::PropertyConfigurator::configure(initFileName);

	log4cpp::Category& root = log4cpp::Category::getRoot();

	log4cpp::Category& sub1 =
		log4cpp::Category::getInstance(std::string("sub1"));

	log4cpp::Category& sub2 =
		log4cpp::Category::getInstance(std::string("sub1.sub2"));

	root.warn("Storm is coming");

	sub1.debug("Received storm warning");
	sub1.info("Closing all hatches");
	for (int i = 0; i < 10000;i++)
	{
		sub2.debug("index=%d",i);
	}

	sub1.info("All hatches closed");

	root.info("Ready for storm.");

	log4cpp::Category::shutdown();
}
void testlockfree(){
	moodycamel::ConcurrentQueue<int> q;
	q.enqueue(25);
	LockFreeQueue<string> qq;
	{
		for (size_t i = 0; i < 100; i++)
		{
			string s = "***";
			qq.push(s);
		}
	}
	for (size_t i = 0; i < 100; i++)
	{
		const string *p = qq.pop();
		if (p!=NULL)
		cout << *p << endl;
	}
	int a;
	bool found = q.try_dequeue(a);
	assert(found && a == 25);
	getchar();
}
int main(){
	// log
	RefBaseClass* pVar = (RefBaseClass*)RefClassFactory::sharedClassFactory().createClassByName("RefHelloClass");
	int v = 5;
	pVar->registProperty();
	pVar->_propertyMap["set_pValue"](pVar, &v);
	pVar->display();
	pVar = (RefBaseClass*)RefClassFactory::sharedClassFactory().createClassByName("EchoTos");
	//testlog();
	testlockfree();
	return 0;
	// catch exception
	// mysql
#ifdef WIN32
	WSADATA wsa_data;
	WSAStartup(0x0201, &wsa_data);
#endif
	CMutex c;
	// bootstrap
	IBootstrap &boot = BootstrapFactory::CreateBootstrap();
	SmartPtr<IAppServer> server(new AppServer());
	SmartPtr<IAppSession> session(new AppSession());
	boot.AddServer(server.own());
	boot.Start();
	boot.Loop();
	boot.Stop();

	 pVar = (RefBaseClass*)RefClassFactory::sharedClassFactory().createClassByName("RefHelloClass");
	pVar->registProperty();
	pVar->_propertyMap["set_pValue"](pVar, &v);
	pVar->display();
	pVar = (RefBaseClass*)RefClassFactory::sharedClassFactory().createClassByName("EchoTos");
	
	pVar->ExecuteCommand(server.own(), session.own());
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