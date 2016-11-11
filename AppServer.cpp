
#include "IAppServer.h"
#include "IAppSession.h"
#include "AppServer.h"
#include <string>
using namespace std;
using namespace CamCommon;
AppServer::AppServer()
{
}
AppServer::~AppServer()
{
}
IAppSession* AppServer::GetSession(string sessionID){
return NULL;
}
bool AppServer::RegisterAppSession(IAppSession* session){
return true;
}
bool AppServer::RemoveAppSession(string sessionID){
return true;
}
