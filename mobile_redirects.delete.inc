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
	$form = array();  
  $form['redirect_delete'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Redirect Delete'),
    '#maxlength' => 128,
    '#size' => 45,
    '#description' => t('Specify a mobile path to delete the alias'),
    '#field_prefix' => url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
    '#required' => TRUE,
  );


	$form['submit'] = array('#type' => 'submit', '#value' => t('Delete Redirect'));
	return $form;
}


/**
	* Handle submission of form to database
	*/
	
function mobile_redirects_delete_submit ($form, $form_state) {
	
	$mr_redirect = $form_state['values']['redirect_delete'];
	db_query("DELETE FROM {mobile_redirects} WHERE redirect = '%s'", $mr_redirect);
	drupal_set_message(t('Your Redirect Has Been Deleted.  <br /><em>(I hope you really wanted to do that!)</em>'));
	
	
}



