#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table cacheurl.
 */
class cacheurlTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    cacheurlTableDefinitionCreateParam();
    virtual ~cacheurlTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
