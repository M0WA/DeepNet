#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table customerdomainblacklist.
 */
class customerdomainblacklistTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customerdomainblacklistTableDefinitionCreateParam();
    virtual ~customerdomainblacklistTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
