#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table logmessages.
 */
class logmessagesTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    logmessagesTableDefinitionCreateParam();
    virtual ~logmessagesTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
