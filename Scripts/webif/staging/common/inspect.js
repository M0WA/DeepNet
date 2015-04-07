/* ******************************************************

  this is part of the DeepNet search engine software
  Copyright 2015, Moritz Wagner
  Author: Moritz Wagner (moritz.wagner@mo-sys.de)

********************************************************* */

var serverNameInspect = "/inspectorserver";
var ajaxInspect;

function inspectServer(xmlRequest)
{
  if(window.XMLHttpRequest)
  {
   ajaxInspect = new XMLHttpRequest();
  }
  else if(window.ActiveXObject)
  {
   try
   {
    ajaxInspect = new ActiveXObject('Msxml2.XMLHTTP');
   }
   catch(e1)
   {
    try
    {
     ajaxInspect = new ActiveXObject('Microsoft.XMLHTTP');
    }
    catch(e2)
    {
      alert(e2);
    }
   }
  }

  if(ajaxInspect != null)
  {
    ajaxInspect.onreadystatechange=onInspectResponse;
    ajaxInspect.open('POST',serverNameInspect,true);
    ajaxInspect.setRequestHeader("Content-type","application/xml");
    ajaxInspect.send(xmlRequest);
  }
}

function CreateContentElement(title)
{
  var contentElement = document.createElement("div");
  var topicElement   = document.createElement("h4");
  contentElement.appendChild(topicElement);
  topicElement.appendChild(document.createTextNode(title));
  return contentElement;
}

function ParseErrors(errorElement, contentRootElement, title)
{
  if(errorElement == null)
    return;

  var contentElement = CreateContentElement(title);

  var messages = errorElement.getElementsByTagName("message");
	for (var i=0; i<messages.length; i++) {
    var messageElement = messages[i];
    var messageText    = GetTextElementContent(messageElement);

    var preformatedErrorMessage = document.createElement("pre");
    preformatedErrorMessage.innerHTML = messageText;
    contentElement.appendChild(preformatedErrorMessage);
  }

  contentRootElement.appendChild(contentElement);
}

function ParseUrls(urlsElement, contentRootElement, title)
{
  if(urlsElement == null)
    return;

  var contentElement = CreateContentElement(title);

  var urls = urlsElement.getElementsByTagName("url");
	for (var i=0; i<urls.length; i++) {
    var urlElement = urls[i];
    var fullUrlElement = urlElement.getElementsByTagName("fullurl")[0];
    var urlText = GetTextElementContent(fullUrlElement);

    var preformatedUrlText = document.createElement("pre");
    preformatedUrlText.innerHTML = urlText;
    contentElement.appendChild(preformatedUrlText);
  }

  contentRootElement.appendChild(contentElement);
}

function ParseMetaInfo(metaInfoElement,contentRootElement, title)
{
  if(metaInfoElement == null)
    return;

  var metaInfos = metaInfoElement.getElementsByTagName("metaTag");
  if(metaInfos.length > 0) {

    var contentElement = CreateContentElement(title);   
    var tableMetaInfo = document.createElement("table");
    contentElement.appendChild(tableMetaInfo);

    for (var i=0; i<metaInfos.length; i++) {

      var metaTagElement = metaInfos[i];

      var metaTagName  = (metaTagElement.getElementsByTagName("name")[0]);
      var metaTagValue = (metaTagElement.getElementsByTagName("value")[0]);

      var cellName = document.createElement("td");
      var cellValue = document.createElement("td");
      cellName.appendChild(document.createTextNode(GetTextElementContent(metaTagName)));
      cellValue.appendChild(document.createTextNode(GetTextElementContent(metaTagValue)));

      var rowMetaInfo = document.createElement("tr");
      tableMetaInfo.appendChild(rowMetaInfo);

      rowMetaInfo.appendChild(cellName);
      rowMetaInfo.appendChild(cellValue);

    }
  }

  contentRootElement.appendChild(contentElement);
}

function ParseDictionary(dictionaryElement, contentRootElement, title)
{
  if(dictionaryElement == null)
    return;

  var keywords = dictionaryElement.getElementsByTagName("keyword");
  if(keywords.length == 0)
    return;

  var contentElement = CreateContentElement(title);
	for (var i=0; i<keywords.length; i++) {
    var keywordElement = keywords[i];
    ParseKeyword(keywordElement, contentElement);
  }

  contentRootElement.appendChild(contentElement);
}

function ParseKeyword(keywordElement, contentElement)
{
  var wordElement       = (keywordElement.getElementsByTagName("word")[0]);
  var spellElement      = (keywordElement.getElementsByTagName("spell")[0]);
  var occurrenceElement = (keywordElement.getElementsByTagName("occurrence")[0]);
  var proposalsElements = keywordElement.getElementsByTagName("proposals");
  var suggestElements   = (proposalsElements.length > 0) ? (proposalsElements[0]).getElementsByTagName("proposal") : null;

  var tableKeyword   = document.createElement("table");
  var rowKeyword     = document.createElement("tr");

  var cellKeyword    = document.createElement("td");
  var cellSpell      = document.createElement("td");
  var cellOccurrence = document.createElement("td");

  var spellText = GetTextElementContent(spellElement);
  if(spellText == "1") spellText = "OK";
  else                 spellText = "CHECK SPELLING";

  cellKeyword.appendChild(document.createTextNode(GetTextElementContent(wordElement)));
  cellSpell.appendChild(document.createTextNode(spellText));
  cellOccurrence.appendChild(document.createTextNode(GetTextElementContent(occurrenceElement)));

  rowKeyword.appendChild(cellKeyword);
  rowKeyword.appendChild(cellSpell);
  rowKeyword.appendChild(cellOccurrence);
  tableKeyword.appendChild(rowKeyword);
  contentElement.appendChild(tableKeyword);

  if(suggestElements != null && suggestElements.length > 0) {
    var tableSuggest = document.createElement("table");
    var rowSuggest   = document.createElement("tr");
	  for (var i=0; i<suggestElements.length; i++) {
      var suggestElement = suggestElements[i];
      var textSuggest = GetTextElementContent(suggestElement);
      var cellSuggest =  document.createElement("td");
      cellSuggest.appendChild(document.createTextNode(textSuggest));
      rowSuggest.appendChild(cellSuggest);
      if( (i%3) == 0 ) {
        tableSuggest.appendChild(rowSuggest);
        rowSuggest = document.createElement("tr"); }
    }

    contentElement.appendChild(tableSuggest);
  }
}

function onInspectResponse()
{
  var isError = (ajaxInspect.readyState==4 && ajaxInspect.status!=200);
  if (ajaxInspect.readyState==4 && ajaxInspect.status==200) {
    var contentRootElement = document.getElementById("inspect_output");
    RemoveAllChildren(contentRootElement);

    var xmlDoc = ajaxInspect.responseXML.documentElement;
    if( xmlDoc == null || xmlDoc.getElementsByTagName("result").length < 1 ) {
      isError = true; }

    var resultElement = (xmlDoc.getElementsByTagName("result")[0]);

    var fatalsElement = (resultElement.getElementsByTagName("fatals")[0]);    
    ParseErrors(fatalsElement,contentRootElement,"fatals");

    var errorsElement = (resultElement.getElementsByTagName("errors")[0]);
    ParseErrors(errorsElement,contentRootElement,"errors");

    var warningsElement = (resultElement.getElementsByTagName("warnings")[0]);
    ParseErrors(warningsElement,contentRootElement,"warnings");

    var urlsElement = (resultElement.getElementsByTagName("urls")[0]);
    ParseUrls(urlsElement,contentRootElement,"urls");

    var backlinksElement = (resultElement.getElementsByTagName("backlinks")[0]);
    ParseUrls(backlinksElement,contentRootElement,"backlinks");

    var metaInfoElement = (resultElement.getElementsByTagName("metaInfo")[0]);
    ParseMetaInfo(metaInfoElement,contentRootElement,"meta information");

    var metaDictionaryElement = (resultElement.getElementsByTagName("metaDictionary")[0]);
    ParseDictionary(metaDictionaryElement,contentRootElement,"meta dictionary");

    var websiteDictionaryElement = (resultElement.getElementsByTagName("websiteDictionary")[0]);
    ParseDictionary(websiteDictionaryElement,contentRootElement,"website dictionary");
  }
  
  if(isError) {
    var contentRootElement = document.getElementById("inspect_output");
    RemoveAllChildren(contentRootElement);

    var errorHeader = document.createElement("h3");
    errorHeader.appendChild(document.createTextNode('an error has occurred'));
    contentRootElement.appendChild(errorHeader);
  }
}

function onInspect()
{
  var xml = "<request id=\"1\"><inspect id=\"1\">" + encodeURIComponent(document.getElementById('inspect_url').value) + "</inspect></request>";
  inspectServer(xml);
}
