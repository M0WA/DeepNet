<?php

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

/* ========================================================================================= */
/*                             MySQL database connection                                     */
/* ========================================================================================= */

require_once(".db.conf.php");

class MySQLDatabaseConnection
{
  static private $mysqlConnection = false;

  function __destruct() {
    if(MySQLDatabaseConnection::$mysqlConnection != false) {
      mysql_close(MySQLDatabaseConnection::$mysqlConnection); 
      MySQLDatabaseConnection::$mysqlConnection = false; }
  }

  static protected function query($sqlQuery)
  {
    $resultArray = array();
    $mysqlResult = MySQLDatabaseConnection::exec($sqlQuery);
    if( $mysqlResult != null ) {
      $count = 0;
      while ($row = mysql_fetch_assoc($mysqlResult)) {
        $resultArray[$count] = $row;
        $count++; }
    }
    return $resultArray;
  }

  static protected function exec($sqlQuery)
  {
    return mysql_query( $sqlQuery, MySQLDatabaseConnection::getConnection() );
  }

  static protected function getConnection()
  {
    if(MySQLDatabaseConnection::$mysqlConnection == false) {      
      return mysql_connect(DatabaseConfig::$databaseHost, DatabaseConfig::$databaseUser, DatabaseConfig::$databasePass, false, MYSQL_CLIENT_COMPRESS);
    } else {
      return MySQLDatabaseConnection::$mysqlConnection;
    }
  }

  static protected function escapeString($rawString)
  {
    return mysql_real_escape_string($rawString, MySQLDatabaseConnection::getConnection());
  }
}

?>