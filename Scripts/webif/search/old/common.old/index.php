<?php
  include_once("php-lib/Variables.php");
  include_once("php-lib/MenuPrinter.php");
  include_once("php-lib/PagePrinter.php");

  $content = "";
  if(isset($_REQUEST['content'])) {
    $content = $_REQUEST['content'];
  }
  PagePrinter::PrintPage($variables,$domain,$content);
?>
