#ifndef _COMMON__H_
#define _COMMON__H_


#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <event2/event.h>
#include <event2/buffer.h>
#include <event2/http.h>
#include <event2/http_struct.h>
#include <event2/keyvalq_struct.h>
#include <vector>
#include <iostream>
#include <map>
#include <mutex>
#include <atomic>
#include <thread>  
#include <stdio.h>
#include <event2/bufferevent.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event_struct.h>

// log4cpp
#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"
#include "log4cpp/PropertyConfigurator.hh"
//
#include <stddef.h>
// lock free queue
#include "concurrentqueue.h"
#include "LockFreeQueue.h"
using namespace std;

#endif