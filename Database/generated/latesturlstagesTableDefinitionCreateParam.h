#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table latesturlstages.
 */
class latesturlstagesTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    latesturlstagesTableDefinitionCreateParam();
    virtual ~latesturlstagesTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
