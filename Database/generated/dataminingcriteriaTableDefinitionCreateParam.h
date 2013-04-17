#pragma once

#include "TableDefinitionCreateParam.h"

namespace database {

/**
 * @brief container for table definition create parameters of table dataminingcriteria.
 */
class dataminingcriteriaTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    dataminingcriteriaTableDefinitionCreateParam();
    virtual ~dataminingcriteriaTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();
};

}
