<?php
/**
 * @file
 * stanford_guides_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_guides_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'guides_search';
  $context->description = 'Placing exposed filter on guides search';
  $context->tag = 'Guides';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'guides-search' => 'guides-search',
        'guides-search/*' => 'guides-search/*',
        'guides' => 'guides',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'stanford_guides_search-guides_search' => array(
          'module' => 'stanford_guides_search',
          'delta' => 'guides_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Guides');
  t('Pplacing exposed filter on guides search');
  $export['guides_search'] = $context;

  return $export;
}
