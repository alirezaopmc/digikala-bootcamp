<?php

$input = fopen("input.txt", "r");
$text = fgets($input);

function camelCase($text) {
  $len = strlen($text);
  $result = '';
  $flag = false;

  for($i=0; $i<$len; $i++) {
    $c = $text[$i];

    if ($c == ' ') {
      $flag = true;
      continue;
    }

    if ($result == '' or !$flag) {
      $result .= strtolower($c);
    } else {
      $result .= strtoupper($c);
    }

    $flag = false;
  }

  return $result;
}

//print $text;
print camelCase($text);

fclose($input);
