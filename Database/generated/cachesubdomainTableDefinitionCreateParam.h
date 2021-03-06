#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table cachesubdomain.
 */
class cachesubdomainTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    cachesubdomainTableDefinitionCreateParam();
    virtual ~cachesubdomainTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
