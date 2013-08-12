/**
 *
 * @file QueryThread.cpp
 * @author Moritz Wagner
 * @date Aug 12, 2013
 *
 */

#include "QueryThread.h"

namespace queryserver {

QueryThread::QueryThread(threading::Thread::ThreadFunction func)
: threading::Thread(func,false){

}

QueryThread::~QueryThread() {
}

}
