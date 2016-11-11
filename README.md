# CamCommon
implement C++ Reflection  and SmartPtr
and memory leak detect use Visual Leak Detector 
# step
*First : down load Visual Leak Detector for visual c++
    link: http://vld.codeplex.com/
*Install and Setting 
   * c/c++ -> General -> Additional Include Directories = C:\Program Files (x86)\Visual Leak Detector\include
   * Linker -> General -> Additional Library Directories = C:\Program Files (x86)\Visual Leak Detector\lib\Win32

# How to use?
```c++
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
```
