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
  $destination = drupal_get_destination();
  $linkattributes = array(
  										'query' => array($destination),
  										'attributes' => array('class' => 'refresh-link',)
  										);
	$updatelink = 'Last updated MLS Listing: '.$lastupdated.'<br />';
	$resetlink = l('(reset)', 'admin/config/content/ramlisting/reset-que', $linkattributes);
	$updatelink .= 'Current Update Offset: '.$curoffset.'&nbsp;'.$resetlink.'<br />';


  $updatelink .= l('Execute Manual Import', 'admin/config/content/ramlisting/update', $linkattributes);
  
  $form['ramlisting_tools']['updatelink'] = array(
    '#prefix'       => '<div style="border:solid 1px #000000;padding:5px;margin-bottom:10px;"><b>Manual Listing Import</b><br />',
    '#markup'       => $updatelink,
    '#suffix'       => '</div>',
  );
  
  
  
  $listingresult = db_query("SELECT COUNT(*) FROM {node} WHERE type = 'ramlisting'")->fetchAssoc();
  $listingcount = $listingresult['count(*)'];
	$prefix = 'There are currently '.$listingcount.' listing nodes in the system.<br />';
	
  $purgelistingslink = l('Delete Listings', 'admin/config/content/ramlisting/purge-listings', $linkattributes);
  
  $form['ramlisting_tools']['purgelistingslink'] = array(
  '#prefix'       => '<div style="border:solid 1px #000000;padding:5px;margin-bottom:10px;"><b>'.t('Delete RAM Listing Nodes').'</b><br />'.$prefix,
    '#markup'       => $purgelistingslink,
    '#suffix'       => '<br /><div style="font-size:10px;line-height:12px;"><b>PLEASE NOTE:</b> Clicking this link will remove RAM listing nodes in batches of 100 to prevent server timeouts and memory overloads. This may require multiple invocations before all RAM listing nodes are removed. All listing nodes must be deleted prior to uninstalling this module.<br /><span style="color:#ff0000;">WARNING:</span> Invoking RAM listing node deletion here will also remove image files associated to the deleted nodes.</div></div>',
  );
  

	
	if($listingcount == 0){
		$purgelinkattributes = array(
			'attributes' => array('class' => 'refresh-link',)
		);
		$purgelink = l('Purge Current MLS', 'admin/config/content/ramlisting/purge', $purgelinkattributes);
	}else{
		
		$purgelink = 'All existing RAM Listing nodes must first be removed prior to purging the currently configured MLS. See <b>Delete RAM Lisitng Nodes</b> above.';
	}
  
  
  $form['ramlisting_tools']['purgelink'] = array(
  '#prefix'       => '<div style="border:solid 1px #000000;padding:5px;margin-bottom:10px;"><b>'.t('Purge Currently Configured MLS.').'</b><br />',
    '#markup'       => $purgelink,
    '#suffix'       => '<br /><div style="font-size:10px;line-height:12px;"><b>PLEASE NOTE:</b> Purging the currently configured MLS will removed fields and field instance associated with the currently configured MLS. It does not removed the ramlisting node type nor the base field (mlsnum, address, city, state, etc etc) installed with the module.</div></div>',
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