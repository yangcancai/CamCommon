
#include "IAppServer.h"
#include "IAppSession.h"
#include "AppServer.h"
#include "AppSession.h"
#include "IBootstrap.h"
#include "SmartPtr.h"
#include <string>
using namespace std;
using namespace CamCommon;
static void conn_readcb(struct bufferevent *bev, void *ctx)
{
	if (bev == NULL || ctx == NULL) {
		return;
	}
	AppSession *session = (AppSession *)ctx;
	AppServer* server = ((AppServer*)session->GetAppServer());
	struct evbuffer *input = bufferevent_get_input(bev);
	if (evbuffer_get_length(input) == 0) {
		bufferevent_free(bev);
	}
	char ch = 0;
	int len = bufferevent_read(bev, &ch, sizeof(char));
	bufferevent_free(bev);
	event_base_loopbreak(server->GetEventBase());

}
static void conn_eventcb(struct bufferevent *bev, short events, void *ctx)
{
	if (bev == NULL || ctx == NULL) {
		return;
	}
	if (events & BEV_EVENT_EOF) {
	}
	else if (events & BEV_EVENT_ERROR) {
	}
	bufferevent_free(bev);
}
static void	listener_cb(struct evconnlistener *listener, evutil_socket_t fd,
struct sockaddr *sa, int socklen, void *arg) {

	AppServer *server = (AppServer *)arg;
	struct bufferevent *bev;
	bev = bufferevent_socket_new(server->GetEventBase(), fd, BEV_OPT_CLOSE_ON_FREE);
	if (!bev) {
		event_base_loopbreak(server->GetEventBase());
		return;
	}
	AppSession *ss = new AppSession();
	string sessionID = "000";
	ss->SetSessionID(sessionID);
	ss->SetAppServer(server);
	server->RegisterAppSession(ss);
	bufferevent_setcb(bev, conn_readcb, NULL, conn_eventcb, ss);
	bufferevent_enable(bev, EV_WRITE | EV_READ);
}
AppServer::AppServer()
{
}
AppServer::~AppServer()
{
	CLock lock(this->lock);
	map<string, IAppSession*>::iterator it;
	for (it = _mapSession.begin(); it != _mapSession.end();++it)
	{
		delete it->second;
	}
	_mapSession.clear();
	if (_listener)
		evconnlistener_free(_listener);
}
IAppSession* AppServer::GetSession(string sessionID){
	CLock lock(this->lock);
	map<string, IAppSession*>::iterator it = _mapSession.find(sessionID);
	if (it != _mapSession.end()){
		return it->second;
	}
	return NULL;
}
bool AppServer::RegisterAppSession(IAppSession* session){
	CLock lock(this->lock);
	map<string, IAppSession*>::iterator it = _mapSession.find(session->SessionID());
	if (it != _mapSession.end()){
		it->second = session;
	}
	else{
		_mapSession.insert(pair<string, IAppSession*>(session->SessionID(), session));
	}
	return true;
}
bool AppServer::RemoveAppSession(string sessionID){
	CLock lock(this->lock);
	map<string, IAppSession*>::iterator it = _mapSession.find(sessionID);
	if (it != _mapSession.end()){
		_mapSession.erase(it);
	}
	return true;
}
bool AppServer::Start(int port){
	return Listen(port);
}
void AppServer::Stop(){

}
string AppServer::Name(){
	return "";
}
int AppServer::SessionCount(){
	return 0;
}
void AppServer::Setup(IBootstrap* boot){
	_boot = boot;
	_base = (event_base*)_boot->GetEventBase();
}

struct event_base* AppServer::GetEventBase(){
	return _base;
}
bool AppServer::Listen(int port){
	struct sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	_listener = evconnlistener_new_bind(_base, listener_cb, this,
		LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE, -1,
		(struct sockaddr*)&sin,
		sizeof(sin));

	if (!_listener) {
		return false;
	}
	return true;
}



