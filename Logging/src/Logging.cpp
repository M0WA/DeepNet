/**
 * @file Logging.h
 * @author Moritz Wagner
 * @date 29.01.2012
 */

#include "Logging.h"

#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <iostream>

namespace log {

Logging* Logging::instance = NULL;
threading::Mutex Logging::mutex;

Logging::Logging()
: isLocking(true)
, logLevel(LOGLEVEL_INFO)
, maxLogMsgLength(-1)
{
	Logging::instance = this;
}

Logging::~Logging()
{
}

void Logging::Log_Intern(LogLevel levelMsg,const std::string& msg)
{
	if(levelMsg>logLevel)
		return;

	bool locked = isLocking;
	if(locked)
		Logging::mutex.Lock();

	std::string preparedMessage = msg;
	if(maxLogMsgLength > 0 && msg.length() > (size_t)maxLogMsgLength) {
		preparedMessage = msg.substr(0,maxLogMsgLength);
		preparedMessage += "...";
	}

	OnLog(levelMsg,preparedMessage);

	if(locked)
		Logging::mutex.Unlock();
}

void Logging::Log(LogLevel levelMsg, const char* fmt,...) {

	if(instance && levelMsg > instance->logLevel)
		return;

	std::string msgOut;
	int n, size = 100;
	char *p = 0, *np = 0;
	va_list ap;

	if ((p = (char*)malloc (size)) == NULL)
		return;

	while (1) {
		va_start(ap, fmt);
		n = vsnprintf (p, size, fmt, ap);
		va_end(ap);
		if (n > -1 && n < size) {
			msgOut = p;
		    break; }
		if (n > -1)    // glibc 2.1
		   size = n+1;
		else           // glibc 2.0
		   size *= 2;
		if ((np = (char*)realloc(p, size)) == NULL) {
		   free(p);
		   p = 0;
		   break;
		} else {
		   p = np;
		}
	}
	if(p) {
		msgOut = p;
		free(p); }
	else
		return;

    if(instance)
    	instance->Log_Intern(levelMsg,msgOut);
    else{
    	Logging::Log(levelMsg,msgOut);}
}

void Logging::RegisterThreadID(const std::string& threadName) {
	instance->threadNames[syscall(SYS_gettid)] = threadName;
}

void Logging::Log(const LogLevel levelMsg,const std::string& msg) {
	if(instance)
		instance->Log_Intern(levelMsg,msg);
	else {
		std::string timeString,logLevelString;
		GetTimeString(timeString);
		GetLogLevelString(levelMsg, logLevelString);
		std::cout << "[" << timeString << "]" << logLevelString << msg << std::endl;
	}
}

void Logging::SetApplicationName(const std::string& applicationNameIn) {
	if(instance)
		instance->SetApplicationName_Intern(applicationNameIn);
}

void Logging::SetMaxLogLength(int maxLogMsgLengthIn) {
	if(instance)
		instance->SetMaxLogLength_Intern(maxLogMsgLengthIn);
}

void Logging::SetLogLevel(LogLevel logLevelIn) {
	if(instance)
		instance->SetLogLevel_Intern(logLevelIn);
}

Logging::LogLevel Logging::GetLogLevel() {
	if(instance)
		return instance->logLevel;
	return LOGLEVEL_MAX;
}

int Logging::GetMaxLogLength() {
	if(instance)
		return instance->maxLogMsgLength;
	return -1;
}

bool Logging::IsLogLevelTrace() {
	return (GetLogLevel() >= LOGLEVEL_TRACE);
}

void Logging::GetTimeString(std::string& timeString){

    time_t now = time(0);
    struct tm tmNow;
    gmtime_r(&now,&tmNow);

	const char* timeStringFormat = "%Y-%m-%d %H:%M:%S";
	char pszTimeString[80] = {0};
	strftime(pszTimeString, 80, timeStringFormat, &tmNow);
	timeString = pszTimeString;
}

void Logging::GetLogLevelString(const LogLevel logLevel, std::string& logLevelString) {

    switch(logLevel)
    {
    case LOGLEVEL_ERROR:
    	logLevelString = "[ERROR]";
    	break;
    case LOGLEVEL_WARN:
    	logLevelString = "[WARN] ";
    	break;
    case LOGLEVEL_INFO:
    	logLevelString = "[INFO] ";
    	break;
    case LOGLEVEL_TRACE:
    	logLevelString = "[TRACE]";
    	break;
    default:
    	logLevelString = "[UKNWN]";
    	break;
    }
}

void Logging::GetPIDTIDString(const std::string& applicationName,std::string& pidTIDString) {

	std::stringstream ssOut;
	__pid_t pid = getpid();
	ssOut << "[" << (!applicationName.empty() ? (applicationName + "-") : "") << getpid();

	long int tid = syscall(SYS_gettid);
	if(instance->threadNames.count(tid)) {
		ssOut << "-" << instance->threadNames[tid];}

	if(pid!=tid)
		ssOut << "-" << syscall(SYS_gettid);
	ssOut<< "]";
	pidTIDString = ssOut.str();
}

void Logging::SetMaxLogLength_Intern(int maxLogMsgLength) {
	this->maxLogMsgLength = maxLogMsgLength;
}

void Logging::SetLogLevel_Intern(LogLevel logLevel) {
	this->logLevel = logLevel;
}

void Logging::SetApplicationName_Intern(const std::string& applicationName) {
	this->applicationName=applicationName;
}


}
