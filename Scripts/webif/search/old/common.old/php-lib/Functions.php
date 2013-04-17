<?php

class ContactForm
{
  public static function SendMail($domain)
  {
    $contactEmail   = $_POST["contact_email"];
    $contactMessage = $_POST["contact_message"];

    if( mail('website_form@siridia.de', 'message from contact formular',  "eMail:\r\n".$contactEmail."\r\n\r\nNachricht:\r\n".$contactMessage."\r\n\r\n\r\ntransmitted by: ".$_SERVER['REMOTE_ADDR']." ".$domain, 'From: website_form@siridia.de') )
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}

class DNSCheck
{
  public static function CheckIfLimitDnsReached()
  {
	  $sqlCmd = "SELECT COUNT(*) as noLookups FROM lookups WHERE actionTime >= datetime('now','localtime','-1 days');";
	  # print $sqlCmd."<br /><br />";
	  $result = SQLLiteDatabaseConnection::query($sqlCmd);	
	  $resultRow = $result->fetch(PDO::FETCH_ASSOC);
	  $result->fetchAll(PDO::FETCH_COLUMN);
	
	  if ( $resultRow == false )
	  {
		  return true;
	  }
	  else if (isset($resultRow['noLookups']) && $resultRow['noLookups']  < 100)
	  {
		  #print "no rows: ".$resultRow['noLookups']."<br />";
		  return false;
	  }
	  return true;
  }

  public static function ForwardDNS($hostName, &$host4, &$host6)
  {	
	  #$escapedHostName = sqlite_escape_string($escapedHostName);
	  #if(CheckIfLimitDnsReached())
		#  return false;
		
	  $host4 = dns_get_record($hostName,DNS_A);
	  $host6 = dns_get_record($hostName,DNS_AAAA);	
	
	  $resultString = print_r($host4,true)."\n".print_r($host6,true);

	  #$sqlCmd = "INSERT INTO lookups (lookupString, lookupResult, requestIp, actionTime) VALUES ('".$escapedHostName."', '".$resultString."', '".$_SERVER['REMOTE_ADDR']."', datetime('now'));";	
	  #SQLLiteDatabaseConnection::exec($sqlCmd);

    return true;
  }

  public static function ReverseDNS($ip, &$host)
  {
	  # $escapedIp = sqlite_escape_string($ip);
	  # if(CheckIfLimitDnsReached())
		#   return false;

	  $ptr  = implode(".",array_reverse(explode(".",$ip))).".in-addr.arpa";
	  $host = dns_get_record($ptr,DNS_PTR);

	  #$sqlCmd = "INSERT INTO lookups (lookupString, lookupResult, requestIp, actionTime) VALUES ('".$escapedIp."', '".$resultString."', '".$_SERVER['REMOTE_ADDR']."', datetime('now'));";	
	  #SQLLiteDatabaseConnection::exec($sqlCmd);

    return true;
  }
}

class GeoLocator
{
  public static function Locate($ip)
  {
    $query_url = 'http://www.geoplugin.net/php.gp?ip='.$ip;
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $query_url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_TIMEOUT, 15);
    return unserialize(curl_exec($ch));
  }
}

?>
