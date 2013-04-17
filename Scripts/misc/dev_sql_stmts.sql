/*
    SELECT COMPLETE URL
*/

SELECT subdomains.subdomain,secondleveldomains.domain,topleveldomains.tld
FROM urls
INNER JOIN secondleveldomains on urls.SECONDLEVELDOMAIN_ID = secondleveldomains.ID
LEFT  JOIN subdomains on urls.SUBDOMAIN_ID = subdomains.ID
INNER JOIN topleveldomains on urls.TOPLEVELDOMAIN_ID = topleveldomains.ID
WHERE url_md5="f56698fbea5fb9cfe986145b58a0edab";
