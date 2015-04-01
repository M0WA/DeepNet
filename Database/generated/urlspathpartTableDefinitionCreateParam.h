#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table urlspathpart.
 */
class urlspathpartTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    urlspathpartTableDefinitionCreateParam();
    virtual ~urlspathpartTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
