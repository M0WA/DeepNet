/**
 * @file DatabaseLogging.cpp
 * @author Moritz Wagner
 * @date 22.09.2012
 */

#include "DatabaseLogging.h"

#include <TimeTools.h>

#include "DatabaseLayer.h"
#include "DatabaseLoggingNotInitializedException.h"

namespace log {

DatabaseLogging::DatabaseLogging(database::DatabaseConfig* dbConfig)
: Logging()
, dbHelper(new database::DatabaseHelper()){

	if(dbHelper->CreateConnection(dbConfig) == 0){
		delete dbHelper;
		dbHelper = 0;
		THROW_EXCEPTION(DatabaseLoggingNotInitializedException,"could not create database connection");}
}

DatabaseLogging::~DatabaseLogging() {

	delete dbHelper;
	dbHelper = 0;
}

void DatabaseLogging::OnLog(const LogLevel levelMsg,const std::string& msg) {

	long int tid = syscall(SYS_gettid);

	database::logmessagesTableBase logMessage;

	logMessage.Set_loglevel(static_cast<long long>(levelMsg));
	logMessage.Set_message(msg);
	logMessage.Set_actiontime(tools::TimeTools::NowUTC());

	logMessage.Set_pid(static_cast<long long>(getpid()));
	logMessage.Set_tid(static_cast<long long>(tid));

	if(!applicationName.empty())
		logMessage.Set_appName(applicationName);

	std::string threadName;
	if(Logging::GetThreadNameByTID(tid, threadName)) {
		logMessage.Set_threadName(threadName);}

	logMessage.Insert(dbHelper->Connection());
}

}
