#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table dict.
 */
class dictTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    dictTableDefinitionCreateParam();
    virtual ~dictTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
