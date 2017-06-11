<?php

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

$customerNotify = array();
$customerId = class_exists( "DataminingDatabaseConnection" ) ? DataminingDatabaseConnection::isLoggedIn() : -1;
if($customerId>0) 
{
    if( isset($_POST["change_alert"]) &&
        isset($_POST["new_email"])
      ) {
        DataminingDatabaseConnection::changeNotification($_POST["change_alert"],$_POST["new_email"],$customerId); }

    $customerNotify = DataminingDatabaseConnection::getNotificationInfoByCustomerID($customerId);
}

?>

<div class="inside">
  <div class="container_24">
    <div class="wrapper" style="font-size: 14px;">
      <center>
      <h3>DataMining - <span class="color-1">Benachrichtungen</span></h3>
      </center>
<?php if(count($customerNotify,0) > 0) { ?>
      <br>
      <h4 style="padding-left: 15%;font-size: 16px;">Benachrichtungs&uuml;bersicht</h4>
      <br>
      <div style="padding-left: 15%;">
        <table style="margin-bottom: 5px;">
            <tbody>
            <thead>
                <th style="border-bottom: 0px;">&nbsp;email&nbsp;</th>
                <th style="border-bottom: 0px;">&nbsp;</th>
                <th style="border-bottom: 0px;">&nbsp;</th>
            </thead>        
<?php foreach( $customerNotify as $row) { ?>
            <tr>
                <form method="post">
                    <input type="hidden" name="change_alert" value="<?php echo $row['ALERT_ID']; ?>" />
                    <td style="border-bottom: 0px;">&nbsp;<?php echo $row['param']; ?>&nbsp;</td>
                    <td style="border-bottom: 0px;">&nbsp;<input type="text" name="new_email" />&nbsp;</td>
                    <td style="border-bottom: 0px;">&nbsp;<input type="submit" value="&Auml;ndern" />&nbsp;</td>
                </form>
            </tr>
<?php } ?>
            </tbody>
        </table>
      </div>
<?php } ?>
    </div>
  </div>
</div>
