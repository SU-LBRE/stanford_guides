<?php
/**
 * @file
 * stanford_guides_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_guides_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'guides_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Guides Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Guides Search';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_s_guides_topic',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
    'custom_link_to_entity' => 0,
    'custom_prefix' => '',
    'custom_suffix' => '',
    'custom_reverse' => 0,
    'custom_trim' => 0,
    'custom_strtolower' => 0,
    'custom_strtoupper' => 0,
    'custom_ucfirst' => 0,
    'custom_ucwords' => 0,
    'custom_strip_tags' => 0,
    'custom_strip_preserve' => '',
  );
  /* Field: Content: Topic */
  $handler->display->display_options['fields']['field_s_guides_topic']['id'] = 'field_s_guides_topic';
  $handler->display->display_options['fields']['field_s_guides_topic']['table'] = 'field_data_field_s_guides_topic';
  $handler->display->display_options['fields']['field_s_guides_topic']['field'] = 'field_s_guides_topic';
  $handler->display->display_options['fields']['field_s_guides_topic']['label'] = '';
  $handler->display->display_options['fields']['field_s_guides_topic']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_guides_topic']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_guides_topic']['settings'] = array(
    'custom_link_to_entity' => 0,
    'custom_prefix' => '',
    'custom_suffix' => '',
    'custom_reverse' => 0,
    'custom_trim' => 0,
    'custom_strtolower' => 0,
    'custom_strtoupper' => 0,
    'custom_ucfirst' => 0,
    'custom_ucwords' => 0,
    'custom_strip_tags' => 0,
    'custom_strip_preserve' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div>
  <h2>[title]</h2>
</div>
<div>[body]</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_guides' => 'stanford_guides',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search By Keyword';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    18 => 0,
    16 => 0,
    14 => 0,
    12 => 0,
    22 => 0,
    6 => 0,
    8 => 0,
    10 => 0,
    20 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_s_guides_topic' => 'field_s_guides_topic',
  );
  /* Filter criterion: Content: Topic (field_s_guides_topic) */
  $handler->display->display_options['filters']['field_s_guides_topic_tid']['id'] = 'field_s_guides_topic_tid';
  $handler->display->display_options['filters']['field_s_guides_topic_tid']['table'] = 'field_data_field_s_guides_topic';
  $handler->display->display_options['filters']['field_s_guides_topic_tid']['field'] = 'field_s_guides_topic_tid';
  $handler->display->display_options['filters']['field_s_guides_topic_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_s_guides_topic_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_s_guides_topic_tid']['expose']['operator_id'] = 'field_s_guides_topic_tid_op';
  $handler->display->display_options['filters']['field_s_guides_topic_tid']['expose']['label'] = 'Filter By Topic';
  $handler->display->display_options['filters']['field_s_guides_topic_tid']['expose']['operator'] = 'field_s_guides_topic_tid_op';
  $handler->display->display_options['filters']['field_s_guides_topic_tid']['expose']['identifier'] = 'field_s_guides_topic_tid';
  $handler->display->display_options['filters']['field_s_guides_topic_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    18 => 0,
    16 => 0,
    14 => 0,
    12 => 0,
    22 => 0,
    6 => 0,
    8 => 0,
    10 => 0,
    20 => 0,
  );
  $handler->display->display_options['filters']['field_s_guides_topic_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_s_guides_topic_tid']['vocabulary'] = 'guides';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'guides/search';
  $export['guides_search'] = $view;

  return $export;
}
