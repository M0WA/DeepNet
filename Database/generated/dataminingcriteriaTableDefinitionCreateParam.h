#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table dataminingcriteria.
 */
class dataminingcriteriaTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    dataminingcriteriaTableDefinitionCreateParam();
    virtual ~dataminingcriteriaTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
