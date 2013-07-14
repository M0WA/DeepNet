#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table customermatchcriteria.
 */
class customermatchcriteriaTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customermatchcriteriaTableDefinitionCreateParam();
    virtual ~customermatchcriteriaTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
