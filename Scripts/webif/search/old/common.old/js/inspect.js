var inspectServerName = "/inspectorserver";
var ajaxRequest;

function inspectServer(xmlRequest)
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
    ajaxRequest.onreadystatechange=onInspectResponse;
    ajaxRequest.open('POST',inspectServerName,true);
    ajaxRequest.setRequestHeader("Content-type","application/xml");
    ajaxRequest.send(xmlRequest);
  }
}

function RemoveAllChildrenInspect(theElement)
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

function onInspectResponse()
{
  if (ajaxRequest.readyState==4 && ajaxRequest.status==200)
  {
		var xmlDoc=ajaxRequest.responseXML.documentElement;
		var x = xmlDoc.getElementsByTagName("result");
    var centerElement = document.createElement("center");
		if ( x != null && x.length > 0) 
		{
			for (i=0;i<x.length;i++)
			{
				if(i!=0) {
          centerElement.appendChild(document.createElement("hr")); }

        var innerResultElement = (x[i].getElementsByTagName("content")[0]);
        var innerResult = innerResultElement.textContent || innerResultElement.innerText || innerResultElement.text || "";
        var innerResultTmp = innerResult;
        try
        {
          innerResult = decodeURIComponent(innerResult);
        }
        catch(e1)
        {
          innerResult = innerResultTmp;
        }

        var resultHtmlContainer = document.createElement('div');
        resultHtmlContainer.innerHTML = innerResult;
        while(resultHtmlContainer.lastChild) {
          centerElement.insertBefore(resultHtmlContainer.lastChild, centerElement.firstChild);
          //centerElement.appendChild(resultHtmlContainer.lastChild);
        }
			}
		}
		else
		{
			centerElement.appendChild(document.createTextNode("error"));
		}

    RemoveAllChildrenInspect(document.getElementById("inspect_output"));
    document.getElementById("inspect_output").appendChild(centerElement);
  }
	else
	{
	}
}

function onInspect()
{
  var xml = "<request id=\"1\"><inspect id=\"1\">" + encodeURIComponent(document.getElementById('inspect_url').value) + "</inspect></request>";
  inspectServer(xml);
}
