<?php

#########################################################
#
# this is part of the DeepNet search engine software
# Copyright 2012-2014, Moritz Wagner
# Author: Moritz Wagner (support@mo-sys.de)
#
#########################################################

function get_ip_location($ip) 
{
	$query_url = 'http://www.geoplugin.net/php.gp?ip='.$ip;
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $query_url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_TIMEOUT, 15);
    return unserialize(curl_exec($ch));
}

?>
