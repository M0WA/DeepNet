<?php

#########################################################
#
# this is part of the SIRIDIA search engine software
# Copyright 2012, SIRIDIA GmbH
# Author: Moritz Wagner (moritz.wagner@siridia.de)
#
#########################################################

class ContentProcessor
{
    public static $contentFile = '';
    public static $footerFile  = 'footer.php';

    public static $pageTitle       = '';
    public static $metaDescription = '';
    public static $metaKeywords    = '';

    public static $includeQueryScripts = false;

    public static function PrintPage($headerEntries,$headerActiveEntry,$headerLoginPart)
    {
        if(ContentProcessor::$contentFile == "" ){
            ContentProcessor::PrintError();
            return; }
?>

<!DOCTYPE html>
<html lang="de">
<head>
<title><?php echo ContentProcessor::$pageTitle; ?></title>
<meta charset="utf-8">
<meta name="Description" content="<?php echo ContentProcessor::$metaDescription; ?>">
<meta name="Description" content="<?php echo ContentProcessor::$metaDescription; ?>">
<meta content="<?php echo ContentProcessor::$metaDescription; ?>" property="og:description" />
<meta content="<?php echo ContentProcessor::$pageTitle; ?>" property="og:title" />
<meta content="SIRIDIA" property="og:site_name" />
<meta name="keywords" content="<?php echo ContentProcessor::$metaKeywords; ?>">
<link rel="stylesheet" href="/css/reset.css" type="text/css" media="screen">
<link rel="stylesheet" href="/css/style.css" type="text/css" media="screen">
<link rel="stylesheet" href="/css/grid.css" type="text/css" media="screen">
<!--
<link type="text/css" rel="stylesheet" href="http://fonts.googleapis.com/css?family=Lato:400,700,900">
-->
<link href='http://fonts.googleapis.com/css?family=Overlock:400,700,900&subset=latin,latin-ext' rel='stylesheet' type='text/css'>
<script type="text/javascript" src="/js/html5.js"></script>
<script type="text/javascript" src="/js/jquery-1.6.2.min.js" ></script>
<script type="text/javascript" src="/js/jquery.easing.1.3.js"></script>
<script type="text/javascript" src="/js/cufon-yui.js" ></script>
<script type="text/javascript" src="/js/cufon-replace.js"></script>
<script type="text/javascript" src="/js/M_1p_500.font.js"></script>
<script type="text/javascript" src="/js/Overlock_400-Overlock_700-Overlock_900.font.js"></script>
<script type="text/javascript" src="/js/Lato_400-Lato_900.font.js"></script>
<script type="text/javascript" src="/js/superfish.js"></script>
<script type="text/javascript" src="/js/jquery.roundabout.js"></script>
<script type="text/javascript" src="/js/roundabout_shapes.js"></script>
<?php if(ContentProcessor::$includeQueryScripts) { ?>
<script type="text/javascript" src="/common/common.js"></script>
<script type="text/javascript" src="/common/suggest.js"></script> 
<script type="text/javascript" src="/common/query.js"></script>
<script type="text/javascript" src="/common/inspect.js"></script>
<!-- <link rel="stylesheet" type="text/css" href="/common/common.css"> -->
<link rel="stylesheet" type="text/css" href="/common/suggest.css">
<link rel="stylesheet" type="text/css" href="/common/query.css">
<link rel="stylesheet" type="text/css" href="/common/inspect.css">
<?php }?>
<script type="text/javascript">

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-33242189-1']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>
<script>
    $(document).ready(function() {
        $('#myRoundabout').roundabout({
            shape: 'figure8',
            minOpacity: 1,
            minScale: 0.67,
            maxScale:1.037,
            tilt: -2.8,
            easing:'easeOut',
            duration:600,
            autoplay:6000,
            btnNext: '#next',
            btnPrev: '#previous'
        });
    $("#banner_link").hover(function(){
        $("#banner").toggleClass("hover");
         return false;
    });
}); </script>
<!--[if lt IE 7]>
   <div style=' clear: both; text-align:center; position: relative;'>
     <a href="http://windows.microsoft.com/en-US/internet-explorer/products/ie/home?ocid=ie6_countdown_bannercode">
       <img src="http://storage.ie6countdown.com/assets/100/images/banners/warning_bar_0000_us.jpg" border="0" height="42" width="820" alt="You are using an outdated browser. For a faster, safer browsing experience, upgrade for free today." />
    </a>
  </div>
<![endif]-->
<!--[if lt IE 9]>
        <script src="/js/html5.js"></script>
        <link rel="stylesheet" href="/css/ie.css"> 
<![endif]-->
</head>
<body id="page1">
<div id="main_outer">
  <div id="main">

    <!-- header -->
    <?php HeaderProcessor::PrintHeader($headerEntries,$headerActiveEntry,$headerLoginPart); ?>

    <!-- content -->
    <section id="content">
    <?php include_once("content/".ContentProcessor::$contentFile); ?>
    </section>

  </div>
</div>

<!-- footer -->
<?php include_once(ContentProcessor::$footerFile) ?>

<script type="text/javascript"> Cufon.now(); </script>
</body>
</html>

<?php
    }

    public static function PrintError() {
?>
    <html>
    <head>
<script type="text/javascript">

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-33242189-1']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>
    </head>
    <body>
    </body>
    </html>
<?php
        $contentFile = '';
        $footerFile  = 'footer.php';
        $pageTitle       = '';
        $metaDescription = '';
        $metaKeywords    = '';
        $includeQueryScripts = false;        
    }
}

?>