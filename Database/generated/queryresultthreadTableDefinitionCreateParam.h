#pragma once

#include "TableDefinitionCreateParam.h"

#include <string>

namespace database {

/**
 * @brief container for table definition create parameters of table queryresultthread.
 */
class queryresultthreadTableDefinitionCreateParam : public TableDefinitionCreateParam {

public:
    queryresultthreadTableDefinitionCreateParam();
    virtual ~queryresultthreadTableDefinitionCreateParam();

private:
    void CreateColumnDefinitions();

private:
    static std::string GetDatabaseName();
};

}
