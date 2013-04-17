<div class="wrapper_centered">
  <div class="outer_centered">
    <div class="inner_centered">


<h4>Ihre aktuelle IP-Adresse:</h4>
<p style="width: 50%; text-align: center; padding-left: 25%;">
<b><?php echo $_SERVER['REMOTE_ADDR']; ?></b>
</p>

<table>
<tr><td>
<h4>Forward-DNS Lookup</h4>
<form name="forward_dns_form" method="POST">
  <input type="hidden" name="forward_dns" value="1" />
  <input type="text"   name="domain"      value="siridia.de" />&nbsp;
  <input type="submit" name="forward"     value="aufl&ouml;sen" />
</form>
</td><td>
&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;
</td><td>
<h4>Reverse-DNS Lookup</h4>
<form name="reverse_dns_form" method="POST">
  <input type="hidden" name="reverse_dns" value="1" />
  <input type="text"   name="ip"          value="<?php echo $_SERVER['REMOTE_ADDR']; ?>" />&nbsp;
  <input type="submit" name="reverse"     value="aufl&ouml;sen" />
</form>
</td></tr>
</table>


    </div>
  </div>
</div>
 <div style="clear: both; height: 0px;"></div>
