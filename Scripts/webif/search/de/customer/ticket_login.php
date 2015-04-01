<?php
$homeActive      = " class=\"first\" ";
$productsActive  = "";
$websearchActive = "";
$toolsActive     = "";
$contactActive   = " class=\"last\" ";
$metaDescription = "SIRIDIA ist Ihr Dienstleister für Informationsaggregation & Data-Mining im Internet. Wir bieten Commerce Search, SEO QA, Custom Web Search, Web Indexing uvm.";
$metaKeywords    = "seo,monitoring,search engine,websearch,commerce search,quality assurance";
$metaTitle       = "SIRIDIA - Ihr Dienstleister für Informationsaggregation";
?>

<!DOCTYPE html>
<html lang="de">
<head>
<title><?php echo $metaTitle; ?></title>
<meta charset="utf-8">
<meta name="Description" content="<?php echo $metaDescription; ?>">
<meta name="Description" content="<?php echo $metaDescription; ?>">
<meta content="<?php echo $metaDescription; ?>" property="og:description" />
<meta content="<?php echo $metaTitle; ?>" property="og:title" />
<meta content="SIRIDIA" property="og:site_name" />
<meta name="keywords" content="<?php echo $metaKeywords; ?>">
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
});	</script>
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
    <?php include_once('../header.php') ?>

    <!-- content -->
    <section id="content">
      <br>
      <br>
      <h3>Unser Ticket-System befindet sich derzeit im Aufbau.</h3>
      <h4>Bei Fragen / Feature Requests etc: <a class="link-2 color-1" style="text-decoration: none;" href="/contact/message.html">&nbsp;&nbsp;Kundendienst</a></h4>
      <br>
      <br>
    </section>

  </div>
</div>

<!-- footer -->
<?php include_once('../footer.php') ?>

<script type="text/javascript"> Cufon.now(); </script>
</body>
</html>
