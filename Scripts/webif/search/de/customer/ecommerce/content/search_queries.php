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
      case "staticTarget":
        CommerceSearchDatabaseConnection::addStaticSearchEntry($customerId,$_POST["query_string"],$_POST["query_string_target"]);
        break;
      case "removeStaticEntry":
        CommerceSearchDatabaseConnection::deleteStaticSearchEntry($customerId,$_POST["keyword"],$_POST["target"]);
        break;
      default:
        break;
    }
  }

  $staticTargets = array();
  CommerceSearchDatabaseConnection::getStaticSearchTargetsByCustomerId($customerId, $staticTargets);
?>

<div class="inside">
  <div class="container_24">
    <div class="wrapper" style="font-size: 14px;">
      <h3 style="padding-left: 15%; padding-right: 15%; text-align: center;">eCommerce Search - <span class="color-1">Suchanfragen</span></h3>
      <br>
      <h4 style="padding-left: 10%; font-size: 16px;">Statische Suchergebnisse konfigurieren</h4>
      <br>
<div style="padding-left: 15%; padding-right: 15%;">
      <form method="post">
        <input type="hidden" name="save_field" value="staticTarget">
        <fieldset>
          <table style="margin-bottom: 5px;">
            <tr>
              <td style="border-bottom: 0px"><label for="query_string">Suchbegriff:&nbsp;&nbsp;</label></td>
              <td style="border-bottom: 0px"><input type="text" name="query_string" />&nbsp;&nbsp;</td>
            </tr>
            <tr>
              <td style="border-bottom: 0px"><label for="query_string_target">Zielseite:&nbsp;&nbsp;</label></td>
              <td style="border-bottom: 0px"><input type="text" name="query_string_target" /></td>
            </tr>
            <tr>
              <td style="border-bottom: 0px"><label for="query_match_type">Erweitert:&nbsp;&nbsp;</label></td>
              <td style="border-bottom: 0px"><input type="radio" name="query_match_type" value="0" checked>Exakt (default)</td>
            </tr>
            <tr>
              <td style="border-bottom: 0px">&nbsp;</td>
              <td style="border-bottom: 0px"><input type="radio" name="query_match_type" value="1">Regular Expression</td>
            </tr>
            <tr>
              <td style="border-bottom: 0px">&nbsp;</td>
              <td style="border-bottom: 0px"><input type="submit" value="Hinzufügen" /></td>
            </tr>
          </table>
        </fieldset>
      </form>
</div>
      <br>
      <h4 style="padding-left: 10%; font-size: 16px;">statisch konfigurierte Suchergebnisse</h4>
<div style="padding-left: 15%;">
<?php
if( count($staticTargets,0) == 0){
  print "n/a";
}
else {
?>
      <br>
      <table>
      <tbody>
      <tr><th style="text-align: left;">Keyword</th><th style="text-align: left;">Ziel</th><th style="text-align: left;">Domain</th><th></th></tr>
<?php
  foreach ($staticTargets as &$value) {
?>
        <tr>
          <td style="border-bottom: 0px; padding-left: 5px; padding-right: 5px;"><?php print $value["keyword"]; ?></td>
          <td style="border-bottom: 0px; padding-left: 5px; padding-right: 5px;"><a href="http://<?php print $value["domain"].$value["target"]; ?>"><?php print $value["target"]; ?></a></td>
          <td style="border-bottom: 0px; padding-left: 5px; padding-right: 5px;"><a href="http://<?php print $value["domain"]; ?>"><?php print $value["domain"]; ?></td>
          <td style="border-bottom: 0px; padding-left: 5px; padding-right: 5px;">
            <form method="POST">
              <input type="hidden" name="save_field"     value="removeStaticEntry" />
              <input type="hidden" name="keyword"        value="<?php print $value["keyword"]; ?>" />
              <input type="hidden" name="domain"         value="<?php print $value["domain"]; ?>" />
              <input type="hidden" name="target"         value="<?php print $value["target"]; ?>" />
              <input type="submit" value="Löschen" />
            </form>
          </td>
        </tr>
<?php } ?>
      </tbody>
      </table>
<?php } ?>
</div>
      <br>
      <h4 style="padding-left: 10%; font-size: 16px;">letzten 100 Suchanfragen</h4>
<div style="padding-left: 15%;">
      n/a
</div>
      <br>
    </div>
  </div>
</div>

<?php
//end of authentication check
}
?>
