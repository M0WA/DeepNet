#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table latesturlstages.
 */
class latesturlstagesTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    latesturlstagesTableDefinitionCreateParam();
    virtual ~latesturlstagesTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
