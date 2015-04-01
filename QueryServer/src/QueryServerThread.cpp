/*
 * @file QueryServerThread.cpp
 * @date Jan 11, 2015
 * @uthor Moritz Wagner
 */

#include "QueryServerThread.h"

namespace queryserver {

QueryServerThread::QueryServerThread(const queryserver::QueryServerThreadConfig& conf)
: fastcgiserver::FastCGIServerThread(conf.GetDatabaseConfig(),conf.GetAcceptMutex(),conf.GetPort(),conf.GetBacklog())
, config(conf){
}

QueryServerThread::~QueryServerThread() {
}

}
