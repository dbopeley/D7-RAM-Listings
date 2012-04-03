<?php
/**
 * This class encapsulates and provides a consistent interface to the RAM API.
 * 
 * @author John Ensign<john@bluetent.com>
 * @since Mon Nov 12 18:23:47 MST 2007
 * @version 1.0
 * @copyright 2007 Blue Tent Marketing LLC
 */

class Ram
{
	private $field_file = 'config/aspen.config.inc';
	private $feature_file = 'features.inc';
	
	private $connection_url;
	private $image_url;
	private $region_id;
	private $system_path;
	private $amenities;
	private $fields;
	private $features;

	public function __construct( $connection_url, $image_url, $region_id )
	{
		$this->connection_url = $connection_url;
		$this->image_url = $image_url;
		$this->region_id = $region_id;
			
		$this->system_path = dirname( __FILE__ ) ;
		
		$this->getFieldMap();
	}

	private function getFieldMap()
	{
		require_once( $this->system_path . '/' . $this->field_file );
		$this->fieldmap = $field_map;
	}

	private function getNormalizedData( $result_set )
	{
		$properties = array();
		$fieldmapping = $this->fieldmap;
		foreach ( $result_set->item as $result ) 
		{		
			$property = array();

			
			foreach ($result->children() as $key => $fieldvalue) {
				$fieldfilter = array('title','field_ramlisting_images');
				if(array_key_exists($key, $fieldmapping)){
					
					if(!in_array($fieldmapping[$key], $fieldfilter)){
						$fieldname = $fieldmapping[$key]['fieldname'];
						$fieldformat = $fieldmapping[$key]['fieldformat'];
						$fielddata = array('fieldvalue' => urldecode((string)$fieldvalue), 'fieldformat' => $fieldformat );
					}else{
						
						$fieldname = $fieldmapping[$key];
						$fielddata = urldecode((string)$fieldvalue);
					}
					
					
					$property[ $fieldname ] = $fielddata;
				}

			}
			
			
			
			
			// get MLS #
		/*	$property[ 'mls_num' ] = (int)$result->key1;
			
			// get type
			$property[ 'type' ] = (string)$result->key2; 
			
			// get area
			$area = $result->key4;
			$area = str_replace('+', ' ', $area);
			$area = str_replace('%2F', ' / ', $area);
			$area = explode( '-', $area );			
			
			$property[ 'area' ] = $area[1];
			
			// get address
			$prop_type = (string)$result->key3;
			$prop_type = urldecode( $prop_type );
			$property[ 'property_type' ] = $prop_type;
			
			// physicall address
			$phys_add = $result->key6;
			$phys_add = str_replace('+', ' ', $phys_add);
			$property[ 'address_physical' ] = urldecode($phys_add);
			
			// city
			$property[ 'city' ] = (string)$result->key7;
			
			// state
			$proptery[ 'state' ] = (string)$result->key8;
			
			// zipcode
			$property[ 'zipcode' ] = (string)$result->key9;
			
			// description, also decode it
			$descs = $result->key42;
			$desc = str_replace('+', ' ', $descs);
			$property[ 'description' ] = urldecode($desc);
			
			// get price and format it in US Dollar format
			$price = $result->key5;
			$price = trim($price);
			setlocale(LC_MONETARY, 'en_US');
			$property[ 'price' ] = '$' . number_format( $price);
			
			// bedrooms
			$property[ 'bedrooms' ] = urldecode( (string)$result->key12 );
			
			//echo '<!--  beds (key12): ' . $property[ 'bedrooms' ] . ' -->';
			
			// full baths
			$property[ 'full_baths' ] = urldecode( (string)$result->key13 );
			
			//echo '<!--  baths (key13): ' . $property[ 'full_baths' ] . '\n\r -->';
			
			// half baths
			$property[ 'half_baths' ] = urldecode(  (string)$result->key14 );
			
			// get garage info
			$property[ 'garage_size' ] = urldecode( (string)$result->key15);
			
			// parking spaces
			$property[ 'parking' ] = urldecode( (string)$result->key15 );
			
			// agent id
			$property[ 'agent_id' ] = (string)$result->key24;
			
			// agent name
			//$agent_name = str_replace('+', ' ', $result->key21);
			//$agent_name = urldecode($agent_name);
			$property[ 'agent_name' ] = urldecode(  (string)$result->key25 );
			
			
			// office
			$property[ 'office' ] = urldecode((string)$result->key28);
			
			// square feet
			$property[ 'sqft' ] = (string)$result->key37;
			
			// deed restrictions
			//$property[ 'deed_restrictions' ] = (string)$result->key17;
			
			// number of units
			$property[ 'num_units' ] = (string)$result->key23;
			
			// subdivision
			$property[ 'subdivision' ] = (string)$result->key30;
			
			// county
			$property[ 'county' ] = urldecode( (string) $result->key32);
			
			// zone district
			$property[ 'zone_district' ] = (string)$result->key33;
			
			// legal
			$legal = str_replace('+', ' ', $result->key34);
			$legal = urldecode($legal);
			$property[ 'legal' ] = $legal;
			
			// year built
			$property[ 'year_built' ] = (string)$result->key35;
			
			// remodeled
			$property[ 'remodeled' ] = (string)$result->key36;
			
			// water supply
			$water_supply = str_replace('+', ' ', $result->key56);
			$water_supply = urldecode($water_supply);
			$property[ 'water_supply' ] = (string)$water_supply;
			
			// electric
			$electric = str_replace('+', ' ', $result->key49);
			$electric = urldecode($electric);
			$property[ 'electric' ] = (string)$electric;
			
			// sanitation
			//$property[ 'sanitation' ] = (string)$result->key50;
			
			// land  sqft
			$property[ 'land_sqft' ] = (string)$result->key63;
			
			// lot number
			//$property[ 'lot_num' ] = (string)$result->key52;
			
			// telephone lines
			//$property[ 'telephone_lines' ] = (string)$result->key53;
			
			// cable tv lines
			//$property[ 'cable_tv_lines' ] = (string)$result->key54;
			
			// disclosure statement 1
			$discloser_1 = str_replace('+', ' ', $result->key55);
			$discloser_1 = urldecode($discloser_1);
			$property[ 'disclosures_1' ] = $discloser_1;
			
			// disclosure statement 2		
			$discloser_2 = str_replace('+', ' ', $result->key56);
			$discloser_2 = urldecode($discloser_2);
			$property[ 'disclosures_2' ] = (string)$discloser_2;
			
			// home owner association dues
			//$property[ 'hoa_dues' ] = (string)$result->key59;
			
			// virtual tours, this needs to be an array!
			//$property[ 'virtual_tours' ] = (string)$result->key59;
			
			//images
			$property[ 'image_path' ] = $this->image_url;
			
			//set region info
			$property[ 'region' ] = $this->region_id;
			
			//loop images into an array
			$images = $result->imagesavailable;
			
			// create array of images
			$image_array = explode('-', $images);
			
			// loop images gathering data
			foreach ($image_array as $image) 
			{
				$entry[ 'name' ] = $image;	
				$property[ 'images' ][] = $entry;
			}
			
			$amenity_codes = $result->key58;
			$amenities = explode('|', $amenity_codes);
			
			foreach ($amenities as $amenity ) 
			{
				$property[ 'amenity_array' ][] =$FeatureArray[ $amenity ];
			}
			*/
			$properties[ (int)$result->key1 ] = $property;
		}
		 
		
		//$_SESSION[ 'mls' ][ 'total' ] = (int) $result_set->itemsTotal;
		
		return $properties;	
	}
	
	public function getUpdateResults( $paramaters )
	{
	  syslog(LOG_INFO, "RAM->getSearchResults");
		$ch = curl_init( $this->connection_url );
		
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
		curl_setopt($ch, CURLOPT_POST, 1);
		curl_setopt($ch, CURLOPT_POSTFIELDS, $paramaters );
		$results = curl_exec($ch); 
		curl_close($ch);			
		
		$resultsxml = simplexml_load_string( $results );	
		
		$properties = $this->getNormalizedData( $resultsxml );

		return $properties;
	}
	
	public function getLastMls( $paramaters )
	{
	  syslog(LOG_INFO, "RAM->getSearchResults");
		$ch = curl_init( $this->connection_url );
		
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
		curl_setopt($ch, CURLOPT_POST, 1);
		curl_setopt($ch, CURLOPT_POSTFIELDS, $paramaters );
		$results = curl_exec($ch); 
		curl_close($ch);			
		$lastmlsxml = simplexml_load_string( $results );	
		
		$lastmls = $this->getNormalizedData( $lastmlsxml );

		return $lastmls;
	}
	
	
}