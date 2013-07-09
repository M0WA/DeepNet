<!DOCTYPE html>   
<?php
    include_once("lib/header.inc.php");
    include_once("lib/menu.inc.php");
    include_once("lib/content.inc.php");
    include_once("lib/footer.inc.php");
    include_once("lib/stylesheets.inc.php");
?>
<html lang="en">
  <head>
	<meta charset='utf-8'>
    <title><?php echo $title; ?></title>
    <?php echo $stylesheets; ?>
  </head>
  <body>
    
  <!--
  header_begin
  -->
  <?php echo $header; ?>
  <!--
  header_end
  -->

  <!--
  menu_begin
  -->
  <?php echo $menu; ?>
  <!--
  menu_end
  -->
  
  <!--
  content_begin
  -->
  <?php echo $content; ?>
  <!--
  content_end
  -->
  äöüäöüäöü
  <!--
  footer_begin
  -->
  <?php echo $footer; ?>
  <!--
  footer_end
  -->

  </body>
</html>
