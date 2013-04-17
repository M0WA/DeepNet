#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table docmeta.
 */
class docmetaTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    docmetaTableDefinitionCreateParam();
    virtual ~docmetaTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
