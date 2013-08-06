#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table cacheurlsearchparts.
 */
class cacheurlsearchpartsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    cacheurlsearchpartsTableDefinitionCreateParam();
    virtual ~cacheurlsearchpartsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
