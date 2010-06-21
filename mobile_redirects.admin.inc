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

function mobile_redirects_settings(&$form_state) {
	$form = array();  
  $form['path'] = array(
    '#type' => 'textfield',
    '#title' => t('Existing system path'),
    '#maxlength' => 128,
    '#size' => 45,
    '#description' => t('Specify the existing path you wish to redirect.'),
    '#field_prefix' => url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
    '#required' => TRUE,
  );
  $form['redirect'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile Redirect'),
    '#maxlength' => 128,
    '#size' => 45,
    '#description' => t('Specify an alternative path where mobile users will be directed. For example, type "about" when writing an about page. Use a relative path and don\'t add a trailing slash or the URL alias won\'t work.'),
    '#field_prefix' => url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
    '#required' => TRUE,
  );

	$form['submit'] = array('#type' => 'submit', '#value' => t('Add Redirect'));
	return $form;
}


/**
	* Handle submission of form to database
	*/
	
function mobile_redirects_settings_submit($form, $form_state) {
	
	$mr_path = $form_state['values']['path'];
	$mr_redirect = $form_state['values']['redirect'];
	
	db_query("DELETE FROM {mobile_redirects} WHERE path = '%s' AND redirect = '%s'", $mr_path, $mr_redirect);
	db_query("INSERT INTO {mobile_redirects} (path, redirect) VALUES ('%s', '%s')", $mr_path, $mr_redirect);
	drupal_set_message(t('Your Redirect Has Been Saved.  Horray!'));
	
	
}



