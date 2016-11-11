#include "ManagerClass.h"

using namespace CamCommon;
ManagerClass::ManagerClass()
{
}


ManagerClass::~ManagerClass()
{
}
ManagerClass& ManagerClass::Instance(){
		static ManagerClass _managerClass;
		return _managerClass;
}
