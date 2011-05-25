<?php
// $Id$

/**
 * @file
 * Views handler: Node filter on "product-ness".
 */

/**
 * Filter nodes based on whether they have an entry in the uc_features table.
 */
class uc_alternative_price_handler_filter_alternative_price extends views_handler_filter_boolean_operator {
  function query() {
    $this->query->add_field('uc_product_features', 'fid');
    $this->query->add_where($this->options['group'], "uc_product_features.fid ". (empty($this->value) ? "NOT " : "") ."IN ('alternative_price')", $this->value);
  }
}
