#pragma once
#include "Object.h"
namespace CamCommon
{
	class ManagerClass :public Object
	{
	public:
		static ManagerClass& Instance();
	private:
		ManagerClass();
		~ManagerClass();
	};
}
