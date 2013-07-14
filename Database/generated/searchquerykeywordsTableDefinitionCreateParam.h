#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table searchquerykeywords.
 */
class searchquerykeywordsTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    searchquerykeywordsTableDefinitionCreateParam();
    virtual ~searchquerykeywordsTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
