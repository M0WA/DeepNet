<?php
  $title = "mo-sys.de - online browser check";
  $meta_description = "online check for information leaking from your browser";
  $meta_keywords = "browser,check,useragent,user agent,security,information,leak,location,online";
?>

<?php
include(".lib/.geolocate.php");
$location_data = get_ip_location($_SERVER['REMOTE_ADDR']);
	
$browser = get_browser($_SERVER['HTTP_USER_AGENT'], true);
$architecture = "";
if ( $browser['win32'] == true )
{
	$architecture = "32 Bit";
}
else if ( $browser['win64'] == true )
{
	$architecture = "64 Bit";
}
else if ( $browser['win16'] == true )
{
	$architecture = "16 Bit";
}
else
{
	$architecture = "n/a";
}
?>
<h2>Browser Check</h2>
<p>This page summarizes information your browser is currently giving. Some information shown here is based on estimations and may therefore be incorrect.</p>
<br />
<center>
<h4>System</h4>
<table cellpadding="10" cellspacing="0" border="0" style="text-align: left; width: 60%;">
	<tr>
		<td style="border: 1px solid #000;">IP Address</td><td style="border: 1px solid #000;"><?php print $_SERVER['REMOTE_ADDR']; ?></td>
	</tr>
	<tr>
		<td style="border: 1px solid #000;">Country</td><td style="border: 1px solid #000;"><?php print $location_data['geoplugin_countryName']." (".$location_data['geoplugin_countryCode'].")"; ?></td>
	</tr>
	<tr>
		<td style="border: 1px solid #000;">Region</td><td style="border: 1px solid #000;"><?php print $location_data['geoplugin_region']; ?></td>
	</tr>
	<tr>
		<td style="border: 1px solid #000;">City</td><td style="border: 1px solid #000;"><?php print $location_data['geoplugin_city']; ?></td>
	</tr>
</table>
<br />
<hr style="width: 50%;" />
<h4>HTTP Header</h4>
<table cellpadding="10" cellspacing="0" border="0" style="text-align: left;">
<tr>
	<td style="border: 1px solid #000;">Refering Page</td><td style="border: 1px solid #000;"><?php print $_SERVER['HTTP_REFERER']; ?></td>
</tr>
<tr>
	<td style="border: 1px solid #000;">Language</td><td style="border: 1px solid #000;"><?php print $_SERVER['HTTP_ACCEPT_LANGUAGE']; ?></td>
</tr>
<tr>
	<td style="border: 1px solid #000;">Charset</td><td style="border: 1px solid #000;"><?php print $_SERVER['HTTP_ACCEPT_CHARSET']; ?></td>
</tr>
<tr>
	<td style="border: 1px solid #000;">User Agent</td><td style="border: 1px solid #000;"><?php print $_SERVER['HTTP_USER_AGENT']; ?></td>
</tr>
</table>
<br />
<hr style="width: 50%;" />
<h4>Browser</h4>
<table cellpadding="10" cellspacing="0" border="0" style="text-align: left;">
	<tr>
		<td style="border: 1px solid #000;">Browser</td><td style="border: 1px solid #000;"><?php print $browser['browser']; ?></td>
		<td style="border: 1px solid #000;">Platform</td><td style="border: 1px solid #000;"><?php print $browser['platform'] ?></td>
	</tr>
	<tr>
		<td style="border: 1px solid #000;">Browser Version</td><td style="border: 1px solid #000;"><?php print $browser['version']; ?></td>
		<td style="border: 1px solid #000;">Browser Architecture</td><td style="border: 1px solid #000;"><?php print $architecture; ?></td>
	</tr>
	<tr>
		<td style="border: 1px solid #000;">Tables</td><td style="border: 1px solid #000;"><?php print ($browser['tables'] == true ? "yes" : "no" ); ?></td>
		<td style="border: 1px solid #000;">Frames</td><td style="border: 1px solid #000;"><?php print ($browser['frames'] == true ? "yes" : "no" ); ?></td>
	</tr>
	<tr>
		<td style="border: 1px solid #000;">iFrames</td><td style="border: 1px solid #000;"><?php print ($browser['iframes'] == true ? "yes" : "no" ); ?></td>
		<td style="border: 1px solid #000;">Cookies</td><td style="border: 1px solid #000;"><?php print ($browser['cookies'] == true ? "yes" : "no" ); ?></td>
	</tr>
	<tr>
		<td style="border: 1px solid #000;">Java Script</td><td style="border: 1px solid #000;"><?php print ($browser['javascript'] == true ? "yes" : "no" ); ?></td>
		<td style="border: 1px solid #000;">Java Applets</td><td style="border: 1px solid #000;"><?php print ($browser['javaapplets'] == true ? "yes" : "no" ); ?></td>
	</tr>
	<tr>
		<td style="border: 1px solid #000;">ActiveX Controls</td><td style="border: 1px solid #000;"><?php print ($browser['activexcontrols'] == true ? "yes" : "no" ); ?></td>
		<td style="border: 1px solid #000;">VB Script</td><td style="border: 1px solid #000;"><?php print ($browser['vbscript'] == true ? "yes" : "no" ); ?></td>
	</tr>
	<tr>
		<td style="border: 1px solid #000;">CSS Version</td><td style="border: 1px solid #000;"><?php print $browser['cssversion']; ?></td>
	</tr>
</table>
<br />
<hr style="width: 50%;">
<h4>Flash</h4>
<table cellpadding="10" cellspacing="0" border="0" style="text-align: left; width: 50%;">
<tr>
	<td style="border: 1px solid #000;">Name</td><td style="border: 1px solid #000;"><div id=flash_name>not available</div></td>
</tr>
<tr>
	<td style="border: 1px solid #000;">Version</td><td style="border: 1px solid #000;"><div id=flash_version>not available</div></td>
</tr>
</table>
</center>

<script type="text/javascript">
function getFlashName()
{
  try {
    try {
      var axo = new ActiveXObject('ShockwaveFlash.ShockwaveFlash.6');
      try { axo.AllowScriptAccess = 'always'; }
      catch(e) { return '6,0,0'; }
    } catch(e) {}
	var axo2 = new ActiveXObject('ShockwaveFlash.ShockwaveFlash');
	var xx = axo2.GetVariable('$version').replace(/\D+/g, ',').match(/^,?(.+),?$/)[1];
    return "Shockwave Flash";
  } catch(e) {
    try {
      if(navigator.mimeTypes["application/x-shockwave-flash"].enabledPlugin)
		return navigator.mimeTypes["application/x-shockwave-flash"].enabledPlugin.name;
    } catch(e) {}
  }
  return 'not available';
}
function getFlashVersion()
{
  try {
    try {
      var axo = new ActiveXObject('ShockwaveFlash.ShockwaveFlash.6');
      try { axo.AllowScriptAccess = 'always'; }
      catch(e) { return '6,0,0'; }
    } catch(e) {}
	var axo2 = new ActiveXObject('ShockwaveFlash.ShockwaveFlash');
    return axo2.GetVariable('$version').replace(/\D+/g, ',').match(/^,?(.+),?$/)[1];
  } catch(e) {
    try {
      if(navigator.mimeTypes["application/x-shockwave-flash"].enabledPlugin)
		return navigator.mimeTypes["application/x-shockwave-flash"].enabledPlugin.version;
    } catch(e) {}
  }
  return '0,0,0';
}

var fieldNameElement = document.getElementById("flash_version");
if(fieldNameElement.firstChild)
	fieldNameElement.firstChild.nodeValue = getFlashVersion().replace(/,/g, ".");
	
fieldNameElement = document.getElementById("flash_name");
if(fieldNameElement.firstChild)
	fieldNameElement.firstChild.nodeValue = getFlashName();
</script>

<?php //print_r($_SERVER);
/*
print "<pre>";
print_r($browser);
print "</pre>";

<h3>Information accessible via ActiveX</h3>
<script type="text/javascript">
<!--
function getCpuInfo() {
      var locator = new ActiveXObject("WbemScripting.SWbemLocator");
      var service = locator.ConnectServer(".");
      var properties = service.ExecQuery("SELECT * FROM Win32_Processor");
      var e = new Enumerator (properties);
      document.write("<table border=1>");
      for (;!e.atEnd();e.moveNext ())
      {
            var p = e.item ();
            document.write("<tr>");
            document.write("<td>" + p.Caption + "</td>");
            document.write("<td>" + p.DeviceID + "</td>");
            document.write("<td>" + p.Name + "</td>");
            document.write("<td>" + p.CpuStatus + "</td>");
            document.write("<td>" + p.Availability + "</td>");
            document.write("<td>" + p.Level + "</td>");
            document.write("<td>" + p.ProcessorID + "</td>");
            document.write("<td>" + p.SystemName + "</td>");
            document.write("<td>" + p.ProcessorType + "</td>");
            document.write("</tr>");
      }
      document.write("</table>");
}

function getMainboardInfo() {
      var locator = new ActiveXObject("WbemScripting.SWbemLocator");
      var service = locator.ConnectServer(".");
      var properties = service.ExecQuery("SELECT * FROM Win32_BaseBoard");
      var e = new Enumerator (properties);
      document.write("<table border=1>");
      for (;!e.atEnd();e.moveNext ())
      {
            var p = e.item ();
            document.write("<tr>");
            document.write("<td>" + p.HostingBoard + "</td>");
            document.write("<td>" + p.Manufacturer + "</td>");
            document.write("<td>" + p.PoweredOn + "</td>");
            document.write("<td>" + p.Product + "</td>");
            document.write("<td>" + p.SerialNumber + "</td>");
            document.write("<td>" + p.Version + "</td>");
            document.write("</tr>");
      }
      document.write("</table>");
}

function getOnBoardDeviceInfo() {
      var locator = new ActiveXObject("WbemScripting.SWbemLocator");
      var service = locator.ConnectServer(".");
      var properties = service.ExecQuery("SELECT * FROM Win32_OnBoardDevice");
      var e = new Enumerator (properties);
      document.write("<table border=\"1\">");
      for (;!e.atEnd();e.moveNext ())
      {
            var p = e.item ();
            document.write("<tr>");
            document.write("<td>" + p.Description + "</td>");
            document.write("<td>" + p.DeviceType + "</td>");
            document.write("<td>" + p.Enabled + "</td>");
            document.write("<td>" + p.Tag + "</td>");
            document.write("</tr>");
      }
      document.write("</table>");
}

function getKeyboardInfo() {
      var locator = new ActiveXObject("WbemScripting.SWbemLocator");
      var service = locator.ConnectServer(".");
      var properties = service.ExecQuery("SELECT * FROM Win32_Keyboard");
      var e = new Enumerator (properties);
      document.write("<table border=1>");
      for (;!e.atEnd();e.moveNext ())
      {
            var p = e.item ();
            document.write("<tr>");
            document.write("<td>" + p.Description + "</td>");
            document.write("<td>" + p.Name + "</td>");
            document.write("<td>" + p.Status + "</td>");
            document.write("</tr>");
      }
      document.write("</table>");
}

function getCDInfo() {
      var locator = new ActiveXObject("WbemScripting.SWbemLocator");
      var service = locator.ConnectServer(".");
      var properties = service.ExecQuery("SELECT * FROM Win32_CDROMDrive");
      var e = new Enumerator (properties);
      document.write("<table border=1>");
      for (;!e.atEnd();e.moveNext ())
      {
            var p = e.item ();
            document.write("<tr>");
            document.write("<td>" + p.Caption + "</td>");
            document.write("<td>" + p.Description + "</td>");
            document.write("<td>" + p.Drive + "</td>");
            document.write("<td>" + p.Status + "</td>");
            document.write("<td>" + p.MediaLoaded + "</td>");
            document.write("</tr>");
      }
      document.write("</table>");
}

getCpuInfo();
getMainboardInfo();
getOnBoardDeviceInfo();
getKeyboardInfo();
getCDInfo();
//-->
</script>
*/ ?>
