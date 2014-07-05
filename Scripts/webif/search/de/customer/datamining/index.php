<?php

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

include_once('../../.lib/.datamining.php');
include_once('../../.lib/.headerprocessor.php');
include_once('../../.lib/.contentprocessor.php');

$headerLoginPart = array("Logout","/customer/datamining_logout.html");
$headerActiveEntry = 0;
$headerEntries = array(
    "Account" => array( "/customer/datamining/", array() ),
    "Crawler" => array( "/customer/datamining/crawler_settings.html", array() ),
    "Keyword" => array( "/customer/datamining/keyword_settings.html", array() ),
    "Notify"  => array( "/customer/datamining/notification_settings.html", array() ),
);

if( isset($_REQUEST["mode"])       && 
    $_REQUEST["mode"] === "logout" && 
    DataminingDatabaseConnection::logoutDatamining() ) 
{
    header('Location: /customer/login.html');
}

ContentProcessor::$footerFile = '../../footer.php';

$page = isset($_REQUEST["page"]) ? $_REQUEST["page"] : "account_settings";
switch($page)
{
case "crawler_settings":
    ContentProcessor::$contentFile     = "crawler_settings.php";
    ContentProcessor::$metaDescription = "Crawler Einstellungen für SIRIDIA Datamining";
    ContentProcessor::$metaKeywords    = "crawler,settings,siridia,datamining";
    ContentProcessor::$pageTitle       = "Crawler Einstellungen";
    $headerActiveEntry = 1;
    break;
case "keyword_settings":
    ContentProcessor::$contentFile     = "keyword_settings.php";
    ContentProcessor::$metaDescription = "Keyword Einstellungen für SIRIDIA Datamining";
    ContentProcessor::$metaKeywords    = "product,settings,siridia,datamining";
    ContentProcessor::$pageTitle       = "Keyword Einstellungen";
    $headerActiveEntry = 2;
    break;
case "notification_settings":
    ContentProcessor::$contentFile     = "notify_settings.php";
    ContentProcessor::$metaDescription = "Benachrichtigungen für SIRIDIA Datamining";
    ContentProcessor::$metaKeywords    = "search query,settings,siridia,datamining";
    ContentProcessor::$pageTitle       = "Benachrichtigungen";
    $headerActiveEntry = 3;
    break;
case "account_settings":
default:
    ContentProcessor::$contentFile     = "account_settings.php";
    ContentProcessor::$metaDescription = "Account Einstellungen für SIRIDIA Datamining";
    ContentProcessor::$metaKeywords    = "account,settings,siridia,datamining";
    ContentProcessor::$pageTitle       = "Account Einstellungen";
    $headerActiveEntry = 0;
    break;
}

$customerId = DataminingDatabaseConnection::isLoggedIn();
if($customerId==-1) {
    $customerId = DataminingDatabaseConnection::tryAuthenticate();}

if( $customerId > 0 ) {
    ContentProcessor::PrintPage($headerEntries,$headerActiveEntry,$headerLoginPart);
} //end of logged in user
else {
    //redirect unauthenticated user and invalid logins back to login page
    header('Location: /customer/login.html');
}
?>