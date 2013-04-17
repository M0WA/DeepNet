#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table customerqueries.
 */
class customerqueriesTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customerqueriesTableDefinitionCreateParam();
    virtual ~customerqueriesTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
