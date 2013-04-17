<?php

include_once("Functions.php");

class PagePrinter
{
  public static function PrintPage($variables,$domain,$content)
  {
      $content_Site = "";
      switch($content)
      {
/* ============================================

        ANALYZER CONTENT

   ============================================ */
        case "analyzer":
          $content_Site .= "
    <div id=\"form_container\">
      <center>
        <form name=\"inspectform\" onsubmit=\"onInspect(); return false;\" onClick=\"return true;\" >
          <input type=\"hidden\" name=\"content\" value=\"analyzer\" />
          <textarea id=\"inspect_url\" name=\"inspect_url\" cols=\"100\" rows=\"10\">".$variables["ANALYSE_HINT"]."</textarea>
          <br>
          <input type=\"submit\" id=\"inspect_button\" value=\"".$variables["ANALYSE_BUTTON_VALUE"]."\" />
        </form>
      </center>
    </div>
    <br>
    <div id=\"inspect_output\">
    </div>";
          break;

/* ============================================

        TOOLS CONTENT

   ============================================ */
        case "tools":
          require('.content/.tools.inc');
          $content_Site .= ob_get_clean();
          if($_REQUEST["forward_dns"]) {
            $host4 = "";
            $host6 = "";
            DNSCheck::ForwardDNS($_REQUEST["domain"], $host4, $host6);
            $content_Site .= "<div style=\"margin: auto; width: 50%;\"><p style=\"text-align: center;\"><br></p><h4 style=\"text-align: center;\">IPv4</h4><p style=\"text-align: center;\">";
	          if ($host4 != null) 
	          {
		          $resolvedIpv4 = "";
		          foreach($host4 as $entry)
		          {
			          $resolvedIpv4 .= $entry['ip']."<br>";
		          /*
			          foreach( $entry as $key => $value )
			          {
				          print $key." => ".$value."<br>";
			          }
		          */
		          }
		          $content_Site .= $resolvedIpv4;
	          }
	          else {
		          $content_Site .= "not resolvable"; }
	          $content_Site .= "</p></div>\n"; 
          }
          elseif($_REQUEST["reverse_dns"]) {
            $domain4 = "";
            $content_Site .= DNSCheck::ReverseDNS($_REQUEST["ip"], $domain4);
            $content_Site .= "<div style=\"margin: auto; width: 50%; text-align: center;\">";
	          if ($domain4 != null)
	          {
		          $content_Site .= "<p>".$_REQUEST["ip"]." resolves to ".$domain4[0]['target'].".</p>\n";
		          $dump = print_r($host,true);
		
		          $content_Site .= "<h4 style=\"text-align: center;\">details</h4>\n<div style=\"margin: auto; width: 50%; text-align: left;\"><pre>\n\n";
		          foreach( $domain4 as $entry )
		          {
			          foreach( $entry as $key => $value )
			          {
				          $content_Site .= $key.": ".$value."<br>";
			          }
			          $content_Site .= "\n";
		          }
		          $content_Site .= "</pre></div>\n";
	          }
	          else
	          {
		          $content_Site .= "<p style=\"text-align: left;\">".$ip." (".$ptr.") could not be resolved.</p>\n";
	          }
          }
          $content_Site .= "</div>";
          break;

/* ============================================

        CONTACT CONTENT

   ============================================ */
        case "contact":
          if($_REQUEST["send_message"])
          {
            if(!ContactForm::SendMail($domain))
            {
            $content_Site .= "
      <div id=\"form_container\">
        <center>
          <p>error: please contact us at info__at__siridia__de</p>
        </center>
      </div>";
            }
            else
            {
            $content_Site .= "
      <div id=\"form_container\">
        <center>
          <p>".$variables["MAIL_SUCCESS"]."</p>
        </center>
      </div>";
            }
          }
          else
          {
            $content_Site .= file_get_contents('.content/.contact.inc', true);
            $content_Site .= "
      <div id=\"form_container\">
        <center>
          <form name=\"contactform\" method=\"POST\">
            <input type=\"hidden\" name=\"send_message\" value=\"1\" />
            <table>
            <tr><td>
              <p style=\"text-align:left;\">email:</p>
              <input type=\"text\" id=\"contact_email\" name=\"contact_email\" size=\"88\"/>
            </td></tr>
            <tr><td>
              <p style=\"text-align:left;\">".$variables["CONTACT_LABEL_MESSAGE"].":</p>
              <textarea id=\"contact_message\" name=\"contact_message\" cols=\"100\" rows=\"10\"></textarea>
            </td></tr>
            </table>
            <br>
            <input type=\"submit\" id=\"contact_button\" value=\"".$variables["CONTACT_BUTTON_VALUE"]."\" />  
          </form>
        </center>
      </div>";
          }
          break;

/* ============================================

        SERVICES CONTENT

   ============================================ */
        case "services":
          $content_Site .= file_get_contents('.content/.services.inc', true);
          break;

/* ============================================

        SEO_SERVICES CONTENT

   ============================================ */
        case "seo_services":
          $content_Site .= file_get_contents('.content/.seo_services.inc', true);
          break;

/* ============================================

        WEBSITE_SERVICES CONTENT

   ============================================ */
        case "website_services":
          $content_Site .= file_get_contents('.content/.website_services.inc', true);
          break;

/* ============================================

        INFORMATION_SERVICES CONTENT

   ============================================ */
        case "information_services":
          $content_Site .= file_get_contents('.content/.information_services.inc', true);
          break;

/* ============================================

        TERMS OF SERVICES CONTENT

   ============================================ */
        case "tos":
          $content_Site .= file_get_contents('.content/.tos.inc', true);
          break;

/* ============================================

        SEARCH/DEFAULT CONTENT

   ============================================ */
        case "search":
        default:
          $content_Site .= "
<div id=\"form_container\">
  <center>
    <form name=\"searchform\" onsubmit=\"return false;\" onClick=\"return true;\">
      <div id=\"criteria_box_id\" name=\"criteria_box\">
        ".$variables["SEARCH_CRITERIA"].":<br>
<!--        <input type=\"checkbox\" name=\"criteria[]\" value=\"1\" /> ".$variables["ALL_CRITERIA"]."<br> -->
        <input type=\"checkbox\" name=\"criteria[]\" value=\"2\" checked /> ".$variables["META_INFORMATION"]."<br>
        <input type=\"checkbox\" name=\"criteria[]\" value=\"4\" checked /> ".$variables["PAGE_TITLE"]."<br>
        <input type=\"checkbox\" name=\"criteria[]\" value=\"16\" checked /> ".$variables["DOMAIN_NAME_CRITERIA"]."<br>
        <input type=\"checkbox\" name=\"criteria[]\" value=\"32\" /> ".$variables["CONTENT_CRITERIA"]."
      </div>
      <br>
      <input type=\"text\" id=\"search_query\" name=\"search_query\"/>
      <input type=\"submit\" id=\"search_button\" onClick=\"onQuery();\" value=\"".$variables["SEARCH_BUTTON_VALUE"]."\" /><br><br>
    </form>
  </center>
</div>
<br>
<div id=\"results_container_pending\">
  <h3 id=\"result_header_pending\"></h3>
  <img src=\"/img/misc/wait.gif\" /><br>
  searching, please wait...
</div>
<div id=\"results_container\">
  <h3 id=\"result_header\"></h3>
  <div id=\"results_space\"></div>
</div>";
          break;
      }

/* ============================================

        PRINTING HTML

   ============================================ */
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
     "http://www.w3.org/TR/html4/strict.dtd">
<html>
  <?php
/* ============================================

       HTML HEADER

   ============================================ */
  ?>
  <head>
    <title>
      siridia - Suchmaschine
    </title>
    <meta name="description" content="<?php echo $domain; ?> - unabh&auml;ngige und alternative Suchmaschine sowie SEO Consulting">
    <meta name="keywords"    content="siridia, search engine, alternative, search, google, yahoo, bing, seo">
    <link rel="search"     type="application/opensearchdescription+xml" title="siridia search plugin" href="http://<?php echo $domain; ?>/ff_plugin/ff_search_plugin.xml">
    <link rel="stylesheet" type="text/css" href="/css/standard.css">
    <link rel="stylesheet" type="text/css" href="/css/query.css">
    <link rel="stylesheet" type="text/css" href="/css/inspect.css">
    <script type="text/javascript" src="/js/query.js"></script>
    <script type="text/javascript" src="/js/inspect.js"></script>
  </head>
  <body>
    <div class="siridia_blue_background">
      <div id="fb-root"></div>
      <script type="text/javascript">(function(d, s, id) {
        var js, fjs = d.getElementsByTagName(s)[0];
        if (d.getElementById(id)) return;
        js = d.createElement(s); js.id = id;
        js.src = "//connect.facebook.net/de_DE/all.js#xfbml=1";
        fjs.parentNode.insertBefore(js, fjs);
      }(document, 'script', 'facebook-jssdk'));</script>
      <div style="float: left;">
        <div style="float: left; margin: 5px; margin-right: 0px;"><a class="undecorated_link" href="http://siridia.de" alt="siridia homepage germany"><img border="0" width="30" height="20" src="/img/flags/de.gif" /></a></div>  
        <div style="float: left; margin: 5px;"><a class="undecorated_link" href="http://siridia.com" alt="siridia homepage"><img border="0" width="30" height="20" src="/img/flags/us.gif" /></a></div>
      </div>
      <div style="float: right;">
        <div style="float: right;">
            <a href="https://twitter.com/share" class="twitter-share-button">Tweet</a>
            <script type="text/javascript">!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
        </div>
        <div style="float: right;" class="fb-like" data-href="http://siridia.de" data-send="true" data-layout="button_count" data-width="200" data-show-faces="true" data-font="verdana"></div>      
      </div>
      <div style="clear: both; height: 0px;"></div>
    <?php
  /* ============================================

          OUTPUT OF MENU

     ============================================ */
    ?>
      <div id="page_header_container">
        <a href="/" class="undecorated_link"><h2 id="siridia_header">SIRIDIA</h2></a>
      </div>
      <div style="clear: both; height: 0px;"></div>
      <?php MenuPrinter::PrintMenu($variables);?>
      <div style="clear: both; height: 10px;"></div>
    </div>

  <?php
/* ============================================

        OUTPUT OF PAGE-SPECIFIC CONTENT

   ============================================ */
  ?>
  <div class="siridia_light_background">
  <?php echo $content_Site; ?>
  <br>
  </div>
  <?php
/* ============================================

        OUTPUT OF FOOTER

   ============================================ */
  ?>
    <center>
      <small><a class="undecorated_link" alt="<?php echo $variables["TERMS_OF_SERVICES_ALT"]; ?>" href="/tos/"><?php echo $variables["TERMS_OF_SERVICES"]; ?></a> | <a class="undecorated_link" alt="<?php echo $variables["SITE_NOTICE_ALT"]; ?>" href="/site_notice/"><?php echo $variables["SITE_NOTICE"]; ?></a></small><br/>
      <small>&copy; by <?php echo date("Y") ?> <a class="undecorated_link" href="http://<?php echo $domain; ?>/"><?php echo $domain; ?></a></small>
    </center>
  </body>
</html>
<?php
  }
}
?>
