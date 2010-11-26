<?php

/**
 * A Drupal form
 * 
 * Called directly through the menu
 */
function fastway_settings() {
	$form = array();
	
	$form['store_price_preference'] = array(
		'#type' => 'radios',
		'#title' => 'Price Preference',
	  '#default_value' => variable_get('fastway_pref_price', FASTWAY_PREF_PRICE_DEFAULT),
	  '#options' => array(
			FASTWAY_PREF_PRICE_HIGHESTPRICE => t('Always choose most expensive shipping label - this allows the store to apply less expensive labels if the store has any inventory remaining.'),
			FASTWAY_PREF_PRICE_LOWESTPRICE => t('Always choose lowest priced shipping label - the store will purchase bulk packs of required labels if the store inventory empties.'),
		),
		'#description' => t('If multiple label options are available for a package, which one should we choose?'),
	);
	
	$form['store_origin'] = array(
		'#type' => 'textfield',
		'#title' => 'Origin',
	  '#default_value' => variable_get('fastway_origin', ''),
	  '#maxlength' => 3,
	  '#size' => 3,
	  '#description' => t('The short origin code for the Fastway depot closest to where the store is located. Examples: ADL, SYD. There is a list of codes in README.md.'),
	);
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save'),
	);
	
	return $form;
}

/**
 * Drupal form validation hook
 * 
 */
function fastway_settings_validate($form, &$form_state) {
	$form_state['values']['store_origin'] = check_plain($form_state['values']['store_origin']);
	if (true !== fastway_api_check_origin($form_state['values']['store_origin'])) {
		form_set_error('store_origin', t('Fastway does not accept this code.'));
	}
}

/**
 * Drupal form submission hook
 * 
 */
function fastway_settings_submit($form, &$form_state) {
	variable_set('fastway_origin', $form_state['values']['store_origin']);
	variable_set('fastway_pref_price', $form_state['values']['store_price_preference']);
}