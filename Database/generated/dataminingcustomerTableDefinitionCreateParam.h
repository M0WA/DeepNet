#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table dataminingcustomer.
 */
class dataminingcustomerTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    dataminingcustomerTableDefinitionCreateParam();
    virtual ~dataminingcustomerTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
