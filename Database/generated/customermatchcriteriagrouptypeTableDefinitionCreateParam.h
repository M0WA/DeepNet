#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table customermatchcriteriagrouptype.
 */
class customermatchcriteriagrouptypeTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    customermatchcriteriagrouptypeTableDefinitionCreateParam();
    virtual ~customermatchcriteriagrouptypeTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
