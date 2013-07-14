#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table syncurls.
 */
class syncurlsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    syncurlsTableDefinitionCreateParam();
    virtual ~syncurlsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
