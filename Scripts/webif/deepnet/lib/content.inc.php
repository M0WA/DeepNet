<?php

$title = "DeepNet - opensource search engine framework";

if(isset($_REQUEST["contentMode"])) {
	$contentMode = $_REQUEST["contentMode"];
}
else {
	$contentMode = "home";
}

switch($contentMode) {

  case 'features':
    include_once('content/features.inc.php');
	break;
	
  case 'documentation':
    include_once('content/documentation.inc.php');
	break;
	
  case 'downloads':
    include_once('content/downloads.inc.php');
	break;
	
  case 'get_involved':
    include_once('content/get_involved.inc.php');
	break;
	
  case 'developer':
    include_once('content/developer.inc.php');
	break;
	
  case 'contact':
    include_once('content/contact.inc.php');
    break;
	
  case 'support':
    include_once('content/support.inc.php');
    break;
	
  case 'home':
  default:
    include_once('content/home.inc.php');
    break;
}

?>
