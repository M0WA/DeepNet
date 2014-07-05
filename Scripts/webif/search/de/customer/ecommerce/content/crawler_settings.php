<?php

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

$customerId = class_exists( "CommerceSearchDatabaseConnection" ) ? CommerceSearchDatabaseConnection::isLoggedIn() : -1;
if($customerId>0) {

  if(isset($_POST["save_field"])){
    switch($_POST["save_field"])
    {
      /* we do not handle domain changes in the backend at this moment      
      case "domain":
        break;
      */
      case "interval":
        CommerceSearchDatabaseConnection::setCrawlerIntervalByCustomerId($customerId,$_POST["crawler_interval"]);
        break;
      case "blacklist":
        CommerceSearchDatabaseConnection::addCrawlerBlacklistByCustomerId($customerId,$_POST["blacklist_path"]);
        break;
      case "removeBlacklistEntry":
        CommerceSearchDatabaseConnection::deleteCrawlerBlacklistByCustomerId($customerId,$_POST["blacklist_path"]);
        break;
      case "triggerUpdate":
        // TODO: trigger update
        break;
      default:
        break;
    }
  }

  $domain = "";
  $revisitInterval = -1;
  $isRegex = false;
  if(!CommerceSearchDatabaseConnection::getDomainInfoByCustomerId($customerId, $domain, $revisitInterval, $isRegex)){
    //customer has no domains
  }

  $blackListEntries = array();
  if(!CommerceSearchDatabaseConnection::getBlacklistByCustomerId($customerId, $blackListEntries)){
    //customer has no blacklist entries
  }
?>

<div class="inside">
  <div class="container_24">
    <div class="wrapper" style="font-size: 14px;">
      <h3 style="padding-left: 5%; padding-right: 15%; text-align: center;">eCommerce Search - <span class="color-1">Crawler</span></h3>
      <br>
      <h4 style="padding-left: 10%; font-size: 16px;">Einstellungen (<?php print $domain; ?>)</h4>
      <br>
        <div style="padding-left: 15%; float: left;">
        <form method="post">
          <input type="hidden" name="save_field" value="interval">
          <fieldset>
            <table style="margin-bottom: 5px;">
              <tr>
                <td style="border-bottom: 0px"><label for="crawler_interval">Interval:&nbsp;&nbsp;</label></td>
                <td style="border-bottom: 0px"><input type="text" name="crawler_interval" value="<?php print $revisitInterval; ?>" /></td>
                <td style="border-bottom: 0px"><input type="submit" value="Speichern" /></td>
              </tr>
            </table>
          </fieldset>
        </form>
        <form method="post">
          <input type="hidden" name="save_field" value="blacklist">
          <fieldset>
            <table style="margin-bottom: 5px;">
              <tr>
                <td style="border-bottom: 0px"><label for="blacklist_path">Blacklist:&nbsp;&nbsp;</label></td>
                <td style="border-bottom: 0px"><input type="text" name="blacklist_path" /></td>
                <td style="border-bottom: 0px"><input type="submit" value="Hinzufügen" /></td>
              </tr>
            </table>
          </fieldset>
        </form>
        <form method="post">
          <input type="hidden" name="save_field" value="trigger_update">
          <fieldset>
            <table style="margin-bottom: 5px;">
              <tr>
                <td style="border-bottom: 0px"><label for="trigger_update">Index:&nbsp;&nbsp;</label></td>
                <td style="border-bottom: 0px"><input type="submit" name="trigger_update" value="Update triggern" /></td>
                <td style="border-bottom: 0px"></td>
              </tr>
            </table>
          </fieldset>
        </form>
        </div>
        <div>
      </div>
      <br style="clear:both;">
      <br>
      <h4 style="padding-left: 10%;font-size: 16px;">Status</h4>
      <div style="padding-left: 15%;">
      <table>
        <tr>
          <td style="border-bottom: 0px">Letztes Update:&nbsp;&nbsp;</td>
          <td style="border-bottom: 0px">n/a</td>
        </tr>
        <tr>
          <td style="border-bottom: 0px">Anzahl Seiten:&nbsp;&nbsp;</td>
          <td style="border-bottom: 0px">n/a</td>
        </tr>
        <tr>
          <td style="border-bottom: 0px">Anzahl Fehler:&nbsp;&nbsp;</td>
          <td style="border-bottom: 0px">n/a</td>
        </tr>
      </table>
      </div>
      <h4 style="padding-left: 10%;font-size: 16px;">Blacklist</h4>
      <div style="padding-left: 15%;">
<?php
if( count($blackListEntries,0) == 0){
  print "n/a";
}
else {
?>
      <br>
      <table>
      <tbody>
      <tr><th style="text-align: left;">Pfad</th><th style="text-align: left;">Domain</th><th></th></tr>
<?php
  foreach ($blackListEntries as &$value) {
?>
        <tr>
          <td style="border-bottom: 0px; padding-left: 5px; padding-right: 5px;"><a href="http://<?php print $value["domain"].$value["path"]; ?>"><?php print $value["path"]; ?></td>
          <td style="border-bottom: 0px; padding-left: 5px; padding-right: 5px;"><a href="http://<?php print $value["domain"]; ?>"><?php print $value["domain"]; ?></a></td>
          <td style="border-bottom: 0px; padding-left: 5px; padding-right: 5px;">
            <form method="POST">
              <input type="hidden" name="save_field"     value="removeBlacklistEntry" />
              <input type="hidden" name="domain"         value="<?php print $value["domain"]; ?>" />
              <input type="hidden" name="blacklist_path" value="<?php print $value["path"]; ?>" />
              <input type="submit" value="Löschen" />
            </form>
          </td>
        </tr>
<?php } ?>
      </tbody>
      </table>
<?php } ?>
      </div>
      <h4 style="padding-left: 10%;font-size: 16px;">Hilfe</h4>
      <ul class="list-3" style="padding-left: 15%;padding-right: 15%;">
        <li><a href=""><span class="color-1">Interval</span></a> - Crawling-Interval in Minuten. Default: 30, Deaktivieren: >=0</li>
        <li><a href=""><span class="color-1">Domain</span></a> - Die Domain Ihres Webshop, z.B. meinshop.de</li>
        <li><a href=""><span class="color-1">Blacklist</span></a> - Pfade/Ordner Ihres Shops die bei der Indexierung ignoriert werden</li>
        <li><a href=""><span class="color-1">Update triggern</span></a> - Neuindexierung ihres Shops veranlassen</li>
      </ul>
    </div>
  </div>
</div>
<?php
//end of authentication check
}
?>
