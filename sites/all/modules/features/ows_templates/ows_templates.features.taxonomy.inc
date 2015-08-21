<?php
/**
 * @file
 * ows_templates.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ows_templates_taxonomy_default_vocabularies() {
  return array(
    'templates_categories' => array(
      'name' => 'Templates Categories',
      'machine_name' => 'templates_categories',
      'description' => 'Categories of the templates',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
