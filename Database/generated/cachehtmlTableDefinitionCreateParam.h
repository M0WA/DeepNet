#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table cachehtml.
 */
class cachehtmlTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    cachehtmlTableDefinitionCreateParam();
    virtual ~cachehtmlTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
