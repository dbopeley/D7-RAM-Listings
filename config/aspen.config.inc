<?php
/**
 * @file aspen.field_mapping.inc
 * An Associative Array of station information from MLS
 */

$classification_options = array( 
		'Residential' => 'Residential', 
		'Commercial' =>'Commercial', 
		'Land' => 'Land',
		);
		
$type_options = array(
	'Single Family' => 'Single Family',
	'Condo/Townhouse' => 'Condo/Townhouse',
	'Duplex/Half Duplex' => 'Duplex/Half Duplex',
	'Fractional Owners' => 'Fractional Owners',
	'Mobile Home' => 'Mobile Home',
	'Commercial/Income' => 'Commercial/Income',
	'Lease Hold' => 'Lease Hold',
	'Business Opportunity' => 'Business Opportunity',
	'Lodge' => 'Lodge',
	'Single Family Lot' => 'Single Family Lot',
	'Farm/Ranch' => 'Farm/Ranch',
	'Unimproved/Comm' => 'Unimproved/Comm',
	'Duplex/Multi-Lot' => 'Duplex/Multi-Lot'	
	);
	
	
	
$bedroom_options = array(
	0 => 'Studio',
	1 => 'One',
	2 => 'Two',
	3 => 'Three',
	4 => 'Four',
	5 => 'Five',
	6 => 'Six',
	7 => 'Seven',
	8 => 'Eight',
	9 => 'Nine Or More',
	);
	
	
$bath_options = array(
	'One' => 'One',
	'Two' => 'Two',
	'Three' => 'Three',
	'Four' => 'Four',
	'Five' => 'Five',
	'Six Or More' => 'Six Or More',
	);
	
$hlfbath_options = array(
	'None' => 'None',
	'One' => 'One',
	'Two' => 'Two',
	'Three' => 'Three',
	'Four' => 'Four',
	'Five' => 'Five',
	'Six Or More' => 'Six Or More'
	);

$field_map = array(
'key1' => 'title', //int(11)
'key2' => array('fieldname'=>'field_ramlisting_class','fieldformat' => ''),
'key3' => array('fieldname'=>'field_ramlisting_type','fieldformat' => ''),	
'key4' => array('fieldname'=>'field_ramlisting_area','fieldformat' => ''), //varchar(50)
'key5' => array('fieldname'=>'field_ramlisting_price','fieldformat' => ''), //int(11)
'key6' => array('fieldname'=>'field_ramlisting_address','fieldformat' => ''), //tinytext
'key7' => array('fieldname'=>'field_ramlisting_city','fieldformat' => ''), //varchar(50)
'key8' => array('fieldname'=>'field_ramlisting_state','fieldformat' => ''), //char(2)
'key9' => array('fieldname'=>'field_ramlisting_zip','fieldformat' => ''), //varchar(15)
'key10' => array('fieldname'=>'field_ramlisting_status','fieldformat' => ''), //varchar(30)
'key11' => array('fieldname'=>'field_ramlisting_salerent','fieldformat' => ''), //enum('S','R')
'key12' => array('fieldname'=>'field_ramlisting_beds','fieldformat' => ''), //enum('Studio','One','Two','Three','Four','Five','Six','Seven','Eight','Nine Or More')
'key13' => array('fieldname'=>'field_ramlisting_baths','fieldformat' => ''), //enum('One','Two','Three','Four','Five','Six Or More')
'key14' => array('fieldname'=>'field_ramlisting_hlfbaths','fieldformat' => ''), //enum('None','One','Two','Three','Four','Five','Six Or More')
'key15' => array('fieldname'=>'field_ramlisting_gargcap','fieldformat' => ''), //varchar(30)
'key16' => array('fieldname'=>'field_ramlisting_gargtype','fieldformat' => ''), //varchar(30)
'key17' => array('fieldname'=>'field_ramlisting_levels','fieldformat' => ''), //varchar(30)
'key18' => array('fieldname'=>'field_ramlisting_basement','fieldformat' => ''), //varchar(30)
'key19' => array('fieldname'=>'field_ramlisting_condition','fieldformat' => ''), //varchar(30)
'key20' => array('fieldname'=>'field_ramlisting_reservations','fieldformat' => ''), //enum('Yes','No')
'key21' => array('fieldname'=>'field_ramlisting_acreage','fieldformat' => ''), //float
'key22' => array('fieldname'=>'field_ramlisting_ppacre','fieldformat' => ''), //int(11)
'key23' => array('fieldname'=>'field_ramlisting_units','fieldformat' => ''), //int(11)
'key24' => array('fieldname'=>'field_ramlisting_agentid','fieldformat' => ''), //int(11)
'key25' => array('fieldname'=>'field_ramlisting_agentname','fieldformat' => ''), //tinytext
'key26' => array('fieldname'=>'field_ramlisting_agentphone','fieldformat' => ''), //varchar(30)
'key27' => array('fieldname'=>'field_ramlisting_officeid','fieldformat' => ''), //int(11)
'key28' => array('fieldname'=>'field_ramlisting_officename','fieldformat' => ''), //tinytext
'key29' => array('fieldname'=>'field_ramlisting_officephone','fieldformat' => ''), //varchar(30)
'key30' => array('fieldname'=>'field_ramlisting_subdivision','fieldformat' => ''), //tinytext
'key31' => array('fieldname'=>'field_ramlisting_school','fieldformat' => ''), //tinytext
'key32' => array('fieldname'=>'field_ramlisting_county','fieldformat' => ''), //tinytext
'key33' => array('fieldname'=>'field_ramlisting_zonedistrict','fieldformat' => ''), //varchar(50)
'key34' => array('fieldname'=>'field_ramlisting_legal','fieldformat' => ''), //tinytext
'key35' => array('fieldname'=>'field_ramlisting_yearbuilt','fieldformat' => ''), //int(11)
'key36' => array('fieldname'=>'field_ramlisting_yearremodeled','fieldformat' => ''), //int(11)
'key37' => array('fieldname'=>'field_ramlisting_sqft','fieldformat' => ''), //int(11)
'key38' => array('fieldname'=>'field_ramlisting_bldg2sqft','fieldformat' => ''), //int(11)
'key39' => array('fieldname'=>'field_ramlisting_bldg3sqft','fieldformat' => ''), //int(11)
'key40' => array('fieldname'=>'field_ramlisting_finished','fieldformat' => ''), //varchar(10)
'key41' => array('fieldname'=>'field_ramlisting_unfinished','fieldformat' => ''), //varchar(10)
'key42' => array('fieldname'=>'field_ramlisting_remarks','fieldformat' => ''), //text
'key43' => array('fieldname'=>'field_ramlisting_garagesize','fieldformat' => ''), //tinytext
//'key44' => array('fieldname'=>'field_ramlisting_garagecomments','fieldformat' => 'text_long'), //tinytext **deprecated
//'key45' => array('fieldname'=>'field_ramlisting_extradescript','fieldformat' => 'text_long'), //tinytext **deprecated
//'key49' => array('fieldname'=>'field_ramlisting_sizecomment','fieldformat' => 'text_long'), //tinytext **deprecated

'key47' => array('fieldname'=>'field_ramlisting_taxes1','fieldformat' => ''), //varchar(20)
'key48' => array('fieldname'=>'field_ramlisting_taxes1yr','fieldformat' => ''), //int(11)
'key49' => array('fieldname'=>'field_ramlisting_taxes2','fieldformat' => ''), //varchar(20)
'key50' => array('fieldname'=>'field_ramlisting_taxes2yr','fieldformat' => ''), //int(11)
'key52' => array('fieldname'=>'field_ramlisting_currentuse','fieldformat' => ''), //tinytext
'key53' => array('fieldname'=>'field_ramlisting_waterrights','fieldformat' => ''), //tinytext
'key54' => array('fieldname'=>'field_ramlisting_constype','fieldformat' => ''), //tinytext
'key55' => array('fieldname'=>'field_ramlisting_amenities','fieldformat' => ''), //text
'key56' => array('fieldname'=>'field_ramlisting_virtualtour','fieldformat' => ''), //tinytext
'key57' => array('fieldname'=>'field_ramlisting_dateinserted','fieldformat' => ''), //date
'key58' => array('fieldname'=>'field_ramlisting_datemodified','fieldformat' => ''), //date
'key59' => array('fieldname'=>'field_ramlisting_lotsizerange','fieldformat' => ''), //tinytext
'key60' => array('fieldname'=>'field_ramlisting_lotsizeactual','fieldformat' => ''), //tinytext
'key61' => array('fieldname'=>'field_ramlisting_agentid2','fieldformat' => ''), //int(11)
'key62' => array('fieldname'=>'field_ramlisting_agentname2','fieldformat' => ''), //tinytext
'key63' => array('fieldname'=>'field_ramlisting_agentphone2','fieldformat' => ''), //varchar(30)
'key67' => array('fieldname'=>'field_ramlisting_hoafees','fieldformat' => ''), //varchar(20)
'key68' => array('fieldname'=>'field_ramlisting_specassess','fieldformat' => ''), //varchar(20)
'key71' => array('fieldname'=>'field_ramlisting_lat','fieldformat' => ''), //varchar(20)
'key72' => array('fieldname'=>'field_ramlisting_lon','fieldformat' => ''), //varchar(20)
'key74' => array('fieldname'=>'field_ramlisting_foreclosure','fieldformat' => ''), //varchar(20)
'key75' => array('fieldname'=>'field_ramlisting_shortsale','fieldformat' => ''), //varchar(20)
'key76' => array('fieldname'=>'field_ramlisting_reo','fieldformat' => ''), //varchar(20)
//'key67' => array('fieldname'=>'field_ramlisting_officeid2','fieldformat' => 'number_integer'), //int(11) **deprecated
//'key68' => array('fieldname'=>'field_ramlisting_officename2','fieldformat' => 'text'), //tinytext **deprecated
//'key69' => array('fieldname'=>'field_ramlisting_officephone2','fieldformat' => 'text'), //varchar(30) **deprecated
'imagesavailable' => array('fieldname'=>'field_ramlisting_imagesavail','fieldformat' => ''),
);

	
	
$custom_fields = array(

'field_ramlisting_class' => array(
		'field_label'=>'Property Classification',
		'field_type'=>'list_text',
		'allowed_values'=> $classification_options,
		'widget_type'=> 'options_select',), //varchar(50)


'field_ramlisting_type' => array(
		'field_label'=>'Property Type',
		'field_type'=>'list_text',
		'allowed_values'=> $type_options,
		'widget_type'=> 'options_select',), //varchar(50)

'field_ramlisting_area' => array(
		'field_label'=>'Area',
		'field_type'=>'text',
		'widget_type'=> 'text_textfield',), //varchar(50)
		
'field_ramlisting_status' => array(
		'field_label'=>'Status', 
		'field_type'=>'text', 
		'widget_type'=>'text_textfield',), //varchar(30)
			
'field_ramlisting_salerent' => array(
		'field_label'=>'Sale Rent', 
		'field_type'=>'text', 
		'widget_type'=>'text_textfield',), //enum('S','R')

'field_ramlisting_beds' => array(
		'field_label'=>'Number of Bedrooms', 
	  'field_type'=>'list_integer', 
		'allowed_values'=> $bedroom_options,
		'widget_type'=> 'options_select',),

'field_ramlisting_baths' => array(
		'field_label'=>'Number of Full Bathrooms', 
	  'field_type'=>'list_text', 
		'allowed_values'=> $bath_options,
		'widget_type'=> 'options_select',), 	
		
'field_ramlisting_hlfbaths' => array(
		'field_label'=>'Number of Half Bathrooms', 
	  'field_type'=>'list_text', 
		'allowed_values'=> $hlfbath_options,
		'widget_type'=> 'options_select',), 
		
'field_ramlisting_gargcap' => array(
		'field_label'=>'Garage Capacity', 
		'field_type'=>'text', 
		'widget_type'=>'text_textfield',), //varchar(30)


'field_ramlisting_gargtype' => array(
		'field_label'=>'Garage Type',
		'field_type'=>'text',
		'widget_type'=>'text_textfield',), //varchar(30)

'field_ramlisting_sqft' => array(
		'field_label'=>'Square Footage',
		'field_type'=>'number_integer',
		'widget_type'=>'number',), //int(11)

'field_ramlisting_levels' => array(
		'field_label'=>'Levels',
		'field_type'=>'text',
		'widget_type'=>'text_textfield',), //varchar(30)


'field_ramlisting_basement' => array(
		'field_label'=>'Basement',
		'field_type'=>'text',
		'widget_type'=>'text_textfield',), //varchar(30)

'field_ramlisting_condition' => array(
		'field_label'=>'Condition', 
		'field_type'=>'text', 
		'widget_type'=>'text_textfield',), //varchar(30)

'field_ramlisting_reservations' => array(		
		'field_label'=>'Reservations', 
	  'field_type'=>'list_text', 
		'allowed_values'=>array('yes','no'),
		'widget_type'=> 'options_buttons',), //enum('Yes','No')

		
'field_ramlisting_acreage' => array(
		'field_label'=>'Acreage',
		'field_type'=>'number_float',
		'precision' => 10,
		'scale' => 2,
		'widget_type'=>'number',), //int(11)

'field_ramlisting_ppacre' => array(
		'field_label'=>'Price Per Acre',
		'field_type'=>'number_integer',
		'widget_type'=>'number',), //int(11)

'field_ramlisting_units' => array(
		'field_label'=>'Number of Units',
		'field_type'=>'number_integer',
		'widget_type'=>'number',), //int(11)
	
'field_ramlisting_agentid' => array(	
		'field_label'=>'Agent ID',
		'field_type'=>'text',
		'widget_type'=>'text_textfield',), //int(11)
	
'field_ramlisting_agentname' => array(
		'field_label'=>'Agent Name', 
		'field_type'=>'text', 
		'widget_type'=>'text_textfield',), //tinytext

'field_ramlisting_agentphone' => array(
		'field_label'=>'Agent Phone',
		'field_type'=>'text',
		'widget_type'=>'text_textfield',), //varchar(30)
	
'field_ramlisting_officeid' => array(
		'field_label'=>'Office ID',
		'field_type'=>'text',
		'widget_type'=>'text_textfield',), //int(11)

'field_ramlisting_officename' => array(
	'field_label'=>'Office Name',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //tinytext
	
'field_ramlisting_officephone' => array(
	'field_label'=>'Office Phone',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(30)

'field_ramlisting_subdivision' => array(
	'field_label'=>'Subdivision',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //tinytext
	
'field_ramlisting_school' => array(
	'field_label'=>'School District',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //tinytext
	
'field_ramlisting_county' => array(
	'field_label'=>'County',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //tinytext
	
'field_ramlisting_zonedistrict' => array(
	'field_label'=>'Zone District',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(50)

'field_ramlisting_legal' => array(
	'field_label'=>'Legal', 
	'field_type'=>'text_long', 
	'widget_type'=>'text_textarea',), //tinytext

'field_ramlisting_yearbuilt' => array(
	'field_label'=>'Year Built',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(50)
	
'field_ramlisting_yearremodeled' => array(
	'field_label'=>'Year Remodeled',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(50)

'field_ramlisting_bldg2sqft' => array(
	'field_label'=>'Building 2 Sqft.',
	'field_type'=>'number_integer',
	'widget_type'=>'number',), //int(11)
	
'field_ramlisting_bldg3sqft' => array(
	'field_label'=>'Building 3 Sqft',
	'field_type'=>'number_integer',
	'widget_type'=>'number',), //int(11)
	
'field_ramlisting_finished' => array(
	'field_label'=>'Finished',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(10)
	
'field_ramlisting_unfinished' => array(
	'field_label'=>'Unfinished',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(10)

'field_ramlisting_remarks' => array(	
		'field_label'=>'Remarks', 
		'field_type'=>'text_long', 
		'widget_type'=>'text_textarea',), //tinytext
		
'field_ramlisting_garagesize' => array(
	'field_label'=>'Garage Size', 
	'field_type'=>'text', 
	'widget_type'=>'text_textfield',
	), //tinytext

/* deprecated
'field_ramlisting_garagecomments' => array(
		'field_label'=>'Garage Comments',
		'field_type'=>'text_long', 
		'widget_type'=>'text_textarea',), //tinytext
		*/

/* deprecated		
'field_ramlisting_extradescript' => array(
		'field_label'=>'Extra Description',
		'field_type'=>'text_long', 
		'widget_type'=>'text_textarea',), //tinytext
*/	

/* deprecated		
'field_ramlisting_sizecomment' => array(		
		'field_label'=>'Size Comments',
		'field_type'=>'text_long', 
		'widget_type'=>'text_textarea',), //tinytext
*/

'field_ramlisting_taxes1' => array(
	'field_label'=>'Taxes 1', 
	'field_type'=>'text', 
	'widget_type'=>'text_textfield',), //varchar(20)

'field_ramlisting_taxes1yr' => array(
	'field_label'=>'Taxes 1 Year', 
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(50)

'field_ramlisting_taxes2' => array(
	'field_label'=>'Taxes 2',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(20)

'field_ramlisting_taxes2yr' => array(
	'field_label'=>'Taxes 2 Year',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(50)

'field_ramlisting_taxesper' => array(
	'field_label'=>'Taxes Per',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(20)


'field_ramlisting_currentuse' => array(
	'field_label'=>'Current Use',
	'field_type'=>'text_long', 
	'widget_type'=>'text_textarea',), //tinytext
		
'field_ramlisting_waterrights' => array(
	'field_label'=>'Water Rights',
	'field_type'=>'text_long', 
	'widget_type'=>'text_textarea',), //tinytext
		
'field_ramlisting_constype' => array(
	'field_label'=>'Construction Type',
	'field_type'=>'text_long', 
	'widget_type'=>'text_textarea',), //tinytext
		
'field_ramlisting_amenities' => array(		
	'field_label'=>'Amenities',
	'field_type'=>'text_long', 
	'widget_type'=>'text_textarea',), //tinytext


'field_ramlisting_virtualtour' => array(
	'field_label'=>'Virtual Tour',
	'field_type'=>'text_long', 
	'widget_type'=>'text_textarea',), //tinytext
			
'field_ramlisting_dateinserted' => array(
	'field_label'=>'Date Inserted',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //date


'field_ramlisting_datemodified' => array(
	'field_label'=>'Date Modified',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //date

'field_ramlisting_lotsizerange' => array(
	'field_label'=>'Lot Size Range',
	'field_type'=>'text_long', 
	'widget_type'=>'text_textarea',), //tinytext
		
'field_ramlisting_lotsizeactual' => array(		
	'field_label'=>'Actual Lot Size',
	'field_type'=>'text_long', 
	'widget_type'=>'text_textarea',), //tinytext
		
'field_ramlisting_agentid2' => array(
	'field_label'=>'Agent 2 ID',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //int(11)

'field_ramlisting_agentname2' => array(
	'field_label'=>'Agent 2 Name', 
	'field_type'=>'text', 
	'widget_type'=>'text_textfield',), //tinytext

'field_ramlisting_agentphone2' => array(
	'field_label'=>'Agent 2 Phone',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(30)
	
	
'field_ramlisting_hoafees' => array(
	'field_label'=>'HOA fees',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(30)
	
	
'field_ramlisting_specassess' => array(
	'field_label'=>'Special Assessment',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(30)
	
	
'field_ramlisting_lat' => array(
	'field_label'=>'Latitude',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(30)
	
'field_ramlisting_lon' => array(
	'field_label'=>'Longitude',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(30)

'field_ramlisting_foreclosure' => array(
	'field_label'=>'Foreclosure',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(30)
	
'field_ramlisting_shortsale' => array(
	'field_label'=>'Short Sale',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(30)

'field_ramlisting_reo' => array(
	'field_label'=>'Real Estate Owned',
	'field_type'=>'text',
	'widget_type'=>'text_textfield',), //varchar(30)
	
	
'field_ramlisting_imagesavail' => array(
	'field_label'=>'Image List',
	'field_type'=>'text_long',
	'widget_type'=>'text_textarea',), //varchar(30)

	
/* **deprecated
'field_ramlisting_officeid2' => array(
		'field_label'=>'Office 2 ID',
		'field_type'=>'number_integer',
		'widget_type'=>'number',), //int(11)
		*/

/**deprecated
'field_ramlisting_officename2' => array(
		'field_label'=>'Office 2 Name', 
		'field_type'=>'text', 
		'widget_type'=>'text_textfield',), //tinytext ??
		*/
/**deprecated
'field_ramlisting_officephone2' => array(
		'field_label'=>'Office 2 Phone',
		'field_type'=>'text',
		'widget_type'=>'text_textfield',), //varchar(30)
	*/

	);

$config = array(
    'conx'=> 'http://aspen.interactiveproperties.com/aspenAPI.php',
    'imagebase' =>'http://aspen.interactiveproperties.com/images/listings/aspen',
    'area' => 'aspen'
  );




$custom_fields_delete = array(
'field_ramlisting_class' => 'field_ramlisting_class', //varchar(50)
'field_ramlisting_type' => 'field_ramlisting_type', //varchar(50)
'field_ramlisting_area' => 'field_ramlisting_area', //varchar(50)
'field_ramlisting_status' => 'field_ramlisting_status', //varchar(30)
'field_ramlisting_salerent' => 'field_ramlisting_salerent', //enum('S','R')
'field_ramlisting_beds' => 'field_ramlisting_beds',
'field_ramlisting_baths' => 'field_ramlisting_baths', 	
'field_ramlisting_hlfbaths' => 'field_ramlisting_hlfbaths', 
'field_ramlisting_gargcap' => 'field_ramlisting_gargcap', //varchar(30)
'field_ramlisting_gargtype' => 'field_ramlisting_gargtype', //varchar(30)
'field_ramlisting_sqft' => 'field_ramlisting_sqft', //int(11)
'field_ramlisting_levels' => 'field_ramlisting_levels', //varchar(30)
'field_ramlisting_basement' => 'field_ramlisting_basement', //varchar(30)
'field_ramlisting_condition' => 'field_ramlisting_condition', //varchar(30)
'field_ramlisting_reservations' => 'field_ramlisting_reservations' , //enum('Yes','No')
'field_ramlisting_acreage' => 'field_ramlisting_acreage', //int(11)
'field_ramlisting_ppacre' => 'field_ramlisting_ppacre', //int(11)
'field_ramlisting_units' => 'field_ramlisting_units', //int(11)
'field_ramlisting_agentid' => 'field_ramlisting_agentid', //int(11)
'field_ramlisting_agentname' => 'field_ramlisting_agentname' , //tinytext
'field_ramlisting_agentphone' => 'field_ramlisting_agentphone' , //varchar(30)
'field_ramlisting_officeid' => 'field_ramlisting_officeid', //int(11)
'field_ramlisting_officename' => 'field_ramlisting_officename', //tinytext
'field_ramlisting_officephone' => 'field_ramlisting_officephone', //varchar(30)
'field_ramlisting_subdivision' => 'field_ramlisting_subdivision', //tinytext
'field_ramlisting_school' => 'field_ramlisting_school', //tinytext
'field_ramlisting_county' => 'field_ramlisting_county', //tinytext
'field_ramlisting_zonedistrict' => 'field_ramlisting_zonedistrict', //varchar(50)
'field_ramlisting_legal' => 'field_ramlisting_legal', //tinytext
'field_ramlisting_yearbuilt' => 'field_ramlisting_yearbuilt', //int(11)
'field_ramlisting_yearremodeled' => 'field_ramlisting_yearremodeled', //int(11)
'field_ramlisting_bldg2sqft' => 'field_ramlisting_bldg2sqft' , //int(11)
'field_ramlisting_bldg3sqft' => 'field_ramlisting_bldg3sqft', //int(11)
'field_ramlisting_finished' => 'field_ramlisting_finished', //varchar(10)
'field_ramlisting_unfinished' =>'field_ramlisting_unfinished', //varchar(10)
'field_ramlisting_remarks' => 'field_ramlisting_remarks', //tinytext
'field_ramlisting_garagesize' => 'field_ramlisting_garagesize', //tinytext

/* deprecated
'field_ramlisting_garagecomments' => 'field_ramlisting_garagecomments' , //tinytext
*/

/* deprecated		
'field_ramlisting_extradescript' => 'field_ramlisting_extradescript', //tinytext
*/	

/* deprecated		
'field_ramlisting_sizecomment' => 'field_ramlisting_sizecomment', //tinytext
*/

'field_ramlisting_taxes1' => 'field_ramlisting_taxes1', //varchar(20)
'field_ramlisting_taxes1yr' => 'field_ramlisting_taxes1yr' , //int(11)
'field_ramlisting_taxes2' => 'field_ramlisting_taxes2', //varchar(20)
'field_ramlisting_taxes2yr' => 'field_ramlisting_taxes2yr', //int(11)
'field_ramlisting_taxesper' => 'field_ramlisting_taxesper', //varchar(20)
'field_ramlisting_currentuse' => 'field_ramlisting_currentuse', //tinytext
'field_ramlisting_waterrights' => 'field_ramlisting_waterrights', //tinytext
'field_ramlisting_constype' => 'field_ramlisting_constype', //tinytext
'field_ramlisting_amenities' => 'field_ramlisting_amenities', //tinytext
'field_ramlisting_virtualtour' => 'field_ramlisting_virtualtour', //tinytext
'field_ramlisting_dateinserted' => 'field_ramlisting_dateinserted', //date
'field_ramlisting_datemodified' => 'field_ramlisting_datemodified', //date
'field_ramlisting_lotsizerange' => 'field_ramlisting_lotsizerange', //tinytext		
'field_ramlisting_lotsizeactual' => 'field_ramlisting_lotsizeactual', //tinytext
'field_ramlisting_agentid2' => 'field_ramlisting_agentid2', //int(11)
'field_ramlisting_agentname2' => 'field_ramlisting_agentname2', //tinytext
'field_ramlisting_agentphone2' => 'field_ramlisting_agentphone2', //varchar(30)
'field_ramlisting_hoafees' => 'field_ramlisting_hoafees', //varchar(30)
'field_ramlisting_specassess' => 'field_ramlisting_specassess', //varchar(30)
'field_ramlisting_lat' => 'field_ramlisting_lat' , //varchar(30)
'field_ramlisting_lon' => 'field_ramlisting_lon', //varchar(30)
'field_ramlisting_foreclosure' => 'field_ramlisting_foreclosure', //varchar(30)
'field_ramlisting_shortsale' => 'field_ramlisting_shortsale', //varchar(30)
'field_ramlisting_reo' => 'field_ramlisting_reo',
'field_ramlisting_imagesavail' => 'field_ramlisting_imagesavail',
);	