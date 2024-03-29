<?php

/**
 * @file
 * User implementations of the page title hooks
 */


/**
 * Implementation of hook_page_title_alter().
 */
function user_page_title_alter(&$title) {
  // If we're looking at either a user profile page, get the user title
  if ( ($user = menu_get_object('user')) &&
       variable_get('page_title_user_showfield', 0) &&
       ($user_title = page_title_load_title($user->uid, 'user')) ) {
    $title = $user_title;
  }
}


/**
 * Implementation of hook_page_title_pattern_alter().
 */
function user_page_title_pattern_alter(&$pattern, &$types) {
  if ($user = menu_get_object('user')) {
    $types['user'] = $user;
    $pattern = variable_get('page_title_user', '');
  }
}
