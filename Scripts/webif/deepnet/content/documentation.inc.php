<?php

$content = "
    <div id=\"content_wrapper\" class=\"content\">
    
      <p>
      This document describes the process of installation,
      configuration and maintaining DeepNet on Debian- and 
      Ubuntu-based machines using lighttpd and MySQL. 
      </p>
      <p>
      It is requires some technological background knowledge, but we working on simplifing the installation
      and providing precompiled packages for Debian and Ubuntu operating systems.
      </p>
      <p>
      There is also a <a href=\"doxygen/Scripts/misc/server_setup.sh\">script</a> which 
      automatically does most of the work when setting up a server.
      Although i would not recommend using it, if you are a newbie to DeepNet.
      </p>
      
      <h4>table of contents</h4>
      <ul class=\"documentation_toc\">
	<li><a href=\"#requirements\">requirements</a></li>
	<li><a href=\"#configuration\">configuration</a>
	  <ul>
	    <li><a href=\"#configuration_common-pages-conf\">common.pages.conf</a></li>
	    <li><a href=\"#configuration_db-generator-conf\">db.generator.conf</a></li>
	    <li><a href=\"#configuration_deepnet-tool-conf\">deepnet.tool.conf</a></li>
	    <li><a href=\"#configuration_workerbot-conf\">workerbot.conf</a></li>
	    <li><a href=\"#configuration_queryserver-conf\">queryserver.conf</a></li>
	    <li><a href=\"#configuration_suggestserver-conf\">suggestserver.conf</a></li>
	    <li><a href=\"#configuration_inspectorserver-conf\">inspectorserver.conf</a></li>
	  </ul>
	</li>
	<li><a href=\"#maintenance\">maintenance</a>
	<li><a href=\"#components\">components</a>
	  <ul>
	    <li><a href=\"#components_deepnettool\">DeepNetTool</a></li>
	    <li><a href=\"#components_workerbot\">WorkerBot</a></li>
	    <li><a href=\"#components_queryserver\">QueryServer</a></li>
	    <li><a href=\"#components_suggestserver\">SuggestServer</a></li>
	    <li><a href=\"#components_inspectorserver\">InspectorServer</a></li>
	  </ul>
	</li>
	</li>
      </ul>
      
      <h4><a name=\"requirements\">requirements</a></h4>
      <p>
      DeepNet is tested on x86 CPUs (32 and 64 Bit) using Debian and Ubuntu
      operating systems. Although DeepNet is theoretically database independent,
      currently implemented and tested is MySQL and PostGRESQL.
      </p>
      
      <h4><a name=\"configuration\">configuration</a></h4>
      <p>install subversion:</p>
      <code>apt-get install subversion</code>
      <p>check out source code or <a href=\"downloads.html\">download it directly</a>:</p>
      <code>mkdir -p /opt/DeepNet</code><br>
      <code>svn co https://deepnet.mo-sys.de/DeepNet /opt/DeepNet</code><br>
      <p>execute installer script for pre-requirements:</p>
      <code>cd /opt/DeepNet/Scripts/</code><br>
      <code>chmod u+x *.sh</code><br>
      <code>./install_prerequirements.sh</code><br>
      <p>then follow the instructions on the screen.</p>
      <p>
	This section assumes that you have already installed all pre-requirements. 
	specific config files are described in their own section.
      </p>
      <p>change into the base directory:</p>
      <code>cd /opt/DeepNet/Scripts</code><br>
      <p>configure the database generator by editing <a href=\"#configuration_db-generator-conf\">db.generator.conf</a>:</p>
      <code>cp conf/db.generator.conf.example conf/db.generator.conf</code><br>
      <p>create an initial database:</p>
      <code>cd /opt/DeepNet/DatabaseTool/</code><br>
      <code>./create.sh --mysql</code><br>
      <p>configure DeepNetTool by editing <a href=\"#configuration_deepnet-tool-conf\">deepnet.tool.conf</a>:</p>
      <code>cd /opt/DeepNet/Scripts</code><br>
      <code>cp conf/deepnet.tool.conf.example conf/deepnet.tool.conf</code><br>
      <p>to enable the tests after compilation being successful, a configured DeepNetTool is required.</p>
      <p>compile DeepNet:</p>
      <code>./update_and_compile_release.sh</code><br>
      <p>
      When this has been successfully, you can choose the components you want to use
      by configuring them separately.
      </p>
      
      <h4><a name=\"maintenance\">maintenance</a></h4>
      <p>TODO: description</p>
      
      <h4><a name=\"components\">components</a></h4>
      <p>
      This section gives a brief overview of the core components of DeepNet. 
      All binaries include an extensible help when called with \"-h\" parameter.
      Additionally the documentation for the component's config file(-s) for more
      information on their usage.
      </p>
      
      <h4><a name=\"components_deepnettool\">DeepNetTool</a></h4>
      <p>
      DeepNetTool is an administrative multi-purpose tool. it implements
      tests as well as database maintenance tasks.
      </p>
      
      <h4><a name=\"components_workerbot\">WorkerBot</a></h4>
      <p>
      WorkerBot is the main application. it can be configured to
      act in different modes all fullfilling different datamining and
      indexing tasks.
      </p>
      
      <h4><a name=\"components_queryserver\">QueryServer</a></h4>
      <p>FastCGI server that answers (search) queries.</p>
      
      <h4><a name=\"components_suggestserver\">SuggestServer</a></h4>
      <p>FastCGI server that gives suggestions for queries. Acts as a helper for QueryServer.</p>
      
      <h4><a name=\"components_inspectorserver\">InspectorServer</a></h4>
      <p>FastCGI server thats plots information about websites and html.</p>
    </div>
";

?>
