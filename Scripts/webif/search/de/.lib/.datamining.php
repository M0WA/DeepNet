<?php

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

include_once(".mysql.php");

class DataminingDatabaseConnection extends MySQLDatabaseConnection 
{
  static public function isLoggedIn()
  {
    if( !isset( $_COOKIE["SIRIDIAID"] ) )
      return -1;
    $siridiaId = MySQLDatabaseConnection::escapeString($_COOKIE["SIRIDIAID"]);

    $query  = "SELECT CUSTOMER_ID FROM datamining.dataminingcustomersession WHERE session='".$siridiaId."' LIMIT 1";
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

    $query  = "SELECT ID FROM datamining.dataminingcustomer WHERE login='".$username."' AND password='".$password."' LIMIT 1";
    $result = MySQLDatabaseConnection::query($query);
    if( count( $result, 0 ) == 1 ) {
      if( !isset($result[0]) || !isset($result[0]['ID']) ){
        return -1; }
      $customerId = $result[0]['ID'];
          $query = "INSERT INTO datamining.dataminingcustomersession (CUSTOMER_ID,session) VALUES (".$customerId.", '".$siridiaId."') ON DUPLICATE KEY UPDATE ID=ID,CUSTOMER_ID=VALUES(CUSTOMER_ID);";
      if( MySQLDatabaseConnection::exec($query) ) {
        return $customerId; }
      else {
        return -1; }
    } 
    else {
      return -1; 
    }
  }

  static public function logoutDatamining()
  {
    if( !isset($_COOKIE["SIRIDIAID"]) ) {
      return false; }
    $siridiaId = MySQLDatabaseConnection::escapeString( $_COOKIE["SIRIDIAID"] );
    $query = "DELETE FROM  datamining.dataminingcustomersession WHERE session='".$siridiaId."' LIMIT 1";
    MySQLDatabaseConnection::exec($query);
    return true;
  }

  static public function changePassword($oldPassword,$newPassword,$customerID) 
  {
    $oldPasswordMD5 = MySQLDatabaseConnection::escapeString( hash("sha512", $oldPassword) );
    $newPasswordMD5 = MySQLDatabaseConnection::escapeString( hash("sha512", $newPassword) );
    $query =
        " UPDATE datamining.dataminingcustomer ".
        " SET password=\"".$newPasswordMD5."\" ".
        " WHERE password=\"".$oldPasswordMD5."\" ".
        " AND ID=".$customerID;
    return MySQLDatabaseConnection::exec($query);
  }

  static public function changeNotification($notificationID,$emailAddress,$customerID)
  {
    $emailAddressEscaped = MySQLDatabaseConnection::escapeString( $emailAddress );
    $query = 
        " UPDATE datamining.dataminingalerts da ".
        " INNER JOIN datamining.dataminingcriteriaalerts dca ON dca.DATAMININGALERT_ID=da.ID ".
        " SET da.param=\"".$emailAddressEscaped."\" ".
        " WHERE da.ID=".$notificationID." AND dca.CUSTOMER_ID=".$customerID;
    error_log($query);
    MySQLDatabaseConnection::exec($query);
  }

  static public function addKeyword($keyword,$isRegex,$customerID,$emailAddress)
  {
    $keywordEscaped      = MySQLDatabaseConnection::escapeString( $keyword );
    $emailAddressEscaped = MySQLDatabaseConnection::escapeString( $emailAddress );

    $query = 
        " INSERT INTO datamining.dataminingalerts (type,param) ".
        " VALUES (1,\"".$emailAddressEscaped."\")";
    MySQLDatabaseConnection::exec($query);

    $alertID = -1;
    $query = "SELECT LAST_INSERT_ID() AS ID";
    $result = MySQLDatabaseConnection::query($query);
    if( (count( $result, 0 ) == 1) && isset($result[0]) && isset($result[0]['ID'])) {
        $alertID = $result[0]['ID']; }
    else { return; }

    $query = 
        " INSERT INTO datamining.dataminingcriteria (keyword,type) ".
        " VALUES (\"".$keywordEscaped."\",1)";
    MySQLDatabaseConnection::exec($query);

    $criteriaID = -1;
    $query = "SELECT LAST_INSERT_ID() AS ID";
    $result = MySQLDatabaseConnection::query($query);
    if( (count( $result, 0 ) == 1) && isset($result[0]) && isset($result[0]['ID'])) {
        $criteriaID = $result[0]['ID']; }
    else { return; }

    $query = 
        " INSERT INTO datamining.dataminingcriteriaalerts (CUSTOMER_ID,DATAMININGALERT_ID,DATAMININGCRITERIA_ID) ".
        " VALUES (".$customerID.",".$alertID.",".$criteriaID.")";
    MySQLDatabaseConnection::exec($query);
  }

  static public function deleteKeyword($keywordID,$customerID)
  {
    $keywordIDEscaped = MySQLDatabaseConnection::escapeString( $keywordID );
    $query = 
        " SELECT ".
        "   dc.ID  AS CRITERIA_ID, ".
        "   da.ID  AS ALERT_ID, ".
        "   dca.ID AS CRITERIAALERT_ID ".
        " FROM datamining.dataminingcriteria dc ".
        " INNER JOIN datamining.dataminingcriteriaalerts dca ON dca.DATAMININGCRITERIA_ID = dc.ID ".
        " INNER JOIN datamining.dataminingalerts da ON dca.DATAMININGALERT_ID = da.ID ".
        " WHERE dca.CUSTOMER_ID=".$customerID." AND dc.ID=".$keywordIDEscaped;
    $result = MySQLDatabaseConnection::query($query);

    if(count($result,0) != 1)
        return;

    $query = "DELETE FROM datamining.dataminingcriteriaalerts WHERE ID=".$result[0]['CRITERIAALERT_ID'];
    MySQLDatabaseConnection::exec($query);

    $query = "DELETE FROM datamining.dataminingalerts WHERE ID=".$result[0]['ALERT_ID'];
    MySQLDatabaseConnection::exec($query);

    $query = "DELETE FROM datamining.dataminingcriteria WHERE ID=".$result[0]['CRITERIA_ID'];
    MySQLDatabaseConnection::exec($query);
  }

  static public function getKeywordInfoByCustomerID($customerID)
  {
    $query =
        " SELECT ".
        "   dc.ID                  AS KEYWORD_ID, ".
        "   dc.keyword             AS keyword, ".
        "   dc.type                AS type, ".
        "   dca.DATAMININGALERT_ID AS ALERT_ID ".
        " FROM datamining.dataminingcriteria dc ".
        " INNER JOIN datamining.dataminingcriteriaalerts dca ON dca.DATAMININGCRITERIA_ID = dc.ID ".
        " WHERE dca.CUSTOMER_ID=".$customerID;
    return MySQLDatabaseConnection::query($query);
  }

  static public function getNotificationInfoByCustomerID($customerID)
  {
    $query =
        " SELECT ".
        "   da.param AS param, ".
        "   da.type  AS type, ".
        "   da.ID    AS ALERT_ID ".
        " FROM datamining.dataminingalerts da ".
        " INNER JOIN datamining.dataminingcriteriaalerts dca ON dca.DATAMININGALERT_ID = da.ID ".
        " WHERE dca.CUSTOMER_ID=".$customerID;
    return MySQLDatabaseConnection::query($query);
  }

  static public function getBlacklistDomainInfoByCustomerID($customerID)
  {
    $query = 
        " SELECT ".
        "   dbl.* ".
        " FROM datamining.dataminingblacklist dbl ".
        " INNER JOIN datamining.dataminingcustomers dc ON dc.ID=dbl.CUSTOMER_ID ".
        " WHERE dbl.CUSTOMER_ID=".$customerID;
    return MySQLDatabaseConnection::query($query);
  }

  static public function addBlacklist($customerID,$blacklistDomain)
  {
    if(!DataminingDatabaseConnection::beginsWith($blacklistDomain,"http://")) {
      $blacklistDomain = "http://".$blacklistDomain; }

    $urlData = parse_url($blacklistDomain);
    $hostname = $urlData['host'];
    $baseDomain = explode(".", $hostname);
    $cntDomains = count($baseDomain);

    if($cntDomains < 2) {
      return; }

    $secondleveldomain = $baseDomain[$cntDomains-2];
    $hostname = MySQLDatabaseConnection::escapeString( $secondleveldomain );
  }

  static private function beginsWith( $str, $sub )
  {
    return ( substr( $str, 0, strlen( $sub ) ) == $sub );
  }
}

?>
