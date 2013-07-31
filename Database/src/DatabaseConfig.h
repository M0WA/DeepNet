/**
 * @file DatabaseConfig.h
 * @author Moritz Wagner
 * @date 29.04.2012
 */

#pragma once

#include <string>

#include "DatabaseTypes.h"

namespace database {

/**
 * @brief generic database configuration.
 * this class serves as a base class for a specialized,
 * database-manufacturer related configuration class.
 * @see database::MySQLDatabaseConfig
 * @see database::DB2DatabaseConfig
 * @see database::PostgreSQLDatabaseConfig
 */
class DatabaseConfig {
protected:
	/**
	 * construct with a certain DatabaseType.
	 * @param type database type.
	 */
	DatabaseConfig(const DatabaseType& type);

public:
	virtual ~DatabaseConfig();

	/**
	 * sets the database type.
	 * @param type database type.
	 */
	inline void SetType(const DatabaseType& type) { this->type = type; }

	/**
	 * sets database host.
	 * @param host hostname of database.
	 */
	inline void SetHost(const std::string& host) { this->host = host; }

	/**
	 * sets database port.
	 * @param port of database.
	 */
	inline void SetPort(const int port) { this->port = port; }

	/**
	 * sets database name.
	 * @param db of database.
	 */
	inline void SetDatabaseName(const std::string& db) { this->db   = db;   }

	/**
	 * sets username for database.
	 * @param user username.
	 */
	inline void SetUser(const std::string& user) { this->user = user; }

	/**
	 * sets password for database.
	 * @param pass password.
	 */
	inline void SetPass(const std::string& pass) { this->pass = pass; }

	/**
	 * sets log query setting.
	 * @param logQuery true to enable, false to disable
	 */
	inline void SetLogQuery(const bool& logQuery) { this->logQuery = logQuery; }

	/**
	 * gets database type.
	 * @return database type
	 */
	inline const DatabaseType& GetType() const { return this->type; }

	/**
	 * gets database host.
	 * @return database host
	 */
	inline const std::string& GetHost() const { return this->host; }

	/**
	 * gets database port.
	 * @return database port
	 */
	inline int GetPort() const { return this->port; }

	/**
	 * gets name of database.
	 * @return database name
	 */
	inline const std::string& GetDatabaseName() const { return this->db; }

	/**
	 * gets username.
	 * @return username
	 */
	inline const std::string& GetUser() const { return this->user; }

	/**
	 * gets password.
	 * @return password
	 */
	inline const std::string&  GetPass() const { return this->pass; }

	/**
	 * gets log query setting.
	 * @return true,false
	 */
	inline bool GetLogQuery() const { return this->logQuery; }

private:
	DatabaseType type;
	std::string host;
	unsigned int port;
	std::string db;
	std::string user;
	std::string pass;
	bool logQuery;
};

}
