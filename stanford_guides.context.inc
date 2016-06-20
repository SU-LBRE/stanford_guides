<?php
/**
 * @file
 * stanford_guides.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_guides_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'guides_by_topics';
  $context->description = 'Blocks on the Guides by topic page';
  $context->tag = 'Guides';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'guides/*' => 'guides/*',
        '~guides/*/*' => '~guides/*/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-guides_taxonomy_terms-block' => array(
          'module' => 'views',
          'delta' => 'guides_taxonomy_terms-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks on the Guides by topic page');
  t('Guides');
  $export['guides_by_topics'] = $context;

  return $export;
}
