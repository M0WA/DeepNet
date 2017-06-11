<?php

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

$customerKeywords = array();
$customerId = class_exists( "DataminingDatabaseConnection" ) ? DataminingDatabaseConnection::isLoggedIn() : -1;
if($customerId>0) 
{
    if( isset($_POST["mode"]) && 
        $_POST["mode"] == "add_keyword" && 
        isset($_POST["keyword"]) &&
        isset($_POST["isRegex"]) &&
        isset($_POST["NotifyEmail"])
      ) {
        DataminingDatabaseConnection::addKeyword($_POST["keyword"],$_POST["isRegex"],$customerId,$_POST["NotifyEmail"]);
    }

    if(isset($_POST["delete_keyword"]) ) {
        DataminingDatabaseConnection::deleteKeyword($_POST["delete_keyword"],$customerId);
    }

    $customerKeywords = DataminingDatabaseConnection::getKeywordInfoByCustomerID($customerId);
}
?>

<div class="inside">
  <div class="container_24">
    <div class="wrapper" style="font-size: 14px;">
      <center>
      <h3>DataMining - <span class="color-1">Keyword</span></h3>
      </center>
<?php if(count($customerKeywords,0) > 0) { ?>
      <br>
      <h4 style="padding-left: 15%;font-size: 16px;">Keyword&uuml;bersicht</h4>
      <br>
      <div style="padding-left: 15%;">
        <table style="margin-bottom: 5px;">
            <tbody>
            <thead>
                <th style="border-bottom: 0px;">&nbsp;keyword&nbsp;</th>
                <th style="border-bottom: 0px;">&nbsp;regex&nbsp;</th>
                <th style="border-bottom: 0px;">&nbsp;</th>
            </thead>        
<?php foreach( $customerKeywords as $row) { ?>
            <tr>
                <form method="post">
                    <input type="hidden" name="delete_keyword" value="<?php echo $row['KEYWORD_ID']; ?>" />
                    <td style="border-bottom: 0px;">&nbsp;<?php echo $row['keyword']; ?>&nbsp;</td>
                    <td style="border-bottom: 0px;">&nbsp;<?php echo ($row['type'] == 1 ? "true" : "false"); ?>&nbsp;</td>
                    <td style="border-bottom: 0px;">&nbsp;<input type="submit" value="L&ouml;schen" />&nbsp;</td>
                </form>
            </tr>
<?php } ?>
            </tbody>
        </table>
      </div>
<?php } ?>
      <br>
      <h4 style="padding-left: 15%;font-size: 16px;">Keyword hinzuf&uuml;gen</h4>
      <br>
      <div style="padding-left: 15%;">
      <form method="post">
      <input type="hidden" name="mode" value="add_keyword">
      <fieldset>
        <table style="margin-bottom: 5px;">
            <tr>
                <td style="border-bottom: 0px"><label for="keyword">&nbsp;Keyword:&nbsp;</label></td>
                <td style="border-bottom: 0px">&nbsp;<textarea style="width: 350px;" name="keyword" rows="20"></textarea>&nbsp;</td>
            </tr>
            <tr>
                <td style="border-bottom: 0px"><label for="isRegex">&nbsp;Regex:&nbsp;</label></td>
                <td style="border-bottom: 0px">&nbsp;<input type="checkbox" name="isRegex" checked />&nbsp;</td>
            </tr>
            <tr>
                <td style="border-bottom: 0px"><label for="NotifyEmail">&nbsp;Notification Email:&nbsp;</label></td>
                <td style="border-bottom: 0px">&nbsp;<input type="text" name="NotifyEmail" />&nbsp;</td>
            </tr>
            <tr>
                <td style="border-bottom: 0px"><input type="submit" value="Hinzuf&uuml;gen" /></td>
            </tr>
        </table>
      </fieldset>
      </form>
      </div>
    </div>
  </div>
</div>
