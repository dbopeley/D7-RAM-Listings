<?php

/**
 * @file
 * Content type editing UI.
 */

/**
 * Displays the content type admin overview page.
 */

function ramlisting_admin_tools($form, $form_state) {

  $form['ramlisting_tools'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('RAM Listing Management Tools'),
    '#collapsible' => FALSE,
    '#collapsed'   => FALSE
  );
  
  $lastupdated = 	variable_get('ramlisting_last_updated_mlsnum', 0);
   $curoffset = 	variable_get('ramlisting_update_offset', 0);

	$updatelink = 'Last updated MLS Listing: '.$lastupdated.'<br />';
	$updatelink .= 'Current Update Offset: '.$curoffset.'<br />';
	$destination = drupal_get_destination();
  $linkattributes = array(
  										'query' => array($destination),
  										'attributes' => array('class' => 'refresh-link',)
  										);
  $updatelink .= l('Execute Manual Import', 'admin/config/content/ramlisting/update', $linkattributes);
  $form['ramlisting_tools']['updatelink'] = array(
    '#prefix'       => '<div style="border:solid 1px #000000;padding:5px;margin-bottom:10px;">',
    '#markup'       => $updatelink,
      '#suffix'       => '</div>',
  );
  
    $purgelink = l('Purge Current MLS', 'admin/config/content/ramlisting/purge', $linkattributes);
  $form['ramlisting_tools']['purgelink'] = array(
  '#prefix'       => '<div style="border:solid 1px #000000;padding:5px;margin-bottom:10px;">'.t('Completely purge currently configured mls settings.').'<br />',
    '#markup'       => $purgelink,
    '#suffix'       => '</div>',
  );

  $form['ramlisting_tools_fs'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Import/Update an Individual MLS Listing'),
    '#collapsible' => FALSE,
    '#collapsed'   => FALSE
  );
  
  
	$form['ramlisting_tools_fs']['mlsnum'] = array(
	  '#type' => 'textfield', 
	  '#title' => t('MLS Number'), 
	  '#description' => t('You may optionally import a new or update an existing MLS Listing by entering the MLS number here and clicking submit. This may be useful when a listing has recently been updated or added to the configure MLS service and you would prefer not to wait for the update que to roll around to it before it updates locally.'),
	  '#default_value' => '', 
	  '#size' => 30, 
	  '#maxlength' => 30, 
	  '#required' => FALSE,
	
	);
  
  
  $form['submit'] = array(
	  '#type' => 'submit',
	  '#value' => t('Save'),
	  '#weight' => 10,
	  '#submit' => array('ramlisting_admin_tools_submit'),
	);
	
		$form['#validate'][] = 'ramlisting_admin_tools_validate' ;	
  
return $form;
   
}

/**ramlisting_admin_settings
 * Submit handler for ram_admin_settings().
 */
function ramlisting_admin_tools_validate($form, &$form_state) {

$mlsnum = $form_state['values']['mlsnum'];
	if($mlsnum != ''){
		ramlisting_execute_listing_update($mlsnum);
	}else{
		
		drupal_set_message(t("Please enter a valid MLS number of the listing you wish to update or import."), 'warning');
	}
	
}


/**ramlisting_admin_settings
 * Submit handler for ram_admin_settings().
 */
function ramlisting_admin_tools_submit($form, &$form_state) {


}