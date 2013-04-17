#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table dockey.
 */
class dockeyTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    dockeyTableDefinitionCreateParam();
    virtual ~dockeyTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
