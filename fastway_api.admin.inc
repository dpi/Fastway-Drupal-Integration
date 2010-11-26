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
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save'),
	);
	
	return $form;
}

/**
 * Drupal form submission hook
 * 
 */
function fastway_settings_submit($form, &$form_state) {
	variable_set('fastway_pref_price', $form_state['values'][store_price_preference]);
}