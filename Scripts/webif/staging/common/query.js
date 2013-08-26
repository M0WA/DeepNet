/* ******************************************************

  this is part of the SIRIDIA search engine software
  Copyright 2012, SIRIDIA GmbH
  Author: Moritz Wagner (moritz.wagner@siridia.de)

********************************************************* */

var queryHelper = new QueryHelper();

function QueryHelper()
{
  this.serverNameQuery = "/queryserver";
  this.ajaxQuery = null;

  this.onQueryResponse = function()
  {
    if(this.ajaxQuery === 'undefined')
      return;

    if (this.ajaxQuery.readyState==4 && this.ajaxQuery.status==200)
    {
      //a valid response has been received

	    var xmlDoc=this.ajaxQuery.responseXML.documentElement;
      var resultTable = this.InitQueryResponse(xmlDoc);

	    var allResultElements = xmlDoc.getElementsByTagName("result");
	    if ( allResultElements == null || allResultElements.length <= 0) 
	    {
        // response has no results
        document.getElementById('results_space').appendChild(document.createTextNode('no results'));
        delete this.ajaxQuery;
        return;
	    }

      //process each single result for query
	    for (var i=0;i<allResultElements.length;i++)
	    {
        var resultElement = allResultElements[i];
        var resultRow = this.processSingleResult(resultElement);
        resultTable.appendChild(resultRow);
	    }

      //print paging for result navigation
      this.printPaging(xmlDoc,allResultElements.length,document.getElementById('results_space'));

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

  this.queryServer = function(xmlRequest)
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
      this.ajaxQuery.onreadystatechange=function() { _this.onQueryResponse(); };
      this.ajaxQuery.open('POST',this.serverNameQuery,true);
      this.ajaxQuery.setRequestHeader("Content-type","application/xml");
      this.ajaxQuery.send(xmlRequest);
    }
  };

  this.onQuery = function(pageNo,queryID)
  {
    // preparing criteria
    var metaRelevance     = document.getElementById("criteria_meta_relevance_id").value;
    var titleRelevance    = document.getElementById("criteria_title_relevance_id").value;
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
              "<relevanceTitle>"+ titleRelevance +"</relevanceTitle>" +
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

  this.InitQueryResponse = function(xmlDoc)
  {
      RemoveAllChildren(document.getElementById('results_space'));
      RemoveAllChildren(document.getElementById('result_header'));

      var queryString = document.getElementById("search_query_id").value;
      var totalResults = GetTextElementContentRaw(xmlDoc.getElementsByTagName("totalResults")[0]);
      document.getElementById('result_header').appendChild(document.createTextNode(totalResults + ' results for: "' + queryString + '"'));
      document.getElementById('results_container').style.visibility = 'visible';

      document.getElementById('results_container_pending').style.height = '0';
      document.getElementById('results_container_pending').style.visibility = 'hidden';

      var resultTable = document.createElement("table");
      resultTable.setAttribute('class', 'result_table');
      document.getElementById('results_space').appendChild(resultTable);
      return resultTable;
  };

  this.processSingleResult = function(resultElement,resultTable)
  {
    //assembling result from XML response
    var lastChangedElement = (resultElement.getElementsByTagName("lastChanged")[0]);
    var lastChanged = GetTextElementContent(lastChangedElement);

    var lastVisitedElement = (resultElement.getElementsByTagName("lastVisited")[0]);
    var lastVisited = GetTextElementContent(lastVisitedElement);

    var urlElement = (resultElement.getElementsByTagName("url")[0]);
    var urlText = GetTextElementContent(urlElement);
    var urlTextDecoded = urlText;
    var urlTextHtmlEnc = urlText;
    try {
      urlTextHtmlEnc = encodeUrlHtml(urlTextDecoded);
    }
    catch(e2) {
      urlTextHtmlEnc = urlText;
      //alert("invalid url: " + urlText);
    }

    //create 'single_result_table' containing per-result information
    var singleResultTable = document.createElement("table");
    singleResultTable.setAttribute('class', 'single_result_table');

    //creating table rows for description and title
    var singleResultTableRowTitle        = document.createElement("tr");
    var singleResultTableRowDescription  = document.createElement("tr");
    singleResultTable.appendChild(singleResultTableRowTitle);
    singleResultTable.appendChild(singleResultTableRowDescription);

    var singleResultTableCellTitle       = document.createElement("td");
    var singleResultTableCellDescription = document.createElement("td");
    singleResultTableRowTitle.appendChild(singleResultTableCellTitle);
    singleResultTableRowDescription.appendChild(singleResultTableCellDescription);

    //assembling title and description for a single result
    try
    {
      var titleElement       = (resultElement.getElementsByTagName("title")[0]);
	    var title              = GetTextElementContent(titleElement);
      var descriptionElement = (resultElement.getElementsByTagName("description")[0]);
	    var description        = GetTextElementContent(descriptionElement);

      var singleUrlLink              = document.createElement("a");
      singleUrlLink.className        = 'undecorated_link';
      singleUrlLink.href             = urlTextDecoded;
      singleUrlLink.target           = '_blank';
      singleUrlLink.style.cssFloat   = 'left';
      singleUrlLink.style.styleFloat = 'left';

      if( title === "") {
        singleUrlLink.appendChild(document.createTextNode(htmlDecode(urlTextHtmlEnc))); }
      else {
         singleUrlLink.appendChild(document.createTextNode(htmlDecode(title))); }

      singleResultTableCellTitle.appendChild(singleUrlLink);
      singleResultTableCellDescription.appendChild(document.createTextNode(htmlDecode(description)));

    }
    catch(e1) 
    {
       singleResultTableCellTitle.appendChild(document.createTextNode('N/A'));
       singleResultTableCellDescription.appendChild(document.createTextNode('N/A'));
    } 

    var singleResultAgeRow = document.createElement("tr");
    var singleResultAgeCell = document.createElement("td");
    singleResultAgeRow.appendChild(singleResultAgeCell);

    //add last-changed information if available
    if(lastChanged)
    {
      singleResultAgeCell.appendChild(document.createTextNode(lastChanged));
      singleResultAgeRow.appendChild(singleResultAgeCell);
      singleResultTable.appendChild(singleResultAgeRow);
    }
    else if(lastVisited)
    {
      //add last-visited information if available and no last-changed info is available
      singleResultAgeCell.appendChild(document.createTextNode(lastVisited));
      singleResultAgeRow.appendChild(singleResultAgeCell);
      singleResultTable.appendChild(singleResultAgeRow);
    }

    //add url as text
    var singleResultTableRowURL  = document.createElement("tr");
    var singleResultTableCellURL = document.createElement("td");
    var singleResultFontURL      = document.createElement("font");
    singleResultFontURL.setAttribute('class','url_font');
    singleResultFontURL.appendChild(document.createTextNode(urlTextHtmlEnc));
    singleResultTableCellURL.appendChild(singleResultFontURL);
    singleResultTableRowURL.appendChild(singleResultTableCellURL);
    singleResultTable.appendChild(singleResultTableRowURL);

    //create advanced info box for this results
    var keywordElements = (resultElement.getElementsByTagName("keywords")[0]).getElementsByTagName("keyword");
    var advancedInfoRow = this.createInfoBox(keywordElements);
    singleResultTable.appendChild(advancedInfoRow);

    //prepare result row for 'result_table' holding all results
    var resultTableCell = document.createElement("td");
    resultTableCell.appendChild(singleResultTable);
    var resultTableRow  = document.createElement("tr");
    resultTableRow.appendChild(resultTableCell);
    return resultTableRow;
  }

  this.createInfoBox = function(keywordElements)
  {
    if(keywordElements.length <= 0) {
      return; }

    var advancedInfoRow = document.createElement('tr');
    var tableCell = document.createElement('td');
    advancedInfoRow.appendChild(tableCell);

    var infoBoxForm        = document.createElement("form");
    var buttonToggle       = document.createElement("input");
    buttonToggle.type      = "submit";
    buttonToggle.value     = "advanced";
    buttonToggle.className = "infoBoxButton";

    var contentElement = document.createElement("div");
    contentElement.style.visibility = "hidden";
    contentElement.className = "infoBoxContent";

    var tmpThis = this;
    buttonToggle.onclick=function() { tmpThis.toggleInfoBox(contentElement); return false; };

    var tableKeywordInfo = document.createElement("table");
    for(var i=0; i < keywordElements.length; i++){
      var typeKeyword = keywordElements[i].getAttribute('type');
      var relevancyKeyword = keywordElements[i].getAttribute('relevancy');
      var wordKeyword = GetTextElementContent(keywordElements[i]);

      var cellKeyword = document.createElement("td");
      cellKeyword.appendChild(document.createTextNode(wordKeyword));
      var cellType = document.createElement("td");
      cellType.appendChild(document.createTextNode(typeKeyword));
      var cellRelevancy = document.createElement("td");
      cellRelevancy.appendChild(document.createTextNode(relevancyKeyword));

      var rowKeywordInfo = document.createElement("tr");
      rowKeywordInfo.appendChild(cellKeyword);
      rowKeywordInfo.appendChild(cellType);
      rowKeywordInfo.appendChild(cellRelevancy);
      tableKeywordInfo.appendChild(rowKeywordInfo);
    }
    contentElement.appendChild(tableKeywordInfo);

    infoBoxForm.appendChild(buttonToggle);
    infoBoxForm.appendChild(contentElement);
    tableCell.appendChild(infoBoxForm);
    return advancedInfoRow;
  };

  this.toggleInfoBox = function(contentElement)
  {
    toggleVisibility(contentElement);

    if(contentElement.style.visibility != "hidden"){
      contentElement.style.height = "auto";
    } else {
      contentElement.style.height = 0;
    }
  };

  this.printPaging = function(xmlDoc,resultsOnPage,contentElement)
  {
    var pageNo = GetTextElementContentRaw(xmlDoc.getElementsByTagName("pageNo")[0]);
    var totalResults = GetTextElementContentRaw(xmlDoc.getElementsByTagName("totalResults")[0]);
    var queryId = GetTextElementContentRaw(xmlDoc.getElementsByTagName("queryId")[0]);

    var maxResults = document.getElementById("limit_result_count_id").value;
    var maxPages = Math.ceil(totalResults / maxResults);
    if(maxPages > 1) {
      var thatThis = this;
      var i = 0;

      for (i = 0; i < maxPages; i++) {
        var divElement = document.createElement("div");
        divElement.appendChild(document.createTextNode(i));
        divElement.style.cssFloat = 'left';
        divElement.style.padding = "3px";
        divElement.style.margin = "3px";
        contentElement.appendChild(divElement);
        if(pageNo != i) {
          var curPage = i;
          divElement.style.border = "1px solid gray";
          divElement.onmousedown = function() { thatThis.onQuery(GetTextElementContentRaw(this),queryId); }
        }
      }
    }
  };
}
