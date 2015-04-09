/* ******************************************************

  this is part of the DeepNet search engine software
  Copyright 2015, Moritz Wagner
  Author: Moritz Wagner (moritz.wagner@mo-sys.de)

********************************************************* */

var resultHelper = new QueryResultHelper();

function QueryResultHelper
{
  this.serverNameQueryResult = "/queryresultserver";
  this.ajaxQuery = null;

  this.queryResult = function(xmlRequest)
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
      this.ajaxQuery.onreadystatechange=function() { _this.onQueryResultResponse(xmlRequest); };
      this.ajaxQuery.open('POST',this.serverNameQueryResult,true);
      this.ajaxQuery.setRequestHeader("Content-type","application/xml");
      this.ajaxQuery.send(xmlRequest);
    }
  };

  this.onQueryResult = function(queryId,pageNo)
  {
    var xml = "<request id=\"1\"><queryresult id=\"1\">";
    xml += "<queryId>"+queryId+"</queryId>";
    xml += "<pageNo>"+pageNo+"</pageNo>";
    xml += "<maxResults>"+document.getElementById("limit_result_count_id").value+"</maxResults>";
    xml += "</queryresult></request>";
    this.queryResult(xml);
  };

  this.onQueryResultResponse = function(xmlRequest)
  {
    if(this.ajaxQuery === 'undefined')
      return;

    if (this.ajaxQuery.readyState==4 && this.ajaxQuery.status==200)
    {
      //a valid response has been received

	    var xmlDoc=this.ajaxQuery.responseXML.documentElement;
      var queryId = GetTextElementContentRaw(xmlDoc.getElementsByTagName("queryId")[0]);
      var pageNo = GetTextElementContentRaw(xmlDoc.getElementsByTagName("pageNo")[0]);
      var isFinished = GetTextElementContentRaw(xmlDoc.getElementsByTagName("finished")[0]);

      if(!isFinished) {
        setTimeout(resultHelper.queryResult, 2000, xmlRequest);
        delete this.ajaxQuery;
        return; 
      }

      var resultTable = this.initQueryResultResponse(xmlDoc);

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

  this.initQueryResultResponse = function(xmlDoc)
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
    var advancedInfoRow = this.createInfoBox(resultElement);
    singleResultTable.appendChild(advancedInfoRow);

    //prepare result row for 'result_table' holding all results
    var resultTableCell = document.createElement("td");
    resultTableCell.appendChild(singleResultTable);
    var resultTableRow  = document.createElement("tr");
    resultTableRow.appendChild(resultTableCell);
    return resultTableRow;
  }

  this.createRelevancyInfo = function(resultElement)
  {
    var weightedRelevance = resultElement.getElementsByTagName('relevancyWeighted')[0];
    var relevancy = resultElement.getElementsByTagName('relevancy')[0];
    var weight = resultElement.getElementsByTagName('weight')[0];

    var relevancyCell = document.createElement('td');
    var weightCell = document.createElement('td');
    var weightedRelevanceCell = document.createElement('td');

    var relevanceHeaderWeighted = document.createElement('th');
    var relevanceHeaderRelevance = document.createElement('th');
    var relevanceHeaderWeight = document.createElement('th');
    relevanceHeaderWeighted.appendChild(document.createTextNode('Quality'));
    relevanceHeaderRelevance.appendChild(document.createTextNode('Relevance'));
    relevanceHeaderWeight.appendChild(document.createTextNode('Weight'));

    var relevanceHeaderRow = document.createElement('tr');
    relevanceHeaderRow.appendChild(relevanceHeaderWeighted);
    relevanceHeaderRow.appendChild(relevanceHeaderRelevance);
    relevanceHeaderRow.appendChild(relevanceHeaderWeight);

    var relevanceWeightedCell = document.createElement('td');
    var relevanceRelevanceCell = document.createElement('td');
    var relevanceWeightCell = document.createElement('td');
    relevanceWeightedCell.appendChild(document.createTextNode(GetTextElementContent(weightedRelevance)));
    relevanceRelevanceCell.appendChild(document.createTextNode(GetTextElementContent(relevancy)));
    relevanceWeightCell.appendChild(document.createTextNode(GetTextElementContent(weight)));

    var relevanceRow = document.createElement('tr');
    relevanceRow.appendChild(relevanceWeightedCell);
    relevanceRow.appendChild(relevanceRelevanceCell);
    relevanceRow.appendChild(relevanceWeightCell);

    var relevanceTable = document.createElement('table');
    relevanceTable.appendChild(relevanceHeaderRow);
    relevanceTable.appendChild(relevanceRow);
    return relevanceTable;
  }

  this.createResultTypeInfo = function(resultElement)
  {
    var resultTypeTable = document.createElement('table');

    var headerCellType = document.createElement('th');
    var headerCellCount = document.createElement('th');
    headerCellType.appendChild(document.createTextNode('Type'));
    headerCellCount.appendChild(document.createTextNode('Count'));

    var headerRow = document.createElement('tr');
    headerRow.appendChild(headerCellType);
    headerRow.appendChild(headerCellCount);

    resultTypeTable.appendChild(headerRow);

    var typesElement = resultElement.getElementsByTagName('types')[0];
    var typeElements = typesElement.getElementsByTagName('type');
    for(var i=0; i < typeElements.length; i++)
    {
      var typeCell = document.createElement('td');
      var countCell = document.createElement('td');

      var typeRow = document.createElement('tr');
      typeRow.appendChild(typeCell);
      typeRow.appendChild(countCell);
      
      resultTypeTable.appendChild(typeRow);

      var typeElement = typeElements[i];
      var countAttribute = typeElement.getAttributeNode('count');
      typeCell.appendChild(document.createTextNode(GetTextElementContent(typeElement)));
      countCell.appendChild(document.createTextNode(GetTextElementContent(countAttribute)));
    }

    return resultTypeTable;
  }

  this.createInfoBox = function(resultElement)
  {
    //container for info box content
    var contentElement = document.createElement('div');
    contentElement.style.visibility = 'hidden';
    contentElement.className = 'infoBoxContent';

    //process relevance information
    contentElement.appendChild(this.createRelevancyInfo(resultElement));

    //process result type information
    contentElement.appendChild(this.createResultTypeInfo(resultElement));

    //add info box form
    var infoBoxForm        = document.createElement('form');
    var buttonToggle       = document.createElement('input');
    buttonToggle.type      = 'submit';
    buttonToggle.value     = 'advanced';
    buttonToggle.className = 'infoBoxButton';
    infoBoxForm.appendChild(buttonToggle);
    infoBoxForm.appendChild(contentElement);

    //add toggle functionality to info box
    var tmpThis = this;
    buttonToggle.onclick=function() { tmpThis.toggleInfoBox(contentElement); return false; };

    //create a new row for returning
    var advancedInfoCell = document.createElement('td');
    advancedInfoCell.appendChild(infoBoxForm);
    var advancedInfoRow = document.createElement('tr');
    advancedInfoRow.appendChild(advancedInfoCell);
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
