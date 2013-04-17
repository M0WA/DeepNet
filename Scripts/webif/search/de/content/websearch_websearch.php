
<!--
    begin: query form
-->
<div id="query_form_container">
  <form name="searchform" onsubmit="return false;" onClick="return true;">

<!--
    begin: query input
-->
    <div id="criteria_box_id" name="criteria_box">
      <h4 class="small_topic_first">criteria</h4>
      <input type="checkbox" name="criteria[]" value="2" onchange="toggleElement('criteria_meta_relevance_id', this.checked);" checked />meta information<br>
      relevance: <input type="text"     size="5" id="criteria_meta_relevance_id" name="criteria_meta_relevance" value="0.45" /><br><br>
      <input type="checkbox" name="criteria[]" value="4" onchange="toggleElement('criteria_title_relevance_id', this.checked);" checked />page title<br>
      relevance: <input type="text"     size="5" id="criteria_title_relevance_id" name="criteria_title_relevance" value="0.66" /><br><br>
      <input type="checkbox" name="criteria[]" value="16" onchange="toggleElement('criteria_domain_relevance_id', this.checked);" checked />domain name<br>
      relevance: <input type="text"     size="5" id="criteria_domain_relevance_id" name="criteria_domain_relevance" value="0.75" /><br><br>
      <input type="checkbox" name="criteria[]" value="32" onchange="toggleElement('criteria_content_relevance_id', this.checked);" />full text<br>
      relevance: <input type="text"     size="5" id="criteria_content_relevance_id" name="criteria_content_relevance" value="0.15" disabled/><br><br>
      <input type="checkbox" name="criteria[]" value="128" onchange="toggleElement('criteria_url_path_relevance_id', this.checked);" />url path<br>
      relevance: <input type="text"     size="5" id="criteria_url_path_relevance_id" name="criteria_url_path_relevance" value="0.45" disabled/><br><br>
      <h4 class="small_topic_first">static criteria</h4>
      <input type="checkbox" name="criteria[]" value="64" />backlinks<br>
      relevance: <input type="text"     size="5" id="criteria_backlinks_relevance_id" name="criteria_backlinks_relevance" value="0.33" /><br><br>
      <h4 class="small_topic">grouping</h4>
      <input type="checkbox" name="grouping[]" value="1" checked />domain name<br>
<!--
      <input type="checkbox" name="grouping[]" value="2" disabled/>url path<br>
      <input type="checkbox" name="grouping[]" value="4" disabled/>file type<br><br>
-->
      <h4 class="small_topic">limitations</h4>
      max <input type="text" size="4" id="limit_result_count_id" name="limit_result_count" value="10"/> results<br><br>
      <input type="checkbox" name="limit[]" value="1" onchange="toggleElement('limit_domain_id', this.checked);" disabled/>domain name<br>
      <input type="text"     size="15" id="limit_domain_id" name="limit_domain" value="domain name" disabled /><br><br>
      <input type="checkbox" name="limit[]" value="2" onchange="toggleElement('limit_age_id', this.checked);" disabled/>age<br>
      <input type="text"     size="15" id="limit_age_id" name="limit_age" value="01-01-2012" disabled /><br><br>
      <input type="checkbox" name="limit[]" value="4" onchange="toggleElement('limit_lang_id', this.checked);" disabled/>language<br>
      <select id="limit_lang_id" disabled>
        <option>english</option>
        <option>german</option>
        <option>french</option>
        <option>russian</option>
      </select>
    </div>
    <div>
<table><tr><td>
      <div id="query_box_id">
        <input type="text" size="80" id="search_query_id" name="search_query" onkeyup="suggestHelper.onSuggest();return true;" onblur="suggestHelper.onSuggestBlur();" autofocus="true" autocomplete="off"/>
        <input type="submit" id="search_button" onClick="suggestHelper.onSuggestBlur();queryHelper.onQuery(-1,-1);" onSubmit="suggestHelper.onSuggestBlur(); return false;" value="search" />        
        <div id="suggest_list"></div>
      </div>
<!--
    end: query input
-->
</td></tr>
<tr><td>
<!--
    begin: query results
-->
      <div id="results_container_pending">
        <h3 id="result_header_pending"></h3>
        <img src="/wait.gif" /><br>
        searching, please wait...
      </div>
      <div id="results_container">
        <h3 id="result_header"></h3>
        <div id="results_space"></div>
      </div>
</td></tr></table>
<!--
    end: query results
-->
    </div>
  </form>
</div>
<!--
    end: query form
-->
