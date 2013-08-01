

/* topleveldomains - DB2   */
CREATE TABLE topleveldomains
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 tld VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__TOPLEVELDOMAINS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__TOPLEVELDOMAINS_TLD UNIQUE (tld)
);


/* cachesecondleveldomain - DB2   */
CREATE TABLE cachesecondleveldomain
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHESECONDLEVELDOMAIN_ID PRIMARY KEY (ID)
);


/* locksecondleveldomain - DB2   */
CREATE TABLE locksecondleveldomain
(
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 CRAWLERSESSION_ID INTEGER NOT NULL,
 schedule TIMESTAMP NOT NULL,
 CONSTRAINT PRI__LOCKSECONDLEVELDOMAIN_SECONDLEVELDOMAIN_ID PRIMARY KEY (SECONDLEVELDOMAIN_ID)
);


/* logmessages - DB2   */
CREATE TABLE logmessages
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 loglevel INTEGER NOT NULL,
 message VARCHAR(2048) NOT NULL,
 actiontime TIMESTAMP NOT NULL,
 pid INTEGER NOT NULL,
 tid INTEGER NOT NULL,
 appName VARCHAR(255),
 threadName VARCHAR(255),
 CONSTRAINT PRI__LOGMESSAGES_ID PRIMARY KEY (ID)
);


/* cacherobots - DB2   */
CREATE TABLE cacherobots
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEROBOTS_ID PRIMARY KEY (ID)
);


/* cachehtml - DB2   */
CREATE TABLE cachehtml
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEHTML_ID PRIMARY KEY (ID)
);


/* queryresults - DB2   */
CREATE TABLE queryresults
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 SEARCHQUERY_ID INTEGER NOT NULL,
 URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 order_position INTEGER NOT NULL,
 CONSTRAINT PRI__QUERYRESULTS_ID PRIMARY KEY (ID)
);


/* urlstages - DB2   */
CREATE TABLE urlstages
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
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
);


/* documentcode - DB2   */
CREATE TABLE documentcode
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 code CLOG(4096000) NOT NULL,
 CONSTRAINT PRI__DOCUMENTCODE_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DOCUMENTCODE_URLSTAGE_ID UNIQUE (URLSTAGE_ID)
);


/* hyperlinks - DB2   */
CREATE TABLE hyperlinks
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 TARGET_URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 count INTEGER NOT NULL,
 CONSTRAINT PRI__HYPERLINKS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__HYPERLINKS_TARGET_URL_ID_URLSTAGE_ID UNIQUE (TARGET_URL_ID,URLSTAGE_ID)
);


/* keywordquery - DB2   */
CREATE TABLE keywordquery
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 query_part VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__KEYWORDQUERY_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__KEYWORDQUERY_QUERY_PART UNIQUE (query_part)
);


/* metainfo - DB2   */
CREATE TABLE metainfo
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 type INTEGER NOT NULL,
 value VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__METAINFO_ID PRIMARY KEY (ID)
);


/* customermatchcriteria - DB2   */
CREATE TABLE customermatchcriteria
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 MATCHCRITERIA_ID INTEGER NOT NULL,
 type INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERMATCHCRITERIA_ID PRIMARY KEY (ID)
);


/* unittest1 - DB2   */
CREATE TABLE unittest1
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 timestamp_test TIMESTAMP NOT NULL,
 varchar_test CLOG(4096000) NOT NULL,
 double_test DOUBLE NOT NULL,
 integer_test INTEGER NOT NULL,
 CONSTRAINT PRI__UNITTEST1_ID PRIMARY KEY (ID)
);


/* schemes - DB2   */
CREATE TABLE schemes
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 scheme VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__SCHEMES_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SCHEMES_SCHEME UNIQUE (scheme)
);


/* customersessions - DB2   */
CREATE TABLE customersessions
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 session VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__CUSTOMERSESSIONS_ID PRIMARY KEY (ID)
);


/* customersyncurl - DB2   */
CREATE TABLE customersyncurl
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 URL_ID INTEGER NOT NULL,
 scheduled TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CUSTOMERSYNCURL_ID PRIMARY KEY (ID)
);


/* unittest3 - DB2   */
CREATE TABLE unittest3
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 UNITTEST1_ID INTEGER NOT NULL,
 UNITTEST2_ID INTEGER NOT NULL,
 CONSTRAINT PRI__UNITTEST3_ID PRIMARY KEY (ID)
);


/* dataminingblacklist - DB2   */
CREATE TABLE dataminingblacklist
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 domain VARCHAR(2048) NOT NULL,
 CONSTRAINT PRI__DATAMININGBLACKLIST_ID PRIMARY KEY (ID)
);


/* images - DB2   */
CREATE TABLE images
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
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
);


/* docurl - DB2   */
CREATE TABLE docurl
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 DICT_ID INTEGER NOT NULL,
 URL_ID INTEGER NOT NULL,
 CONSTRAINT PRI__DOCURL_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DOCURL_URL_ID_DICT_ID UNIQUE (URL_ID,DICT_ID)
);


/* dataminingcustomersession - DB2   */
CREATE TABLE dataminingcustomersession
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 session VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__DATAMININGCUSTOMERSESSION_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DATAMININGCUSTOMERSESSION_SESSION UNIQUE (session)
);


/* latesturlstages - DB2   */
CREATE TABLE latesturlstages
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 CONSTRAINT PRI__LATESTURLSTAGES_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__LATESTURLSTAGES_URL_ID UNIQUE (URL_ID)
);


/* urlpathparts - DB2   */
CREATE TABLE urlpathparts
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 PATHPART_ID INTEGER NOT NULL,
 URLPATHPART_ID_NEXT INTEGER,
 CONSTRAINT PRI__URLPATHPARTS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__URLPATHPARTS_PATHPART_ID_URLPATHPART_ID_NEXT UNIQUE (PATHPART_ID,URLPATHPART_ID_NEXT)
);


/* pathparts - DB2   */
CREATE TABLE pathparts
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 path VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__PATHPARTS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__PATHPARTS_PATH UNIQUE (path)
);


/* imagelinks - DB2   */
CREATE TABLE imagelinks
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 TARGET_URL_ID INTEGER NOT NULL,
 IMAGE_URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 CONSTRAINT PRI__IMAGELINKS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__IMAGELINKS_TARGET_URL_ID_URLSTAGE_ID_IMAGE_URL_ID UNIQUE (TARGET_URL_ID,URLSTAGE_ID,IMAGE_URL_ID)
);


/* customerproductimages - DB2   */
CREATE TABLE customerproductimages
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 PRODUCT_ID INTEGER NOT NULL,
 imageUrl VARCHAR(2048) NOT NULL,
 CONSTRAINT PRI__CUSTOMERPRODUCTIMAGES_ID PRIMARY KEY (ID)
);


/* unittest2 - DB2   */
CREATE TABLE unittest2
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 timestamp_test TIMESTAMP NOT NULL,
 varchar_test CLOG(4096000) NOT NULL,
 double_test DOUBLE NOT NULL,
 integer_test INTEGER NOT NULL,
 CONSTRAINT PRI__UNITTEST2_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__UNITTEST2_DOUBLE_TEST UNIQUE (double_test)
);


/* customers - DB2   */
CREATE TABLE customers
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 login VARCHAR(255) NOT NULL,
 password VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__CUSTOMERS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__CUSTOMERS_LOGIN UNIQUE (login)
);


/* cachesubdomain - DB2   */
CREATE TABLE cachesubdomain
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHESUBDOMAIN_ID PRIMARY KEY (ID)
);


/* dockey - DB2   */
CREATE TABLE dockey
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 DICT_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 occurrence INTEGER NOT NULL,
 CONSTRAINT PRI__DOCKEY_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DOCKEY_DICT_ID_URLSTAGE_ID UNIQUE (DICT_ID,URLSTAGE_ID)
);


/* customerproductkeywords - DB2   */
CREATE TABLE customerproductkeywords
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 PRODUCT_ID INTEGER NOT NULL,
 DICT_ID INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERPRODUCTKEYWORDS_ID PRIMARY KEY (ID)
);


/* secondleveldomains - DB2   */
CREATE TABLE secondleveldomains
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 domain VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__SECONDLEVELDOMAINS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SECONDLEVELDOMAINS_DOMAIN UNIQUE (domain)
);


/* dataminingcustomer - DB2   */
CREATE TABLE dataminingcustomer
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 login VARCHAR(255) NOT NULL,
 password VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__DATAMININGCUSTOMER_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DATAMININGCUSTOMER_LOGIN UNIQUE (login)
);


/* dataminingcriteriaalerts - DB2   */
CREATE TABLE dataminingcriteriaalerts
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 DATAMININGALERT_ID INTEGER NOT NULL,
 DATAMININGCRITERIA_ID INTEGER NOT NULL,
 CONSTRAINT PRI__DATAMININGCRITERIAALERTS_ID PRIMARY KEY (ID)
);


/* customerdomains - DB2   */
CREATE TABLE customerdomains
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 domain VARCHAR(2048) NOT NULL,
 revisitInterval INTEGER NOT NULL,
 isDomainRegex INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERDOMAINS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__CUSTOMERDOMAINS_CUSTOMER_ID UNIQUE (CUSTOMER_ID)
);


/* syncurls - DB2   */
CREATE TABLE syncurls
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 URL_ID INTEGER NOT NULL,
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 CRAWLERSESSION_ID INTEGER NOT NULL,
 schedule TIMESTAMP NOT NULL,
 CONSTRAINT PRI__SYNCURLS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SYNCURLS_URL_ID UNIQUE (URL_ID)
);


/* crawlersessions - DB2   */
CREATE TABLE crawlersessions
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CONSTRAINT PRI__CRAWLERSESSIONS_ID PRIMARY KEY (ID)
);


/* urls - DB2   */
CREATE TABLE urls
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
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
);


/* dataminingcriteria - DB2   */
CREATE TABLE dataminingcriteria
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 keyword VARCHAR(2048) NOT NULL,
 type INTEGER NOT NULL,
 CONSTRAINT PRI__DATAMININGCRITERIA_ID PRIMARY KEY (ID)
);


/* customerkeywords - DB2   */
CREATE TABLE customerkeywords
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 keyword VARCHAR(2048) NOT NULL,
 target VARCHAR(2048) NOT NULL,
 isKeywordRegex INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERKEYWORDS_ID PRIMARY KEY (ID)
);


/* dockeypos - DB2   */
CREATE TABLE dockeypos
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 DOCKEY_ID INTEGER NOT NULL,
 paragraph INTEGER NOT NULL,
 position INTEGER NOT NULL,
 CONSTRAINT PRI__DOCKEYPOS_ID PRIMARY KEY (ID)
);


/* customerproducturls - DB2   */
CREATE TABLE customerproducturls
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 PRODUCT_ID INTEGER NOT NULL,
 URL_ID INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERPRODUCTURLS_ID PRIMARY KEY (ID)
);


/* customersynccrawler - DB2   */
CREATE TABLE customersynccrawler
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 CRAWLERSESSION_ID INTEGER NOT NULL,
 scheduled TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CUSTOMERSYNCCRAWLER_ID PRIMARY KEY (ID)
);


/* customermatchcriteriagrouptype - DB2   */
CREATE TABLE customermatchcriteriagrouptype
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CUSTOMERMATCHCRITERIA_ID INTEGER NOT NULL,
 type INTEGER NOT NULL,
 groupPosition INTEGER NOT NULL,
 isPrimaryKey INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERMATCHCRITERIAGROUPTYPE_ID PRIMARY KEY (ID)
);


/* searchquerykeywords - DB2   */
CREATE TABLE searchquerykeywords
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 KEYWORDQUERY_ID INTEGER NOT NULL,
 SEARCHQUERY_ID INTEGER NOT NULL,
 CONSTRAINT PRI__SEARCHQUERYKEYWORDS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SEARCHQUERYKEYWORDS_SEARCHQUERY_ID_KEYWORDQUERY_ID UNIQUE (SEARCHQUERY_ID,KEYWORDQUERY_ID)
);


/* customerqueries - DB2   */
CREATE TABLE customerqueries
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 query VARCHAR(2048) NOT NULL,
 CONSTRAINT PRI__CUSTOMERQUERIES_ID PRIMARY KEY (ID)
);


/* searchquery - DB2   */
CREATE TABLE searchquery
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 session CHAR(64) NOT NULL,
 CONSTRAINT PRI__SEARCHQUERY_ID PRIMARY KEY (ID)
);


/* docmeta - DB2   */
CREATE TABLE docmeta
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 DICT_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 occurrence INTEGER NOT NULL,
 type INTEGER NOT NULL,
 CONSTRAINT PRI__DOCMETA_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DOCMETA_DICT_ID_URLSTAGE_ID_TYPE UNIQUE (DICT_ID,URLSTAGE_ID,type)
);


/* fencedsearch - DB2   */
CREATE TABLE fencedsearch
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 CONSTRAINT PRI__FENCEDSEARCH_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__FENCEDSEARCH_CUSTOMER_ID_SECONDLEVELDOMAIN_ID UNIQUE (CUSTOMER_ID,SECONDLEVELDOMAIN_ID)
);


/* dataminingalerts - DB2   */
CREATE TABLE dataminingalerts
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 type INTEGER NOT NULL,
 param VARCHAR(2048),
 CONSTRAINT PRI__DATAMININGALERTS_ID PRIMARY KEY (ID)
);


/* cacheurl - DB2   */
CREATE TABLE cacheurl
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEURL_ID PRIMARY KEY (ID)
);


/* dict - DB2   */
CREATE TABLE dict
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 keyword VARCHAR(255) NOT NULL,
 occurrence INTEGER NOT NULL,
 CONSTRAINT PRI__DICT_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DICT_KEYWORD UNIQUE (keyword)
);


/* customerproducts - DB2   */
CREATE TABLE customerproducts
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 productNo VARCHAR(1024) NOT NULL,
 productName VARCHAR(1024) NOT NULL,
 productBrand VARCHAR(1024) NOT NULL,
 CONSTRAINT PRI__CUSTOMERPRODUCTS_ID PRIMARY KEY (ID)
);


/* customerdomainblacklist - DB2   */
CREATE TABLE customerdomainblacklist
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 path VARCHAR(2048) NOT NULL,
 isPathRegex INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERDOMAINBLACKLIST_ID PRIMARY KEY (ID)
);


/* subdomains - DB2   */
CREATE TABLE subdomains
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 subdomain VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__SUBDOMAINS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SUBDOMAINS_SUBDOMAIN UNIQUE (subdomain)
);


/* matchcriteria - DB2   */
CREATE TABLE matchcriteria
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 regex VARCHAR(2048) NOT NULL,
 CONSTRAINT PRI__MATCHCRITERIA_ID PRIMARY KEY (ID)
);


/* cacheparsed - DB2   */
CREATE TABLE cacheparsed
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEPARSED_ID PRIMARY KEY (ID)
);


ALTER TABLE queryresults ADD CONSTRAINT FK__SEARCHQUERY_ID FOREIGN KEY (SEARCHQUERY_ID) REFERENCES searchquery (ID);

ALTER TABLE urlstages ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE documentcode ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE hyperlinks ADD CONSTRAINT FK__TARGET_URL_ID FOREIGN KEY (TARGET_URL_ID) REFERENCES urls (ID);

ALTER TABLE hyperlinks ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE metainfo ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE customermatchcriteria ADD CONSTRAINT FK__CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES customerdomains (ID);

ALTER TABLE customermatchcriteria ADD CONSTRAINT FK__MATCHCRITERIA_ID FOREIGN KEY (MATCHCRITERIA_ID) REFERENCES matchcriteria (ID);

ALTER TABLE customersessions ADD CONSTRAINT FK__CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES customers (ID);

ALTER TABLE customersyncurl ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE unittest3 ADD CONSTRAINT FK__UNITTEST1_ID FOREIGN KEY (UNITTEST1_ID) REFERENCES unittest1 (ID);

ALTER TABLE unittest3 ADD CONSTRAINT FK__UNITTEST2_ID FOREIGN KEY (UNITTEST2_ID) REFERENCES unittest2 (ID);

ALTER TABLE dataminingblacklist ADD CONSTRAINT FK__CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES dataminingcustomer (ID);

ALTER TABLE images ADD CONSTRAINT FK__SCHEME_ID FOREIGN KEY (SCHEME_ID) REFERENCES schemes (ID);

ALTER TABLE images ADD CONSTRAINT FK__TOPLEVELDOMAIN_ID FOREIGN KEY (TOPLEVELDOMAIN_ID) REFERENCES topleveldomains (ID);

ALTER TABLE images ADD CONSTRAINT FK__SUBDOMAIN_ID FOREIGN KEY (SUBDOMAIN_ID) REFERENCES subdomains (ID);

ALTER TABLE images ADD CONSTRAINT FK__SECONDLEVELDOMAIN_ID FOREIGN KEY (SECONDLEVELDOMAIN_ID) REFERENCES secondleveldomains (ID);

ALTER TABLE docurl ADD CONSTRAINT FK__DICT_ID FOREIGN KEY (DICT_ID) REFERENCES dict (ID);

ALTER TABLE docurl ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE dataminingcustomersession ADD CONSTRAINT FK__CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES dataminingcustomer (ID);

ALTER TABLE latesturlstages ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE latesturlstages ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE urlpathparts ADD CONSTRAINT FK__PATHPART_ID FOREIGN KEY (PATHPART_ID) REFERENCES pathparts (ID);

ALTER TABLE urlpathparts ADD CONSTRAINT FK__URLPATHPART_ID_NEXT FOREIGN KEY (URLPATHPART_ID_NEXT) REFERENCES urlpathparts (ID);

ALTER TABLE imagelinks ADD CONSTRAINT FK__TARGET_URL_ID FOREIGN KEY (TARGET_URL_ID) REFERENCES urls (ID);

ALTER TABLE imagelinks ADD CONSTRAINT FK__IMAGE_URL_ID FOREIGN KEY (IMAGE_URL_ID) REFERENCES images (ID);

ALTER TABLE imagelinks ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE customerproductimages ADD CONSTRAINT FK__PRODUCT_ID FOREIGN KEY (PRODUCT_ID) REFERENCES customerproducts (ID);

ALTER TABLE dockey ADD CONSTRAINT FK__DICT_ID FOREIGN KEY (DICT_ID) REFERENCES dict (ID);

ALTER TABLE dockey ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE customerproductkeywords ADD CONSTRAINT FK__PRODUCT_ID FOREIGN KEY (PRODUCT_ID) REFERENCES customerproducts (ID);

ALTER TABLE customerproductkeywords ADD CONSTRAINT FK__DICT_ID FOREIGN KEY (DICT_ID) REFERENCES dict (ID);

ALTER TABLE dataminingcriteriaalerts ADD CONSTRAINT FK__CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES dataminingcustomer (ID);

ALTER TABLE dataminingcriteriaalerts ADD CONSTRAINT FK__DATAMININGALERT_ID FOREIGN KEY (DATAMININGALERT_ID) REFERENCES dataminingalerts (ID);

ALTER TABLE dataminingcriteriaalerts ADD CONSTRAINT FK__DATAMININGCRITERIA_ID FOREIGN KEY (DATAMININGCRITERIA_ID) REFERENCES dataminingcriteria (ID);

ALTER TABLE customerdomains ADD CONSTRAINT FK__CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES customers (ID);

ALTER TABLE syncurls ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE syncurls ADD CONSTRAINT FK__SECONDLEVELDOMAIN_ID FOREIGN KEY (SECONDLEVELDOMAIN_ID) REFERENCES secondleveldomains (ID);

ALTER TABLE urls ADD CONSTRAINT FK__SCHEME_ID FOREIGN KEY (SCHEME_ID) REFERENCES schemes (ID);

ALTER TABLE urls ADD CONSTRAINT FK__TOPLEVELDOMAIN_ID FOREIGN KEY (TOPLEVELDOMAIN_ID) REFERENCES topleveldomains (ID);

ALTER TABLE urls ADD CONSTRAINT FK__SUBDOMAIN_ID FOREIGN KEY (SUBDOMAIN_ID) REFERENCES subdomains (ID);

ALTER TABLE urls ADD CONSTRAINT FK__SECONDLEVELDOMAIN_ID FOREIGN KEY (SECONDLEVELDOMAIN_ID) REFERENCES secondleveldomains (ID);

ALTER TABLE customerkeywords ADD CONSTRAINT FK__CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES customerdomains (ID);

ALTER TABLE dockeypos ADD CONSTRAINT FK__DOCKEY_ID FOREIGN KEY (DOCKEY_ID) REFERENCES dockey (ID);

ALTER TABLE customerproducturls ADD CONSTRAINT FK__PRODUCT_ID FOREIGN KEY (PRODUCT_ID) REFERENCES customerproducts (ID);

ALTER TABLE customerproducturls ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE customersynccrawler ADD CONSTRAINT FK__CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES customerdomains (ID);

ALTER TABLE customermatchcriteriagrouptype ADD CONSTRAINT FK__CUSTOMERMATCHCRITERIA_ID FOREIGN KEY (CUSTOMERMATCHCRITERIA_ID) REFERENCES customermatchcriteria (ID);

ALTER TABLE searchquerykeywords ADD CONSTRAINT FK__SEARCHQUERY_ID FOREIGN KEY (SEARCHQUERY_ID) REFERENCES searchquery (ID);

ALTER TABLE searchquerykeywords ADD CONSTRAINT FK__KEYWORDQUERY_ID FOREIGN KEY (KEYWORDQUERY_ID) REFERENCES keywordquery (ID);

ALTER TABLE customerqueries ADD CONSTRAINT FK__CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES customerdomains (ID);

ALTER TABLE docmeta ADD CONSTRAINT FK__DICT_ID FOREIGN KEY (DICT_ID) REFERENCES dict (ID);

ALTER TABLE docmeta ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE fencedsearch ADD CONSTRAINT FK__CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES dataminingcustomer (ID);

ALTER TABLE fencedsearch ADD CONSTRAINT FK__SECONDLEVELDOMAIN_ID FOREIGN KEY (SECONDLEVELDOMAIN_ID) REFERENCES secondleveldomains (ID);

ALTER TABLE customerproducts ADD CONSTRAINT FK__CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES customerdomains (ID);

ALTER TABLE customerdomainblacklist ADD CONSTRAINT FK__CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES customerdomains (ID);
