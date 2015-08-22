
\c deepnet


/* documentcode - Postgre   */
CREATE TABLE documentcode
(
 ID BIGSERIAL NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 code TEXT NOT NULL,
 CONSTRAINT PRI__DOCUMENTCODE_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DOCUMENTCODE_URLSTAGE_ID UNIQUE (URLSTAGE_ID)
);


/* cacheurlpathparts - Postgre   */
CREATE TABLE cacheurlpathparts
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEURLPATHPARTS_ID PRIMARY KEY (ID)
);


/* searchquery - Postgre   */
CREATE TABLE searchquery
(
 ID BIGSERIAL NOT NULL,
 RESULTTHREAD_ID INTEGER NOT NULL,
 PROPERTIES_ID INTEGER NOT NULL,
 session CHAR(64) NOT NULL,
 query VARCHAR(255) NOT NULL,
 started TIMESTAMP NOT NULL,
 modified TIMESTAMP NOT NULL,
 finished INTEGER(1) NOT NULL,
 total INTEGER NOT NULL,
 identifier VARCHAR(32) NOT NULL,
 CONSTRAINT PRI__SEARCHQUERY_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SEARCHQUERY_IDENTIFIER UNIQUE (identifier)
);


/* matchcriteria - Postgre   */
CREATE TABLE matchcriteria
(
 ID BIGSERIAL NOT NULL,
 regex VARCHAR(2048) NOT NULL,
 CONSTRAINT PRI__MATCHCRITERIA_ID PRIMARY KEY (ID)
);


/* docmeta - Postgre   */
CREATE TABLE docmeta
(
 ID BIGSERIAL NOT NULL,
 DICT_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 occurrence INTEGER NOT NULL,
 type INTEGER NOT NULL,
 CONSTRAINT PRI__DOCMETA_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DOCMETA_DICT_ID_URLSTAGE_ID_TYPE UNIQUE (DICT_ID,URLSTAGE_ID,type)
);


/* queryresults - Postgre   */
CREATE TABLE queryresults
(
 ID BIGSERIAL NOT NULL,
 SEARCHQUERY_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 URL_ID INTEGER NOT NULL,
 position INTEGER NOT NULL,
 CONSTRAINT PRI__QUERYRESULTS_ID PRIMARY KEY (ID)
);


/* customermatchcriteria - Postgre   */
CREATE TABLE customermatchcriteria
(
 ID BIGSERIAL NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 MATCHCRITERIA_ID INTEGER NOT NULL,
 type INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERMATCHCRITERIA_ID PRIMARY KEY (ID)
);


/* subdomains - Postgre   */
CREATE TABLE subdomains
(
 ID BIGSERIAL NOT NULL,
 subdomain VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__SUBDOMAINS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SUBDOMAINS_SUBDOMAIN UNIQUE (subdomain)
);


/* cachepathparts - Postgre   */
CREATE TABLE cachepathparts
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEPATHPARTS_ID PRIMARY KEY (ID)
);


/* customermatchcriteriagrouptype - Postgre   */
CREATE TABLE customermatchcriteriagrouptype
(
 ID BIGSERIAL NOT NULL,
 CUSTOMERMATCHCRITERIA_ID INTEGER NOT NULL,
 type INTEGER NOT NULL,
 groupPosition INTEGER NOT NULL,
 isPrimaryKey INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERMATCHCRITERIAGROUPTYPE_ID PRIMARY KEY (ID)
);


/* dataminingcustomersession - Postgre   */
CREATE TABLE dataminingcustomersession
(
 ID BIGSERIAL NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 session VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__DATAMININGCUSTOMERSESSION_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DATAMININGCUSTOMERSESSION_SESSION UNIQUE (session)
);


/* cacherobots - Postgre   */
CREATE TABLE cacherobots
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEROBOTS_ID PRIMARY KEY (ID)
);


/* schemes - Postgre   */
CREATE TABLE schemes
(
 ID BIGSERIAL NOT NULL,
 scheme VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__SCHEMES_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SCHEMES_SCHEME UNIQUE (scheme)
);


/* metainfo - Postgre   */
CREATE TABLE metainfo
(
 ID BIGSERIAL NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 type INTEGER NOT NULL,
 value VARCHAR(512) NOT NULL,
 CONSTRAINT PRI__METAINFO_ID PRIMARY KEY (ID)
);


/* cacheurlsearchparts - Postgre   */
CREATE TABLE cacheurlsearchparts
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEURLSEARCHPARTS_ID PRIMARY KEY (ID)
);


/* secondleveldomains - Postgre   */
CREATE TABLE secondleveldomains
(
 ID BIGSERIAL NOT NULL,
 domain VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__SECONDLEVELDOMAINS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SECONDLEVELDOMAINS_DOMAIN UNIQUE (domain)
);


/* imagelinks - Postgre   */
CREATE TABLE imagelinks
(
 ID BIGSERIAL NOT NULL,
 TARGET_URL_ID INTEGER NOT NULL,
 IMAGE_URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 CONSTRAINT PRI__IMAGELINKS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__IMAGELINKS_TARGET_URL_ID_URLSTAGE_ID_IMAG UNIQUE (TARGET_URL_ID,URLSTAGE_ID,IMAGE_URL_ID)
);


/* urlpathparts - Postgre   */
CREATE TABLE urlpathparts
(
 ID BIGSERIAL NOT NULL,
 PATHPART_ID INTEGER NOT NULL,
 URLPATHPART_ID_NEXT INTEGER NOT NULL,
 CONSTRAINT PRI__URLPATHPARTS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__URLPATHPARTS_PATHPART_ID_URLPATHPART_ID_NEX UNIQUE (PATHPART_ID,URLPATHPART_ID_NEXT)
);


/* topleveldomains - Postgre   */
CREATE TABLE topleveldomains
(
 ID BIGSERIAL NOT NULL,
 tld VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__TOPLEVELDOMAINS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__TOPLEVELDOMAINS_TLD UNIQUE (tld)
);


/* dataminingcriteria - Postgre   */
CREATE TABLE dataminingcriteria
(
 ID BIGSERIAL NOT NULL,
 keyword VARCHAR(2048) NOT NULL,
 type INTEGER NOT NULL,
 CONSTRAINT PRI__DATAMININGCRITERIA_ID PRIMARY KEY (ID)
);


/* customerqueries - Postgre   */
CREATE TABLE customerqueries
(
 ID BIGSERIAL NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 query VARCHAR(2048) NOT NULL,
 CONSTRAINT PRI__CUSTOMERQUERIES_ID PRIMARY KEY (ID)
);


/* customerproductkeywords - Postgre   */
CREATE TABLE customerproductkeywords
(
 ID BIGSERIAL NOT NULL,
 PRODUCT_ID INTEGER NOT NULL,
 DICT_ID INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERPRODUCTKEYWORDS_ID PRIMARY KEY (ID)
);


/* unittest1 - Postgre   */
CREATE TABLE unittest1
(
 ID BIGSERIAL NOT NULL,
 timestamp_test TIMESTAMP NOT NULL,
 varchar_test TEXT NOT NULL,
 double_test DOUBLE PRECISION NOT NULL,
 integer_test INTEGER NOT NULL,
 CONSTRAINT PRI__UNITTEST1_ID PRIMARY KEY (ID)
);


/* customerdomains - Postgre   */
CREATE TABLE customerdomains
(
 ID BIGSERIAL NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 domain VARCHAR(2048) NOT NULL,
 revisitInterval INTEGER NOT NULL,
 isDomainRegex INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERDOMAINS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__CUSTOMERDOMAINS_CUSTOMER_ID UNIQUE (CUSTOMER_ID)
);


/* customerdomainblacklist - Postgre   */
CREATE TABLE customerdomainblacklist
(
 ID BIGSERIAL NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 path VARCHAR(2048) NOT NULL,
 isPathRegex INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERDOMAINBLACKLIST_ID PRIMARY KEY (ID)
);


/* customerproductimages - Postgre   */
CREATE TABLE customerproductimages
(
 ID BIGSERIAL NOT NULL,
 PRODUCT_ID INTEGER NOT NULL,
 imageUrl VARCHAR(2048) NOT NULL,
 CONSTRAINT PRI__CUSTOMERPRODUCTIMAGES_ID PRIMARY KEY (ID)
);


/* hyperlinks - Postgre   */
CREATE TABLE hyperlinks
(
 ID BIGSERIAL NOT NULL,
 TARGET_URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 count INTEGER NOT NULL,
 CONSTRAINT PRI__HYPERLINKS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__HYPERLINKS_TARGET_URL_ID_URLSTAGE_ID UNIQUE (TARGET_URL_ID,URLSTAGE_ID)
);


/* locksecondleveldomain - Postgre   */
CREATE TABLE locksecondleveldomain
(
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 CRAWLERSESSION_ID INTEGER NOT NULL,
 schedule TIMESTAMP NOT NULL,
 CONSTRAINT PRI__LOCKSECONDLEVELDOMAIN_SECONDLEVELDOMAIN_ID PRIMARY KEY (SECONDLEVELDOMAIN_ID)
);


/* syncurls - Postgre   */
CREATE TABLE syncurls
(
 ID BIGSERIAL NOT NULL,
 URL_ID INTEGER NOT NULL,
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 CRAWLERSESSION_ID INTEGER NOT NULL,
 schedule TIMESTAMP NOT NULL,
 CONSTRAINT PRI__SYNCURLS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SYNCURLS_URL_ID UNIQUE (URL_ID)
);


/* cachesubdomain - Postgre   */
CREATE TABLE cachesubdomain
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHESUBDOMAIN_ID PRIMARY KEY (ID)
);


/* urls - Postgre   */
CREATE TABLE urls
(
 ID BIGSERIAL NOT NULL,
 SCHEME_ID INTEGER NOT NULL,
 TOPLEVELDOMAIN_ID INTEGER NOT NULL,
 SUBDOMAIN_ID INTEGER NOT NULL,
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 port INTEGER NOT NULL,
 URLPATHPART_ID INTEGER NOT NULL,
 URLSEARCHPART_ID INTEGER NOT NULL,
 found_date TIMESTAMP NOT NULL,
 CONSTRAINT PRI__URLS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__URLS_SCHEME_ID_SUBDOMAIN_ID_SECONDL UNIQUE (SCHEME_ID,SUBDOMAIN_ID,SECONDLEVELDOMAIN_ID,TOPLEVELDOMAIN_ID,port,URLPATHPART_ID,URLSEARCHPART_ID)
);


/* customerproducts - Postgre   */
CREATE TABLE customerproducts
(
 ID BIGSERIAL NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 productNo VARCHAR(1024) NOT NULL,
 productName VARCHAR(1024) NOT NULL,
 productBrand VARCHAR(1024) NOT NULL,
 CONSTRAINT PRI__CUSTOMERPRODUCTS_ID PRIMARY KEY (ID)
);


/* dataminingblacklist - Postgre   */
CREATE TABLE dataminingblacklist
(
 ID BIGSERIAL NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 domain VARCHAR(2048) NOT NULL,
 CONSTRAINT PRI__DATAMININGBLACKLIST_ID PRIMARY KEY (ID)
);


/* latesturlstages - Postgre   */
CREATE TABLE latesturlstages
(
 ID BIGSERIAL NOT NULL,
 URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 CONSTRAINT PRI__LATESTURLSTAGES_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__LATESTURLSTAGES_URL_ID UNIQUE (URL_ID)
);


/* unittest3 - Postgre   */
CREATE TABLE unittest3
(
 ID BIGSERIAL NOT NULL,
 UNITTEST1_ID INTEGER NOT NULL,
 UNITTEST2_ID INTEGER NOT NULL,
 CONSTRAINT PRI__UNITTEST3_ID PRIMARY KEY (ID)
);


/* dataminingalerts - Postgre   */
CREATE TABLE dataminingalerts
(
 ID BIGSERIAL NOT NULL,
 type INTEGER NOT NULL,
 param VARCHAR(2048),
 CONSTRAINT PRI__DATAMININGALERTS_ID PRIMARY KEY (ID)
);


/* customers - Postgre   */
CREATE TABLE customers
(
 ID BIGSERIAL NOT NULL,
 login VARCHAR(255) NOT NULL,
 password VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__CUSTOMERS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__CUSTOMERS_LOGIN UNIQUE (login)
);


/* crawlersessions - Postgre   */
CREATE TABLE crawlersessions
(
 ID BIGSERIAL NOT NULL,
 CONSTRAINT PRI__CRAWLERSESSIONS_ID PRIMARY KEY (ID)
);


/* customerproducturls - Postgre   */
CREATE TABLE customerproducturls
(
 ID BIGSERIAL NOT NULL,
 PRODUCT_ID INTEGER NOT NULL,
 URL_ID INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERPRODUCTURLS_ID PRIMARY KEY (ID)
);


/* urlspathpart - Postgre   */
CREATE TABLE urlspathpart
(
 ID BIGSERIAL NOT NULL,
 PATHPART_ID INTEGER NOT NULL,
 URL_ID INTEGER NOT NULL,
 CONSTRAINT PRI__URLSPATHPART_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__URLSPATHPART_PATHPART_ID_URL_ID UNIQUE (PATHPART_ID,URL_ID)
);


/* unittest2 - Postgre   */
CREATE TABLE unittest2
(
 ID BIGSERIAL NOT NULL,
 timestamp_test TIMESTAMP NOT NULL,
 varchar_test TEXT NOT NULL,
 double_test DOUBLE PRECISION NOT NULL,
 integer_test INTEGER NOT NULL,
 CONSTRAINT PRI__UNITTEST2_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__UNITTEST2_DOUBLE_TEST UNIQUE (double_test)
);


/* customersyncurl - Postgre   */
CREATE TABLE customersyncurl
(
 ID BIGSERIAL NOT NULL,
 URL_ID INTEGER NOT NULL,
 scheduled TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CUSTOMERSYNCURL_ID PRIMARY KEY (ID)
);


/* urlstages - Postgre   */
CREATE TABLE urlstages
(
 ID BIGSERIAL NOT NULL,
 URL_ID INTEGER NOT NULL,
 response_code INTEGER,
 content_md5 CHAR(32),
 last_change TIMESTAMP,
 redirect_count INTEGER,
 download_speed NUMERIC(15),
 upload_speed NUMERIC(15),
 content_length NUMERIC(15),
 content_type VARCHAR(255),
 primary_ip NUMERIC(15),
 primary_port INTEGER,
 int_links INTEGER,
 ext_links INTEGER,
 download_time INTEGER,
 html_errors INTEGER,
 found_date TIMESTAMP NOT NULL,
 CONSTRAINT PRI__URLSTAGES_ID PRIMARY KEY (ID)
);


/* customerkeywords - Postgre   */
CREATE TABLE customerkeywords
(
 ID BIGSERIAL NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 keyword VARCHAR(2048) NOT NULL,
 target VARCHAR(2048) NOT NULL,
 isKeywordRegex INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERKEYWORDS_ID PRIMARY KEY (ID)
);


/* dockey - Postgre   */
CREATE TABLE dockey
(
 ID BIGSERIAL NOT NULL,
 DICT_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 occurrence INTEGER NOT NULL,
 CONSTRAINT PRI__DOCKEY_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DOCKEY_DICT_ID_URLSTAGE_ID UNIQUE (DICT_ID,URLSTAGE_ID)
);


/* customersynccrawler - Postgre   */
CREATE TABLE customersynccrawler
(
 ID BIGSERIAL NOT NULL,
 CUSTOMERDOMAIN_ID INTEGER NOT NULL,
 CRAWLERSESSION_ID INTEGER NOT NULL,
 scheduled TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CUSTOMERSYNCCRAWLER_ID PRIMARY KEY (ID)
);


/* cacheparsed - Postgre   */
CREATE TABLE cacheparsed
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEPARSED_ID PRIMARY KEY (ID)
);


/* cachehtml - Postgre   */
CREATE TABLE cachehtml
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEHTML_ID PRIMARY KEY (ID)
);


/* queryproperties - Postgre   */
CREATE TABLE queryproperties
(
 ID BIGSERIAL NOT NULL,
 SECONDLEVELDOMAIN_ID INTEGER,
 SUBDOMAIN_ID INTEGER,
 minAge TIMESTAMP,
 maxAge TIMESTAMP,
 language CHAR(3) NOT NULL,
 relContent DOUBLE PRECISION NOT NULL,
 relMeta DOUBLE PRECISION NOT NULL,
 relSecondLevel DOUBLE PRECISION NOT NULL,
 relSubdomain DOUBLE PRECISION NOT NULL,
 relUrlPath DOUBLE PRECISION NOT NULL,
 groupBySecondLevel INTEGER NOT NULL,
 CONSTRAINT PRI__QUERYPROPERTIES_ID PRIMARY KEY (ID)
);


/* cachesecondleveldomain - Postgre   */
CREATE TABLE cachesecondleveldomain
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHESECONDLEVELDOMAIN_ID PRIMARY KEY (ID)
);


/* queryresultthread - Postgre   */
CREATE TABLE queryresultthread
(
 ID BIGSERIAL NOT NULL,
 CONSTRAINT PRI__QUERYRESULTTHREAD_ID PRIMARY KEY (ID)
);


/* dataminingcustomer - Postgre   */
CREATE TABLE dataminingcustomer
(
 ID BIGSERIAL NOT NULL,
 login VARCHAR(255) NOT NULL,
 password VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__DATAMININGCUSTOMER_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DATAMININGCUSTOMER_LOGIN UNIQUE (login)
);


/* customersessions - Postgre   */
CREATE TABLE customersessions
(
 ID BIGSERIAL NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 session VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__CUSTOMERSESSIONS_ID PRIMARY KEY (ID)
);


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
 threadName VARCHAR(255),
 CONSTRAINT PRI__LOGMESSAGES_ID PRIMARY KEY (ID)
);


/* pathparts - Postgre   */
CREATE TABLE pathparts
(
 ID BIGSERIAL NOT NULL,
 path VARCHAR(4096) NOT NULL,
 md5 CHAR(32) NOT NULL,
 CONSTRAINT PRI__PATHPARTS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__PATHPARTS_MD5 UNIQUE (md5)
);


/* dockeypos - Postgre   */
CREATE TABLE dockeypos
(
 ID BIGSERIAL NOT NULL,
 DOCKEY_ID INTEGER NOT NULL,
 paragraph INTEGER NOT NULL,
 position INTEGER NOT NULL,
 CONSTRAINT PRI__DOCKEYPOS_ID PRIMARY KEY (ID)
);


/* images - Postgre   */
CREATE TABLE images
(
 ID BIGSERIAL NOT NULL,
 SCHEME_ID INTEGER NOT NULL,
 TOPLEVELDOMAIN_ID INTEGER NOT NULL,
 SUBDOMAIN_ID INTEGER NOT NULL,
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 port INTEGER NOT NULL,
 URLPATHPART_ID INTEGER NOT NULL,
 URLSEARCHPART_ID INTEGER NOT NULL,
 found_date TIMESTAMP NOT NULL,
 CONSTRAINT PRI__IMAGES_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__IMAGES_SCHEME_ID_SUBDOMAIN_ID_SECONDL UNIQUE (SCHEME_ID,SUBDOMAIN_ID,SECONDLEVELDOMAIN_ID,TOPLEVELDOMAIN_ID,port,URLPATHPART_ID,URLSEARCHPART_ID)
);


/* urlsearchparts - Postgre   */
CREATE TABLE urlsearchparts
(
 ID BIGSERIAL NOT NULL,
 searchpart VARCHAR(4096) NOT NULL,
 md5 CHAR(32) NOT NULL,
 CONSTRAINT PRI__URLSEARCHPARTS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__URLSEARCHPARTS_MD5 UNIQUE (md5)
);


/* dataminingcriteriaalerts - Postgre   */
CREATE TABLE dataminingcriteriaalerts
(
 ID BIGSERIAL NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 DATAMININGALERT_ID INTEGER NOT NULL,
 DATAMININGCRITERIA_ID INTEGER NOT NULL,
 CONSTRAINT PRI__DATAMININGCRITERIAALERTS_ID PRIMARY KEY (ID)
);


/* cacheurl - Postgre   */
CREATE TABLE cacheurl
(
 ID BIGSERIAL NOT NULL,
 size INTEGER NOT NULL,
 matches INTEGER NOT NULL,
 misses INTEGER NOT NULL,
 action_time TIMESTAMP NOT NULL,
 CONSTRAINT PRI__CACHEURL_ID PRIMARY KEY (ID)
);


/* fencedsearch - Postgre   */
CREATE TABLE fencedsearch
(
 ID BIGSERIAL NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 SECONDLEVELDOMAIN_ID INTEGER NOT NULL,
 CONSTRAINT PRI__FENCEDSEARCH_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__FENCEDSEARCH_CUSTOMER_ID_SECONDLEVELDOMAIN_ UNIQUE (CUSTOMER_ID,SECONDLEVELDOMAIN_ID)
);


/* dict - Postgre   */
CREATE TABLE dict
(
 ID BIGSERIAL NOT NULL,
 keyword VARCHAR(255) NOT NULL,
 occurrence INTEGER NOT NULL,
 CONSTRAINT PRI__DICT_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DICT_KEYWORD UNIQUE (keyword)
);


ALTER TABLE documentcode ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE searchquery ADD CONSTRAINT FK__RESULTTHREAD_ID FOREIGN KEY (RESULTTHREAD_ID) REFERENCES queryresultthread (ID);

ALTER TABLE searchquery ADD CONSTRAINT FK__PROPERTIES_ID FOREIGN KEY (PROPERTIES_ID) REFERENCES queryproperties (ID);

ALTER TABLE docmeta ADD CONSTRAINT FK__DICT_ID FOREIGN KEY (DICT_ID) REFERENCES dict (ID);

ALTER TABLE docmeta ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE queryresults ADD CONSTRAINT FK__SEARCHQUERY_ID FOREIGN KEY (SEARCHQUERY_ID) REFERENCES searchquery (ID);

ALTER TABLE queryresults ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE queryresults ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE customermatchcriteria ADD CONSTRAINT FK__CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES customerdomains (ID);

ALTER TABLE customermatchcriteria ADD CONSTRAINT FK__MATCHCRITERIA_ID FOREIGN KEY (MATCHCRITERIA_ID) REFERENCES matchcriteria (ID);

ALTER TABLE customermatchcriteriagrouptype ADD CONSTRAINT FK__CUSTOMERMATCHCRITERIA_ID FOREIGN KEY (CUSTOMERMATCHCRITERIA_ID) REFERENCES customermatchcriteria (ID);

ALTER TABLE dataminingcustomersession ADD CONSTRAINT FK__CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES dataminingcustomer (ID);

ALTER TABLE metainfo ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE imagelinks ADD CONSTRAINT FK__TARGET_URL_ID FOREIGN KEY (TARGET_URL_ID) REFERENCES urls (ID);

ALTER TABLE imagelinks ADD CONSTRAINT FK__IMAGE_URL_ID FOREIGN KEY (IMAGE_URL_ID) REFERENCES images (ID);

ALTER TABLE imagelinks ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE urlpathparts ADD CONSTRAINT FK__PATHPART_ID FOREIGN KEY (PATHPART_ID) REFERENCES pathparts (ID);

ALTER TABLE urlpathparts ADD CONSTRAINT FK__URLPATHPART_ID_NEXT FOREIGN KEY (URLPATHPART_ID_NEXT) REFERENCES urlpathparts (ID);

ALTER TABLE customerqueries ADD CONSTRAINT FK__CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES customerdomains (ID);

ALTER TABLE customerproductkeywords ADD CONSTRAINT FK__PRODUCT_ID FOREIGN KEY (PRODUCT_ID) REFERENCES customerproducts (ID);

ALTER TABLE customerproductkeywords ADD CONSTRAINT FK__DICT_ID FOREIGN KEY (DICT_ID) REFERENCES dict (ID);

ALTER TABLE customerdomains ADD CONSTRAINT FK__CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES customers (ID);

ALTER TABLE customerdomainblacklist ADD CONSTRAINT FK__CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES customerdomains (ID);

ALTER TABLE customerproductimages ADD CONSTRAINT FK__PRODUCT_ID FOREIGN KEY (PRODUCT_ID) REFERENCES customerproducts (ID);

ALTER TABLE hyperlinks ADD CONSTRAINT FK__TARGET_URL_ID FOREIGN KEY (TARGET_URL_ID) REFERENCES urls (ID);

ALTER TABLE hyperlinks ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE syncurls ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE syncurls ADD CONSTRAINT FK__SECONDLEVELDOMAIN_ID FOREIGN KEY (SECONDLEVELDOMAIN_ID) REFERENCES secondleveldomains (ID);

ALTER TABLE urls ADD CONSTRAINT FK__SCHEME_ID FOREIGN KEY (SCHEME_ID) REFERENCES schemes (ID);

ALTER TABLE urls ADD CONSTRAINT FK__TOPLEVELDOMAIN_ID FOREIGN KEY (TOPLEVELDOMAIN_ID) REFERENCES topleveldomains (ID);

ALTER TABLE urls ADD CONSTRAINT FK__SUBDOMAIN_ID FOREIGN KEY (SUBDOMAIN_ID) REFERENCES subdomains (ID);

ALTER TABLE urls ADD CONSTRAINT FK__SECONDLEVELDOMAIN_ID FOREIGN KEY (SECONDLEVELDOMAIN_ID) REFERENCES secondleveldomains (ID);

ALTER TABLE urls ADD CONSTRAINT FK__URLPATHPART_ID FOREIGN KEY (URLPATHPART_ID) REFERENCES urlpathparts (ID);

ALTER TABLE urls ADD CONSTRAINT FK__URLSEARCHPART_ID FOREIGN KEY (URLSEARCHPART_ID) REFERENCES urlsearchparts (ID);

ALTER TABLE customerproducts ADD CONSTRAINT FK__CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES customerdomains (ID);

ALTER TABLE dataminingblacklist ADD CONSTRAINT FK__CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES dataminingcustomer (ID);

ALTER TABLE latesturlstages ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE latesturlstages ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE unittest3 ADD CONSTRAINT FK__UNITTEST1_ID FOREIGN KEY (UNITTEST1_ID) REFERENCES unittest1 (ID);

ALTER TABLE unittest3 ADD CONSTRAINT FK__UNITTEST2_ID FOREIGN KEY (UNITTEST2_ID) REFERENCES unittest2 (ID);

ALTER TABLE customerproducturls ADD CONSTRAINT FK__PRODUCT_ID FOREIGN KEY (PRODUCT_ID) REFERENCES customerproducts (ID);

ALTER TABLE customerproducturls ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE urlspathpart ADD CONSTRAINT FK__PATHPART_ID FOREIGN KEY (PATHPART_ID) REFERENCES pathparts (ID);

ALTER TABLE urlspathpart ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE customersyncurl ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE urlstages ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE customerkeywords ADD CONSTRAINT FK__CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES customerdomains (ID);

ALTER TABLE dockey ADD CONSTRAINT FK__DICT_ID FOREIGN KEY (DICT_ID) REFERENCES dict (ID);

ALTER TABLE dockey ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

ALTER TABLE customersynccrawler ADD CONSTRAINT FK__CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES customerdomains (ID);

ALTER TABLE queryproperties ADD CONSTRAINT FK__SECONDLEVELDOMAIN_ID FOREIGN KEY (SECONDLEVELDOMAIN_ID) REFERENCES secondleveldomains (ID);

ALTER TABLE queryproperties ADD CONSTRAINT FK__SUBDOMAIN_ID FOREIGN KEY (SUBDOMAIN_ID) REFERENCES subdomains (ID);

ALTER TABLE customersessions ADD CONSTRAINT FK__CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES customers (ID);

ALTER TABLE dockeypos ADD CONSTRAINT FK__DOCKEY_ID FOREIGN KEY (DOCKEY_ID) REFERENCES dockey (ID);

ALTER TABLE images ADD CONSTRAINT FK__SCHEME_ID FOREIGN KEY (SCHEME_ID) REFERENCES schemes (ID);

ALTER TABLE images ADD CONSTRAINT FK__TOPLEVELDOMAIN_ID FOREIGN KEY (TOPLEVELDOMAIN_ID) REFERENCES topleveldomains (ID);

ALTER TABLE images ADD CONSTRAINT FK__SUBDOMAIN_ID FOREIGN KEY (SUBDOMAIN_ID) REFERENCES subdomains (ID);

ALTER TABLE images ADD CONSTRAINT FK__SECONDLEVELDOMAIN_ID FOREIGN KEY (SECONDLEVELDOMAIN_ID) REFERENCES secondleveldomains (ID);

ALTER TABLE images ADD CONSTRAINT FK__URLPATHPART_ID FOREIGN KEY (URLPATHPART_ID) REFERENCES urlpathparts (ID);

ALTER TABLE images ADD CONSTRAINT FK__URLSEARCHPART_ID FOREIGN KEY (URLSEARCHPART_ID) REFERENCES urlsearchparts (ID);

ALTER TABLE dataminingcriteriaalerts ADD CONSTRAINT FK__CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES dataminingcustomer (ID);

ALTER TABLE dataminingcriteriaalerts ADD CONSTRAINT FK__DATAMININGALERT_ID FOREIGN KEY (DATAMININGALERT_ID) REFERENCES dataminingalerts (ID);

ALTER TABLE dataminingcriteriaalerts ADD CONSTRAINT FK__DATAMININGCRITERIA_ID FOREIGN KEY (DATAMININGCRITERIA_ID) REFERENCES dataminingcriteria (ID);

ALTER TABLE fencedsearch ADD CONSTRAINT FK__CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES dataminingcustomer (ID);

ALTER TABLE fencedsearch ADD CONSTRAINT FK__SECONDLEVELDOMAIN_ID FOREIGN KEY (SECONDLEVELDOMAIN_ID) REFERENCES secondleveldomains (ID);
