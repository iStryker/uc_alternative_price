<?php
// $Id$

/**
 * @file
 * Views 2 hooks and callback registries.
 */

/**
 * Implementation of hook_views_data().
 */
function uc_alternative_price_views_data() {

  $data['uc_alternative_prices']['table']['group'] = t('Product');
  $data['uc_product_features']['table']['group'] = t('Product');
  
  //joins the alternative price table to product features table
  $data['uc_alternative_prices']['table']['join'] = array(
    'node' => array(
      'left_table' => 'uc_product_features', 
      'left_field' => 'pfid',
      'field' => 'pfid',
    ),
  );
   
  //then joins the product features table to the node table
  $data['uc_product_features']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );
  
  
  $data['uc_alternative_prices']['alternative_price'] = array(
    'title' => t('Alternative Price'),
    'help' => t('The alternative price product feature (if applicable).'),
    'field' => array(
      'handler' => 'uc_alternative_price_handler_field_alternative_price',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['uc_product_features']['description'] = array(
    'title' => t('Alternative Price Description'),
    'help' => t('The alternative price product feature (if applicable).'),
    'field' => array(
      'handler' => 'views_handler_field',
      //'handler' => 'uc_alternative_price_handler_field_alternative_price',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['uc_product_features']['has_alternative_price'] = array(
    'title' => t('Has a product feature of alternative price'),
    'help' => t('Filter the product feature based on whether it has an alternative price.'),
    'group' => t('Product Feature'),
    'filter' => array(
      'handler' => 'uc_alternative_price_handler_filter_alternative_price',
      'label' => t('Has an alternative price'),
    ),
  );

  return $data;
}


/**
 * Implementation of hook_views_handlers().
 */
function uc_alternative_price_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'uc_alternative_price') .'/views',
    ),
    'handlers' => array(
      'uc_alternative_price_handler_field_alternative_price' => array(
        'parent' => 'views_handler_field',
      ),
      'uc_alternative_price_handler_filter_alternative_price' => array(
        'parent' => 'views_handler_filter_boolean_operator',
      ),
    ),
  );
}


// /**
 // * Conditionally add editablefields support.
 // */
// function uc_product_views_tables_alter(&$tables) {
  // if (module_exists('editablefields')) {
    // if (is_array($tables['uc_products']['fields']['model']['option'])) {
      // $tables['uc_products']['fields']['model']['option']['#options']['editable'] = t('Editable');
    // }
    // else {
      // $tables['uc_products']['fields']['model']['option'] = array(
        // '#type' => 'select',
        // '#options' => array(
          // 'display' => t('Display'),
          // 'editable' => t('Editable'),
        // ),
      // );
    // }
    // $tables['uc_products']['fields']['model']['form_parents'] = 'base][model';
    // if (is_array($tables['uc_products']['fields']['list_price']['option'])) {
      // $tables['uc_products']['fields']['list_price']['option']['#options']['editable'] = t('Editable');
    // }
    // else {
      // $tables['uc_products']['fields']['list_price']['option'] = array(
        // '#type' => 'select',
        // '#options' => array(
          // 'display' => t('Display'),
          // 'editable' => t('Editable'),
        // ),
      // );
    // }
    // $tables['uc_products']['fields']['list_price']['form_parents'] = 'base][prices][list_price';
    // if (is_array($tables['uc_products']['fields']['cost']['option'])) {
      // $tables['uc_products']['fields']['cost']['option']['#options']['editable'] = t('Editable');
    // }
    // else {
      // $tables['uc_products']['fields']['cost']['option'] = array(
        // '#type' => 'select',
        // '#options' => array(
          // 'display' => t('Display'),
          // 'editable' => t('Editable'),
        // ),
      // );
    // }
    // $tables['uc_products']['fields']['cost']['form_parents'] = 'base][prices][cost';
    // if (is_array($tables['uc_products']['fields']['sell_price']['option'])) {
      // $tables['uc_products']['fields']['sell_price']['option']['#options']['editable'] = t('Editable');
    // }
    // else {
      // $tables['uc_products']['fields']['sell_price']['option'] = array(
        // '#type' => 'select',
        // '#options' => array(
          // 'display' => t('Display'),
          // 'editable' => t('Editable'),
        // ),
      // );
    // }
    // $tables['uc_products']['fields']['sell_price']['form_parents'] = 'base][prices][sell_price';
    // if (is_array($tables['uc_products']['fields']['weight']['option'])) {
      // $tables['uc_products']['fields']['weight']['option']['#options']['editable'] = t('Editable');
    // }
    // else {
      // $tables['uc_products']['fields']['weight']['option'] = array(
        // '#type' => 'select',
        // '#options' => array(
          // 'display' => t('Display'),
          // 'editable' => t('Editable'),
        // ),
      // );
    // }
    // $tables['uc_products']['fields']['weight']['form_parents'] = 'base][weight';
  // }
// }
