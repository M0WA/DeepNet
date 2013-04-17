#pragma once

#include "TableDefinitionCreateParam.h"

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
};

}
