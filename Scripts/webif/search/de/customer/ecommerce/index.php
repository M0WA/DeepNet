<?php

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
#
#########################################################

include_once("../../.lib/.commercesearch.php");
include_once('../../.lib/.headerprocessor.php');
include_once('../../.lib/.contentprocessor.php');

$headerLoginPart = array("Logout","/customer/commerce_search_logout.html");
$headerActiveEntry = 0;
$headerEntries = array(
    "Account"      => array( "/customer/ecommerce/", array() ),
    "Crawler"      => array( "/customer/ecommerce/crawler_settings.html", array() ),
    "Produkte"     => array( "/customer/ecommerce/product_list.html", array() ),
    "Suchanfragen" => array( "/customer/ecommerce/search_queries.html", array() ),
);

if( isset($_REQUEST["mode"])       && 
    $_REQUEST["mode"] === "logout" && 
    CommerceSearchDatabaseConnection::logoutEcommerce() ) 
{
    header('Location: /customer/login.html');
}

ContentProcessor::$footerFile = '../../footer.php';

$page = isset($_REQUEST["page"]) ? $_REQUEST["page"] : "account_settings";
switch($page)
{
case "crawler_settings":
  ContentProcessor::$contentFile     = "crawler_settings.php";
  ContentProcessor::$metaDescription = "Crawler Einstellungen für SIRIDIA Commerce Search";
  ContentProcessor::$metaKeywords    = "crawler,settings,siridia,commerce search";
  ContentProcessor::$pageTitle       = "Crawler Settings";
  $headerActiveEntry = 1;
  break;
case "product_list":
  ContentProcessor::$contentFile     = "product_list.php";
  ContentProcessor::$metaDescription = "Produkt Einstellungen für SIRIDIA Commerce Search";
  ContentProcessor::$metaKeywords    = "product,settings,siridia,commerce search";
  ContentProcessor::$pageTitle       = "Produktübersicht";
  $headerActiveEntry = 2;
  break;
case "search_queries":
  ContentProcessor::$contentFile     = "search_queries.php";
  ContentProcessor::$metaDescription = "Suchanfragen für SIRIDIA Commerce Search";
  ContentProcessor::$metaKeywords    = "search query,settings,siridia,commerce search";
  ContentProcessor::$pageTitle       = "Suchanfragen";
  $headerActiveEntry = 3;
  break;
case "account_settings":
default:
  ContentProcessor::$contentFile     = "account_settings.php";
  ContentProcessor::$metaDescription = "Account Einstellungen für SIRIDIA Commerce Search";
  ContentProcessor::$metaKeywords    = "account,settings,siridia,commerce search";
  ContentProcessor::$pageTitle       = "Account Settings";
  $headerActiveEntry = 0;
  break;
}

$customerId = CommerceSearchDatabaseConnection::isLoggedIn();
if($customerId==-1) {
  $customerId = CommerceSearchDatabaseConnection::tryAuthenticate();}

if( $customerId > 0 ) {
  ContentProcessor::PrintPage($headerEntries,$headerActiveEntry,$headerLoginPart);
} //end of logged in user
else {
  //redirect unauthenticated user and invalid logins back to login page
  header('Location: /customer/login.html');
}
?>
