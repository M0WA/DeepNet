#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table cachepathparts.
 */
class cachepathpartsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    cachepathpartsTableDefinitionCreateParam();
    virtual ~cachepathpartsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
