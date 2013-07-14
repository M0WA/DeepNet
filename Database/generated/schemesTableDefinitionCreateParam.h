#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table schemes.
 */
class schemesTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    schemesTableDefinitionCreateParam();
    virtual ~schemesTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
