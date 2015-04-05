/*
 * DataMiningTools.h
 *
 *  Created on: 26.09.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

namespace database {
	class DatabaseConnection;
}

namespace toolbot {

class DataMiningTools {
public:
	DataMiningTools();
	virtual ~DataMiningTools();

public:
	static bool RegisterDataminingAlert(database::DatabaseConnection* db, const std::string& username, const std::string& criteria, const std::string& alertType, const std::string& alertParam);
	static bool InsertDataminingUser(database::DatabaseConnection* db, const std::string& username, const std::string& password);
	static bool InsertFencedUrl(database::DatabaseConnection* db, const std::string& username, const std::string& url);
};

}

