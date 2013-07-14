#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table locksecondleveldomain.
 */
class locksecondleveldomainTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    locksecondleveldomainTableDefinitionCreateParam();
    virtual ~locksecondleveldomainTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
