<?php
  $title = "mo-sys.de - online ip converter";
  $meta_description = "convert ip addresses into different formats(CIDR,IP/NETMASK,...)";
  $meta_keywords = "convert,ip,online,cidr,subnet,netmask,calculate,integer,numeric,broadcast";
?>
<?php
function cidr($ip_addr_cidr) 
{
  $ip_arr = explode('/', $ip_addr_cidr);

  $dotcount = substr_count($ip_arr[0], ".");
  $padding = str_repeat(".0", 3 - $dotcount);
  $ip_arr[0].=$padding;

  $bin = '';
  for($i=1;$i<=32;$i++) {
     $bin .= $ip_arr[1] >= $i ? '1' : '0';
  }
  $ip_arr[1] = bindec($bin);

  $ip = ip2long($ip_arr[0]);
  $nm = ip2long($ip_arr[1]);
  $nw = ($ip & $nm);
  $bc = $nw | (~$nm);

  $startIP  = long2ip($nw + 1);
  $stopIP   = long2ip($bc - 1);
?>
<br />
<table>
<tr>
  <td>range</td><td><b><?php print $startIP." -> ".$stopIP; ?></b></td>
</tr>
<tr>
  <td>broadcast</td><td><b><?php print long2ip($bc); ?></b></td>
</tr>
<tr>
  <td>network</td><td><b><?php print long2ip($nw); ?></b></td>
</tr>
<tr>
  <td>netmask</td><td><b><?php print long2ip($nm); ?></b></td>
</tr>
</table>
<?php
}
?>
<h2>IP Address Converter</h2>
<h4>numeric conversions</h4>
<p>Converts IP addresses and its numeric hex and integer representations. This may be useful when searching i.e. binaries for certain IP addresses or to convert your findings
back into a human readable form.</p>
<form action="/tools/IpTools/" method="POST">
  <input type="text" name="ip" value="<?php if ( $_REQUEST["ip"] != ""){ print $_REQUEST["ip"]; } else { print $_SERVER['REMOTE_ADDR'];}?>">&nbsp;&nbsp;
  <input type="submit" name="ip2n" value="ip to numeric value">&nbsp;
  <input type="submit" name="n2ip" value="numeric value to ip">
</form>
<?php
  if ( $_REQUEST["ip"] != "" && $_REQUEST["ip2n"] )
  {
    $intIP = ip2long ( $_REQUEST["ip"] );
    if($intIP === false)
    {
?>
<p>
An error occured. Maybe the IP you entered was not valid.
</p>
<?php
    }
    else
    {
?>
<br />
<table>
<tr>
  <td>integer</td><td><b><?php print $intIP; ?></b></td>
</tr>
<tr>
  <td>hexdecimal</td><td><b><?php print "0x".dechex($intIP); ?></b></td>
</tr>
</table>
<?php
    }
  }
  else if ( $_REQUEST["ip"] != "" && $_REQUEST["n2ip"] )
  {
    $strIP = long2ip( $_REQUEST["ip"] );
    if($intIP === false)
    {
?>
<p>
An error occured. Maybe the IP you entered was not valid.
</p>
<?php
    }
    else
    {
?>
<p>
IP address is <b><?php print $strIP;?></b>.
</p>
<?php
    } 
  } 
?>
<h4>cidr conversions</h4>
<p>Extracts ip range, broadcast and network address and netmask from CIDR notation.</p>
<form action="/tools/IpTools/" method="POST">
  <input type="text" name="ipCidr" value="<?php if ( $_REQUEST["ipCidr"] != ""){ print $_REQUEST["ipCidr"]; } else { print "192.168.0.1/24";}?>">&nbsp;&nbsp;
  <input type="submit" name="cidr" value="cidr to range">
</form>
<?php
  if ( $_REQUEST["ipCidr"] != "" && $_REQUEST["cidr"] )
  {
    cidr($_REQUEST["ipCidr"]);
  }
?>
