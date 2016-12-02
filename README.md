# CamCommon
* implement C++ Reflection  and SmartPtr
* memory leak detect use Visual Leak Detector 
* server classes with libevent

# How to Install
* Download something 
   * Down load Visual Leak Detector for visual c++
   * Link: http://vld.codeplex.com/
   * Down load libevent
   * Link: http://libevent.org/
* Install and Setting 
   * c/c++ -> General -> Additional Include Directories = C:\Program Files (x86)\Visual Leak Detector\include
   * Linker -> General -> Additional Library Directories = C:\Program Files (x86)\Visual Leak Detector\lib\Win32
   * c/c++ -> General -> Additional Include Directories = libevent\include
   * Linker -> General -> Additional Library Directories = libevent\lib
   * c/c++ -> command -> /D WIN32
   
# How to use?
```c
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libevent.lib")
int main(){

#ifdef WIN32
    WSADATA wsa_data;
	WSAStartup(0x0201, &wsa_data);
#endif
    IBootstrap &boot = BootstrapFactory::CreateBootstrap();
    SmartPtr<IAppServer> server(new AppServer());
	SmartPtr<IAppSession> session(new AppSession());
	boot.AddServer(server.own());
	boot.Start();
	boot.Loop();
    
    
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
```
# Thanks
  * [SmartPtr](http://www.cnblogs.com/QG-whz/p/4777312.html)
  * [Leak Detector](http://www.cnblogs.com/chuncn/archive/2012/12/05/2803450.html)
  * [C++ Reflection](http://blog.csdn.net/cen616899547/article/details/9317323)
  * [SuperSocket](http://www.supersocket.net/)
  * [Libevent](http://libevent.org/)
 
# About author
  If you have any quetions,please contact `710180334@qq.com`
