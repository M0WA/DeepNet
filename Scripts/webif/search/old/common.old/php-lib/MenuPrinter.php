<?php

class MenuPrinter {

  public static function PrintMenu($variables){
    echo "
  <div id=\"page_toolbar_container\">
  <center>
  <table id=\"page_toolbar_table\">
  <tr>
    <td valign=\"middle\" style=\"height: 30px;\">
      <a class=\"toolbar_link\" href=\"/search/\" alt=\"".$variables["WEB_SEARCH_ALT"]."\">".$variables["WEB_SEARCH"]."</a>
    </td><td style=\"height: 30px;\">
      <img src=\"/img/menu/separator.gif\" class=\"menu_separator\">
    </td><td valign=\"middle\" style=\"height: 30px;\">
      <a class=\"toolbar_link\" href=\"/services/\" alt=\"".$variables["SERVICES_ALT"]."\">".$variables["SERVICES"]."</a>
    </td><td style=\"height: 30px;\">
      <img src=\"/img/menu/separator.gif\" class=\"menu_separator\">
    </td><td valign=\"middle\" style=\"height: 30px;\">
      <a class=\"toolbar_link\" href=\"/analyzer/\" alt=\"".$variables["SEO_ANALYSER_ALT"]."\">".$variables["SEO_ANALYSER"]."</a>
    </td><td style=\"height: 30px;\">
      <img src=\"/img/menu/separator.gif\" class=\"menu_separator\">
    </td><td valign=\"middle\" style=\"height: 30px;\">
      <a class=\"toolbar_link\" href=\"/tools/\" alt=\"".$variables["TOOLS_ALT"]."\">".$variables["TOOLS"]."</a>
    </td><td style=\"height: 30px;\">
      <img src=\"/img/menu/separator.gif\" class=\"menu_separator\">
    </td><td valign=\"middle\" style=\"height: 30px;\">
      <a class=\"toolbar_link\" href=\"/contact/\" alt=\"".$variables["CONTACT_ALT"]."\">".$variables["CONTACT"]."</a>
    </td><td style=\"height: 30px;\">
      <img src=\"/img/menu/separator.gif\" class=\"menu_separator\">
    </td><td valign=\"middle\" style=\"height: 30px;\">
      <a class=\"toolbar_link toolbar_link_emp\" href=\"http://blog.siridia.de\" alt=\"".$variables["BLOG_ALT"]."\" target=\"_blank\">".$variables["BLOG"]."</a>
    </td>
  </tr>
  </table>
  </center>
  </div>
";
  }
}

?>
