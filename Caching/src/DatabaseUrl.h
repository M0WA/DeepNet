/**
 * @file DatabaseUrl.h
 * @author Moritz Wagner
 * @date 29.12.2012
 */

#pragma once

#include <map>
#include <vector>

#include <HttpUrl.h>

namespace database {
	class DatabaseConnection;
	class urlsTableBase;
}

namespace caching {
	class CacheDatabaseUrl;

/**
 * @brief class for database related functionality of URLs.
 * @see caching::CacheDatabaseUrl
 * @see network::HttpUrl
 * this class can only be used in conjunction with caching::CacheDatabaseUrl
 */
class DatabaseUrl : public network::HttpUrl {

	friend class caching::CacheDatabaseUrl;

private:
	DatabaseUrl();
	DatabaseUrl(database::DatabaseConnection* db, const long long& urlID);
	DatabaseUrl(database::DatabaseConnection* db, const network::HttpUrl& url);
	DatabaseUrl(database::DatabaseConnection* db, database::urlsTableBase* urlTbl);

public:
	virtual ~DatabaseUrl();
	bool operator==(const long long& urlID) const;

public:
	/**
	 * gets url id.
	 * @return url id.
	 */
	const long long GetUrlID() const;

	/**
	 * gets scheme id.
	 * @return scheme id.
	 */
	const long long GetSchemeID() const;

	/**
	 * gets subdomain id.
	 * @return subdomain id.
	 */
	const long long GetSubdomainID() const;

	/**
	 * gets secondlevel domain id.
	 * @return secondlevel domain id.
	 */
	const long long GetSecondLevelID() const;

	/**
	 * gets toplevel domain id.
	 * @return toplevel domain id.
	 */
	const long long GetTopLevelID() const;

	/**
	 * gets url path part id.
	 * @return url path part id.
	 */
	const long long GetUrlPathPartID() const;

	/**
	 * gets url search part id.
	 * @return url search part id.
	 */
	const long long GetUrlSearchPartID() const;

public:
	/**
	 * compares two urls by values not by md5 string
	 * @param rhs url to compare to.
	 * @param compareAuth true if authentication part should be respected in comparison.
	 * @return false if urls do not match, true if urls match.
	 */
	virtual bool DeepMatchUrl(const DatabaseUrl& rhs, const bool compareAuth = false) const;

public:
	/**
	 * gets backlinks for an url.
	 * @param db database connection.
	 * @param urlID url id for backlinks.
	 * @param mapIDUrls result backlinks url ids.
	 */
	static void GetBackLinks(
			database::DatabaseConnection* db,
			const long long& urlID,
			std::map<long long,DatabaseUrl>& mapIDUrls);

private:
	void InitByHttpUrl(database::DatabaseConnection* db);

	void InitByTable(database::DatabaseConnection* db,database::urlsTableBase* urlTbl);

	void InitByUrlID(database::DatabaseConnection* db, const long long& urlID);
	void InitByIDs(database::DatabaseConnection* db);

	void Store(database::DatabaseConnection* db,const std::vector<long long>& pathPartIDs);

private:
	long long urlID;
	long long schemeID;
	long long subdomainID;
	long long secondlevelID;
	long long toplevelID;
	long long urlPathPartID;
	long long urlSearchPartID;
};

}
