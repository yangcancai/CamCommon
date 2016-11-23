#include "NormalBootstrap.h"
using namespace CamCommon;
NormalBootstrap::NormalBootstrap()
{
	Init();
}
NormalBootstrap::~NormalBootstrap()
{
	if (_base)
	event_base_free(_base);
	AppServers.clear();
}
bool NormalBootstrap::Start(){
	for (unsigned int i = 0; i < AppServers.size(); i++){
		AppServers[i]->Setup(this);
		AppServers[i]->Start(8800);
	}
	return true;
}
void NormalBootstrap::Stop(){
	for (unsigned int i = 0; i < AppServers.size(); i++){
		AppServers[i]->Stop();
	}
}
void NormalBootstrap::AddServer(IAppServer * server){
	AppServers.push_back(server);
}
void NormalBootstrap::Init(){
	_base = event_base_new();
}
void NormalBootstrap::Loop(){
	event_base_dispatch(_base);
}
void* NormalBootstrap::GetEventBase(){
	return _base;
}
