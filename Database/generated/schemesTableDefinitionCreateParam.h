#pragma once

#include "TableDefinitionCreateParam.h"

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
};

}
