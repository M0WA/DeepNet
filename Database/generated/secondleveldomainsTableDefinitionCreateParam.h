#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table secondleveldomains.
 */
class secondleveldomainsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    secondleveldomainsTableDefinitionCreateParam();
    virtual ~secondleveldomainsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
