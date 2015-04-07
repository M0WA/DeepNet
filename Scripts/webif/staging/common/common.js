/* ******************************************************

  this is part of the SIRIDIA search engine software
  Copyright 2012, SIRIDIA GmbH
  Author: Moritz Wagner (moritz.wagner@mo-sys.de)

********************************************************* */

function encodeUrlHtml(url) {
   encodedHtml = url;
   encodedHtml = encodedHtml.replace(/&/g,"&amp;");
   encodedHtml = encodedHtml.replace(/\:80/g,"");
   return encodedHtml;
}

function htmlDecode(input){
  var e = document.createElement('div');
  e.innerHTML = input;
  return e.childNodes.length === 0 ? "" : e.childNodes[0].nodeValue;
}

function IsReturnKeyDown(evt) {
  var keyCode = document.layers ? evt.which : evt.keyCode;
  if (keyCode == 13) {
    return true; }
  return false;
}

function toggleCriteriaBox(buttonCollapseId,buttonExpandId,boxId,doExpand)
{
  var expand   = document.getElementById(buttonExpandId);
  var collapse = document.getElementById(buttonCollapseId);
  var box      = document.getElementById(boxId);

  setDisplay(expand,!doExpand);
  setVisibility(expand,!doExpand);

  setDisplay(collapse,doExpand);
  setVisibility(collapse,doExpand);

  setDisplay(box,doExpand);
  setVisibility(box,doExpand);
}

function toggleElement(elementId, isChecked)
{
  var element = document.getElementById(elementId);
  element.disabled = !isChecked;
  setDisplay(element,isChecked);
  setVisibility(element,isChecked);
}

function toggleVisibility(contentElement)
{
  if(contentElement.style.visibility == "hidden") {
    setVisibility(contentElement,true);
  }
  else {
    setVisibility(contentElement,false);
  }
}

function setVisibility(contentElement,isVisible)
{
  if(isVisible) {
    contentElement.style.visibility = "visible";
  }
  else {
    contentElement.style.visibility = "hidden";
  }
}

function setDisplay(contentElement,isVisible) {
  if(isVisible) {
    contentElement.style.display = "inline";
  }
  else {
    contentElement.style.display = "none";
  }
}

function RemoveAllChildren(theElement)
{
  try
  {
    if ( theElement.hasChildNodes() ) {
        while ( theElement.childNodes.length >= 1 ) {
            theElement.removeChild( theElement.firstChild );       
        } 
    }
  }
  catch(e1)
  {
  }
}

function GetTextElementContentRaw(theElement)
{
  if(theElement==null)
    return "";
  var elementText = theElement.textContent || theElement.innerText || theElement.text || "";
  return elementText;
}

function GetTextElementContent(theElement)
{
  if(theElement==null)
    return "";
  var elementText = theElement.textContent || theElement.innerText || theElement.text || "";
  var elementTextDecoded = elementText;  
  try
  {
    elementTextDecoded = decodeURIComponent(elementText);
  }
  catch(e1)
  {
    try
    {
      elementTextDecoded = decodeURI(elementText);
    }
    catch(e2)
    {
      elementTextDecoded = elementText;
    }
  }
  return elementTextDecoded;
}

function getCookieValueByName(cookieName) { 

  var theCookie = document.cookie; 
  if (theCookie.indexOf(cookieName) == -1) { 
    return null; }

  var startPos = theCookie.indexOf(cookieName) + cookieName.length + 1;  
  var endPos = theCookie.indexOf(";", startPos); 
  if (endPos == -1) { endPos = theCookie.length; }
  return unescape(theCookie.substr(startPos,endPos - startPos)); 
} 
