<?php

function stanford_guides_search_input_form($form, &$form_state) {
  $topics = taxonomy_allowed_values(field_info_field('field_s_guides_topic'));
  $topics = array('All' => 'All') + $topics;
  $keyword = isset($_COOKIE['stanford_guides_keyword']) ? $_COOKIE['stanford_guides_keyword'] : '';
  $topic = isset($_COOKIE['stanford_guides_topic']) ? $_COOKIE['stanford_guides_topic'] : 'All';
  // To make these fields required
  $form['keyword'] = array(
    '#type' => 'textfield',
    '#title' => t('Search By Keyword'),
    //'#default_value' => variable_get('stanford_guides_keyword', NULL),
    '#default_value' => $keyword,
  );
  $form['topic'] = array(
    '#type' => 'select',
    '#title' => t('Filter By Topic'),
    '#options' => $topics,
    //'#default_value' => variable_get('stanford_guides_topic', array_shift($topics)),
    //'#default_value' => variable_get('stanford_guides_topic', $topics)
    '#default_value' => $topic,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Go',
  );
  $form['options']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset'),
    '#submit' => array('stanford_guides_search_input_form_reset'),
  );
  return $form;
}

/**
 * Add a submit handler/function to the form.
 */
function stanford_guides_search_input_form_submit($form, &$form_state) {
  if (isset($_POST['keyword'])) {
    //variable_set('stanford_guides_keyword', $_POST['keyword']);
    setcookie('stanford_guides_keyword', $_POST['keyword'], time() + (60 * 60 * 24 * 30 * 12), '/');
  }
  //variable_set('stanford_guides_topic', $_POST['topic']);
  setcookie('stanford_guides_topic', $_POST['topic'], time() + (60 * 60 * 24 * 30 * 12), '/');
  $form_state['rebuild'] = FALSE;
  if ($_POST['topic'] != 'All') {
    $term = taxonomy_term_load($_POST['topic']);
    $topic = $term->name;
    $topic = strtolower(str_replace(' ', '-', $topic));
  }
  else {
    $topic = 'All';
  }
  $form_state['redirect'] = 'guides-search/' . $topic;
}

/**
 * Add a reset.
 */
function stanford_guides_search_input_form_reset($form, &$form_state) {
  $form_state['rebuild'] = FALSE;
  //variable_set('stanford_guides_keyword', '');
  setcookie('stanford_guides_keyword', '', time() + (60 * 60 * 24 * 30 * 12), '/');
  $topic_ids= array_keys(taxonomy_allowed_values(field_info_field('field_s_guides_topic')));
  $topic_ids = array('All' => 'All') + $topic_ids;
  //variable_set('stanford_guides_topic', array_shift($topic_ids));
  setcookie('stanford_guides_topic', 'All', time() + (60 * 60 * 24 * 30 * 12), '/');
  drupal_goto('guides/');
}


