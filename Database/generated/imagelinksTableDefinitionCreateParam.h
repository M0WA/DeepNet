#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table imagelinks.
 */
class imagelinksTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    imagelinksTableDefinitionCreateParam();
    virtual ~imagelinksTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
