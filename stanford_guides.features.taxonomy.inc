<?php
/**
 * @file
 * stanford_guides.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function stanford_guides_taxonomy_default_vocabularies() {
  return array(
    'guides' => array(
      'name' => 'Guides',
      'machine_name' => 'guides',
      'description' => 'Terms for guidelines and policies',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
