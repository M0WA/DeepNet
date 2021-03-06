#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table subdomains.
 */
class subdomainsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    subdomainsTableDefinitionCreateParam();
    virtual ~subdomainsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
