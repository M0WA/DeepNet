#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table matchcriteria.
 */
class matchcriteriaTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    matchcriteriaTableDefinitionCreateParam();
    virtual ~matchcriteriaTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
