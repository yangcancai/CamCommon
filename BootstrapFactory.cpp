#include "BootstrapFactory.h"
#include "NormalBootstrap.h"
using namespace CamCommon;
BootstrapFactory::BootstrapFactory()
{
}
BootstrapFactory::~BootstrapFactory()
{
}
IBootstrap& BootstrapFactory::CreateBootstrap(){
	static NormalBootstrap bootstrap;
	return bootstrap;
}
