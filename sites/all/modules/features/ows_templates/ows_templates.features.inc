<?php
/**
 * @file
 * ows_templates.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ows_templates_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ows_templates_node_info() {
  $items = array(
    'templates' => array(
      'name' => t('Templates'),
      'base' => 'node_content',
      'description' => t('Templates of websites'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
