#include "logmessagesTableDefinitionCreateParam.h"
#include "TableColumnDefinitionCreateParam.h"
#include "TableColumnDefinition.h"
#include "logmessagesTableBase.h"
#include "DatabaseHelper.h"

#include <StringTools.h>

namespace database {

logmessagesTableDefinitionCreateParam::logmessagesTableDefinitionCreateParam()
: TableDefinitionCreateParam(GetDatabaseName(),"logmessages") {

    CreateColumnDefinitions();
}

logmessagesTableDefinitionCreateParam::~logmessagesTableDefinitionCreateParam() {
}

void logmessagesTableDefinitionCreateParam::CreateColumnDefinitions() {

    //
    // template: TableDefinitionCreateParam_CreateColumnDefinitions.inc.cpp
    //

    //creating column definition for ID
    columnDefinitions.push_back(logmessagesTableBase::GetDefinition_ID());

    //creating column definition for loglevel
    columnDefinitions.push_back(logmessagesTableBase::GetDefinition_loglevel());

    //creating column definition for message
    columnDefinitions.push_back(logmessagesTableBase::GetDefinition_message());

    //creating column definition for actiontime
    columnDefinitions.push_back(logmessagesTableBase::GetDefinition_actiontime());

    //creating column definition for pid
    columnDefinitions.push_back(logmessagesTableBase::GetDefinition_pid());

    //creating column definition for tid
    columnDefinitions.push_back(logmessagesTableBase::GetDefinition_tid());

    //creating column definition for appName
    columnDefinitions.push_back(logmessagesTableBase::GetDefinition_appName());

    //creating column definition for threadName
    columnDefinitions.push_back(logmessagesTableBase::GetDefinition_threadName());


	std::vector<std::string> tmpCombined;

}

std::string logmessagesTableDefinitionCreateParam::GetDatabaseName() {
    switch(DatabaseHelper::GetDatabaseType()) {
    case DB_MYSQL:
      return "logging";
    case DB_IBM_DB2:
      return "deepnet";
    case DB_POSTGRESQL:
      return "deepnet.public";
    case DB_INVALID_TYPE:
    default:
      return "";
    }
}

}
