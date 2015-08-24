<?php

/**
 * Page callback for the template json page.
 */
function ows_templates_view_json_template_data_callback() {
	$sql = "SELECT n.nid, n.title, tc.field_template_category_tid AS tid, timg.field_template_image_fid AS fid FROM {node} n 
		INNER JOIN {field_data_field_template_category} tc ON tc.entity_id = n.nid 
		INNER JOIN {field_data_field_template_image} timg ON timg.entity_id = n.nid 
		WHERE n.type = :type
		";
	$query = db_query($sql, array(':type' => 'templates'));
	$results = $query->fetchAll();
	
	$data = array();
	foreach ($results as $key => $value) {
		$uri = db_query('SELECT uri FROM {file_managed} WHERE fid = :fid', array(':fid' => $value->fid))->fetchField();
		$value->image = image_style_url('medium', $uri);
		$data[$value->tid][] = (array)$value;
	}

	drupal_json_output($data);
}

/**
 * Page callback for the template json page.
 */
function ows_templates_view_json_alltemplate_data_callback() {
	$sql = "SELECT n.nid, n.title, tc.field_template_category_tid AS tid, timg.field_template_image_fid AS fid FROM {node} n 
		INNER JOIN {field_data_field_template_category} tc ON tc.entity_id = n.nid 
		INNER JOIN {field_data_field_template_image} timg ON timg.entity_id = n.nid 
		WHERE n.type = :type
		";
	$query = db_query($sql, array(':type' => 'templates'));
	$results = $query->fetchAll();
	
	$data = array();
	foreach ($results as $key => $value) {
		$uri = db_query('SELECT uri FROM {file_managed} WHERE fid = :fid', array(':fid' => $value->fid))->fetchField();
		$value->image = image_style_url('medium', $uri);
		$data[] = (array)$value;
	}
	drupal_json_output($data);	
}

/**
 * Page callback for the templates view page.
 */
function ows_templates_view_page_callback() {
	drupal_add_library('angularjs', 'angularjs');
	$path = drupal_get_path('module', 'ows_template_view');
	drupal_add_js($path . '/js/templates/app.js', array('type' => 'file'));
	drupal_add_js($path . '/js/bootstrap/ui-bootstrap-tpls-0.13.3.min.js', array('type' => 'file'));
	return theme('ows_templates');
} 