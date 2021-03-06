<?php

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2015, Moritz Wagner
# Author: Moritz Wagner (moritz.wagner@mo-sys.de)
#
#########################################################

$customerId = class_exists( "CommerceSearchDatabaseConnection" ) ? CommerceSearchDatabaseConnection::isLoggedIn() : -1;
if($customerId>0) {
    if( isset($_POST["mode"]) && 
        $_POST["mode"] == "change_password" && 
        isset($_POST["old_password"])  &&
        isset($_POST["new_password1"]) &&
        isset($_POST["new_password2"]) &&
        $_POST["new_password1"] == $_POST["new_password2"]
      ){
            CommerceSearchDatabaseConnection::changePassword($_POST["old_password"],$_POST["new_password1"],$customerId);
    }
}
?>

<div class="inside">
  <div class="container_24">
    <div class="wrapper" style="font-size: 14px;">
      <h3 style="padding-left: 15%;padding-right: 15%;text-align: center;">eCommerce Search - <span class="color-1">Account</span></h3>
      <p style="padding-left: 15%;padding-right: 15%;">
        Sie haben hier die Möglichkeit, die Shop-Suche nach Ihren Bedürftnisse zu konfigurieren sowie relevante Daten zu exportieren.
      </p>
      <p style="padding-left: 15%;padding-right: 15%;">
        Um Fehlkonfigurationen vorzubeugen, unterstützt Sie unser <a href="mailto:support@siridia.de?subject=Supportanfrage: eCommerce Search (<?php echo $customerId; ?>)">Support</a> (<i>support@siridia.de</i>) gerne.
      </p>
      <br>
      <h4 style="padding-left: 15%;font-size: 16px;">Passwort ändern</h4>
      <div style="padding-left: 15%;">
      <form method="post">
      <input type="hidden" name="mode" value="change_password">
      <fieldset>
        <table style="margin-bottom: 5px;">
            <tr>
                <td style="border-bottom: 0px"><label for="old_password">Altes Passwort:&nbsp;&nbsp;</label></td>
                <td style="border-bottom: 0px"><input type="password" name="old_password" value="" /></td>
            </tr>
            <tr>
                <td style="border-bottom: 0px"><label for="new_password1">Neues Passwort:&nbsp;&nbsp;</label></td>
                <td style="border-bottom: 0px"><input type="password" name="new_password1" value="" /></td>
            </tr>
            <tr>
                <td style="border-bottom: 0px"><label for="new_password2">Passwort wiederholen:&nbsp;&nbsp;</label></td>
                <td style="border-bottom: 0px"><input type="password" name="new_password2" value="" /></td>
            </tr>
            <tr>
                <td style="border-bottom: 0px"><input type="submit" value="Speichern" /></td>
            </tr>
        </table>
        </fieldset>
        </form>
      </div>
      <br>
      <h4 style="padding-left: 15%;font-size: 16px;">Hilfe zu den Menüpunkten</h4>
      <ul class="list-3" style="padding-left: 15%;padding-right: 15%;">
        <li><a href="/customer/ecommerce/crawler_settings.html"><span class="color-1">Crawler</span></a> - Einstellmöglichkeiten zu Indexierung, z.B. Crawling-Interval</li>
        <li><a href="/customer/ecommerce/product_list.html"><span class="color-1">Produkte</span></a> - Erfasste Produkte, Einstellungen zu einzelnen Produkten</li>
        <li><a href="/customer/ecommerce/search_queries.html"><span class="color-1">Suchanfragen</span></a> - Suchstatistiken exportieren, Ergebnisse konfigurieren etc.</li>
      </ul>
      <br>
      <br>
      <h4 style="padding-left: 15%;font-size: 16px;">Hinweise zur Account-Sicherheit</h4>
      <ul class="list-3" style="padding-left: 15%;padding-right: 10%;">
        <li><a href=""></a>Verwenden Sie Passwörter die min. 8 Zeichen lang sowie nicht-semantisch sind und Sonderzeichen enthalten</li>
        <li><a href=""></a>Wechseln Sie das Passwort in regelmäßigen Abständen</li>
        <li><a href=""></a>Verwenden Sie das Passwort bei keinem anderem Webservice</li>
        <li><a href=""></a>Melden Sie sich immer ab wenn Sie fertig sind (Logout Link oben rechts)</li>
        <li><a href=""></a>Stellen Sie sicher dass, die Email-Adresse dieses Accounts nur für Zugangsberechtige erreichbar ist</li>
        <li><a href=""></a>Ihr Passwort wird aus Sicherheitsgründen SHA512 verschlüsselt gespeichert, im Verlustfall sind deshalb nur Passwortänderungen mögl.</li>
      </ul>
    </div>
  </div>
</div>
