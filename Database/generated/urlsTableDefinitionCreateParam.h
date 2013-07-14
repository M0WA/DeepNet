#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table urls.
 */
class urlsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    urlsTableDefinitionCreateParam();
    virtual ~urlsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
