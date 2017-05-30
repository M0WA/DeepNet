#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table searchqueryresultinfo.
 */
class searchqueryresultinfoTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    searchqueryresultinfoTableDefinitionCreateParam();
    virtual ~searchqueryresultinfoTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
