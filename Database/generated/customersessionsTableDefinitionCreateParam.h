#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table customersessions.
 */
class customersessionsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customersessionsTableDefinitionCreateParam();
    virtual ~customersessionsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
