<?php

function uib_webdesk__release_notes_page() {

  $notes_md = file_get_contents('../doc/release-notes.md');
  if (!$notes_md)
    return MENU_NOT_FOUND;

  $page = array();

  $heading = 'Release notes';
  $version = uibx_current_version();
  if ($version) {
    $heading .= " for w3.uib.no versjon $version";
  }

  $page['heading'] = array('#markup' => '<h1>' . check_plain($heading) . '</h1>');


  if (module_load_include('php', 'markdown')) {
    $notes_md = preg_replace('/^\#/m', '##', $notes_md);  // start headings at h2
    $notes_html = Markdown($notes_md);
    $notes_html = uibx_html_linkify('/#(\d+)/', function ($matches) {
      return '<a href="https://rts.uib.no/issues/' . $matches[1] . '">' . $matches[0] . '</a>';
    }, $notes_html);
    $page['text']['#markup'] = $notes_html;
  }
  else {
    $page['raw']['#markup'] = '<pre>' . check_plain($notes_md) . '</pre>';
  }

  drupal_add_css('
    li { list-style: disc; }
  ', array('type' => 'inline', 'group' => CSS_THEME));

  return $page;
}
