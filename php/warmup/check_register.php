<?php

function checkAllPaterns($bad_patterns, $text) {
  foreach($bad_patterns as $bp) {
    if (preg_match($bp, $text)) return false;
  }
  return true;
}

function isValid($username, $password) {

  $bad_username_patterns = [
    '/^quera$/',
    '/^admin$/',
    '/^.{0,3}$/',
  ];

  $bad_password_patterns = [
    '/^(.{0,5}|\d+)$/',
  ];

  return (
    checkAllPaterns($bad_username_patterns, $username) 
    and
    checkAllPaterns($bad_password_patterns, $password)
  );
}

function checkRegistrationRules($credentials) {
  $result = [];

  foreach($credentials as [$username, $password]) {
    if (isValid($username, $password)) $result[] = $username;
  }

//  print_r($result);
  return $result;
}

/*
checkRegistrationRules([
  ['alireza', '1234'],
  ['parham', 'ramzekh00b']
]);
*/
