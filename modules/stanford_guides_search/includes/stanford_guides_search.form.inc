<?php



function stanford_guides_search_input_form($form, &$form_state) {
  $topics = taxonomy_allowed_values(field_info_field('field_s_guides_topic'));
  // To make these fields required
  $form['keyword'] = array(
    '#type' => 'textfield',
    '#title' => t('Search By Keyword'),
  );
  $form['topic'] = array(
    '#type' => 'select',
    '#title' => t('Filter By Topic'),
    '#options' => $topics,
    '#default_value' => variable_get('stanford_guides_topic', array_shift($topics)),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Go',
  );
  $form['reset'] = array(
    '#type' => 'button',
    '#button_type' => 'reset',
    '#value' => t('Reset'),
    '#weight' => 9,
    '#validate' => array(),
    '#attributes' => array(
      'onclick' => 'this.form.reset(); return false;',
    ),
  );
  return $form;
}

/**
 * Add a submit handler/function to the form.
 */
function stanford_guides_search_input_form_submit($form, &$form_state) {
  variable_set('stanford_guides_topic', $_POST['topic']);
  $form_state['rebuild'] = FALSE;
  $term = taxonomy_term_load($_POST['topic']);
  $topic = $term->name;
  $topic = strtolower(str_replace(' ', '-', $topic));
  $form_state['redirect'] = 'guides-search/' . $topic;
}


