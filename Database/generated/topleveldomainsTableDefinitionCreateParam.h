#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table topleveldomains.
 */
class topleveldomainsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    topleveldomainsTableDefinitionCreateParam();
    virtual ~topleveldomainsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
