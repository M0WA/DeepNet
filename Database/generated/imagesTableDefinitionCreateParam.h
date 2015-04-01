#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table images.
 */
class imagesTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    imagesTableDefinitionCreateParam();
    virtual ~imagesTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
