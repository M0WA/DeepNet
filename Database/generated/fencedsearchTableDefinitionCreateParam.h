#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table fencedsearch.
 */
class fencedsearchTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    fencedsearchTableDefinitionCreateParam();
    virtual ~fencedsearchTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
