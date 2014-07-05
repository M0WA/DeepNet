<?php

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

include_once('.lib/.headerprocessor.php');
include_once('.lib/.contentprocessor.php');

$headerLoginPart = array("Login","/customer/login.html");
$headerActiveEntry = 0;
$headerEntries = array(
    "Home"       => array( "/", array()  ),
    "Leistungen" => array( "#", 
        array(
            "Commerce Search" => "/services/ecommerce.html",
            "Site Monitor"    => "/services/sitemonitor.html",
            "Web Mining"      => "/services/webmining.html",
            "Whitelabel"      => "/services/whitelabel.html",
        )
    ),
    "Tools" => array( "#",  
        array(
            "SEO Check"     => "/tools/webpage_analyser.html",
            "DNS Check"     => "/tools/dns_checks.html",
            "IP Tools"      => "/tools/ip_tools.html",
            "Browser Check" => "/tools/browser_tools.html",
        )
    ),
    "WebSuche" => array( "/websearch/websearch.html", array() ),
    "Kontakt"  => array( "/contact/message.html", 
        array(
            "&Uuml;ber SIRIDIA" => "/contact/about.html",
            "Kontaktformular"   => "/contact/message.html",
            "Impressum"         => "/contact/impressum.html",
        )
    ),
);

ContentProcessor::$includeQueryScripts = false;

switch($_REQUEST["dir"])
{
case "customer":
    $headerActiveEntry = -1;
    if( $_REQUEST["page"] == 'login' ) {
        $headerLoginPart = array("<u><b>Login</b></u>","/customer/login.html");
        ContentProcessor::$contentFile     = "customer_login.php";
        ContentProcessor::$metaDescription = "Login für unseren Kundenbereich";
        ContentProcessor::$metaKeywords    = "";
        ContentProcessor::$pageTitle       = "Kundenbereich - Login";
    }
    break;

case "services":
    $headerActiveEntry = 1;
    switch($_REQUEST["page"])
    {
    case "ecommerce":
        ContentProcessor::$contentFile     = "services_ecommerce.php";
        ContentProcessor::$metaDescription = "";
        ContentProcessor::$metaKeywords    = "";
        ContentProcessor::$pageTitle       = "";
        break;
    case "webmining":
        ContentProcessor::$contentFile     = "services_webmining.php";
        ContentProcessor::$metaDescription = "";
        ContentProcessor::$metaKeywords    = "";
        ContentProcessor::$pageTitle       = "";
        break;
    default:
        ContentProcessor::$contentFile = "";
        $headerActiveEntry = 0;
        break;
    }
    break;

case "tools":
  $headerActiveEntry = 2;
  switch($_REQUEST["page"])
  {
  case "dns_checks":
    ContentProcessor::$contentFile     = "tools_dns_checks.php";
    ContentProcessor::$metaDescription = "";
    ContentProcessor::$metaKeywords    = "";
    ContentProcessor::$pageTitle       = "";
    break;
  case "ip_tools":
    ContentProcessor::$contentFile     = "tools_ip_tools.php";
    ContentProcessor::$metaDescription = "";
    ContentProcessor::$metaKeywords    = "";
    ContentProcessor::$pageTitle       = "";
    break;
  case "browser_tools":
    ContentProcessor::$contentFile     = "tools_browser_tools.php";
    ContentProcessor::$metaDescription = "Online Check für Browser";
    ContentProcessor::$metaKeywords    = "online,browser,check,user agent,http referrer";
    ContentProcessor::$pageTitle       = "Online Browser Check";
    break;
  case "webpage_analyser":
    ContentProcessor::$contentFile     = "tools_webpage_analyser.php";
    ContentProcessor::$metaDescription = "Online SEO Check für ihre Webseite";
    ContentProcessor::$metaKeywords    = "seo,check,analyse,online seo check,website analyser";
    ContentProcessor::$pageTitle       = "Online SEO Check";
    ContentProcessor::$includeQueryScripts = true;
    break;
  default:
    ContentProcessor::$contentFile = "";
    $headerActiveEntry = 0;
    break;
  }
  break;

case "websearch":
  $headerActiveEntry = 3;
  ContentProcessor::$contentFile = "websearch_websearch.php";
  ContentProcessor::$includeQueryScripts = true;
  break;

case "contact":
  $headerActiveEntry = 4;
  switch($_REQUEST["page"])
  {
  case "message":
    ContentProcessor::$contentFile     = "contact_message.php";
    ContentProcessor::$metaDescription = "Kontaktieren Sie uns";
    ContentProcessor::$metaKeywords    = "Anschrift, postalische Adresse";
    ContentProcessor::$pageTitle       = "Kontakt";
    break;
  case "about":
    ContentProcessor::$contentFile     = "contact_about.php";
    ContentProcessor::$metaDescription = "Über SIRIDIA";
    ContentProcessor::$metaKeywords    = "Beschreibung";
    ContentProcessor::$pageTitle       = "Über uns";
    break;
  case "impressum":
    ContentProcessor::$contentFile     = "contact_impressum.php";
    ContentProcessor::$metaDescription = "Impressum SIRIDIA";
    ContentProcessor::$metaKeywords    = "imprint,impressum";
    ContentProcessor::$pageTitle       = "Impressum";
    break;
  default:
    ContentProcessor::$contentFile = "";
    $headerActiveEntry = 0;
    break;
  }
  break;

case "home":
default:
  $headerActiveEntry = 0;
  ContentProcessor::$contentFile     = "home_home.php";
  ContentProcessor::$metaDescription = "SIRIDIA ist Ihr Dienstleister für Informationsaggregation & Data-Mining im Internet. Wir bieten Commerce Search, SEO QA, Custom Web Search, Web Indexing uvm.";
  ContentProcessor::$metaKeywords    = "seo,monitoring,search engine,websearch,commerce search,quality assurance";
  ContentProcessor::$pageTitle       = "SIRIDIA - Ihr Dienstleister für Informationsaggregation";
  break;
}

ContentProcessor::PrintPage($headerEntries,$headerActiveEntry,$headerLoginPart);

?>
