#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table fencedsearch.
 */
class fencedsearchTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    fencedsearchTableDefinitionCreateParam();
    virtual ~fencedsearchTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
