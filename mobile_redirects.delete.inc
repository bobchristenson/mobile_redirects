<?php

//$Id&

/**
	* @file
	* Admin form for mobile_redirect settings
	*/
	
/**
	* Form Building for the settings screen
	*
	* @ingroup forms
	* see system_settings_form().
	*/

function mobile_redirects_delete(&$form_state) {

	$sql = 'SELECT * FROM {mobile_redirects}';
	$result = pager_query(db_rewrite_sql($sql), 200, 0);
	$redirects = array();
	$paths = array();

	while ($data = db_fetch_array($result)) {
		$redirects[] .= $data['redirect'];
		$paths[] .= $data['path'];
	}

	
	 $form['existing_redirects'] = array(
	 	'#type' => 'fieldset',
	 	'#title' => t('Existing Redirects'),
	 	'#description' => t('Check the path redirects you want to delete'),
	 );
	 
	 
	 $form['existing_redirects']['list'] = array(
	 	'#type' => 'checkboxes',
	 	'#options' => $redirects,
	 	
	 );
	 	
	
	
	$form['submit'] = array('#type' => 'submit', '#value' => t('Delete Redirect'));
	
	return $form;
	

	
}

/**
	* Handle submission of form to database
	* Method taken from http://drupal.org/node/631926#comment-2264622
	* Need to look further to http://drupal.org/node/631926#comment-2268976 to get it to work (and theme as a table)
	*/
	
function mobile_redirects_delete_submit ($form, $form_state) {

	$checked_boxes = array();
	$form_state_array = $form_state['values']['existing_redirects']['list'];
	foreach($form_state_array as $checkbox) {
		$checked_boxes[] = $checkbox;
	}	
	foreach($checked_boxes as $checked_box)	{
		db_query("DELETE FROM {mobile_redirects} WHERE redirect = '%s'", $checked_box);
	}		
	
	drupal_set_message(t('Your Redirect Has Been Deleted.  <br /><em>(I hope you really wanted to do that!)</em>'));
}	

