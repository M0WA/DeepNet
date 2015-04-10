/* ******************************************************

  this is part of the DeepNet search engine software
  Copyright 2015, Moritz Wagner
  Author: Moritz Wagner (moritz.wagner@mo-sys.de)

********************************************************* */

var queryHelper = new QueryHelper();

function QueryHelper()
{
  this.serverNameQuery = "/queryserver";
  this.ajaxQuery = null;

  this.onQueryResponse = function(pageNo)
  {
    if(this.ajaxQuery === 'undefined')
      return;

    if (this.ajaxQuery.readyState==4 && this.ajaxQuery.status==200)
    {
      //a valid response has been received

	    var xmlDoc=this.ajaxQuery.responseXML.documentElement;
      this.processQueryResponse(xmlDoc,pageNo);

      delete this.ajaxQuery;     
    }
    else if(this.ajaxQuery.readyState==4 && this.ajaxQuery.status!=200)
    {
      //an valid response has been received, show the error...

      document.getElementById('results_container_pending').style.visibility = 'hidden';
      document.getElementById('results_container').style.visibility = 'visible';

      RemoveAllChildren(document.getElementById('result_header'));
      RemoveAllChildren(document.getElementById('results_space'));

      document.getElementById('result_header').appendChild(document.createTextNode('an error occurred'));
      delete this.ajaxQuery;
    }
  };

  this.queryServer = function(xmlRequest,pageNo)
  {
    if(window.XMLHttpRequest)
    {
     this.ajaxQuery = new XMLHttpRequest();
    }
    else if(window.ActiveXObject)
    {
     try
     {
      this.ajaxQuery = new ActiveXObject('Msxml2.XMLHTTP');
     }
     catch(e1)
     {
      try
      {
       this.ajaxQuery = new ActiveXObject('Microsoft.XMLHTTP');
      }
      catch(e2)
      {
        alert(e2);
      }
     }
    }

    if(this.ajaxQuery != null)
    {
      var _this = this;
      this.ajaxQuery.onreadystatechange=function() { _this.onQueryResponse(pageNo); };
      this.ajaxQuery.open('POST',this.serverNameQuery,true);
      this.ajaxQuery.setRequestHeader("Content-type","application/xml");
      this.ajaxQuery.send(xmlRequest);
    }
  };

  this.onQuery = function(pageNo,queryID)
  {
    // preparing criteria
    var metaRelevance     = document.getElementById("criteria_meta_relevance_id").value;
    var domainRelevance   = document.getElementById("criteria_domain_relevance_id").value;
    var contentRelevance  = document.getElementById("criteria_content_relevance_id").value;
    var backlinkRelevance = document.getElementById("criteria_backlinks_relevance_id").value;
    var urlPathRelevance  = document.getElementById("criteria_url_path_relevance_id").value;

    // preparing grouping

    // preparing limitations
    var limitationsFlag = 0;
    var maxResults      = document.getElementById("limit_result_count_id").value;
    var domainLimit     = document.getElementById("limit_domain_id").value;
    var ageLimit        = document.getElementById("limit_age_id").value;
    var langLimit       = document.getElementById("limit_lang_id").value;

    // create xml request
    var searchQueryIdElement = document.getElementById("search_query_id");
    if( !(typeof searchQueryIdElement.value === 'undefined') && searchQueryIdElement.value != '' )
    {
      var queryString = searchQueryIdElement.value;
      var words = queryString.split(/\W+/);

      var xml = "<request id=\"1\"><query id=\"1\">";

      if(pageNo != -1) {
         xml += "<pageNo>"+pageNo+"</pageNo>"; }

      if(queryID != -1) {
         xml += "<queryId>"+queryID+"</queryId>"; }

      for(var i = 0; i < words.length; i++) {
        xml += "<querypart id=\""+i+"\">" + words[i] + "</querypart>"; }
      xml += "<criteria>";

      var criteriaElements = document.getElementsByName("criteria[]");
      for (var i = 0; i < criteriaElements.length; i++) {
        if (criteriaElements[i].checked) {
          xml +=  "<flag>"+criteriaElements[i].value+"</flag>";
        }
      }
      xml +=
              "<relevanceMeta>"+ metaRelevance +"</relevanceMeta>" +
              "<relevanceDomain>"+ domainRelevance +"</relevanceDomain>" +
              "<relevanceFullText>"+ contentRelevance +"</relevanceFullText>" +
              "<relevanceBackLinks>"+ backlinkRelevance +"</relevanceBackLinks>" +
              "<relevanceUrlPath>"+ urlPathRelevance +"</relevanceUrlPath>" +
            "</criteria>" +
            "<grouping>";

      var groupingElements = document.getElementsByName("grouping[]");
      for (var i = 0; i < groupingElements.length; i++) {
        if (groupingElements[i].checked) {
          xml +=  "<flag>"+groupingElements[i].value+"</flag>";
        }
      }
      xml +=
            "</grouping>" +
            "<limitations>";

      var limitElements = document.getElementsByName("limit[]");
      for (var i = 0; i < limitElements.length; i++) {
        if (limitElements[i].checked) {
          xml +=  "<flag>"+limitElements[i].value+"</flag>";
        }
      }
      xml +=
              "<maxResults>"+maxResults+"</maxResults>" +
              "<domainLimit>"+domainLimit+"</domainLimit>" +
              "<ageLimit>"+ageLimit+"</ageLimit>" +
              "<langLimit>"+langLimit+"</langLimit>" +
            "</limitations>";
      xml += "</query></request>";
      this.queryServer(xml);

      document.getElementById('results_container').style.visibility = 'hidden';
      document.getElementById('results_container_pending').style.visibility = 'visible';

      RemoveAllChildren(document.getElementById('result_header_pending'));
      document.getElementById('result_header_pending').appendChild(document.createTextNode('searching for: "' + queryString + '"'));
    }
    else
    {
      //dont send empty or invalid querys
      document.getElementById('results_container_pending').style.visibility = 'hidden';
      document.getElementById('results_container').style.visibility = 'hidden';
    }
  };

  this.processQueryResponse = function(xmlDoc,pageNo)
  {
      RemoveAllChildren(document.getElementById('results_space'));
      RemoveAllChildren(document.getElementById('result_header'));

      var queryString = document.getElementById("search_query_id").value;
      var queryId = GetTextElementContentRaw(xmlDoc.getElementsByTagName("queryId")[0]);

      if(queryId > 0) {
        resultHelper.onQueryResult(queryId,pageNo);
      }
      else {
        alert('invalid query id');
      }
/*
      document.getElementById('result_header').appendChild(document.createTextNode(totalResults + ' results for: "' + queryString + '"'));
      document.getElementById('results_container').style.visibility = 'visible';

      document.getElementById('results_container_pending').style.height = '0';
      document.getElementById('results_container_pending').style.visibility = 'hidden';

      var resultTable = document.createElement("table");
      resultTable.setAttribute('class', 'result_table');
      document.getElementById('results_space').appendChild(resultTable);
      return resultTable;
*/
  };
}
