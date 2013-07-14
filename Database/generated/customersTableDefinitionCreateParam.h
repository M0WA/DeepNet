#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table customers.
 */
class customersTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customersTableDefinitionCreateParam();
    virtual ~customersTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
