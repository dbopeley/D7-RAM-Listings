<?php

/**
 * @file
 * Content administration and module settings UI.
 */

function ramlisting_admin_settings($form_state) {


	
	
  $form['ramlisting_config_fs'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('RAM MLS Feed and Field Mapping Configuration'),
    '#collapsible' => FALSE,
    '#collapsed'   => FALSE
  );
  

  $field_config_files = file_scan_directory(RAMLISTING_CONFIG_PATH,'/.*\.inc$/');
   

  $ram_field_mapping_file_options = array();
  $fileoptions['Select an Area'] = 'Select an Area';
  foreach ($field_config_files as $fileitem) {
  	
  	$fileitem_value = $fileitem->filename;
  	$fileitem_name = $fileitem->name;
  	
  	$fileitem_name_array = explode('.',$fileitem_name);
  	$fileitem_title = $fileitem_name_array[0];
  	
  	$fileoptions[$fileitem_value] =  $fileitem_title;
  }
  
  //kpr($ram_field_mapping_file_options);

  $curconfigfile = variable_get('ramlisting_config_file', null);
    




  if($curconfigfile){
		$curfilescopy = 'The following MLS area is currently in use:<br />';
$curfilescopy .= "<br /><b>$curconfigfile</b><br /><br />";
		
		$curfilescopy .= 'CAUTION: Unselecting the current configuration file will result in all conifguration file specific fields and instances as well as all existing ramlisting node being deleted';
		
  	
  }else{
  	
  	$curfilescopy = 'Please select the MLS area from the list below you wish to configure. Once selected and submitted, the module will automatically add the neccessary fields (as defined in the selected configuration file) to the ramlisting node type.';
  	
  }

  $form['ramlisting_config_fs']['ramlisting_config_curfilescopy'] = array(
		'#markup'          => $curfilescopy,
		'#weight'         => 5
	);
  
  
  $form['ramlisting_config_fs']['ramlisting_config_file'] = array(
		'#type'           => 'select',
		'#title'          => t( 'Select a Ram Field Mapping File.' ),
		'#description'    => t( 'The MLS file selected here will be used to define how the RAM MLS system maps data imported form the RAM MLS system to a local content type.' ),
		'#options'        => $fileoptions,
		'#default_value'  => $curconfigfile,
		'#multiple' => FALSE, 
		'#weight'         => 10
	);

	$form['ramlisting_update_perpage'] = array(
    '#type'             => 'select',
    '#title'            => t('Import/Update Threshold'),
    '#description'      => t('The value set here determines how many listings are updated per cron or manual Import (above).'),
    '#options'          => array(10=>'10',20=>'20',30=>'30',40=>'40',50=>'50',60=>'60',70=>'70',80=>'80',90=>'90',100=>'100'),
    '#default_value'    => variable_get('ramlisting_update_perpage', 50),
    '#weight'         => 20
  );
  
	
	
	$form['#validate'][] = 'ramlisting_admin_settings_validate' ;
	$form['#submit'][] = 'ramlisting_admin_settings_submit' ;
 return system_settings_form($form);
 

}

/**ramlisting_admin_settings
 * Submit handler for ram_admin_settings().
 */
function ramlisting_admin_settings_validate($form, &$form_state) {

	if($form_state['values']['ramlisting_config_file'] == 'Select an Area'){
		
		 form_set_error('ramlisting_config_file', t('Please select one of the available RAM Field Mapping files from the list below'));
    
	}

}

/**ramlisting_admin_settings
 * Submit handler for ram_admin_settings().
 */
function ramlisting_admin_settings_submit($form, &$form_state) {

	$submitted_config_file = $form_state['values']['ramlisting_config_file'];
	$current_config_file = variable_get('ramlisting_config_file', NULL);
	
	
/*
	
	if(!$current_config_files){
		
		$feedsadded = $submitted_config_files;
		
	}else{
		$feedsremoved = array_diff_key($current_config_files, $submitted_config_files);
		$feedsadded = array_diff_key($submitted_config_files, $current_config_files);
	}
	
*/	


	if($submitted_config_file){
		if($submitted_config_file == $current_config_file){
			
		}else{

			$feed_path_add = RAMLISTING_CONFIG_PATH.'/'.$submitted_config_file;
			include_once($feed_path_add);
			
			
			variable_set('ramlisting_imagebase',$config['imagebase'] );
  		variable_set('ramlisting_feeduri', $config['feeduri']);
  		variable_set('ramlisting_mlsarea', $config['area']);
  		variable_set('ramlisting_customfields_delete',$custom_fields_delete);

			$fieldscreated = ramlisting_create_fields($custom_fields);

			
		}
	}

	/*
	
	if(!empty($feedsremoved)){
		
		//kpr($feedsremoved);
		
		foreach ($feedsremoved as $removefeedfile) {

			$feed_path_remove = ramlisting_CONFIG_PATH.'/'.$removefeedfile;
			
			//kpr($feed_path_remove);
			
			
			//include_once($feed_path_remove);
			
			//kpr($config);
			//ramlisting_remove_feed_fields($feed_obj);
		}
	}
	*/
}



function ramlisting_create_fields($custom_fields) {
	
  foreach ($custom_fields as $fieldname => $fieldconfig) {
  	 	
		$fieldlabel = $fieldconfig['field_label'];
		$fieldtype = $fieldconfig['field_type'];
		$fieldflag = field_info_field($fieldname);
  	$instanceflag = field_info_instance('ramlisting', $fieldname, $fieldtype);
  	$settings = _ramlisting_config_field_instance_settings($fieldconfig);

	  if (empty($fieldflag)) {
	    $field = array(
	      'field_name' => $fieldname,
	      'type' => $fieldtype,
	    );
	    
	    if(!empty($settings['field'])){
	       $field['settings'] = $settings['field'];
	    }
			$fieldcreated = field_create_field($field);
	  }
	  

	  if (empty($instanceflag)) {
    
	  	$instance = array(
	      'field_name' => $fieldname,
	      'entity_type' => 'node',
	      'bundle' => 'ramlisting',
	      'label' => $fieldlabel,
	    	);
	    if(!empty($settings['instance']['widget'])){
	       $instance['widget'] = $settings['instance']['widget'];
	    }
	    if(!empty($settings['instance']['settings'])){
	       $instance['settings'] = $settings['instance']['settings'];
	    }
	    if(!empty($settings['instance']['display'])){
	       $instance['display'] = $settings['instance']['display'];
	    }

    	$instancecreated = field_create_instance($instance);
 		}
  		
  }
  return true;
}


function _ramlisting_config_field_instance_settings($fieldconfig){

	
	$fieldtype = $fieldconfig['field_type'];
	$fieldsettings = array();
	$widget = array();
	$instancesettings = array();
	$display = array();

	
	switch($fieldtype){
		
  		case'list_float':
  		case'list_integer':
  		case'list_text':
  			if($fieldconfig['allowed_values']){
  				$fieldsettings['allowed_values'] = $fieldconfig['allowed_values'];
  			}
  			if($fieldconfig['widget_type']){
					$widget['type'] = $fieldconfig['widget_type'];
				}
  		break;
  		
  		case'number_integer':
  			if($fieldconfig['widget_type']){
					$widget['type'] = $fieldconfig['widget_type'];
				}
  		break;
  		
  		case'number_decimal':
  			if($fieldconfig['precision']){
  				$fieldsettings['precision'] = $fieldconfig['precision'];
  			}
  			if($fieldconfig['scale']){
  				$fieldsettings['scale'] = $fieldconfig['scale'];
  			}
  			if($fieldconfig['widget_type']){
					$widget['type'] = $fieldconfig['widget_type'];
				}
  		break;
  		
  		case'text':
  			/* this should be added to config file to create more efficient table
  			if($fieldconfig['max_length']){
  				$fieldsettings['max_length'] = $fieldconfig['max_length'];
  			}
  			*/
  			if($fieldconfig['widget_type']){
					$widget['type'] = $fieldconfig['widget_type'];
				}
  		break;
  		case'text_long':
  			if($fieldconfig['widget_type']){
					$widget['type'] = $fieldconfig['widget_type'];
				}
  		break;		
  	}
  	
  	$settings['field'] = $fieldsettings;
  	
  	if(!empty($widget)){
  		$settings['instance']['widget'] = $widget;
  	}
  	if(!empty($instancesettings)){
  	$settings['instance']['settings'] = $instancesettings;
  	}
  	if(!empty($display)){
  	$settings['instance']['display'] = $display;
  	}
	return $settings;
}