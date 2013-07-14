#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table dockeypos.
 */
class dockeyposTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    dockeyposTableDefinitionCreateParam();
    virtual ~dockeyposTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
