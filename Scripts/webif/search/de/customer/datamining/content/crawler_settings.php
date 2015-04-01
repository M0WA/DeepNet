<?php

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

$blacklistDomains = array();
$customerId = class_exists( "DataminingDatabaseConnection" ) ? DataminingDatabaseConnection::isLoggedIn() : -1;
if($customerId>0) 
{
    if( isset($_POST["mode"]) && $_POST["mode"] == "add_blacklist" && isset($_POST["blacklist_domain"]) ) {
      DataminingDatabaseConnection::addBlacklist($customerId,$_POST["blacklist_domain"]);
    }
    
    $blacklistDomains = DataminingDatabaseConnection::getBlacklistDomainInfoByCustomerID($customerId);
}

?>
<div class="inside">
  <div class="container_24">
    <div class="wrapper" style="font-size: 14px;">
      <center>
      <h3>DataMining - <span class="color-1">Crawler</span></h3>
      </center>
      <br>
      <h4>Blacklist</h4>
      <form method="post">
        <input type="hidden" name="mode" value="add_blacklist" />
        <input type="text" name="blacklist_domain" value="example.com" />&nbsp;&nbsp;<input type="submit" value="Hinzuf&uuml;gen" />
      </form>
<?php if(count($blacklistDomains,0) > 0) {
} ?>
    </div>
  </div>
</div>
