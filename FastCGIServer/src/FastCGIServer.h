/**
 * @file FastCGIServer.h
 * @author Moritz Wagner
 * @date 12.03.2012
 */

#pragma once

#include <vector>
#include <string>

#include <Mutex.h>
#include <ConfigManager.h>
#include <DatabaseLayer.h>

namespace log {
	class Logging;
}

namespace errors {
	class Exception;
}

namespace fastcgiserver {
class FastCGIServerThread;

/**
 * @brief implements a fastcgi server instance.
 */
class FastCGIServer
{
protected:
	FastCGIServer();
public:
	virtual ~FastCGIServer();

public:
	/**
	 * starts fastcgi server.
	 * @param argc commandline arg count.
	 * @param argv commandline args.
	 * @return false on error, true on success.
	 */
	virtual bool StartServer(int argc, char** argv);

	/**
	 * stops fastcgi server.
	 * @return false on error, true on success.
	 */
	virtual bool StopServer();

public:
	/**
	 * generic function to catch untyped expressions.
	 */
	virtual void OnException();

	/**
	 * generic function to catch errors::Exception
	 * @param ex exception.
	 */
	virtual void OnException(errors::Exception& ex);

private:
	virtual FastCGIServerThread* CreateThreadPort(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, const int port, const int backlog = 0)=0;
	virtual FastCGIServerThread* CreateThreadSocket(database::DatabaseConfig* databaseConfig,threading::Mutex* acceptMutex, const std::string& filename, const int backlog = 0)=0;

	virtual void RegisterConfig() {}
	virtual bool InitConfig() {return true;}

	void RegisterSocketConfig();
	bool InitSocketConfig();

	void RegisterLoggingParams();
	void InitLoggingConfig();

	void RegisterDatabaseConfigParams(void);
	bool InitDatabaseConfigs(void);

	void RegisterCacheConfigParams();
	bool InitCacheConfigParams();

protected:
	/**
	 * server configuration.
	 */
	bot::ConfigManager config;

	/**
	 * database configuration.
	 */
	database::DatabaseConfig* databaseConfig;

	/**
	 * logging.
	 */
	log::Logging* logging;

	/**
	 * xsd for requests.
	 */
	std::string xsdRequestContent;

	/**
	 * xsd for responses.
	 */
	std::string xsdResponseContent;

private:
	threading::Mutex acceptMutex;
	std::vector<FastCGIServerThread*> threads;
	int basePort;
	int threadCount;
	std::string dictionaryFile;
	std::string affixFile;
	std::string requestXSD;
	std::string responseXSD;

	database::DatabaseHelper dbHelper;
};

}
