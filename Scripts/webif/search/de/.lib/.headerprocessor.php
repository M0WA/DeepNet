<?php

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

class HeaderProcessor
{
    public static function PrintSubEntries($subEntries)
    {
        if(count($subEntries) == 0)
            return "";
        $entryHtml = "<ul>";
        foreach( $subEntries as $k => $v ) {
            $entryHtml .= "<li><a href=\"".$v."\">".$k."</a></li>\n"; }
        $entryHtml .= "</ul>\n";
        return $entryHtml;
    }

    public static function PrintEntries($headerEntries,$headerActiveEntry)
    {
        $i = 0;
        $max = count($headerEntries) - 1;
        foreach( $headerEntries as $k => $v ) {
            $cssClass = "";
            if($i == 0) {
                $cssClass = "first"; }
            if($i == $max) {
                $cssClass = "last"; }
            if($i == $headerActiveEntry) {
                $cssClass .= " active"; }
            if($cssClass != "") {
                $cssClass = " class=\"".$cssClass."\""; }

            echo "<li".$cssClass."><a href=\"".$v[0]."\">".$k."</a>".HeaderProcessor::PrintSubEntries($v[1])."</li>\n";
            $i++;
        }
    }

    public static function PrintHeader($headerEntries,$headerActiveEntry,$headerLoginPart) 
    {
?>
<header>
  <div class="inside">
    <div class="extra-wrap">
      <h1><a href="/">SIRIDIA</a></h1>
      <div class="fright">
        <form id="form-top" enctype="multipart/form-data" method="post">
          <fieldset>
            <div class="form-top"> <span>
              <input name="name" type="text" value="Searching ..." onFocus="if(this.value=='Searching ...'){this.value=''}" onBlur="if(this.value==''){this.value='Searching ...'}">
              </span> <a onClick="document.getElementById('form-top').submit()" href="#"></a> </div>
          </fieldset>
        </form>
        <div id="header-links"><a href="/contact/faq.html">FAQ</a>|<a href="#">Sitemap</a>|<a href="<?php echo $headerLoginPart[1]; ?>"><?php echo $headerLoginPart[0]; ?></a></div>
      </div>
      <nav>
        <ul class="sf-menu">
            <?php HeaderProcessor::PrintEntries($headerEntries,$headerActiveEntry); ?>
        </ul>
      </nav>
    </div>
  </div>
</header>
<?php
    }
}

?>