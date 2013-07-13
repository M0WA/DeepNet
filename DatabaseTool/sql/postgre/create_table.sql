
DROP TABLE topleveldomains;

/* topleveldomains - Postgre   */
CREATE TABLE topleveldomains
(
 ID BIGSERIAL NOT NULL,
 tld VARCHAR(255) NOT NULL
);

DROP TABLE cachesecondleveldomain;

/* cachesecondleveldomain - Postgre   */
CREATE TABLE cachesecondleveldomain
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL
);

DROP TABLE locksecondleveldomain;

/* locksecondleveldomain - Postgre   */
CREATE TABLE locksecondleveldomain
(
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 CRAWLERSESSION_ID INTEGER NOT NULL,
 schedule TIMESTAMP NOT NULL
);

DROP TABLE logmessages;

/* logmessages - Postgre   */
CREATE TABLE logmessages
(
 ID BIGSERIAL NOT NULL,
 loglevel INTEGER NOT NULL,
 message VARCHAR(2048) NOT NULL,
 actiontime TIMESTAMP NOT NULL,
 pid INTEGER NOT NULL,
 tid INTEGER NOT NULL,
 appName VARCHAR(255),
 threadName VARCHAR(255)
);

DROP TABLE cacherobots;

/* cacherobots - Postgre   */
CREATE TABLE cacherobots
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL
);

DROP TABLE cachehtml;

/* cachehtml - Postgre   */
CREATE TABLE cachehtml
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL
);

DROP TABLE queryresults;

/* queryresults - Postgre   */
CREATE TABLE queryresults
(
 ID BIGSERIAL NOT NULL,
 SEARCHQUERY_ID INTEGER NOT NULL,
 URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 order_position INTEGER NOT NULL
);

DROP TABLE urlstages;

/* urlstages - Postgre   */
CREATE TABLE urlstages
(
 ID BIGSERIAL NOT NULL,
 URL_ID INTEGER NOT NULL,
 response_code INTEGER,
 content_md5 CHAR(32),
 last_change TIMESTAMP,
 redirect_count INTEGER,
 download_speed INTEGER,
 upload_speed INTEGER,
 content_length INTEGER,
 content_type VARCHAR(255),
 primary_ip INTEGER,
 primary_port INTEGER,
 int_links INTEGER,
 ext_links INTEGER,
 download_time INTEGER,
 html_errors INTEGER,
 found_date TIMESTAMP NOT NULL
);

DROP TABLE documentcode;

/* documentcode - Postgre   */
CREATE TABLE documentcode
(
 ID BIGSERIAL NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 code VARCHAR(4096000) NOT NULL
);

DROP TABLE hyperlinks;

/* hyperlinks - Postgre   */
CREATE TABLE hyperlinks
(
 ID BIGSERIAL NOT NULL,
 TARGET_URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 count INTEGER NOT NULL
);

DROP TABLE keywordquery;

/* keywordquery - Postgre   */
CREATE TABLE keywordquery
(
 ID BIGSERIAL NOT NULL,
 query_part VARCHAR(255) NOT NULL
);

DROP TABLE metainfo;

/* metainfo - Postgre   */
CREATE TABLE metainfo
(
 ID BIGSERIAL NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 type INTEGER NOT NULL,
 value VARCHAR(255) NOT NULL
);

DROP TABLE customermatchcriteria;

/* customermatchcriteria - Postgre   */
CREATE TABLE customermatchcriteria
(
 ID BIGSERIAL NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 MATCHCRITERIA_ID INTEGER NOT NULL,
 type INTEGER NOT NULL
);

DROP TABLE schemes;

/* schemes - Postgre   */
CREATE TABLE schemes
(
 ID BIGSERIAL NOT NULL,
 scheme VARCHAR(255) NOT NULL
);

DROP TABLE customersessions;

/* customersessions - Postgre   */
CREATE TABLE customersessions
(
 ID BIGSERIAL NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 session VARCHAR(255) NOT NULL
);

DROP TABLE customersyncurl;

/* customersyncurl - Postgre   */
CREATE TABLE customersyncurl
(
 ID BIGSERIAL NOT NULL,
 URL_ID INTEGER NOT NULL,
 scheduled TIMESTAMP NOT NULL
);

DROP TABLE dataminingblacklist;

/* dataminingblacklist - Postgre   */
CREATE TABLE dataminingblacklist
(
 ID BIGSERIAL NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 domain VARCHAR(2048) NOT NULL
);

DROP TABLE docurl;

/* docurl - Postgre   */
CREATE TABLE docurl
(
 ID BIGSERIAL NOT NULL,
 DICT_ID INTEGER NOT NULL,
 URL_ID INTEGER NOT NULL
);

DROP TABLE images;

/* images - Postgre   */
CREATE TABLE images
(
 ID BIGSERIAL NOT NULL,
 SCHEME_ID INTEGER NOT NULL,
 TOPLEVELDOMAIN_ID INTEGER NOT NULL,
 SUBDOMAIN_ID INTEGER,
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 port INTEGER NOT NULL,
 path_part VARCHAR(2048) NOT NULL,
 search_part VARCHAR(2048) NOT NULL,
 url_md5 CHAR(32) NOT NULL,
 found_date TIMESTAMP NOT NULL
);

DROP TABLE dataminingcustomersession;

/* dataminingcustomersession - Postgre   */
CREATE TABLE dataminingcustomersession
(
 ID BIGSERIAL NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 session VARCHAR(255) NOT NULL
);

DROP TABLE latesturlstages;

/* latesturlstages - Postgre   */
CREATE TABLE latesturlstages
(
 ID BIGSERIAL NOT NULL,
 URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL
);

DROP TABLE imagelinks;

/* imagelinks - Postgre   */
CREATE TABLE imagelinks
(
 ID BIGSERIAL NOT NULL,
 TARGET_URL_ID INTEGER NOT NULL,
 IMAGE_URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL
);

DROP TABLE customerproductimages;

/* customerproductimages - Postgre   */
CREATE TABLE customerproductimages
(
 ID BIGSERIAL NOT NULL,
 PRODUCT_ID INTEGER NOT NULL,
 imageUrl VARCHAR(2048) NOT NULL
);

DROP TABLE customers;

/* customers - Postgre   */
CREATE TABLE customers
(
 ID BIGSERIAL NOT NULL,
 login VARCHAR(255) NOT NULL,
 password VARCHAR(255) NOT NULL
);

DROP TABLE cachesubdomain;

/* cachesubdomain - Postgre   */
CREATE TABLE cachesubdomain
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL
);

DROP TABLE dockey;

/* dockey - Postgre   */
CREATE TABLE dockey
(
 ID BIGSERIAL NOT NULL,
 DICT_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 occurrence INTEGER NOT NULL
);

DROP TABLE customerproductkeywords;

/* customerproductkeywords - Postgre   */
CREATE TABLE customerproductkeywords
(
 ID BIGSERIAL NOT NULL,
 PRODUCT_ID INTEGER NOT NULL,
 DICT_ID INTEGER NOT NULL
);

DROP TABLE dataminingcriteriaalerts;

/* dataminingcriteriaalerts - Postgre   */
CREATE TABLE dataminingcriteriaalerts
(
 ID BIGSERIAL NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 DATAMININGALERT_ID INTEGER NOT NULL,
 DATAMININGCRITERIA_ID INTEGER NOT NULL
);

DROP TABLE dataminingcustomer;

/* dataminingcustomer - Postgre   */
CREATE TABLE dataminingcustomer
(
 ID BIGSERIAL NOT NULL,
 login VARCHAR(255) NOT NULL,
 password VARCHAR(255) NOT NULL
);

DROP TABLE secondleveldomains;

/* secondleveldomains - Postgre   */
CREATE TABLE secondleveldomains
(
 ID BIGSERIAL NOT NULL,
 domain VARCHAR(255) NOT NULL
);

DROP TABLE customerdomains;

/* customerdomains - Postgre   */
CREATE TABLE customerdomains
(
 ID BIGSERIAL NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 domain VARCHAR(2048) NOT NULL,
 revisitInterval INTEGER NOT NULL,
 isDomainRegex INTEGER NOT NULL
);

DROP TABLE syncurls;

/* syncurls - Postgre   */
CREATE TABLE syncurls
(
 ID BIGSERIAL NOT NULL,
 URL_ID INTEGER NOT NULL,
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 CRAWLERSESSION_ID INTEGER NOT NULL,
 schedule TIMESTAMP NOT NULL
);

DROP TABLE crawlersessions;

/* crawlersessions - Postgre   */
CREATE TABLE crawlersessions
(
 ID BIGSERIAL NOT NULL
);

DROP TABLE urls;

/* urls - Postgre   */
CREATE TABLE urls
(
 ID BIGSERIAL NOT NULL,
 SCHEME_ID INTEGER NOT NULL,
 TOPLEVELDOMAIN_ID INTEGER NOT NULL,
 SUBDOMAIN_ID INTEGER,
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 port INTEGER NOT NULL,
 path_part VARCHAR(2048) NOT NULL,
 search_part VARCHAR(2048) NOT NULL,
 url_md5 CHAR(32) NOT NULL,
 found_date TIMESTAMP NOT NULL
);

DROP TABLE dataminingcriteria;

/* dataminingcriteria - Postgre   */
CREATE TABLE dataminingcriteria
(
 ID BIGSERIAL NOT NULL,
 keyword VARCHAR(2048) NOT NULL,
 type INTEGER NOT NULL
);

DROP TABLE customerkeywords;

/* customerkeywords - Postgre   */
CREATE TABLE customerkeywords
(
 ID BIGSERIAL NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 keyword VARCHAR(2048) NOT NULL,
 target VARCHAR(2048) NOT NULL,
 isKeywordRegex INTEGER NOT NULL
);

DROP TABLE dockeypos;

/* dockeypos - Postgre   */
CREATE TABLE dockeypos
(
 ID BIGSERIAL NOT NULL,
 DOCKEY_ID INTEGER NOT NULL,
 paragraph INTEGER NOT NULL,
 position INTEGER NOT NULL
);

DROP TABLE customerproducturls;

/* customerproducturls - Postgre   */
CREATE TABLE customerproducturls
(
 ID BIGSERIAL NOT NULL,
 PRODUCT_ID INTEGER NOT NULL,
 URL_ID INTEGER NOT NULL
);

DROP TABLE customersynccrawler;

/* customersynccrawler - Postgre   */
CREATE TABLE customersynccrawler
(
 ID BIGSERIAL NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 CRAWLERSESSION_ID INTEGER NOT NULL,
 scheduled TIMESTAMP NOT NULL
);

DROP TABLE customermatchcriteriagrouptype;

/* customermatchcriteriagrouptype - Postgre   */
CREATE TABLE customermatchcriteriagrouptype
(
 ID BIGSERIAL NOT NULL,
 CUSTOMERMATCHCRITERIA_ID INTEGER NOT NULL,
 type INTEGER NOT NULL,
 groupPosition INTEGER NOT NULL,
 isPrimaryKey INTEGER NOT NULL
);

DROP TABLE searchquerykeywords;

/* searchquerykeywords - Postgre   */
CREATE TABLE searchquerykeywords
(
 ID BIGSERIAL NOT NULL,
 KEYWORDQUERY_ID INTEGER NOT NULL,
 SEARCHQUERY_ID INTEGER NOT NULL
);

DROP TABLE customerqueries;

/* customerqueries - Postgre   */
CREATE TABLE customerqueries
(
 ID BIGSERIAL NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 query VARCHAR(2048) NOT NULL
);

DROP TABLE searchquery;

/* searchquery - Postgre   */
CREATE TABLE searchquery
(
 ID BIGSERIAL NOT NULL,
 session CHAR(64) NOT NULL
);

DROP TABLE docmeta;

/* docmeta - Postgre   */
CREATE TABLE docmeta
(
 ID BIGSERIAL NOT NULL,
 DICT_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 occurrence INTEGER NOT NULL,
 type INTEGER NOT NULL
);

DROP TABLE fencedsearch;

/* fencedsearch - Postgre   */
CREATE TABLE fencedsearch
(
 ID BIGSERIAL NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL
);

DROP TABLE dataminingalerts;

/* dataminingalerts - Postgre   */
CREATE TABLE dataminingalerts
(
 ID BIGSERIAL NOT NULL,
 type INTEGER NOT NULL,
 param VARCHAR(2048)
);

DROP TABLE cacheurl;

/* cacheurl - Postgre   */
CREATE TABLE cacheurl
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL
);

DROP TABLE dict;

/* dict - Postgre   */
CREATE TABLE dict
(
 ID BIGSERIAL NOT NULL,
 keyword VARCHAR(255) NOT NULL,
 occurrence INTEGER NOT NULL
);

DROP TABLE customerproducts;

/* customerproducts - Postgre   */
CREATE TABLE customerproducts
(
 ID BIGSERIAL NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 productNo VARCHAR(1024) NOT NULL,
 productName VARCHAR(1024) NOT NULL,
 productBrand VARCHAR(1024) NOT NULL
);

DROP TABLE customerdomainblacklist;

/* customerdomainblacklist - Postgre   */
CREATE TABLE customerdomainblacklist
(
 ID BIGSERIAL NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 path VARCHAR(2048) NOT NULL,
 isPathRegex INTEGER NOT NULL
);

DROP TABLE subdomains;

/* subdomains - Postgre   */
CREATE TABLE subdomains
(
 ID BIGSERIAL NOT NULL,
 subdomain VARCHAR(255) NOT NULL
);

DROP TABLE matchcriteria;

/* matchcriteria - Postgre   */
CREATE TABLE matchcriteria
(
 ID BIGSERIAL NOT NULL,
 regex VARCHAR(2048) NOT NULL
);

DROP TABLE cacheparsed;

/* cacheparsed - Postgre   */
CREATE TABLE cacheparsed
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL
);

