DISCONNECT CURRENT;
DROP   DATABASE deepnet;
CREATE DATABASE deepnet AUTOMATIC STORAGE YES  ON '/home/deepinst' DBPATH ON '/home/deepinst' USING CODESET UTF-8 TERRITORY DE COLLATE USING SYSTEM PAGESIZE 8192;


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
 CONSTRAINT PRI__DOCUMENTCODE_ID PRIMARY KEY (ID)
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


/* dataminingblacklist - DB2   */
CREATE TABLE dataminingblacklist
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 CUSTOMER_ID INTEGER NOT NULL,
 domain VARCHAR(2048) NOT NULL,
 CONSTRAINT PRI__DATAMININGBLACKLIST_ID PRIMARY KEY (ID)
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


/* imagelinks - DB2   */
CREATE TABLE imagelinks
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 TARGET_URL_ID INTEGER NOT NULL,
 IMAGE_URL_ID INTEGER NOT NULL,
 URLSTAGE_ID INTEGER NOT NULL,
 CONSTRAINT PRI__IMAGELINKS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__IMAGELINKS_TARGET_URL_ID_URLSTAGE_ID_IMAGE_URL_ID UNIQUE (TARGET_URL_ID,URLSTAGE_ID,IMAGE_URL_ID )
);


/* customerproductimages - DB2   */
CREATE TABLE customerproductimages
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 PRODUCT_ID INTEGER NOT NULL,
 imageUrl VARCHAR(2048) NOT NULL,
 CONSTRAINT PRI__CUSTOMERPRODUCTIMAGES_ID PRIMARY KEY (ID)
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
 CONSTRAINT PRI__DOCKEY_ID PRIMARY KEY (ID)
);


/* customerproductkeywords - DB2   */
CREATE TABLE customerproductkeywords
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 PRODUCT_ID INTEGER NOT NULL,
 DICT_ID INTEGER NOT NULL,
 CONSTRAINT PRI__CUSTOMERPRODUCTKEYWORDS_ID PRIMARY KEY (ID)
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


/* dataminingcustomer - DB2   */
CREATE TABLE dataminingcustomer
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 login VARCHAR(255) NOT NULL,
 password VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__DATAMININGCUSTOMER_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__DATAMININGCUSTOMER_LOGIN UNIQUE (login)
);


/* secondleveldomains - DB2   */
CREATE TABLE secondleveldomains
(
 ID INTEGER GENERATED ALWAYS AS IDENTITY NOT NULL,
 domain VARCHAR(255) NOT NULL,
 CONSTRAINT PRI__SECONDLEVELDOMAINS_ID PRIMARY KEY (ID),
 CONSTRAINT UNIQ__SECONDLEVELDOMAINS_DOMAIN UNIQUE (domain)
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
 CONSTRAINT PRI__SEARCHQUERYKEYWORDS_ID PRIMARY KEY (ID)
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
 CONSTRAINT PRI__DOCMETA_ID PRIMARY KEY (ID)
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

ALTER TABLE dataminingblacklist ADD CONSTRAINT FK__CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES dataminingcustomer (ID);

ALTER TABLE docurl ADD CONSTRAINT FK__DICT_ID FOREIGN KEY (DICT_ID) REFERENCES dict (ID);

ALTER TABLE docurl ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE images ADD CONSTRAINT FK__SCHEME_ID FOREIGN KEY (SCHEME_ID) REFERENCES schemes (ID);

ALTER TABLE images ADD CONSTRAINT FK__TOPLEVELDOMAIN_ID FOREIGN KEY (TOPLEVELDOMAIN_ID) REFERENCES topleveldomains (ID);

ALTER TABLE images ADD CONSTRAINT FK__SUBDOMAIN_ID FOREIGN KEY (SUBDOMAIN_ID) REFERENCES subdomains (ID);

ALTER TABLE images ADD CONSTRAINT FK__SECONDLEVELDOMAIN_ID FOREIGN KEY (SECONDLEVELDOMAIN_ID) REFERENCES secondleveldomains (ID);

ALTER TABLE dataminingcustomersession ADD CONSTRAINT FK__CUSTOMER_ID FOREIGN KEY (CUSTOMER_ID) REFERENCES dataminingcustomer (ID);

ALTER TABLE latesturlstages ADD CONSTRAINT FK__URL_ID FOREIGN KEY (URL_ID) REFERENCES urls (ID);

ALTER TABLE latesturlstages ADD CONSTRAINT FK__URLSTAGE_ID FOREIGN KEY (URLSTAGE_ID) REFERENCES urlstages (ID);

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

ALTER TABLE customerproducts ADD CONSTRAINT FK__CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES customerdomains (ID);

ALTER TABLE customerdomainblacklist ADD CONSTRAINT FK__CUSTOMERDOMAIN_ID FOREIGN KEY (CUSTOMERDOMAIN_ID) REFERENCES customerdomains (ID);

INSERT INTO 
  topleveldomains (tld)
VALUES
 ('ac'), -- ascension island
 ('ad'), -- andorra
 ('ae'), -- united arab emirates
 ('aero'), -- reserved for members of the air-transport industry
 ('af'), -- afghanistan
 ('ag'), -- antigua and barbuda
 ('ai'), -- anguilla
 ('al'), -- albania
 ('am'), -- armenia
 ('an'), -- netherlands antilles
 ('ao'), -- angola
 ('aq'), -- antarctica
 ('ar'), -- argentina
 ('arpa'), -- reserved exclusively to support operationally-critical infrastructural identifier spaces as advised by the internet architecture board
 ('as'), -- american samoa
 ('asia'), -- restricted to the pan-asia and asia pacific community
 ('at'), -- austria
 ('au'), -- australia
 ('aw'), -- aruba
 ('ax'), -- aland islands
 ('az'), -- azerbaijan
 ('ba'), -- bosnia and herzegovina
 ('bb'), -- barbados
 ('bd'), -- bangladesh
 ('be'), -- belgium
 ('bf'), -- burkina faso
 ('bg'), -- bulgaria
 ('bh'), -- bahrain
 ('bi'), -- burundi
 ('biz'), -- restricted for business
 ('bj'), -- benin
 ('bl'), -- saint barthelemy
 ('bm'), -- bermuda
 ('bn'), -- brunei darussalam
 ('bo'), -- bolivia
 ('br'), -- brazil
 ('bs'), -- bahamas
 ('bt'), -- bhutan
 ('bv'), -- bouvet island
 ('bw'), -- botswana
 ('by'), -- belarus
 ('bz'), -- belize
 ('ca'), -- canada
 ('cat'), -- reserved for the catalan linguistic and cultural community
 ('cc'), -- cocos (keeling) islands
 ('cd'), -- congo, the democratic republic of the
 ('cf'), -- central african republic
 ('cg'), -- congo
 ('ch'), -- switzerland
 ('ci'), -- cote d'ivoire
 ('ck'), -- cook islands
 ('cl'), -- chile
 ('cm'), -- cameroon
 ('cn'), -- china
 ('co'), -- colombia
 ('com'), -- generic top-level domain
 ('coop'), -- reserved for cooperative associations
 ('cr'), -- costa rica
 ('cu'), -- cuba
 ('cv'), -- cape verde
 ('cx'), -- christmas island
 ('cy'), -- cyprus
 ('cz'), -- czech republic
 ('de'), -- germany
 ('dj'), -- djibouti
 ('dk'), -- denmark
 ('dm'), -- dominica
 ('do'), -- dominican republic
 ('dz'), -- algeria
 ('ec'), -- ecuador
 ('edu'), -- reserved for post-secondary institutions accredited by an agency on the us department of education's list of nationally recognized accrediting agencies
 ('ee'), -- estonia
 ('eg'), -- egypt
 ('eh'), -- western sahara
 ('er'), -- eritrea
 ('es'), -- spain
 ('et'), -- ethiopia
 ('eu'), -- european union
 ('fi'), -- finland
 ('fj'), -- fiji
 ('fk'), -- falkland islands (malvinas)
 ('fm'), -- micronesia, federated states of
 ('fo'), -- faroe islands
 ('fr'), -- france
 ('ga'), -- gabon
 ('gb'), -- united kingdom
 ('gd'), -- grenada
 ('ge'), -- georgia
 ('gf'), -- french guiana
 ('gg'), -- guernsey
 ('gh'), -- ghana
 ('gi'), -- gibraltar
 ('gl'), -- greenland
 ('gm'), -- gambia
 ('gn'), -- guinea
 ('gov'), -- reserved exclusively for the united states government
 ('gp'), -- guadeloup
 ('gq'), -- equatorial guinea
 ('gr'), -- greece
 ('gs'), -- south georgia and the south sandwich islands
 ('gt'), -- guatemala
 ('gu'), -- guam
 ('gw'), -- guinea-bissau
 ('gy'), -- guyana
 ('hk'), -- hong kong
 ('hm'), -- heard island and mcdonald islands
 ('hn'), -- honduras
 ('hr'), -- croatia
 ('ht'), -- haiti
 ('hu'), -- hungary
 ('id'), -- indonesia
 ('ie'), -- ireland
 ('il'), -- israel
 ('im'), -- isle of man
 ('in'), -- india
 ('info'), -- generic top-level domain
 ('int'), -- used only for registering organizations established by international treaties between governments
 ('io'), -- british indian ocean territory
 ('iq'), -- iraq
 ('ir'), -- iran, islamic republic of
 ('is'), -- iceland
 ('it'), -- italy
 ('je'), -- jersey
 ('jm'), -- jamaica
 ('jo'), -- jordan
 ('jobs'), -- reserved for human resource managers
 ('jp'), -- japan
 ('ke'), -- kenya
 ('kg'), -- kyrgyzstan
 ('kh'), -- cambodia
 ('ki'), -- kiribati
 ('km'), -- comoros
 ('kn'), -- saint kitts and nevis
 ('kp'), -- korea, democratic people's republic of
 ('kr'), -- korea, republic of
 ('kw'), -- kuwait
 ('ky'), -- cayman islands
 ('kz'), -- kazakhstan
 ('la'), -- laos people's democratic republic
 ('lb'), -- lebanon
 ('lc'), -- saint lucia
 ('li'), -- liechtenstein
 ('lk'), -- sri lanka
 ('lr'), -- liberia
 ('ls'), -- lesotho
 ('lt'), -- lithuania
 ('lu'), -- luxembourg
 ('lv'), -- latvia
 ('ly'), -- libyan arab jamahiriya
 ('ma'), -- morocco
 ('mc'), -- monaco
 ('md'), -- moldova, republic of
 ('me'), -- montenegro
 ('mf'), -- saint martin (french part)
 ('mg'), -- madagascar
 ('mh'), -- marshall islands
 ('mil'), -- reserved exclusively for the united states military
 ('mk'), -- macedonia, the former yugoslav republic of
 ('ml'), -- mali
 ('mm'), -- myanmar
 ('mn'), -- mongolia
 ('mo'), -- macao
 ('mobi'), -- reserved for consumers and providers of mobile products and services
 ('mp'), -- northern mariana islands
 ('mq'), -- martinique
 ('mr'), -- mauritania
 ('ms'), -- montserrat
 ('mt'), -- malta
 ('mu'), -- mauritius
 ('museum'), -- reserved for museums
 ('mv'), -- maldives
 ('mw'), -- malawi
 ('mx'), -- mexico
 ('my'), -- malaysia
 ('mz'), -- mozambique
 ('na'), -- namibia
 ('name'), -- reserved for individuals
 ('nc'), -- new caledonia
 ('ne'), -- niger
 ('net'), -- generic top-level domain
 ('nf'), -- norfolk island
 ('ng'), -- nigeria
 ('ni'), -- nicaragua
 ('nl'), -- netherlands
 ('no'), -- norway
 ('np'), -- nepal
 ('nr'), -- nauru
 ('nu'), -- niue
 ('nz'), -- new zealand
 ('om'), -- oman
 ('org'), -- generic top-level domain
 ('pa'), -- panama
 ('pe'), -- peru
 ('pf'), -- french polynesia
 ('pg'), -- papua new guinea
 ('ph'), -- philippines
 ('pk'), -- pakistan
 ('pl'), -- poland
 ('pm'), -- saint pierre and miquelon
 ('pn'), -- pitcairn
 ('pr'), -- puerto rico
 ('pro'), -- restricted to credentialed professionals and related entities
 ('ps'), -- palestinian territory, occupied
 ('pt'), -- portugal
 ('pw'), -- palau
 ('py'), -- paraguay
 ('qa'), -- qatar
 ('re'), -- reunion
 ('ro'), -- romania
 ('rs'), -- serbia
 ('ru'), -- russian federation
 ('rw'), -- rwanda
 ('sa'), -- saudi arabia
 ('sb'), -- solomon islands
 ('sc'), -- seychelles
 ('sd'), -- sudan
 ('se'), -- sweden
 ('sg'), -- singapore
 ('sh'), -- saint helena
 ('si'), -- slovenia
 ('sj'), -- svalbard and jan mayen
 ('sk'), -- slovakia
 ('sl'), -- sierra leone
 ('sm'), -- san marino
 ('sn'), -- senegal
 ('so'), -- somalia
 ('sr'), -- suriname
 ('ss'), -- south sudan
 ('st'), -- sao tome and principe
 ('su'), -- soviet union (being phased out)
 ('sv'), -- el salvador
 ('sy'), -- syrian arab republic
 ('sz'), -- swaziland
 ('tc'), -- turks and caicos islands
 ('td'), -- chad
 ('tel'), -- reserved for businesses and individuals to publish their contact data
 ('tf'), -- french southern territories
 ('tg'), -- togo
 ('th'), -- thailand
 ('tj'), -- tajikistan
 ('tk'), -- tokelau
 ('tl'), -- timor-leste
 ('tm'), -- turkmenistan
 ('tn'), -- tunisia
 ('to'), -- tonga
 ('tp'), -- portuguese timor (being phased out)
 ('tr'), -- turkey
 ('travel'), -- reserved for entities whose primary area of activity is in the travel industry
 ('tt'), -- trinidad and tobago
 ('tv'), -- tuvalu
 ('tw'), -- taiwan
 ('tz'), -- tanzania, united republic of
 ('ua'), -- ukraine
 ('ug'), -- uganda
 ('uk'), -- united kingdom
 ('um'), -- united states minor outlying islands
 ('us'), -- united states
 ('uy'), -- uruguay
 ('uz'), -- uzbekistan
 ('va'), -- holy see (vatican city state)
 ('vc'), -- saint vincent and the grenadines
 ('ve'), -- venezuela
 ('vg'), -- virgin islands, british
 ('vi'), -- virgin islands, us
 ('vn'), -- viet nam
 ('vu'), -- vanuatu
 ('wf'), -- wallis and futuna
 ('ws'), -- samoa
 ('ye'), -- yemen
 ('yt'), -- mayotte
 ('yu'), -- yugoslavia
 ('za'), -- south africa
 ('zm'), -- zambia
 ('zw') -- zimbabwe
;
INSERT INTO 
  schemes (scheme)
VALUES 
  ('http'),
  ('https')
;
DROP TRIGGER after_insert_urls;

--#SET TERMINATOR @

CREATE TRIGGER after_insert_urls 
  AFTER INSERT ON urls
  REFERENCING
    NEW AS POST
  FOR EACH ROW
  BEGIN ATOMIC
    INSERT INTO syncurls (URL_ID, SECONDLEVELDOMAIN_ID, CRAWLERSESSION_ID, schedule) 
    VALUES ( POST.ID, POST.SECONDLEVELDOMAIN_ID, 0, current timestamp - current timezone );
    

    MERGE INTO locksecondleveldomain lck
      USING (VALUES (POST.SECONDLEVELDOMAIN_ID))
      ON (POST.SECONDLEVELDOMAIN_ID = lck.SECONDLEVELDOMAIN_ID)
    WHEN NOT MATCHED THEN
      INSERT (SECONDLEVELDOMAIN_ID, CRAWLERSESSION_ID, schedule)
      VALUES (POST.SECONDLEVELDOMAIN_ID, 0, current timestamp - current timezone)
    ELSE IGNORE;
  END@

--#SET TERMINATOR ;
