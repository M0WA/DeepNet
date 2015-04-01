var queryServerName = "/queryserver";
var ajaxRequest;

function encodeUrlHtml(url) {
   encodedHtml = url;
   encodedHtml = encodedHtml.replace(/&/g,"&amp;");
   encodedHtml = encodedHtml.replace(/\:80/g,"");
   return encodedHtml;
} 

function RemoveAllChildren(theElement)
{
  try
  {
    if ( theElement.hasChildNodes() )
    {
        while ( theElement.childNodes.length >= 1 )
        {
            theElement.removeChild( theElement.firstChild );       
        } 
    }
  }
  catch(e1)
  {
  }
}

function queryServer(xmlRequest)
{
  if(window.XMLHttpRequest)
  {
   ajaxRequest = new XMLHttpRequest();
  }
  else if(window.ActiveXObject)
  {
   try
   {
    ajaxRequest = new ActiveXObject('Msxml2.XMLHTTP');
   }
   catch(e1)
   {
    try
    {
     ajaxRequest = new ActiveXObject('Microsoft.XMLHTTP');
    }
    catch(e2)
    {
      alert(e2);
    }
   }
  }

  if(ajaxRequest != null)
  {
    ajaxRequest.onreadystatechange=onQueryResponse;
    ajaxRequest.open('POST',queryServerName,true);
    ajaxRequest.setRequestHeader("Content-type","application/xml");
    ajaxRequest.send(xmlRequest);
  }
}

function onQueryResponse()
{
  if (ajaxRequest.readyState==4 && ajaxRequest.status==200)
  {
		var xmlDoc=ajaxRequest.responseXML.documentElement;
		var x = xmlDoc.getElementsByTagName("result");

    RemoveAllChildren(document.getElementById('results_space'));
    RemoveAllChildren(document.getElementById('result_header'));

    var queryString = document.getElementById("search_query").value;
    document.getElementById('result_header').appendChild(document.createTextNode('results for: "' + queryString + '"'));
    document.getElementById('results_container').style.visibility = 'visible';

    document.getElementById('results_container_pending').style.height = '0';
    document.getElementById('results_container_pending').style.visibility = 'hidden';

		if ( x != null && x.length > 0) 
		{
			for (i=0;i<x.length;i++)
			{
        var lastChangedElement = (x[i].getElementsByTagName("lastChanged")[0]);
        var lastChanged = lastChangedElement.textContent || lastChangedElement.innerText || lastChangedElement.text || "";

        var lastVisitedElement = (x[i].getElementsByTagName("lastVisited")[0]);
        var lastVisited = lastVisitedElement.textContent || lastVisitedElement.innerText || lastVisitedElement.text || "";

        var urlElement = (x[i].getElementsByTagName("url")[0]);
        var urlText = urlElement.textContent || urlElement.innerText || urlElement.text || "";
        var urlTextDecoded = urlText;
        var urlTextHtmlEnc = urlText;
        try
        {
          urlTextDecoded = decodeURIComponent(urlText);
          urlTextHtmlEnc = encodeUrlHtml(urlTextDecoded);
        }
        catch(e2)
        {
          urlTextDecoded = urlText;
          urlTextHtmlEnc = urlText;
          //alert("invalid url: " + urlText);
        }

        var singleResultTable = document.createElement("table");
        singleResultTable.setAttribute('class', 'result_table');

        var singleResultTableRowTitle        = document.createElement("tr");
        var singleResultTableRowDescription  = document.createElement("tr");

        var singleResultTableCellTitle       = document.createElement("td");
        var singleResultTableCellDescription = document.createElement("td");

		    try
		    {
          var titleElement       = (x[i].getElementsByTagName("title")[0]);
					var title              = titleElement.textContent || titleElement.innerText || titleElement.text || "";
          var descriptionElement = (x[i].getElementsByTagName("description")[0]);
					var description        = descriptionElement.textContent || descriptionElement.innerText || descriptionElement.text || "";

          var singleUrlLink = document.createElement("a");
          singleUrlLink.setAttribute('class', 'undecorated_link');
          singleUrlLink.setAttribute('href', urlTextDecoded);
          singleUrlLink.setAttribute('target', '_blank');

          var title = decodeURIComponent(title);
          if( title == "")
            singleUrlLink.appendChild(document.createTextNode(urlTextHtmlEnc));
          else
            singleUrlLink.appendChild(document.createTextNode(title));

          singleResultTableCellTitle.appendChild(singleUrlLink);
          singleResultTableRowTitle.appendChild(singleResultTableCellTitle);

          singleResultTableCellDescription.appendChild(document.createTextNode(decodeURIComponent(description)));
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

        document.getElementById('results_space').appendChild(singleResultTable);
			}
		}
		else
		{
      document.getElementById('results_space').appendChild(document.createTextNode('no results'));
		}
  }
  else if(ajaxRequest.readyState==4 && ajaxRequest.status!=200)
  {
    document.getElementById('results_container_pending').style.visibility = 'hidden';
    document.getElementById('results_container').style.visibility = 'visible';

    RemoveAllChildren(document.getElementById(document.getElementById('result_header')));
    RemoveAllChildren(document.getElementById(document.getElementById('results_space')));

    document.getElementById('result_header').appendChild(document.createTextNode('an error occurred'));
  }
}

function onQuery()
{
  var queryCriteria = 0;
  for (var i = 0; i < (document.getElementsByName("criteria[]").length); i++) {
    if (document.getElementsByName("criteria[]")[i].checked) {
      queryCriteria |= document.getElementsByName("criteria[]")[i].value;
    }
  }

  if( queryCriteria != 0 && !(typeof document.getElementById("search_query").value === 'undefined')  && document.getElementById("search_query").value != '' )
  {
    var queryString = document.getElementById("search_query").value;
    var words = queryString.split(/\W+/);

    var xml = "<request id=\"1\"><query id=\"1\">";
    for(var i = 0; i < words.length; i++) {
      xml += "<querypart id=\""+i+"\">" + words[i] + "</querypart>"; }
    xml += "<querycriteria id=\"1\">"+ queryCriteria +"</querycriteria></query></request>";
    queryServer(xml);

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
}
