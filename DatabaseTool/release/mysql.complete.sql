SET foreign_key_checks=0;

CREATE DATABASE IF NOT EXISTS `sync`;
DROP DATABASE `sync`;
CREATE DATABASE `sync`
  DEFAULT CHARACTER SET utf8
  DEFAULT COLLATE utf8_general_ci;

CREATE DATABASE IF NOT EXISTS `contents`;
DROP DATABASE `contents`;
CREATE DATABASE `contents`
  DEFAULT CHARACTER SET utf8
  DEFAULT COLLATE utf8_general_ci;

CREATE DATABASE IF NOT EXISTS `lexicon`;
DROP DATABASE `lexicon`;
CREATE DATABASE `lexicon`
  DEFAULT CHARACTER SET utf8
  DEFAULT COLLATE utf8_general_ci;

CREATE DATABASE IF NOT EXISTS `documents`;
DROP DATABASE `documents`;
CREATE DATABASE `documents`
  DEFAULT CHARACTER SET utf8
  DEFAULT COLLATE utf8_general_ci;

CREATE DATABASE IF NOT EXISTS `commercesearch`;
DROP DATABASE `commercesearch`;
CREATE DATABASE `commercesearch`
  DEFAULT CHARACTER SET utf8
  DEFAULT COLLATE utf8_general_ci;

CREATE DATABASE IF NOT EXISTS `datamining`;
DROP DATABASE `datamining`;
CREATE DATABASE `datamining`
  DEFAULT CHARACTER SET utf8
  DEFAULT COLLATE utf8_general_ci;

CREATE DATABASE IF NOT EXISTS `queryserver`;
DROP DATABASE `queryserver`;
CREATE DATABASE `queryserver`
  DEFAULT CHARACTER SET utf8
  DEFAULT COLLATE utf8_general_ci;

CREATE DATABASE IF NOT EXISTS `logging`;
DROP DATABASE `logging`;
CREATE DATABASE `logging`
  DEFAULT CHARACTER SET utf8
  DEFAULT COLLATE utf8_general_ci;
CREATE USER 'write'@'localhost' IDENTIFIED BY 'Ahrah5leFup5BaidYoh1INgiKa9soocoael3eaLeiV8ooVauquee8SohzeeF2oa0';
CREATE USER 'read'@'localhost' IDENTIFIED BY 'kiz8Cah7ooW0fiehChi8shaikaeseQu2Oow4iex6bi7IiCaiaiyouM2lxohsh9Sh';

GRANT SELECT, UPDATE, INSERT, DELETE ON `sync`.* TO 'write'@'localhost';
GRANT SELECT ON `sync`.* TO 'read'@'localhost';

GRANT SELECT, UPDATE, INSERT, DELETE ON `content`.* TO 'write'@'localhost';
GRANT SELECT ON `content`.* TO 'read'@'localhost';

GRANT SELECT, UPDATE, INSERT, DELETE ON `lexicon`.* TO 'write'@'localhost';
GRANT SELECT ON `lexicon`.* TO 'read'@'localhost';

GRANT SELECT, UPDATE, INSERT, DELETE ON `documents`.* TO 'write'@'localhost';
GRANT SELECT ON `documents`.* TO 'read'@'localhost';

GRANT SELECT, UPDATE, INSERT, DELETE ON `queryserver`.* TO 'write'@'localhost';
GRANT SELECT ON `queryserver`.* TO 'read'@'localhost';

GRANT SELECT, UPDATE, INSERT, DELETE ON `webifserver`.* TO 'write'@'localhost';
GRANT SELECT ON `webifserver`.* TO 'read'@'localhost';

GRANT SELECT, UPDATE, INSERT, DELETE ON `logging`.* TO 'write'@'localhost';
GRANT SELECT ON `logging`.* TO 'read'@'localhost';

FLUSH PRIVILEGES;


/* topleveldomains - MySQL */
CREATE TABLE IF NOT EXISTS  documents.topleveldomains (ID INTEGER);
DROP TABLE documents.topleveldomains;
CREATE TABLE documents.topleveldomains
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 tld VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__TOPLEVELDOMAINS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__TOPLEVELDOMAINS_TLD UNIQUE (tld)
) Engine=InnoDB;
SHOW WARNINGS;


/* cachesecondleveldomain - MySQL */
CREATE TABLE IF NOT EXISTS  logging.cachesecondleveldomain (ID INTEGER);
DROP TABLE logging.cachesecondleveldomain;
CREATE TABLE logging.cachesecondleveldomain
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHESECONDLEVELDOMAIN_ID PRIMARY KEY (ID)
) Engine=Archive, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* locksecondleveldomain - MySQL */
CREATE TABLE IF NOT EXISTS  sync.locksecondleveldomain (ID INTEGER);
DROP TABLE sync.locksecondleveldomain;
CREATE TABLE sync.locksecondleveldomain
(
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 CRAWLERSESSION_ID INTEGER NOT NULL,
 schedule TIMESTAMP NOT NULL,
 CONSTRAINT PRI__LOCKSECONDLEVELDOMAIN_SECONDLEVELDOMAIN_ID PRIMARY KEY (SECONDLEVELDOMAIN_ID),
 INDEX IDX__locksecondleveldomain_CRAWLERSESSION_ID (CRAWLERSESSION_ID DESC)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* logmessages - MySQL */
CREATE TABLE IF NOT EXISTS  logging.logmessages (ID INTEGER);
DROP TABLE logging.logmessages;
CREATE TABLE logging.logmessages
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 loglevel INTEGER NOT NULL,
 message VARCHAR(2048) NOT NULL,
 actiontime TIMESTAMP NOT NULL,
 pid INTEGER NOT NULL,
 tid INTEGER NOT NULL,
 appName VARCHAR(255),
 threadName VARCHAR(255),
 CONSTRAINT PRI__LOGMESSAGES_ID PRIMARY KEY (ID)
) Engine=Archive, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* cacherobots - MySQL */
CREATE TABLE IF NOT EXISTS  logging.cacherobots (ID INTEGER);
DROP TABLE logging.cacherobots;
CREATE TABLE logging.cacherobots
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEROBOTS_ID PRIMARY KEY (ID)
) Engine=Archive, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* cachehtml - MySQL */
CREATE TABLE IF NOT EXISTS  logging.cachehtml (ID INTEGER);
DROP TABLE logging.cachehtml;
CREATE TABLE logging.cachehtml
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEHTML_ID PRIMARY KEY (ID)
) Engine=Archive, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* queryresults - MySQL */
CREATE TABLE IF NOT EXISTS  queryserver.queryresults (ID INTEGER);
DROP TABLE queryserver.queryresults;
CREATE TABLE queryserver.queryresults
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 SEARCHQUERY_ID INTEGER NOT NULL,
 URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 order_position INTEGER NOT NULL,
 CONSTRAINT PRI__QUERYRESULTS_ID PRIMARY KEY (ID),
 INDEX IDX__queryresults_ORDER_POSITION (order_position ASC)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* urlstages - MySQL */
CREATE TABLE IF NOT EXISTS  contents.urlstages (ID INTEGER);
DROP TABLE contents.urlstages;
CREATE TABLE contents.urlstages
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
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
 found_date TIMESTAMP NOT NULL,
 CONSTRAINT PRI__URLSTAGES_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* documentcode - MySQL */
CREATE TABLE IF NOT EXISTS  contents.documentcode (ID INTEGER);
DROP TABLE contents.documentcode;
CREATE TABLE contents.documentcode
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 code VARCHAR(4096000) NOT NULL,
 CONSTRAINT PRI__DOCUMENTCODE_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* hyperlinks - MySQL */
CREATE TABLE IF NOT EXISTS  contents.hyperlinks (ID INTEGER);
DROP TABLE contents.hyperlinks;
CREATE TABLE contents.hyperlinks
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 TARGET_URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 count INTEGER NOT NULL,
 CONSTRAINT PRI__HYPERLINKS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__HYPERLINKS_TARGET_URL_ID_URLSTAGE_ID UNIQUE (TARGET_URL_ID,URLSTAGE_ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* keywordquery - MySQL */
CREATE TABLE IF NOT EXISTS  queryserver.keywordquery (ID INTEGER);
DROP TABLE queryserver.keywordquery;
CREATE TABLE queryserver.keywordquery
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 query_part VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__KEYWORDQUERY_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__KEYWORDQUERY_QUERY_PART UNIQUE (query_part)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* metainfo - MySQL */
CREATE TABLE IF NOT EXISTS  contents.metainfo (ID INTEGER);
DROP TABLE contents.metainfo;
CREATE TABLE contents.metainfo
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 type INTEGER NOT NULL,
 value VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__METAINFO_ID PRIMARY KEY (ID),
 INDEX IDX__metainfo_TYPE (type DESC)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* customermatchcriteria - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.customermatchcriteria (ID INTEGER);
DROP TABLE commercesearch.customermatchcriteria;
CREATE TABLE commercesearch.customermatchcriteria
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 MATCHCRITERIA_ID INTEGER NOT NULL,
 type INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERMATCHCRITERIA_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* schemes - MySQL */
CREATE TABLE IF NOT EXISTS  documents.schemes (ID INTEGER);
DROP TABLE documents.schemes;
CREATE TABLE documents.schemes
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 scheme VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__SCHEMES_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SCHEMES_SCHEME UNIQUE (scheme)
) Engine=InnoDB;
SHOW WARNINGS;


/* customersessions - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.customersessions (ID INTEGER);
DROP TABLE commercesearch.customersessions;
CREATE TABLE commercesearch.customersessions
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 session VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__CUSTOMERSESSIONS_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* customersyncurl - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.customersyncurl (ID INTEGER);
DROP TABLE commercesearch.customersyncurl;
CREATE TABLE commercesearch.customersyncurl
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 URL_ID INTEGER NOT NULL,
 scheduled TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CUSTOMERSYNCURL_ID PRIMARY KEY (ID),
 INDEX IDX__customersyncurl_SCHEDULED (scheduled ASC)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* dataminingblacklist - MySQL */
CREATE TABLE IF NOT EXISTS  datamining.dataminingblacklist (ID INTEGER);
DROP TABLE datamining.dataminingblacklist;
CREATE TABLE datamining.dataminingblacklist
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 domain VARCHAR(2048) NOT NULL,
 CONSTRAINT PRI__DATAMININGBLACKLIST_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* docurl - MySQL */
CREATE TABLE IF NOT EXISTS  lexicon.docurl (ID INTEGER);
DROP TABLE lexicon.docurl;
CREATE TABLE lexicon.docurl
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 DICT_ID INTEGER NOT NULL,
 URL_ID INTEGER NOT NULL,
 CONSTRAINT PRI__DOCURL_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DOCURL_URL_ID_DICT_ID UNIQUE (URL_ID,DICT_ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* images - MySQL */
CREATE TABLE IF NOT EXISTS  documents.images (ID INTEGER);
DROP TABLE documents.images;
CREATE TABLE documents.images
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 SCHEME_ID INTEGER NOT NULL,
 TOPLEVELDOMAIN_ID INTEGER NOT NULL,
 SUBDOMAIN_ID INTEGER,
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 port INTEGER NOT NULL,
 path_part VARCHAR(2048) NOT NULL,
 search_part VARCHAR(2048) NOT NULL,
 url_md5 CHAR(32) NOT NULL,
 found_date TIMESTAMP NOT NULL,
 CONSTRAINT PRI__IMAGES_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__IMAGES_URL_MD5 UNIQUE (url_md5)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* dataminingcustomersession - MySQL */
CREATE TABLE IF NOT EXISTS  datamining.dataminingcustomersession (ID INTEGER);
DROP TABLE datamining.dataminingcustomersession;
CREATE TABLE datamining.dataminingcustomersession
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 session VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__DATAMININGCUSTOMERSESSION_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DATAMININGCUSTOMERSESSION_SESSION UNIQUE (session)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* latesturlstages - MySQL */
CREATE TABLE IF NOT EXISTS  contents.latesturlstages (ID INTEGER);
DROP TABLE contents.latesturlstages;
CREATE TABLE contents.latesturlstages
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 CONSTRAINT PRI__LATESTURLSTAGES_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__LATESTURLSTAGES_URL_ID UNIQUE (URL_ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* imagelinks - MySQL */
CREATE TABLE IF NOT EXISTS  contents.imagelinks (ID INTEGER);
DROP TABLE contents.imagelinks;
CREATE TABLE contents.imagelinks
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 TARGET_URL_ID INTEGER NOT NULL,
 IMAGE_URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 CONSTRAINT PRI__IMAGELINKS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__IMAGELINKS_TARGET_URL_ID_URLSTAGE_ID_IMAGE_URL_ID UNIQUE (TARGET_URL_ID,URLSTAGE_ID,IMAGE_URL_ID )
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* customerproductimages - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.customerproductimages (ID INTEGER);
DROP TABLE commercesearch.customerproductimages;
CREATE TABLE commercesearch.customerproductimages
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 PRODUCT_ID INTEGER NOT NULL,
 imageUrl VARCHAR(2048) NOT NULL,
 CONSTRAINT PRI__CUSTOMERPRODUCTIMAGES_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* customers - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.customers (ID INTEGER);
DROP TABLE commercesearch.customers;
CREATE TABLE commercesearch.customers
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 login VARCHAR(255) NOT NULL,
 password VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__CUSTOMERS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__CUSTOMERS_LOGIN UNIQUE (login)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* cachesubdomain - MySQL */
CREATE TABLE IF NOT EXISTS  logging.cachesubdomain (ID INTEGER);
DROP TABLE logging.cachesubdomain;
CREATE TABLE logging.cachesubdomain
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHESUBDOMAIN_ID PRIMARY KEY (ID)
) Engine=Archive, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* dockey - MySQL */
CREATE TABLE IF NOT EXISTS  lexicon.dockey (ID INTEGER);
DROP TABLE lexicon.dockey;
CREATE TABLE lexicon.dockey
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 DICT_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 occurrence INTEGER NOT NULL,
 CONSTRAINT PRI__DOCKEY_ID PRIMARY KEY (ID),
 INDEX IDX__dockey_OCCURRENCE (occurrence DESC)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* customerproductkeywords - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.customerproductkeywords (ID INTEGER);
DROP TABLE commercesearch.customerproductkeywords;
CREATE TABLE commercesearch.customerproductkeywords
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 PRODUCT_ID INTEGER NOT NULL,
 DICT_ID INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERPRODUCTKEYWORDS_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* dataminingcriteriaalerts - MySQL */
CREATE TABLE IF NOT EXISTS  datamining.dataminingcriteriaalerts (ID INTEGER);
DROP TABLE datamining.dataminingcriteriaalerts;
CREATE TABLE datamining.dataminingcriteriaalerts
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 DATAMININGALERT_ID INTEGER NOT NULL,
 DATAMININGCRITERIA_ID INTEGER NOT NULL,
 CONSTRAINT PRI__DATAMININGCRITERIAALERTS_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* dataminingcustomer - MySQL */
CREATE TABLE IF NOT EXISTS  datamining.dataminingcustomer (ID INTEGER);
DROP TABLE datamining.dataminingcustomer;
CREATE TABLE datamining.dataminingcustomer
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 login VARCHAR(255) NOT NULL,
 password VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__DATAMININGCUSTOMER_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DATAMININGCUSTOMER_LOGIN UNIQUE (login)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* secondleveldomains - MySQL */
CREATE TABLE IF NOT EXISTS  documents.secondleveldomains (ID INTEGER);
DROP TABLE documents.secondleveldomains;
CREATE TABLE documents.secondleveldomains
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 domain VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__SECONDLEVELDOMAINS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SECONDLEVELDOMAINS_DOMAIN UNIQUE (domain)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* customerdomains - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.customerdomains (ID INTEGER);
DROP TABLE commercesearch.customerdomains;
CREATE TABLE commercesearch.customerdomains
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 domain VARCHAR(2048) NOT NULL,
 revisitInterval INTEGER NOT NULL,
 isDomainRegex INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERDOMAINS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__CUSTOMERDOMAINS_CUSTOMER_ID UNIQUE (CUSTOMER_ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* syncurls - MySQL */
CREATE TABLE IF NOT EXISTS  sync.syncurls (ID INTEGER);
DROP TABLE sync.syncurls;
CREATE TABLE sync.syncurls
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 URL_ID INTEGER NOT NULL,
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 CRAWLERSESSION_ID INTEGER NOT NULL,
 schedule TIMESTAMP NOT NULL,
 CONSTRAINT PRI__SYNCURLS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SYNCURLS_URL_ID UNIQUE (URL_ID),
 INDEX IDX__syncurls_SCHEDULE (schedule ASC),
 INDEX IDX__syncurls_CRAWLERSESSION_ID (CRAWLERSESSION_ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* crawlersessions - MySQL */
CREATE TABLE IF NOT EXISTS  sync.crawlersessions (ID INTEGER);
DROP TABLE sync.crawlersessions;
CREATE TABLE sync.crawlersessions
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 CONSTRAINT PRI__CRAWLERSESSIONS_ID PRIMARY KEY (ID)
) Engine=Memory;
SHOW WARNINGS;


/* urls - MySQL */
CREATE TABLE IF NOT EXISTS  documents.urls (ID INTEGER);
DROP TABLE documents.urls;
CREATE TABLE documents.urls
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 SCHEME_ID INTEGER NOT NULL,
 TOPLEVELDOMAIN_ID INTEGER NOT NULL,
 SUBDOMAIN_ID INTEGER,
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 port INTEGER NOT NULL,
 path_part VARCHAR(2048) NOT NULL,
 search_part VARCHAR(2048) NOT NULL,
 url_md5 CHAR(32) NOT NULL,
 found_date TIMESTAMP NOT NULL,
 CONSTRAINT PRI__URLS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__URLS_URL_MD5 UNIQUE (url_md5)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* dataminingcriteria - MySQL */
CREATE TABLE IF NOT EXISTS  datamining.dataminingcriteria (ID INTEGER);
DROP TABLE datamining.dataminingcriteria;
CREATE TABLE datamining.dataminingcriteria
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 keyword VARCHAR(2048) NOT NULL,
 type INTEGER NOT NULL,
 CONSTRAINT PRI__DATAMININGCRITERIA_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* customerkeywords - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.customerkeywords (ID INTEGER);
DROP TABLE commercesearch.customerkeywords;
CREATE TABLE commercesearch.customerkeywords
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 keyword VARCHAR(2048) NOT NULL,
 target VARCHAR(2048) NOT NULL,
 isKeywordRegex INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERKEYWORDS_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* dockeypos - MySQL */
CREATE TABLE IF NOT EXISTS  lexicon.dockeypos (ID INTEGER);
DROP TABLE lexicon.dockeypos;
CREATE TABLE lexicon.dockeypos
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 DOCKEY_ID INTEGER NOT NULL,
 paragraph INTEGER NOT NULL,
 position INTEGER NOT NULL,
 CONSTRAINT PRI__DOCKEYPOS_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* customerproducturls - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.customerproducturls (ID INTEGER);
DROP TABLE commercesearch.customerproducturls;
CREATE TABLE commercesearch.customerproducturls
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 PRODUCT_ID INTEGER NOT NULL,
 URL_ID INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERPRODUCTURLS_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* customersynccrawler - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.customersynccrawler (ID INTEGER);
DROP TABLE commercesearch.customersynccrawler;
CREATE TABLE commercesearch.customersynccrawler
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 CRAWLERSESSION_ID INTEGER NOT NULL,
 scheduled TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CUSTOMERSYNCCRAWLER_ID PRIMARY KEY (ID),
 INDEX IDX__customersynccrawler_SCHEDULED (scheduled ASC),
 INDEX IDX__customersynccrawler_CRAWLERSESSION_ID (CRAWLERSESSION_ID ASC)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* customermatchcriteriagrouptype - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.customermatchcriteriagrouptype (ID INTEGER);
DROP TABLE commercesearch.customermatchcriteriagrouptype;
CREATE TABLE commercesearch.customermatchcriteriagrouptype
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 CUSTOMERMATCHCRITERIA_ID INTEGER NOT NULL,
 type INTEGER NOT NULL,
 groupPosition INTEGER NOT NULL,
 isPrimaryKey INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERMATCHCRITERIAGROUPTYPE_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* searchquerykeywords - MySQL */
CREATE TABLE IF NOT EXISTS  queryserver.searchquerykeywords (ID INTEGER);
DROP TABLE queryserver.searchquerykeywords;
CREATE TABLE queryserver.searchquerykeywords
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 KEYWORDQUERY_ID INTEGER NOT NULL,
 SEARCHQUERY_ID INTEGER NOT NULL,
 CONSTRAINT PRI__SEARCHQUERYKEYWORDS_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* customerqueries - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.customerqueries (ID INTEGER);
DROP TABLE commercesearch.customerqueries;
CREATE TABLE commercesearch.customerqueries
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 query VARCHAR(2048) NOT NULL,
 CONSTRAINT PRI__CUSTOMERQUERIES_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* searchquery - MySQL */
CREATE TABLE IF NOT EXISTS  queryserver.searchquery (ID INTEGER);
DROP TABLE queryserver.searchquery;
CREATE TABLE queryserver.searchquery
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 session CHAR(64) NOT NULL,
 CONSTRAINT PRI__SEARCHQUERY_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* docmeta - MySQL */
CREATE TABLE IF NOT EXISTS  lexicon.docmeta (ID INTEGER);
DROP TABLE lexicon.docmeta;
CREATE TABLE lexicon.docmeta
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 DICT_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 occurrence INTEGER NOT NULL,
 CONSTRAINT PRI__DOCMETA_ID PRIMARY KEY (ID),
 INDEX IDX__docmeta_OCCURRENCE (occurrence DESC)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* dataminingalerts - MySQL */
CREATE TABLE IF NOT EXISTS  datamining.dataminingalerts (ID INTEGER);
DROP TABLE datamining.dataminingalerts;
CREATE TABLE datamining.dataminingalerts
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 type INTEGER NOT NULL,
 param VARCHAR(2048),
 CONSTRAINT PRI__DATAMININGALERTS_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* cacheurl - MySQL */
CREATE TABLE IF NOT EXISTS  logging.cacheurl (ID INTEGER);
DROP TABLE logging.cacheurl;
CREATE TABLE logging.cacheurl
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEURL_ID PRIMARY KEY (ID)
) Engine=Archive, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* dict - MySQL */
CREATE TABLE IF NOT EXISTS  lexicon.dict (ID INTEGER);
DROP TABLE lexicon.dict;
CREATE TABLE lexicon.dict
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 keyword VARCHAR(255) NOT NULL,
 occurrence INTEGER NOT NULL,
 CONSTRAINT PRI__DICT_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DICT_KEYWORD UNIQUE (keyword),
 INDEX IDX__dict_OCCURRENCE (occurrence DESC)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* customerproducts - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.customerproducts (ID INTEGER);
DROP TABLE commercesearch.customerproducts;
CREATE TABLE commercesearch.customerproducts
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 productNo VARCHAR(1024) NOT NULL,
 productName VARCHAR(1024) NOT NULL,
 productBrand VARCHAR(1024) NOT NULL,
 CONSTRAINT PRI__CUSTOMERPRODUCTS_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* customerdomainblacklist - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.customerdomainblacklist (ID INTEGER);
DROP TABLE commercesearch.customerdomainblacklist;
CREATE TABLE commercesearch.customerdomainblacklist
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 path VARCHAR(2048) NOT NULL,
 isPathRegex INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERDOMAINBLACKLIST_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* subdomains - MySQL */
CREATE TABLE IF NOT EXISTS  documents.subdomains (ID INTEGER);
DROP TABLE documents.subdomains;
CREATE TABLE documents.subdomains
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 subdomain VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__SUBDOMAINS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SUBDOMAINS_SUBDOMAIN UNIQUE (subdomain)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* matchcriteria - MySQL */
CREATE TABLE IF NOT EXISTS  commercesearch.matchcriteria (ID INTEGER);
DROP TABLE commercesearch.matchcriteria;
CREATE TABLE commercesearch.matchcriteria
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 regex VARCHAR(2048) NOT NULL,
 CONSTRAINT PRI__MATCHCRITERIA_ID PRIMARY KEY (ID)
) Engine=InnoDB, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


/* cacheparsed - MySQL */
CREATE TABLE IF NOT EXISTS  logging.cacheparsed (ID INTEGER);
DROP TABLE logging.cacheparsed;
CREATE TABLE logging.cacheparsed
(
 ID INTEGER AUTO_INCREMENT NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEPARSED_ID PRIMARY KEY (ID)
) Engine=Archive, ROW_FORMAT=COMPRESSED;
SHOW WARNINGS;


ALTER TABLE queryserver.queryresults ADD CONSTRAINT FK__QUERYRESULTS_SEARCHQUERY_ID FOREIGN KEY (SEARCHQUERY_ID) REFERENCES queryserver.searchquery (ID);

ALTER TABLE contents.urlstages ADD CONSTRAINT FK__URLSTAGES_URL_ID FOREIGN KEY (URL_ID) REFERENCES documents.urls (ID);

ALTER TABLE contents.documentcode ADD CONSTRAINT FK__DOCUMENTCODE_URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES contents.urlstages (ID);

ALTER TABLE contents.hyperlinks ADD CONSTRAINT FK__HYPERLINKS_TARGET_URL_ID FOREIGN KEY (TARGET_URL_ID) REFERENCES documents.urls (ID);

ALTER TABLE contents.hyperlinks ADD CONSTRAINT FK__HYPERLINKS_URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES contents.urlstages (ID);

ALTER TABLE contents.metainfo ADD CONSTRAINT FK__METAINFO_URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES contents.urlstages (ID);

ALTER TABLE commercesearch.customermatchcriteria ADD CONSTRAINT FK__CUSTOMERMATCHCRITERIA_CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES commercesearch.customerdomains (ID);

ALTER TABLE commercesearch.customermatchcriteria ADD CONSTRAINT FK__CUSTOMERMATCHCRITERIA_MATCHCRITERIA_ID FOREIGN KEY (MATCHCRITERIA_ID) REFERENCES commercesearch.matchcriteria (ID);

ALTER TABLE commercesearch.customersessions ADD CONSTRAINT FK__CUSTOMERSESSIONS_CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES commercesearch.customers (ID);

ALTER TABLE datamining.dataminingblacklist ADD CONSTRAINT FK__DATAMININGBLACKLIST_CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES datamining.dataminingcustomer (ID);

ALTER TABLE lexicon.docurl ADD CONSTRAINT FK__DOCURL_DICT_ID FOREIGN KEY (DICT_ID) REFERENCES lexicon.dict (ID);

ALTER TABLE lexicon.docurl ADD CONSTRAINT FK__DOCURL_URL_ID FOREIGN KEY (URL_ID) REFERENCES documents.urls (ID);

ALTER TABLE documents.images ADD CONSTRAINT FK__IMAGES_SCHEME_ID FOREIGN KEY (SCHEME_ID) REFERENCES documents.schemes (ID);

ALTER TABLE documents.images ADD CONSTRAINT FK__IMAGES_TOPLEVELDOMAIN_ID FOREIGN KEY (TOPLEVELDOMAIN_ID) REFERENCES documents.topleveldomains (ID);

ALTER TABLE documents.images ADD CONSTRAINT FK__IMAGES_SUBDOMAIN_ID FOREIGN KEY (SUBDOMAIN_ID) REFERENCES documents.subdomains (ID);

ALTER TABLE documents.images ADD CONSTRAINT FK__IMAGES_SECONDLEVELDOMAIN_ID FOREIGN KEY (SECONDLEVELDOMAIN_ID) REFERENCES documents.secondleveldomains (ID);

ALTER TABLE datamining.dataminingcustomersession ADD CONSTRAINT FK__DATAMININGCUSTOMERSESSION_CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES datamining.dataminingcustomer (ID);

ALTER TABLE contents.latesturlstages ADD CONSTRAINT FK__LATESTURLSTAGES_URL_ID FOREIGN KEY (URL_ID) REFERENCES documents.urls (ID);

ALTER TABLE contents.latesturlstages ADD CONSTRAINT FK__LATESTURLSTAGES_URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES contents.urlstages (ID);

ALTER TABLE contents.imagelinks ADD CONSTRAINT FK__IMAGELINKS_TARGET_URL_ID FOREIGN KEY (TARGET_URL_ID) REFERENCES documents.urls (ID);

ALTER TABLE contents.imagelinks ADD CONSTRAINT FK__IMAGELINKS_IMAGE_URL_ID FOREIGN KEY (IMAGE_URL_ID) REFERENCES documents.images (ID);

ALTER TABLE contents.imagelinks ADD CONSTRAINT FK__IMAGELINKS_URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES contents.urlstages (ID);

ALTER TABLE commercesearch.customerproductimages ADD CONSTRAINT FK__CUSTOMERPRODUCTIMAGES_PRODUCT_ID FOREIGN KEY (PRODUCT_ID) REFERENCES commercesearch.customerproducts (ID);

ALTER TABLE lexicon.dockey ADD CONSTRAINT FK__DOCKEY_DICT_ID FOREIGN KEY (DICT_ID) REFERENCES lexicon.dict (ID);

ALTER TABLE lexicon.dockey ADD CONSTRAINT FK__DOCKEY_URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES contents.urlstages (ID);

ALTER TABLE commercesearch.customerproductkeywords ADD CONSTRAINT FK__CUSTOMERPRODUCTKEYWORDS_PRODUCT_ID FOREIGN KEY (PRODUCT_ID) REFERENCES commercesearch.customerproducts (ID);

ALTER TABLE commercesearch.customerproductkeywords ADD CONSTRAINT FK__CUSTOMERPRODUCTKEYWORDS_DICT_ID FOREIGN KEY (DICT_ID) REFERENCES lexicon.dict (ID);

ALTER TABLE datamining.dataminingcriteriaalerts ADD CONSTRAINT FK__DATAMININGCRITERIAALERTS_CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES datamining.dataminingcustomer (ID);

ALTER TABLE datamining.dataminingcriteriaalerts ADD CONSTRAINT FK__DATAMININGCRITERIAALERTS_DATAMININGALERT_ID FOREIGN KEY (DATAMININGALERT_ID) REFERENCES datamining.dataminingalerts (ID);

ALTER TABLE datamining.dataminingcriteriaalerts ADD CONSTRAINT FK__DATAMININGCRITERIAALERTS_DATAMININGCRITERIA_ID FOREIGN KEY (DATAMININGCRITERIA_ID) REFERENCES datamining.dataminingcriteria (ID);

ALTER TABLE commercesearch.customerdomains ADD CONSTRAINT FK__CUSTOMERDOMAINS_CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES commercesearch.customers (ID);

ALTER TABLE sync.syncurls ADD CONSTRAINT FK__SYNCURLS_URL_ID FOREIGN KEY (URL_ID) REFERENCES documents.urls (ID);

ALTER TABLE sync.syncurls ADD CONSTRAINT FK__SYNCURLS_SECONDLEVELDOMAIN_ID FOREIGN KEY (SECONDLEVELDOMAIN_ID) REFERENCES documents.secondleveldomains (ID);

ALTER TABLE documents.urls ADD CONSTRAINT FK__URLS_SCHEME_ID FOREIGN KEY (SCHEME_ID) REFERENCES documents.schemes (ID);

ALTER TABLE documents.urls ADD CONSTRAINT FK__URLS_TOPLEVELDOMAIN_ID FOREIGN KEY (TOPLEVELDOMAIN_ID) REFERENCES documents.topleveldomains (ID);

ALTER TABLE documents.urls ADD CONSTRAINT FK__URLS_SUBDOMAIN_ID FOREIGN KEY (SUBDOMAIN_ID) REFERENCES documents.subdomains (ID);

ALTER TABLE documents.urls ADD CONSTRAINT FK__URLS_SECONDLEVELDOMAIN_ID FOREIGN KEY (SECONDLEVELDOMAIN_ID) REFERENCES documents.secondleveldomains (ID);

ALTER TABLE commercesearch.customerkeywords ADD CONSTRAINT FK__CUSTOMERKEYWORDS_CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES commercesearch.customerdomains (ID);

ALTER TABLE lexicon.dockeypos ADD CONSTRAINT FK__DOCKEYPOS_DOCKEY_ID FOREIGN KEY (DOCKEY_ID) REFERENCES lexicon.dockey (ID);

ALTER TABLE commercesearch.customerproducturls ADD CONSTRAINT FK__CUSTOMERPRODUCTURLS_PRODUCT_ID FOREIGN KEY (PRODUCT_ID) REFERENCES commercesearch.customerproducts (ID);

ALTER TABLE commercesearch.customerproducturls ADD CONSTRAINT FK__CUSTOMERPRODUCTURLS_URL_ID FOREIGN KEY (URL_ID) REFERENCES documents.urls (ID);

ALTER TABLE commercesearch.customersynccrawler ADD CONSTRAINT FK__CUSTOMERSYNCCRAWLER_CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES commercesearch.customerdomains (ID);

ALTER TABLE commercesearch.customermatchcriteriagrouptype ADD CONSTRAINT FK__CUSTOMERMATCHCRITERIAGROUPTYPE_CUSTOMERMATCHCRITERIA_ID FOREIGN KEY (CUSTOMERMATCHCRITERIA_ID) REFERENCES commercesearch.customermatchcriteria (ID);

ALTER TABLE queryserver.searchquerykeywords ADD CONSTRAINT FK__SEARCHQUERYKEYWORDS_SEARCHQUERY_ID FOREIGN KEY (SEARCHQUERY_ID) REFERENCES queryserver.searchquery (ID);

ALTER TABLE queryserver.searchquerykeywords ADD CONSTRAINT FK__SEARCHQUERYKEYWORDS_KEYWORDQUERY_ID FOREIGN KEY (KEYWORDQUERY_ID) REFERENCES queryserver.keywordquery (ID);

ALTER TABLE commercesearch.customerqueries ADD CONSTRAINT FK__CUSTOMERQUERIES_CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES commercesearch.customerdomains (ID);

ALTER TABLE lexicon.docmeta ADD CONSTRAINT FK__DOCMETA_DICT_ID FOREIGN KEY (DICT_ID) REFERENCES lexicon.dict (ID);

ALTER TABLE lexicon.docmeta ADD CONSTRAINT FK__DOCMETA_URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES contents.urlstages (ID);

ALTER TABLE commercesearch.customerproducts ADD CONSTRAINT FK__CUSTOMERPRODUCTS_CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES commercesearch.customerdomains (ID);

ALTER TABLE commercesearch.customerdomainblacklist ADD CONSTRAINT FK__CUSTOMERDOMAINBLACKLIST_CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES commercesearch.customerdomains (ID);

INSERT INTO 
  documents.topleveldomains (tld)
VALUES
 ("ac"), -- ascension island
 ("ad"), -- andorra
 ("ae"), -- united arab emirates
 ("aero"), -- reserved for members of the air-transport industry
 ("af"), -- afghanistan
 ("ag"), -- antigua and barbuda
 ("ai"), -- anguilla
 ("al"), -- albania
 ("am"), -- armenia
 ("an"), -- netherlands antilles
 ("ao"), -- angola
 ("aq"), -- antarctica
 ("ar"), -- argentina
 ("arpa"), -- reserved exclusively to support operationally-critical infrastructural identifier spaces as advised by the internet architecture board
 ("as"), -- american samoa
 ("asia"), -- restricted to the pan-asia and asia pacific community
 ("at"), -- austria
 ("au"), -- australia
 ("aw"), -- aruba
 ("ax"), -- aland islands
 ("az"), -- azerbaijan
 ("ba"), -- bosnia and herzegovina
 ("bb"), -- barbados
 ("bd"), -- bangladesh
 ("be"), -- belgium
 ("bf"), -- burkina faso
 ("bg"), -- bulgaria
 ("bh"), -- bahrain
 ("bi"), -- burundi
 ("biz"), -- restricted for business
 ("bj"), -- benin
 ("bl"), -- saint barthelemy
 ("bm"), -- bermuda
 ("bn"), -- brunei darussalam
 ("bo"), -- bolivia
 ("br"), -- brazil
 ("bs"), -- bahamas
 ("bt"), -- bhutan
 ("bv"), -- bouvet island
 ("bw"), -- botswana
 ("by"), -- belarus
 ("bz"), -- belize
 ("ca"), -- canada
 ("cat"), -- reserved for the catalan linguistic and cultural community
 ("cc"), -- cocos (keeling) islands
 ("cd"), -- congo, the democratic republic of the
 ("cf"), -- central african republic
 ("cg"), -- congo
 ("ch"), -- switzerland
 ("ci"), -- cote d'ivoire
 ("ck"), -- cook islands
 ("cl"), -- chile
 ("cm"), -- cameroon
 ("cn"), -- china
 ("co"), -- colombia
 ("com"), -- generic top-level domain
 ("coop"), -- reserved for cooperative associations
 ("cr"), -- costa rica
 ("cu"), -- cuba
 ("cv"), -- cape verde
 ("cx"), -- christmas island
 ("cy"), -- cyprus
 ("cz"), -- czech republic
 ("de"), -- germany
 ("dj"), -- djibouti
 ("dk"), -- denmark
 ("dm"), -- dominica
 ("do"), -- dominican republic
 ("dz"), -- algeria
 ("ec"), -- ecuador
 ("edu"), -- reserved for post-secondary institutions accredited by an agency on the us department of education's list of nationally recognized accrediting agencies
 ("ee"), -- estonia
 ("eg"), -- egypt
 ("eh"), -- western sahara
 ("er"), -- eritrea
 ("es"), -- spain
 ("et"), -- ethiopia
 ("eu"), -- european union
 ("fi"), -- finland
 ("fj"), -- fiji
 ("fk"), -- falkland islands (malvinas)
 ("fm"), -- micronesia, federated states of
 ("fo"), -- faroe islands
 ("fr"), -- france
 ("ga"), -- gabon
 ("gb"), -- united kingdom
 ("gd"), -- grenada
 ("ge"), -- georgia
 ("gf"), -- french guiana
 ("gg"), -- guernsey
 ("gh"), -- ghana
 ("gi"), -- gibraltar
 ("gl"), -- greenland
 ("gm"), -- gambia
 ("gn"), -- guinea
 ("gov"), -- reserved exclusively for the united states government
 ("gp"), -- guadeloup
 ("gq"), -- equatorial guinea
 ("gr"), -- greece
 ("gs"), -- south georgia and the south sandwich islands
 ("gt"), -- guatemala
 ("gu"), -- guam
 ("gw"), -- guinea-bissau
 ("gy"), -- guyana
 ("hk"), -- hong kong
 ("hm"), -- heard island and mcdonald islands
 ("hn"), -- honduras
 ("hr"), -- croatia
 ("ht"), -- haiti
 ("hu"), -- hungary
 ("id"), -- indonesia
 ("ie"), -- ireland
 ("il"), -- israel
 ("im"), -- isle of man
 ("in"), -- india
 ("info"), -- generic top-level domain
 ("int"), -- used only for registering organizations established by international treaties between governments
 ("io"), -- british indian ocean territory
 ("iq"), -- iraq
 ("ir"), -- iran, islamic republic of
 ("is"), -- iceland
 ("it"), -- italy
 ("je"), -- jersey
 ("jm"), -- jamaica
 ("jo"), -- jordan
 ("jobs"), -- reserved for human resource managers
 ("jp"), -- japan
 ("ke"), -- kenya
 ("kg"), -- kyrgyzstan
 ("kh"), -- cambodia
 ("ki"), -- kiribati
 ("km"), -- comoros
 ("kn"), -- saint kitts and nevis
 ("kp"), -- korea, democratic people's republic of
 ("kr"), -- korea, republic of
 ("kw"), -- kuwait
 ("ky"), -- cayman islands
 ("kz"), -- kazakhstan
 ("la"), -- laos people's democratic republic
 ("lb"), -- lebanon
 ("lc"), -- saint lucia
 ("li"), -- liechtenstein
 ("lk"), -- sri lanka
 ("lr"), -- liberia
 ("ls"), -- lesotho
 ("lt"), -- lithuania
 ("lu"), -- luxembourg
 ("lv"), -- latvia
 ("ly"), -- libyan arab jamahiriya
 ("ma"), -- morocco
 ("mc"), -- monaco
 ("md"), -- moldova, republic of
 ("me"), -- montenegro
 ("mf"), -- saint martin (french part)
 ("mg"), -- madagascar
 ("mh"), -- marshall islands
 ("mil"), -- reserved exclusively for the united states military
 ("mk"), -- macedonia, the former yugoslav republic of
 ("ml"), -- mali
 ("mm"), -- myanmar
 ("mn"), -- mongolia
 ("mo"), -- macao
 ("mobi"), -- reserved for consumers and providers of mobile products and services
 ("mp"), -- northern mariana islands
 ("mq"), -- martinique
 ("mr"), -- mauritania
 ("ms"), -- montserrat
 ("mt"), -- malta
 ("mu"), -- mauritius
 ("museum"), -- reserved for museums
 ("mv"), -- maldives
 ("mw"), -- malawi
 ("mx"), -- mexico
 ("my"), -- malaysia
 ("mz"), -- mozambique
 ("na"), -- namibia
 ("name"), -- reserved for individuals
 ("nc"), -- new caledonia
 ("ne"), -- niger
 ("net"), -- generic top-level domain
 ("nf"), -- norfolk island
 ("ng"), -- nigeria
 ("ni"), -- nicaragua
 ("nl"), -- netherlands
 ("no"), -- norway
 ("np"), -- nepal
 ("nr"), -- nauru
 ("nu"), -- niue
 ("nz"), -- new zealand
 ("om"), -- oman
 ("org"), -- generic top-level domain
 ("pa"), -- panama
 ("pe"), -- peru
 ("pf"), -- french polynesia
 ("pg"), -- papua new guinea
 ("ph"), -- philippines
 ("pk"), -- pakistan
 ("pl"), -- poland
 ("pm"), -- saint pierre and miquelon
 ("pn"), -- pitcairn
 ("pr"), -- puerto rico
 ("pro"), -- restricted to credentialed professionals and related entities
 ("ps"), -- palestinian territory, occupied
 ("pt"), -- portugal
 ("pw"), -- palau
 ("py"), -- paraguay
 ("qa"), -- qatar
 ("re"), -- reunion
 ("ro"), -- romania
 ("rs"), -- serbia
 ("ru"), -- russian federation
 ("rw"), -- rwanda
 ("sa"), -- saudi arabia
 ("sb"), -- solomon islands
 ("sc"), -- seychelles
 ("sd"), -- sudan
 ("se"), -- sweden
 ("sg"), -- singapore
 ("sh"), -- saint helena
 ("si"), -- slovenia
 ("sj"), -- svalbard and jan mayen
 ("sk"), -- slovakia
 ("sl"), -- sierra leone
 ("sm"), -- san marino
 ("sn"), -- senegal
 ("so"), -- somalia
 ("sr"), -- suriname
 ("ss"), -- south sudan
 ("st"), -- sao tome and principe
 ("su"), -- soviet union (being phased out)
 ("sv"), -- el salvador
 ("sy"), -- syrian arab republic
 ("sz"), -- swaziland
 ("tc"), -- turks and caicos islands
 ("td"), -- chad
 ("tel"), -- reserved for businesses and individuals to publish their contact data
 ("tf"), -- french southern territories
 ("tg"), -- togo
 ("th"), -- thailand
 ("tj"), -- tajikistan
 ("tk"), -- tokelau
 ("tl"), -- timor-leste
 ("tm"), -- turkmenistan
 ("tn"), -- tunisia
 ("to"), -- tonga
 ("tp"), -- portuguese timor (being phased out)
 ("tr"), -- turkey
 ("travel"), -- reserved for entities whose primary area of activity is in the travel industry
 ("tt"), -- trinidad and tobago
 ("tv"), -- tuvalu
 ("tw"), -- taiwan
 ("tz"), -- tanzania, united republic of
 ("ua"), -- ukraine
 ("ug"), -- uganda
 ("uk"), -- united kingdom
 ("um"), -- united states minor outlying islands
 ("us"), -- united states
 ("uy"), -- uruguay
 ("uz"), -- uzbekistan
 ("va"), -- holy see (vatican city state)
 ("vc"), -- saint vincent and the grenadines
 ("ve"), -- venezuela
 ("vg"), -- virgin islands, british
 ("vi"), -- virgin islands, us
 ("vn"), -- viet nam
 ("vu"), -- vanuatu
 ("wf"), -- wallis and futuna
 ("ws"), -- samoa
 ("ye"), -- yemen
 ("yt"), -- mayotte
 ("yu"), -- yugoslavia
 ("za"), -- south africa
 ("zm"), -- zambia
 ("zw") -- zimbabwe
;
INSERT INTO 
  documents.schemes (ID,scheme) 
VALUES 
  (1,'http'),
  (2,'https')
;
USE `documents`;

DELIMITER |

CREATE TRIGGER `after_insert_urls` AFTER INSERT ON `documents`.`urls`
  FOR EACH ROW
  BEGIN
    INSERT INTO `sync`.`syncurls` (`URL_ID`, `SECONDLEVELDOMAIN_ID`, `CRAWLERSESSION_ID`, `schedule`) 
		VALUES ( NEW.`ID`, NEW.`SECONDLEVELDOMAIN_ID`, 0, UTC_TIMESTAMP() );

    INSERT INTO `sync`.`locksecondleveldomain` (`SECONDLEVELDOMAIN_ID`, `CRAWLERSESSION_ID`, `schedule`) 
		VALUES (NEW.`SECONDLEVELDOMAIN_ID`, 0, UTC_TIMESTAMP() ) ON DUPLICATE KEY UPDATE `SECONDLEVELDOMAIN_ID`=`SECONDLEVELDOMAIN_ID`;
  END;
|

DELIMITER ;
