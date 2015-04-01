<?php

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

function CheckIfLimitDnsReached()
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

function ForwardDNS($hostName, &$host4, &$host6)
{	
	$escapedHostName = sqlite_escape_string($escapedHostName);
	if(CheckIfLimitDnsReached())
		return false;
		
	$host4 = dns_get_record($hostName,DNS_A);
	$host6 = dns_get_record($hostName,DNS_AAAA);	
	
	$resultString = print_r($host4,true)."\n".print_r($host6,true);
	$sqlCmd = "INSERT INTO lookups (lookupString, lookupResult, requestIp, actionTime) VALUES ('".$escapedHostName."', '".$resultString."', '".$_SERVER['REMOTE_ADDR']."', datetime('now'));";	
	SQLLiteDatabaseConnection::exec($sqlCmd);
}

function ReverseDNS($ip, &$host)
{
	$escapedIp = sqlite_escape_string($ip);
	if(CheckIfLimitDnsReached())
		return false;

	$ptr  = implode(".",array_reverse(explode(".",$ip))).".in-addr.arpa";
	$host = dns_get_record($ptr,DNS_PTR);
	
	$resultString = print_r($host,true)."\n";
	$sqlCmd = "INSERT INTO lookups (lookupString, lookupResult, requestIp, actionTime) VALUES ('".$escapedIp."', '".$resultString."', '".$_SERVER['REMOTE_ADDR']."', datetime('now'));";	
	SQLLiteDatabaseConnection::exec($sqlCmd);
}
?>
