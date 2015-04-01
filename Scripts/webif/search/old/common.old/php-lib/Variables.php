<?php

global $domain;
$domain = $_SERVER['HTTP_HOST'];

if($domain == "com.siridia")
  $domain = "siridia.com";
elseif($domain == "de.siridia")
  $domain = "siridia.de";

global $variables;
$variables = array();

try
{$db = new PDO('sqlite:webif.db');}
catch( PDOException $e )
{die( $e->getMessage() );}

$query="SELECT ID FROM domains WHERE domain='".sqlite_escape_string ( $domain )."' LIMIT 1;";
$result = $db->query($query);
$rowarray = $result->fetchall(PDO::FETCH_ASSOC);
$rowno = 0;
foreach($rowarray as $row)
{
  $domainID = $row['ID'];
  $rowno++;
}

$query=" SELECT variables.name AS variableName, words.word AS variableValue".
       " FROM variables_domains ".
       " INNER JOIN variables ON variables.ID = variables_domains.VARIABLE_ID ".
       " INNER JOIN words ON words.ID = variables_domains.WORD_ID ".
       " WHERE variables_domains.DOMAIN_ID = ".$domainID;
$result = $db->query($query);
$rowarray = $result->fetchall(PDO::FETCH_ASSOC);
$rowno = 0;
foreach($rowarray as $row)
{
  $variableName  = $row['variableName'];
  $variableValue = $row['variableValue'];
  $variables[$variableName] = $variableValue;
 // echo $variableName." ".$variables[$variableName]."<br>";
  $rowno++;
}
?>
