<?php
/**
 * @file vail.config.inc
 * An Associative Array of station information from Vail MLS
 */

  
  /**
   *
   * Boolean list_boolean
number_decimal
file
number_float
image
number_integer
list_float
list_integer
list_text
text_long
text_with_summary
taxonomy_term_reference
text
   */
$config = array(
    'ramfields' => array(
	    'KEY1' => array('field_name'=>'mlsnum', 'field_label'=>'MLS Number', 'type'=>'text'),
	    'KEY2' => array('field_name'=>'propclass', 'field_label'=>'Property Classification', 'type'=>'text'),
	    'KEY3' => array('field_name'=>'proptype', 'field_label'=>'Property Type', 'type'=>'text'),
	    'KEY4' => array('field_name'=>'area', 'field_label'=>'Area', 'type'=>'text'),
	    'KEY5' => array('field_name'=>'askingprice', 'field_label'=>'Asking Price', 'type'=>'number_decimal'),
	    'KEY6' => array('field_name'=>'address', 'field_label'=>'Street Address', 'type'=>'text'),
	    'KEY7' => array('field_name'=>'city', 'field_label'=>'City', 'type'=>'text'),
	    'KEY8' => array('field_name'=>'state', 'field_label'=>'State', 'type'=>'text'),
	    'KEY9' => array('field_name'=>'Zip', 'field_label'=>'Zip', 'type'=>'text'),
	    'KEY10' => array('field_name'=>'status', 'field_label'=>'Status', 'type'=>'text'),
	    'KEY11' => array('field_name'=>'salerent', 'field_label'=>'Sale Rent', 'type'=>'text'),
	    'KEY12' => array('field_name'=>'numbeds', 'field_label'=>'Number of Bedrooms', 'type'=>'number_integer'),
	    'KEY13' => array('field_name'=>'numbaths', 'field_label'=>'Number of Full Baths', 'type'=>'number_integer'),
	    'KEY14' => array('field_name'=>'numhlfbaths', 'field_label'=>'Number of Half Baths', 'type'=>'number_integer'),
	    'KEY15' => array('field_name'=>'gargcap', 'field_label'=>'Garage Capacity', 'type'=>'text'),
	    'KEY16' => array('field_name'=>'gargtyp', 'field_label'=>'Garage Type', 'type'=>'text'),
	    'KEY17' => array('field_name'=>'levels', 'field_label'=>'Levels', 'type'=>'number_decimal'),
	    'KEY18' => array('field_name'=>'basement', 'field_label'=>'Basement', 'type'=>'text'),
	    'KEY19' => array('field_name'=>'condition', 'field_label'=>'Condition', 'type'=>'text_long'),
	    'KEY20' => array('field_name'=>'reservations', 'field_label'=>'Reservations', 'type'=>'text_long'),
	    'KEY21' => array('field_name'=>'numacres', 'field_label'=>'Number of Acres', 'type'=>'number_decimal'),
	    'KEY22' => array('field_name'=>'priceperacre', 'field_label'=>'Price Per Acre', 'type'=>'number_decimal'),
	    'KEY23' => array('field_name'=>'numunits', 'field_label'=>'Number of Units', 'type'=>'number_decimal'),
	    'KEY24' => array('field_name'=>'agntid', 'field_label'=>'Agent ID', 'type'=>'text'),
	    'KEY25' => array('field_name'=>'agntname', 'field_label'=>'Agent Name', 'type'=>'text'),
	    'KEY26' => array('field_name'=>'agntphone', 'field_label'=>'Agent Phone', 'type'=>'text'),
	    'KEY27' => array('field_name'=>'officeid', 'field_label'=>'Office ID', 'type'=>'text'),
	    'KEY28' => array('field_name'=>'office', 'field_label'=>'Office', 'type'=>'text'),
	    'KEY29' => array('field_name'=>'officephone', 'field_label'=>'Office Phone', 'type'=>'text'),
	    'KEY30' => array('field_name'=>'subdivision', 'field_label'=>'Subdivision', 'type'=>'text'),
	    'KEY31' => array('field_name'=>'school', 'field_label'=>'School', 'type'=>'text'),
	    'KEY32' => array('field_name'=>'county', 'field_label'=>'County', 'type'=>'text'),
	    'KEY33' => array('field_name'=>'zonedist', 'field_label'=>'Zone - Disctrict', 'type'=>'text'),
	    'KEY34' => array('field_name'=>'legal', 'field_label'=>'Legal', 'type'=>'text_long'),
	    'KEY35' => array('field_name'=>'yrbuilt', 'field_label'=>'Year Built', 'type'=>'text'),
	    'KEY36' => array('field_name'=>'remodeled', 'field_label'=>'Year Remodeled', 'type'=>'text'),
	    'KEY37' => array('field_name'=>'totsqft', 'field_label'=>'Total Sq. Ft.', 'type'=>'text'),
	    'KEY38' => array('field_name'=>'bldg2totsqft', 'field_label'=>'Building 2 Sq. Ft.', 'type'=>'text'),
	    'KEY39' => array('field_name'=>'bldg3totsqft', 'field_label'=>'Building 3 Sq. Ft.', 'type'=>'text'),
	    'KEY40' => array('field_name'=>'finished', 'field_label'=>'Furnished', 'type'=>'text'),
	    'KEY41' => array('field_name'=>'unfinished', 'field_label'=>'Unfurnished', 'type'=>'text'),
	    'KEY42' => array('field_name'=>'remarks', 'field_label'=>'Remarks', 'type'=>'text_long'),
	    'KEY43' => array('field_name'=>'gargsize', 'field_label'=>'Garage Size', 'type'=>'text'),
	    'KEY44' => array('field_name'=>'gargcomments', 'field_label'=>'Garage Comments', 'type'=>'text_long'),
	    'KEY45' => array('field_name'=>'extdesc', 'field_label'=>'Extra Description', 'type'=>'text_long'),
	    'KEY46' => array('field_name'=>'sizecmnt', 'field_label'=>'Size Comment', 'type'=>'text_long'),
	    'KEY47' => array('field_name'=>'taxes1', 'field_label'=>'Taxes 1', 'type'=>'text'),
	    'KEY48' => array('field_name'=>'taxes1yr', 'field_label'=>'Taxes 1 Year', 'type'=>'text'),
	    'KEY49' => array('field_name'=>'taxes2', 'field_label'=>'Taxes 2', 'type'=>'text'),
	    'KEY50' => array('field_name'=>'taxes2yr', 'field_label'=>'Taxes 2 Year', 'type'=>'text'),
	    'KEY51' => array('field_name'=>'taxesper', 'field_label'=>'Taxes Per', 'type'=>'text'),
	    'KEY52' => array('field_name'=>'curuse', 'field_label'=>'Current Use', 'type'=>'text'),
	    'KEY53' => array('field_name'=>'wtrrights', 'field_label'=>'Water Rights', 'type'=>'text'),
	    'KEY54' => array('field_name'=>'constype', 'field_label'=>'Construction Type', 'type'=>'text'),
	    'KEY55' => array('field_name'=>'amenities', 'field_label'=>'Amenities', 'type'=>'text_long'),
	    'KEY56' => array('field_name'=>'virtour', 'field_label'=>'Virtual Tour', 'type'=>'text_long'),
	    'KEY57' => array('field_name'=>'dateinsert', 'field_label'=>'Date Inserted', 'type'=>'text'),
	    'KEY58' => array('field_name'=>'datemod', 'field_label'=>'Date Modified', 'type'=>'text'),
	    'KEY59' => array('field_name'=>'lotsizerange', 'field_label'=>'Lot Size Range', 'type'=>'text'),
	    'KEY60' => array('field_name'=>'lotsizeactual', 'field_label'=>'Lot Size Actual', 'type'=>'text'),
	    'KEY61' => array('field_name'=>'agnt2id', 'field_label'=>'Agent 2 ID', 'type'=>'text'),
	    'KEY62' => array('field_name'=>'agnt2name', 'field_label'=>'Agent 2 Name', 'type'=>'text'),
	    'KEY63' => array('field_name'=>'agnt2phone', 'field_label'=>'Agent 2 Phone', 'type'=>'text'),
	    'KEY64' => array('field_name'=>'office2id', 'field_label'=>'Office 2 ID', 'type'=>'text'),
	    'KEY65' => array('field_name'=>'office2', 'field_label'=>'Office 2', 'type'=>'text'),
	    'KEY66' => array('field_name'=>'office2phone', 'field_label'=>'Office 2 Phone', 'type'=>'text'),
	    ),
    'imagesavailable' => array('field_name'=>'images', 'field_label'=>'xxxx', 'type'=>'text'),
    'MD5' => array('field_name'=>'md5', 'field_label'=>'MD5', 'type'=>'int'),
    'feedurl'=> 'http://vail.interactiveproperties.com/vailAPI.php',
    'area' => 'vail'
    );
