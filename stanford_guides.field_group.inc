<?php
/**
 * @file
 * stanford_guides.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_guides_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lead_text_styles|node|stanford_guides|default';
  $field_group->group_name = 'group_lead_text_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_guides';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Lead Text Styles',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_guides_lead_text',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Lead Text Styles',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'summary',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_lead_text_styles|node|stanford_guides|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic_styles|node|stanford_guides|default';
  $field_group->group_name = 'group_topic_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_guides';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Topic Styles',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_guides_topic',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Topic Styles',
      'instance_settings' => array(
        'classes' => '',
        'element' => 'h2',
        'show_label' => '0',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $export['group_topic_styles|node|stanford_guides|default'] = $field_group;

  return $export;
}
