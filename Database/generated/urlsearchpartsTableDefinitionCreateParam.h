#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table urlsearchparts.
 */
class urlsearchpartsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    urlsearchpartsTableDefinitionCreateParam();
    virtual ~urlsearchpartsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
