<?php

$title = "DeepNet - opensource search engine framework";
$contentMode = $_REQUEST['content'];

switch($contentMode) {
  case 'contact':
    include_once('content/home.inc.php');
    break;
  default:
    include_once('content/home.inc.php');
    break;
}

?>
