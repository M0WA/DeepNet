<?php

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

$productList = array();
$customerId = class_exists( "CommerceSearchDatabaseConnection" ) ? CommerceSearchDatabaseConnection::isLoggedIn() : -1;
if($customerId>0) {

    $productList = CommerceSearchDatabaseConnection::getProductListByCustomerId($customerId);
}
?>

<div class="inside">
  <div class="container_24">
    <div class="wrapper" style="font-size: 14px;">
      <center>
      <h3>eCommerce Search - <span class="color-1">Produkte</span></h3>
      </center>
    </div>
  </div>
</div>
