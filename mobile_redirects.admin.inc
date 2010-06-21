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

function mobile_redirects_settings() {
	$form = array();
  $form['activate'] = array(
    '#type' => 'checkbox',
    '#title' => t('Activate Mobile Redirects'),
    '#description' => t('When checking this box, your mobile redirects below will be active.'),
  );
  
  $form['src'] = array(
    '#type' => 'textfield',
    '#title' => t('Existing system path'),
    '#maxlength' => 128,
    '#size' => 45,
    '#description' => t('Specify the existing path you wish to redirect.'),
    '#field_prefix' => url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
    '#required' => TRUE,
  );
  $form['dst'] = array(
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


