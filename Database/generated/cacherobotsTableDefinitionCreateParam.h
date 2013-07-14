#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table cacherobots.
 */
class cacherobotsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    cacherobotsTableDefinitionCreateParam();
    virtual ~cacherobotsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
