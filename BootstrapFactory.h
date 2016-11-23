#pragma once
#include "IBootstrap.h"
namespace CamCommon{
	class BootstrapFactory
	{
	public:
		static IBootstrap& CreateBootstrap();
	private:
		BootstrapFactory();
		~BootstrapFactory();
	};
}

