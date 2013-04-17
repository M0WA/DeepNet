#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table customerproductkeywords.
 */
class customerproductkeywordsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customerproductkeywordsTableDefinitionCreateParam();
    virtual ~customerproductkeywordsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
