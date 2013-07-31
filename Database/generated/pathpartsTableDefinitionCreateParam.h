#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table pathparts.
 */
class pathpartsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    pathpartsTableDefinitionCreateParam();
    virtual ~pathpartsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
