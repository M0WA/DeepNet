/* ******************************************************

  this is part of the DeepNet search engine software
  Copyright 2015, Moritz Wagner
  Author: Moritz Wagner (moritz.wagner@mo-sys.de)

********************************************************* */

var suggestHelper = new SuggestHelper();

function SuggestHelper()
{
  this.suggestServerName = "/suggestserver";
  this.suggestRequest;

  this.setCaretPosition = function(theElement, caretPos)
  {
      if(theElement != null) {
          if(theElement.createTextRange) {
              var range = theElement.createTextRange();
              range.move('character', caretPos);
              range.select();
          }
          else {
              if(theElement.selectionStart) {
                  theElement.setSelectionRange(caretPos, caretPos); }
          }
      }
  };

  this.ParseDictionarySuggest = function(dictionaryElement, contentRootElement)
  {
    if(dictionaryElement == null)
      return;

    var keywords = dictionaryElement.getElementsByTagName("keyword");
    if(keywords.length == 0)
      return;

	  for (var i=0; i<keywords.length; i++) {
      var keywordElement = keywords[i];
      this.ParseKeywordSuggest(keywordElement, contentRootElement);
    }

    return keywords.length;
  };

  this.ParseKeywordSuggest = function(keywordElement, contentElement)
  {
    var wordElement       = (keywordElement.getElementsByTagName("word")[0]);
    var spellElement      = (keywordElement.getElementsByTagName("spell")[0]);
    var proposalsElements = keywordElement.getElementsByTagName("proposals");
    var suggestElements   = (proposalsElements.length > 0) ? (proposalsElements[0]).getElementsByTagName("proposal") : null;

    var spellText = GetTextElementContent(spellElement);
    var word = GetTextElementContent(wordElement);

    if(suggestElements != null && suggestElements.length > 0) {
	    for (var i=0; i<suggestElements.length; i++) {
        var suggestElement = suggestElements[i];
        var textSuggest = GetTextElementContent(suggestElement);

        var _this = this;
        var optNode = document.createElement("div");
        optNode.className = 'suggest_option';
        optNode.onmouseover=function() { _this.hightlightSuggest(this); };
        optNode.onmouseout=function() { _this.deselectSuggest(this); };
        optNode.onmousedown=function() { _this.onSuggestClick(this); };
        optNode.appendChild(document.createTextNode(textSuggest));
        contentElement.appendChild(optNode);
      }
    }
  };

  this.suggestServer = function(xmlRequest)
  {
    if(window.XMLHttpRequest) {
     this.suggestRequest = new XMLHttpRequest();
    }
    else if(window.ActiveXObject) {
      try {
        this.suggestRequest = new ActiveXObject('Msxml2.XMLHTTP');
      }
      catch(e1) {
        try {
          this.suggestRequest = new ActiveXObject('Microsoft.XMLHTTP');
        }
        catch(e2) {
          alert(e2);
        }
      }
    }

    if(this.suggestRequest != null)
    {
      var _this = this;
      this.suggestRequest.onreadystatechange=function() { _this.onSuggestResponse(); };
      this.suggestRequest.open('POST',this.suggestServerName,true);
      this.suggestRequest.setRequestHeader("Content-type","application/xml");
      this.suggestRequest.send(xmlRequest);
    }
  };

  this.onSuggestResponse = function()
  {
    if (this.suggestRequest.readyState==4) 
    { 
      var suggestList = document.getElementById("suggest_list");
      if( this.suggestRequest.status==200) 
      {
        RemoveAllChildren(suggestList);

        var xmlDoc = this.suggestRequest.responseXML.documentElement;
        if( xmlDoc == null || xmlDoc.getElementsByTagName("result").length < 1 ) {
          isError = true; }

        var dictionaryElement = (xmlDoc.getElementsByTagName("result")[0]);
        if ( this.ParseDictionarySuggest(dictionaryElement, suggestList) > 0 ) {
          suggestList.style.display='block';
          suggestList.style.border='1px solid black';
        }
        else {
          suggestList.style.display='none';
          suggestList.style.border='none';
        }
      }
      else {
        suggestList.style.display='none';
        suggestList.style.border='none';
      }

      delete this.suggestRequest;
    }
  };

  this.hightlightSuggest = function(element)
  {
    element.className='suggest_option suggest_option_highlighted';
  };

  this.deselectSuggest = function(element)
  {
    element.className='suggest_option';
  };

  this.clearSuggest = function()
  {
      var suggestList = document.getElementById("suggest_list");
      suggestList.blur();
      suggestList.style.display='none';
      suggestList.style.border='none';
  };

  this.onSuggestBlur = function()
  {
    this.clearSuggest();
  };

  this.onSuggestClick = function(element)
  {
      var searchQueryElement = document.getElementById("search_query_id"); 
      var queryString = searchQueryElement.value;
      var words = queryString.split(/\W+/);

      var lastWord = words.length -1;
      var newQuery = "";
      for(var i = 0; i < lastWord; i++) {
        newQuery += words[i] + " "; }
      newQuery += GetTextElementContent(element) + " ";

      searchQueryElement.value = newQuery;
      this.setCaretPosition(searchQueryElement, newQuery.length);

      this.clearSuggest();
      searchQueryElement.focus();
  };

  this.onSuggest = function()
  {
    if( !(typeof document.getElementById("search_query_id").value === 'undefined')  && document.getElementById("search_query_id").value != '' )
    {
      var queryString = document.getElementById("search_query_id").value;
      var words = queryString.split(/\W+/);

      var lastWord = words.length -1;
      if(lastWord < 0)
        return;

      var xml = "<request id=\"1\"><query id=\"1\"><querypart id=\"1\">" + words[lastWord] + "</querypart></query></request>";
      this.suggestServer(xml);
    }
  };
}
