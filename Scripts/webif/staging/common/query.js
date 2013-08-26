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
	    var xmlDoc=this.ajaxQuery.responseXML.documentElement;
	    var x = xmlDoc.getElementsByTagName("result");

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

	    if ( x != null && x.length > 0) 
	    {
        var i=0;
		    for (i=0;i<x.length;i++)
		    {

          var lastChangedElement = (x[i].getElementsByTagName("lastChanged")[0]);
          var lastChanged = GetTextElementContent(lastChangedElement);

          var lastVisitedElement = (x[i].getElementsByTagName("lastVisited")[0]);
          var lastVisited = GetTextElementContent(lastVisitedElement);

          var urlElement = (x[i].getElementsByTagName("url")[0]);
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

          var singleResultTable = document.createElement("table");
          singleResultTable.setAttribute('class', 'single_result_table');

          var singleResultTableRowTitle        = document.createElement("tr");
          var singleResultTableRowDescription  = document.createElement("tr");

          var singleResultTableCellTitle       = document.createElement("td");
          var singleResultTableCellDescription = document.createElement("td");

	        try
	        {
            var titleElement       = (x[i].getElementsByTagName("title")[0]);
				    var title              = GetTextElementContent(titleElement);
            var descriptionElement = (x[i].getElementsByTagName("description")[0]);
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
            var keywordElements = (x[i].getElementsByTagName("keywords")[0]).getElementsByTagName("keyword");
            this.CreateInfoBox(keywordElements, singleResultTableCellTitle);

            singleResultTableRowTitle.appendChild(singleResultTableCellTitle);

            singleResultTableCellDescription.appendChild(document.createTextNode(htmlDecode(description)));
            singleResultTableRowDescription.appendChild(singleResultTableCellDescription);
		      }
			    catch(e1) 
			    {
             singleResultTableCellTitle.appendChild(document.createTextNode('N/A'));
             singleResultTableCellDescription.appendChild(document.createTextNode('N/A'));
			    }          
          singleResultTable.appendChild(singleResultTableRowTitle);
          singleResultTable.appendChild(singleResultTableRowDescription);

          var singleResultTableRowLastChanged  = document.createElement("tr");
          var singleResultTableRowLastVisited  = document.createElement("tr");
          var singleResultTableCellLastChanged = document.createElement("td");
          var singleResultTableCellLastVisited = document.createElement("td");

          singleResultTableCellLastChanged.appendChild(document.createTextNode(lastChanged));
          singleResultTableRowLastChanged.appendChild(singleResultTableCellLastChanged);
          singleResultTable.appendChild(singleResultTableRowLastChanged);

          singleResultTableCellLastVisited.appendChild(document.createTextNode(lastVisited));
          singleResultTableRowLastVisited.appendChild(singleResultTableCellLastVisited);
          singleResultTable.appendChild(singleResultTableRowLastVisited);

          var singleResultTableRowURL  = document.createElement("tr");
          var singleResultTableCellURL = document.createElement("td");
          var singleResultFontURL      = document.createElement("font");
          singleResultFontURL.setAttribute('class','url_font');
          singleResultFontURL.appendChild(document.createTextNode(urlTextHtmlEnc));
          singleResultTableCellURL.appendChild(singleResultFontURL);

          singleResultTableRowURL.appendChild(singleResultTableCellURL);
          singleResultTable.appendChild(singleResultTableRowURL);

          var resultTableCell = document.createElement("td");
          resultTableCell.appendChild(singleResultTable);

          var resultTableRow  = document.createElement("tr");
          resultTableRow.appendChild(resultTableCell);

          resultTable.appendChild(resultTableRow);
		    }

        this.printPaging(xmlDoc,x.length,document.getElementById('results_space'));
	    }
	    else
	    {
        document.getElementById('results_space').appendChild(document.createTextNode('no results'));
	    }
      delete this.ajaxQuery;     
    }
    else if(this.ajaxQuery.readyState==4 && this.ajaxQuery.status!=200)
    {
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
    /*
      preparing criteria
    */
    var metaRelevance     = document.getElementById("criteria_meta_relevance_id").value;
    var titleRelevance    = document.getElementById("criteria_title_relevance_id").value;
    var domainRelevance   = document.getElementById("criteria_domain_relevance_id").value;
    var contentRelevance  = document.getElementById("criteria_content_relevance_id").value;
    var backlinkRelevance = document.getElementById("criteria_backlinks_relevance_id").value;
    var urlPathRelevance  = document.getElementById("criteria_url_path_relevance_id").value;

    /*
      preparing grouping
    */

    /*
      preparing limitations
    */
    var limitationsFlag = 0;
    var maxResults      = document.getElementById("limit_result_count_id").value;
    var domainLimit     = document.getElementById("limit_domain_id").value;
    var ageLimit        = document.getElementById("limit_age_id").value;
    var langLimit       = document.getElementById("limit_lang_id").value;

    /*
      create xml request
    */
    if( !(typeof document.getElementById("search_query_id").value === 'undefined')  && document.getElementById("search_query_id").value != '' )
    {
      var queryString = document.getElementById("search_query_id").value;
      var words = queryString.split(/\W+/);

      var xml = "<request id=\"1\"><query id=\"1\">";

      if(pageNo != -1) {
         xml += "<pageNo>"+pageNo+"</pageNo>"; }

      if(queryID != -1) {
         xml += "<queryId>"+queryID+"</queryId>"; }

      for(var i = 0; i < words.length; i++) {
        xml += "<querypart id=\""+i+"\">" + words[i] + "</querypart>"; }
      xml += "<criteria>";
      for (var i = 0; i < (document.getElementsByName("criteria[]").length); i++) {
        if (document.getElementsByName("criteria[]")[i].checked) {
          xml +=  "<flag>"+document.getElementsByName("criteria[]")[i].value+"</flag>";
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
      for (var i = 0; i < (document.getElementsByName("grouping[]").length); i++) {
        if (document.getElementsByName("grouping[]")[i].checked) {
          xml +=  "<flag>"+document.getElementsByName("grouping[]")[i].value+"</flag>";
        }
      }
      xml +=
            "</grouping>" +
            "<limitations>";
      for (var i = 0; i < (document.getElementsByName("limit[]").length); i++) {
        if (document.getElementsByName("limit[]")[i].checked) {
          xml +=  "<flag>"+document.getElementsByName("limit[]")[i].value+"</flag>";
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

  this.CreateInfoBox = function(keywordElements, tableCell)
  {
    if(keywordElements.length <= 0) {
      return; }

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
