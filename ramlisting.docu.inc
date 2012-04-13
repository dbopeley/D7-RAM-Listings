<?php

/**
 * @file
 * Content type editing UI.
 */

/**
 * Displays the content type admin overview page.
 */

function ramlisting_admin_docu($form, $form_state) {

  $form['ramlisting_docu_overview'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Overview'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE
  );

	
  
  $form['ramlisting_docu_overview']['overview'] = array(
    '#markup'       => '<div style="border:solid 1px #000000;padding:5px;margin-bottom:10px;">This module provides a framework for importing MLS property data from the RAM MLS service into a \'module created\' custom node type called a ramlisting. Upon install, the ramlisting node type is automatically created with the following base-fields configured:<ul><li>MLS Number (as the node title)</li><li>Price</li><li>Address</li><li>City</li></li><li>State</li><li>Zip</li><li>Images (type image:mulitple)</li><li>Is Featured</li></ul>The MLS Number, Price and Location fields should be common to any property belonging to any MLS Area. Properties may or may not have images but an image field that allows multiple images is also included on install. Finally an \'Is Featured\' Checkbox is included for obvious reasons. Beyond these 8 base field, configuration of the ramlisting node type is dependant entirely on the MLS Configuration file selected. More on MLS Configuration files below, but in short the configuration file is responsible for defining additional fields specific to the selected MLS.<br /><br />Once a configuration file has been selected, the admin can either enable the cron setting and allow cron to invoke import:create/update process OR can manually invoke the import:create/update process via the RAM Listing Tools Admin.</div>',
  );
  
  $form['ramlisting_docu_importing'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Importing Listings'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE
  );

	
  
  $form['ramlisting_docu_importing']['importing'] = array(
    '#markup'       => '<div style="border:solid 1px #000000;padding:5px;margin-bottom:10px;">As mentioned above, importing RAM MLS data can either occur automatically via cron or manually via the RAM Lisitng Tools Admin. To enable RAM Listing imports on cron simply check the \'Enable updates on cron\' check box on the RAM Listings Configuration Page. Imports on cron will not occur unless this box is checked. Alternately, one can manually invoke imports via the RAM Listing Tools page by clicking \'Execute Manual Import\'. Please Note: Whether by cron or manual import, the total number of listings that populate a single request to from RAM is determined by the \'Import/Update Threshold\' setting. We limit the number of listings that can be imported to avoid server timeouts and memory overloads. The values for this threshold are 10 - 100 (increments of 10).<br /><br />When the module is first enabled, listing imports will be <b>creating</b> nodes and uploading large amounts images files, hence as the import process makes its first pass over the entire list of MLS listings available it is a good idea to set the threshold at a middle to lower setting. Once the initial pass has been made over the entire MLS, this threshold can be set higher effectively speeding up the the rate at which properties update. This is possible because as the system makes subsquent passes over the MLS updates to the ramlisting nodes only occur if data in the matching listing imported from RAM has changed.<br /> <br /></div>',
  );  

return $form;
   
}

