#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table queryresults.
 */
class queryresultsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    queryresultsTableDefinitionCreateParam();
    virtual ~queryresultsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
