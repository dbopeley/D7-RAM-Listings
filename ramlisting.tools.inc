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


  
    $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 10,
    '#submit' => array('ramlisting_admin_tools_submit'),
  );
  
return $form;
   
}


function features_export_build_form_submit($form, &$form_state) {
	
	kpr($form_state);

}