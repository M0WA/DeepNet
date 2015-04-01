#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table cachesecondleveldomain.
 */
class cachesecondleveldomainTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    cachesecondleveldomainTableDefinitionCreateParam();
    virtual ~cachesecondleveldomainTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
