#pragma once
#include "common.h"
namespace CamCommon
{
	class IMutex
	{
	public:
		IMutex(){}
		virtual ~IMutex() = 0{}
		virtual void Lock()  = 0;
		virtual void UnLock()   = 0;
		virtual bool TryLock() = 0;
	};
	class CMutex : public IMutex
	{
	public:
		CMutex();
		~CMutex();
		void Lock() ;
		void UnLock() ;
		bool TryLock();
	private:
		 std::mutex lock;
	};
	class CLock
	{
	public:
		CLock( IMutex& lock);
		~CLock();
	private:
		 IMutex& _lock;
	};
}

