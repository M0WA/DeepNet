#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table customermatchcriteria.
 */
class customermatchcriteriaTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customermatchcriteriaTableDefinitionCreateParam();
    virtual ~customermatchcriteriaTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
