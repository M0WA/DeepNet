<?php

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

include_once(".mysql.php");

class CommerceSearchDatabaseConnection extends MySQLDatabaseConnection
{
  static public function isLoggedIn()
  {
    if( !isset( $_COOKIE["SIRIDIAID"] ) )
      return -1;
    $siridiaId = MySQLDatabaseConnection::escapeString($_COOKIE["SIRIDIAID"]);

    $query  = "SELECT CUSTOMER_ID FROM commercesearch.customersessions WHERE session='".$siridiaId."' LIMIT 1";
    $result = MySQLDatabaseConnection::query($query);
    if( isset($result) && count( $result, 0 ) == 1 ) {
      return isset($result[0]["CUSTOMER_ID"]) ? $result[0]["CUSTOMER_ID"] : -1;
    } else {
      return -1;
    }
  }

  static public function tryAuthenticate()
  {
    if( !isset($_POST["username"]) || !isset($_POST["password"]) || !isset($_COOKIE["SIRIDIAID"]) ) {
      return -1; }

    $username  = MySQLDatabaseConnection::escapeString( $_POST["username"] );
    $password  = MySQLDatabaseConnection::escapeString( hash("sha512", $_POST["password"]) );
    $siridiaId = MySQLDatabaseConnection::escapeString( $_COOKIE["SIRIDIAID"] );

    $query  = "SELECT ID FROM commercesearch.customers WHERE login='".$username."' AND password='".$password."' LIMIT 1";
    $result = MySQLDatabaseConnection::query($query);
    if( count( $result, 0 ) == 1 ) {
      if( !isset($result[0]) || !isset($result[0]['ID']) ){
        return -1; }
      $customerId = $result[0]['ID'];
		  $query = "INSERT INTO commercesearch.customersessions (CUSTOMER_ID,session) VALUES (".$customerId.", '".$siridiaId."') ON DUPLICATE KEY UPDATE ID=ID,CUSTOMER_ID=VALUES(CUSTOMER_ID);";
      if( MySQLDatabaseConnection::exec($query) ) {
        return $customerId; }
      else {
        return -1; }
    } 
    else {
      return -1; 
    }
  }

  static public function logoutEcommerce()
  {
    if( !isset($_COOKIE["SIRIDIAID"]) ) {
      return false; }
    $siridiaId = MySQLDatabaseConnection::escapeString( $_COOKIE["SIRIDIAID"] );
    $query = "DELETE FROM  commercesearch.customersessions WHERE session='".$siridiaId."' LIMIT 1";
    MySQLDatabaseConnection::exec($query);
    return true;
  }

  static public function getDomainInfoByCustomerId($customerId, &$domain, &$revisitInterval, &$isRegex)
  { 
    $domain          = "";
    $revisitInterval = -1;
    $isRegex         = false;

    $query  = "SELECT domain,revisitInterval,isDomainRegex FROM commercesearch.customerdomains WHERE CUSTOMER_ID=".$customerId." LIMIT 1";
    $result = MySQLDatabaseConnection::query($query);
    if( count( $result, 0 ) == 1             && 
        isset($result[0])                    && 
        isset($result[0]['domain'])          && 
        isset($result[0]['revisitInterval']) && 
        isset($result[0]['isDomainRegex'])   
    ){
      $domain          = $result[0]['domain'];
      $revisitInterval = $result[0]['revisitInterval'];
      $isRegex         = $result[0]['isDomainRegex'];
      return true; }
    else {
      return false; }
  }

  static public function getBlacklistByCustomerId($customerId, &$blackListEntries)
  {
    $blackListEntries = array();
    $query = " SELECT dom.domain, bl.path, bl.isPathRegex ".
             " FROM commercesearch.customerdomainblacklist bl ".
             " INNER JOIN commercesearch.customerdomains dom ON dom.ID = bl.CUSTOMERDOMAIN_ID ".
             " WHERE dom.CUSTOMER_ID=".$customerId." ".
             " ORDER BY bl.path ASC ";
    $result = MySQLDatabaseConnection::query($query);
    $count = count( $result, 0 );
    if( $count > 0 ){
      $count = 0;
      foreach ($result as &$value) {
        if( isset($value)                && 
            isset($value['domain'])      && 
            isset($value['path'])        && 
            isset($value['isPathRegex']) 
        ){
          $blackListEntries[$count] = $value;
          $count++;
        }
        else {
          return false;
        }
      }
      return true; 
    }
    return false;
  }

  static public function getProductListByCustomerId($customerID)
  {
    $query = 
        " SELECT * ".
        " FROM commercesearch.customerproducts p ".
        " INNER JOIN commercesearch.customerdomains        dom  ON dom.ID=p.CUSTOMERDOMAIN_ID ".
        " LEFT JOIN commercesearch.customerproducturls     purl ON purl.PRODUCT_ID=p.ID ".
        " LEFT JOIN commercesearch.customerproductimages   pimg ON pimg.PRODUCT_ID=p.ID ".
        " LEFT JOIN commercesearch.customerproductkeywords pkey ON pkey.PRODUCT_ID=p.ID ".
        " LEFT JOIN lexicon.dict                           dict ON pkey.DICT_ID=dict.ID ".
        " WHERE dom.CUSTOMER_ID=".$customerID;
    return MySQLDatabaseConnection::query($query);
  }

  static public function setCrawlerIntervalByCustomerId($customerId, $revisitInterval)
  {
    $query = "UPDATE commercesearch.customerdomains ".
            " SET revisitInterval=".MySQLDatabaseConnection::escapeString($revisitInterval)." ".
            " WHERE CUSTOMER_ID=".$customerId.
            " LIMIT 1";
    return MySQLDatabaseConnection::exec($query);
  }

  static public function addCrawlerBlacklistByCustomerId($customerId,$blacklist_path)
  {
    $query = "INSERT INTO commercesearch.customerdomainblacklist (CUSTOMERDOMAIN_ID,path,isPathRegex) ".
            " SELECT customerdomains.ID, \"".MySQLDatabaseConnection::escapeString($blacklist_path)."\", 0 ".
            " FROM commercesearch.customerdomains WHERE CUSTOMER_ID=".$customerId;
    return MySQLDatabaseConnection::exec($query);
  }

  static public function deleteCrawlerBlacklistByCustomerId($customerId,$blacklist_path)
  {
    $query = "DELETE FROM commercesearch.customerdomainblacklist ".
            " WHERE ".
            "   CUSTOMERDOMAIN_ID=".$customerId." AND ".
            "   path=\"".MySQLDatabaseConnection::escapeString($blacklist_path)."\" ".
            " LIMIT 1";
    return MySQLDatabaseConnection::exec($query);
  }

  static public function getStaticSearchTargetsByCustomerId($customerId, &$staticTargets)
  {
    $staticTargets = array();
    $query = " SELECT dom.domain, custKey.keyword, custKey.target ".
             " FROM commercesearch.customerkeywords custKey ".
             " INNER JOIN commercesearch.customerdomains dom ON dom.ID = custKey.CUSTOMERDOMAIN_ID ".
             " WHERE dom.CUSTOMER_ID=".$customerId." ".
             " ORDER BY custKey.keyword ASC ";
    $result = MySQLDatabaseConnection::query($query);
    $count = count( $result, 0 );
    if( $count > 0 ){
      $count = 0;
      foreach ($result as &$value) {
        if( isset($value)                && 
            isset($value['domain'])      && 
            isset($value['keyword'])     && 
            isset($value['target']) 
        ){
          $staticTargets[$count] = $value;
          $count++;
        }
        else {
          return false;
        }
      }
      return true; 
    }
    return false;
  }

  static public function addStaticSearchEntry($customerId,$keyword,$target)
  {
    $query = "INSERT INTO commercesearch.customerkeywords (CUSTOMERDOMAIN_ID,keyword,target,isKeywordRegex) ".
            " SELECT ".
            "  custDom.ID, ".
            "  \"".MySQLDatabaseConnection::escapeString($keyword)."\", ".
            "  \"".MySQLDatabaseConnection::escapeString($target)."\", ".
            "  0 ".
            " FROM commercesearch.customerdomains custDom ".
            " WHERE custDom.CUSTOMER_ID=".$customerId;
    return MySQLDatabaseConnection::exec($query);
  }

  static public function deleteStaticSearchEntry($customerId,$keyword,$target)
  {
    $query = 
            " DELETE commercesearch.customerkeywords FROM commercesearch.customerkeywords ".
            " INNER JOIN commercesearch.customerdomains custDom ".
            " WHERE ".
              " custDom.CUSTOMER_ID=".$customerId." AND ".
              " custDom.ID=customerkeywords.CUSTOMERDOMAIN_ID AND ".
              " customerkeywords.keyword=\"".MySQLDatabaseConnection::escapeString($keyword)."\" AND ".
              " customerkeywords.target=\"".MySQLDatabaseConnection::escapeString($target)."\" ";
    return MySQLDatabaseConnection::exec($query);
  }

  static public function changePassword($oldPassword,$newPassword,$customerID) 
  {
    $oldPasswordMD5 = MySQLDatabaseConnection::escapeString( hash("sha512", $oldPassword) );
    $newPasswordMD5 = MySQLDatabaseConnection::escapeString( hash("sha512", $newPassword) );
    $query =
        " UPDATE commercesearch.customers ".
        " SET password=\"".$newPasswordMD5."\" ".
        " WHERE password=\"".$oldPasswordMD5."\" ".
        " AND ID=".$customerID;
    return MySQLDatabaseConnection::exec($query);
  }
}

/* ========================================================================================= */
/*                           SQLLite database connection (!!!DEPRECATED!!!)                  */
/* ========================================================================================= */

/*
class SQLLiteDatabaseConnection
{
  private static $dbFile = "../.lib/ecommerce.db";


  static private function getPDO($dbFile)
  {
    return new PDO("sqlite:".$dbFile);
  }

  static public function setDbFile($dbFileIn)
  {
    $dbFile = $dbFileIn;
  }

  static public function query($sqlQuery)
  {
	  $database = SQLLiteDatabaseConnection::getPDO($dbFile);
    $result = $database->query($sqlQuery);
    return $result;
  }

  static public function exec($dbFile,$sqlQuery)
  {
	  $database = SQLLiteDatabaseConnection::getPDO($dbFile);
    $database->beginTransaction();
    $database->exec($sqlQuery);
    $database->commit();
  }

  static public function isLoggedIn($dbFile)
  {
    if( !isset( $_COOKIE["SIRIDIAID"] ) )
      return false;
    $siridiaId = sqlite_escape_string ( $_COOKIE["SIRIDIAID"] );

    $query  = "SELECT * FROM ecommerce_user_session WHERE session='".$siridiaId."'";
    $result = SQLLiteDatabaseConnection::query($dbFile,$query);

    $resultRow = $result->fetch(PDO::FETCH_ASSOC);
	  $result->fetchAll(PDO::FETCH_COLUMN);	
	  if ( $resultRow == false ) {
		  return false;
	  }
	  else if ( isset($resultRow['ID']) ) {
		  return true;
	  }
    return false;
  }

  static public function tryAuthenticate($dbFile)
  {
    if( !isset($_POST["username"]) || !isset($_POST["password"]) || !isset($_COOKIE["SIRIDIAID"]) ) {
      return false; }

    $username  = sqlite_escape_string ( $_POST["username"]    );
    $password  = sqlite_escape_string ( hash("sha512", $_POST["password"]) );
    $siridiaId = sqlite_escape_string ( $_COOKIE["SIRIDIAID"] );

    $query  = "SELECT ID as USER_ID FROM ecommerce_user WHERE username='".$username."' AND password='".$password."'";
    $result = SQLLiteDatabaseConnection::query($dbFile,$query);

    $resultRow = $result->fetch(PDO::FETCH_ASSOC);
	  $result->fetchAll(PDO::FETCH_COLUMN);	
	  if ( $resultRow == false ) {
      $dbError = "error1";
		  return false;
	  }
	  else if ( isset($resultRow['USER_ID']) ) {
		  $query = "INSERT INTO ecommerce_user_session (USER_ID,session,age) VALUES (".$resultRow['USER_ID'].", '".$siridiaId."', datetime('now'));";
      SQLLiteDatabaseConnection::exec($dbFile,$query);
		  return true;
	  }
    return false;
  }

  static public function logoutEcommerce($dbFile)
  {
    if( !isset($_COOKIE["SIRIDIAID"]) ) {
      return false; }
    $siridiaId = sqlite_escape_string ( $_COOKIE["SIRIDIAID"] );
    $query = "DELETE FROM ecommerce_user_session WHERE session='".$siridiaId."'";
    SQLLiteDatabaseConnection::exec($dbFile,$query);
    return true;
  }
}
*/

/* ========================================================================================= */

?>
