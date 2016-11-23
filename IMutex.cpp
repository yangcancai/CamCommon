#include "IMutex.h"
using namespace CamCommon;
CMutex::CMutex()
{
}
CMutex::~CMutex()
{
}
void CMutex::Lock(){
	lock.lock();
}
void CMutex::UnLock(){
	lock.unlock();
}
bool CMutex::TryLock(){
	return lock.try_lock();
}
CLock::CLock(IMutex& lock) :_lock(lock)
{
	_lock.Lock();
}

CLock::~CLock()
{
	_lock.UnLock();
}