<?php
    include_once("lib/header.inc.php");
    include_once("lib/menu.inc.php");
    include_once("lib/content.inc.php");
    include_once("lib/footer.inc.php");
    include_once("lib/stylesheets.inc.php");
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
        "http://www.w3.org/TR/html4/strict.dtd">
<html>
  <head>
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
