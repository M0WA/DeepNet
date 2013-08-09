/**
 * @file Logging.h
 * @author Moritz Wagner
 * @date 29.01.2012
 */

#include "Logging.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

namespace log {

Logging* Logging::instance = NULL;
threading::Mutex Logging::mutex;

std::map<long int,std::string> Logging::threadNames;
threading::ReadWriteLock Logging::lockThreadNames;

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

void Logging::Log_Intern(const LogLevel levelMsg, const size_t length,const std::string& msg)
{
	if(levelMsg > logLevel)
		return;

	bool locked = isLocking;
	if(locked)
		Logging::mutex.Lock();

	std::string preparedMessage = msg;
	if(length > 0 && msg.length() > length) {
		preparedMessage = msg.substr(0,length);
		preparedMessage += "...";
	}

	OnLog(levelMsg,preparedMessage);

	if(locked)
		Logging::mutex.Unlock();
}

void Logging::FormatVAString(std::string& outString, const char* fmt, va_list& ap) {

	outString.clear();

	int n, size(100);
	char *p(0), *np(0);

	if ((p = (char*)malloc (size)) == NULL)
		return;

	while (1) {
		n = vsnprintf (p, size, fmt, ap);
		if (n > -1 && n < size) {
		    break; }

		if (n > -1) {  // glibc 2.1
		   size = n+1; }
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
		outString = p;
		free(p); }
	else
		return;
}

void Logging::Log(LogLevel levelMsg, const char* fmt,...) {

	if(instance && levelMsg > instance->logLevel)
		return;

	std::string msgOut;
	va_list args;
	va_start(args, fmt);
	FormatVAString(msgOut,fmt,args);
	va_end(args);

    if(instance)
    	instance->Log_Intern(levelMsg,instance->maxLogMsgLength,msgOut);
    else{
    	Logging::Log(levelMsg,msgOut);}
}

void Logging::LogUnlimited(LogLevel levelMsg, const char* fmt,...) {

	if(instance && levelMsg > instance->logLevel)
		return;

	std::string msgOut;
	va_list args;
	va_start(args, fmt);
	FormatVAString(msgOut,fmt,args);
	va_end(args);

    if(instance)
    	instance->Log_Intern(levelMsg,0,msgOut);
    else{
    	Logging::LogUnlimited(levelMsg,msgOut);}
}

void Logging::RegisterThreadID(const std::string& threadName) {

	lockThreadNames.WaitForWriteLock();
	threadNames[syscall(SYS_gettid)] = threadName;
	lockThreadNames.ReleaseLock();
}

void Logging::Log(const LogLevel levelMsg,const std::string& msg) {
	if(instance)
		instance->Log_Intern(levelMsg,instance->maxLogMsgLength,msg);
	else {
		std::string timeString,logLevelString;
		GetTimeString(timeString);
		GetLogLevelString(levelMsg, logLevelString);
		std::cout << "[" << timeString << "]" << logLevelString << msg << std::endl;
	}
}

void Logging::LogUnlimited(const LogLevel levelMsg,const std::string& msg) {
	if(instance)
		instance->Log_Intern(levelMsg,0,msg);
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

void Logging::SetMaxLogLength(size_t maxLogMsgLengthIn) {
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

bool Logging::IsLogLevelTrace() {
	return (GetLogLevel() >= LOGLEVEL_TRACE);
}

void Logging::GetTimeString(std::string& timeString){

    time_t now(time(0));
    struct tm tmNow;
    gmtime_r(&now,&tmNow);

	const char* timeStringFormat("%Y-%m-%d %H:%M:%S");
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
	__pid_t pid(getpid());
	ssOut << "[" << (!applicationName.empty() ? (applicationName + "-") : "") << getpid();

	std::string threadName;
	long int tid(syscall(SYS_gettid));
	if(GetThreadNameByTID(tid, threadName)) {
		ssOut << "-" << threadName;}

	if(pid!=tid)
		ssOut << "-" << tid;
	ssOut<< "]";
	pidTIDString = ssOut.str();
}

bool Logging::GetThreadNameByTID(const long int& tid, std::string& threadName) {
	threadName.clear();
	lockThreadNames.WaitForReadLock();
	if(threadNames.count(tid)) {
		threadName = threadNames.at(tid);}
	lockThreadNames.ReleaseLock();
	return !threadName.empty();
}

void Logging::SetMaxLogLength_Intern(size_t maxLogMsgLength) {
	this->maxLogMsgLength = maxLogMsgLength;
}

void Logging::SetLogLevel_Intern(LogLevel logLevel) {
	this->logLevel = logLevel;
}

void Logging::SetApplicationName_Intern(const std::string& applicationName) {
	this->applicationName=applicationName;
}

void Logging::LogError(const char* fmt,...) {

	if(instance && LOGLEVEL_ERROR > instance->logLevel)
		return;

	std::string msgOut;
	va_list args;
	va_start(args, fmt);
	FormatVAString(msgOut,fmt,args);
	va_end(args);

    if(instance)
    	instance->Log_Intern(LOGLEVEL_ERROR,0,msgOut);
    else{
    	Logging::LogUnlimited(LOGLEVEL_ERROR,msgOut);}
}

void Logging::LogWarn(const char* fmt,...){

	if(instance && LOGLEVEL_WARN > instance->logLevel)
		return;

	std::string msgOut;
	va_list args;
	va_start(args, fmt);
	FormatVAString(msgOut,fmt,args);
	va_end(args);

    if(instance)
    	instance->Log_Intern(LOGLEVEL_WARN,0,msgOut);
    else{
    	Logging::LogUnlimited(LOGLEVEL_WARN,msgOut);}
}

void Logging::LogInfo(const char* fmt,...){

	if(instance && LOGLEVEL_INFO > instance->logLevel)
		return;

	std::string msgOut;
	va_list args;
	va_start(args, fmt);
	FormatVAString(msgOut,fmt,args);
	va_end(args);

    if(instance)
    	instance->Log_Intern(LOGLEVEL_INFO,0,msgOut);
    else{
    	Logging::LogUnlimited(LOGLEVEL_INFO,msgOut);}
}

void Logging::LogTrace(const char* fmt,...){

	if(instance && LOGLEVEL_TRACE > instance->logLevel)
		return;

	std::string msgOut;
	va_list args;
	va_start(args, fmt);
	FormatVAString(msgOut,fmt,args);
	va_end(args);

    if(instance)
    	instance->Log_Intern(LOGLEVEL_TRACE,0,msgOut);
    else{
    	Logging::LogUnlimited(LOGLEVEL_TRACE,msgOut);}
}

}
