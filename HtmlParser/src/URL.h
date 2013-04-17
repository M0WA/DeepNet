/*
 * URL.h
 *
 *  Created on: 14.01.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <map>
#include <vector>
#include <string>

namespace database {
	class DatabaseConnection;
}

namespace caching {
	class CacheUrl;
}

namespace htmlparser {

class UrlParser;
class URL {

	friend class caching::CacheUrl;
	friend class UrlParser;

public:
	URL();
	virtual ~URL();
	bool operator<(URL const& rhs) const;
	bool operator==(URL const& rhs) const;
	bool operator==(const long long& urlID) const;

public:
	std::string Dump() const;
	void Dump(std::string& dump) const;
	bool CalculateFullUrl(database::DatabaseConnection* connection, const bool forceRecalculate = false);

	static bool GetBackLinks(database::DatabaseConnection* db, const long long urlID, std::map<long long,URL>& mapIDUrls);
	static bool PathPartIndex(database::DatabaseConnection* database, const URL& url);

public:
	inline const std::string& GetScheme()            const { return scheme;            }
	inline const std::string& GetFullUrl()           const { return fullUrl;           }
	inline const std::string& GetMD5()               const { return md5;               }
	inline const std::string& GetDomain()            const { return domain;            }
	inline const std::string& GetPort()              const { return port;              }
	inline const std::string& GetTLD()               const { return tld;               }
	inline const std::string& GetSecondLevelDomain() const { return secondleveldomain; }
	inline const std::string& GetSubdomain()         const { return subdomain;         }
	inline const std::string& GetPathPart()          const { return path_part;         }
	inline const std::string& GetPath()              const { return path;              }
	inline const std::string& GetDocument()          const { return document;          }
	inline const std::string& GetSearchPart()        const { return search_part;       }
	inline const std::string& GetFragmentPart()      const { return fragment_part;     }
	inline const std::string& GetAuthUser()          const { return auth_user;         }
	inline const std::string& GetAuthPass()          const { return auth_pass;         }

	inline const long long GetUrlID()         const { return urlID;         }
	inline const long long GetSchemeID()      const { return schemeID;      }
	inline const long long GetSubdomainID()   const { return subdomainID;   }
	inline const long long GetSecondLevelID() const { return secondlevelID; }
	inline const long long GetTopLevelID()    const { return toplevelID;    }

public:
	static bool DeepMatchURL(const URL& url1, const URL& url2);

private:
	void CalculatePortPart(database::DatabaseConnection* connection);
	void CalculateDomainPart(database::DatabaseConnection* connection);
	void CalculateSchemePart(database::DatabaseConnection* connection);

private:
	std::string fullUrl;

	std::string domain;
	std::string scheme;
	std::string subdomain;
	std::string secondleveldomain;
	std::string tld;
	std::string port;
	std::string path_part;
	std::string search_part;
	std::string fragment_part;

	std::string path;
	std::string document;

	std::string auth_user;
	std::string auth_pass;

	std::string md5;

	long long urlID;
	long long schemeID;
	long long toplevelID;
	long long secondlevelID;
	long long subdomainID;

	bool isCalculated;
};

}
