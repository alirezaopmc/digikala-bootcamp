<?php

// With Python Hack
/*
function getExtension($filename) {
  $script = 'python3 -c "print(\"' . $filename . '\".split(\".\")[1])"';
  //echo $script;
  $output = shell_exec($script);
  echo $output;
}
*/

// With Shell Hack
/*
function getExtension($filename) {
  $part1 = 'FILE="' . $filename . '"';
  $part2 = 'echo "${FILE##*.}"';

  $cmd = $part1 . ';' . $part2;

  $ans = shell_exec($cmd);
  echo $ans;
}
*/

function getExtension($filename) {
  $pattern = '{\.([\w]+)$}';
  if (preg_match($pattern, $filename, $matches)) {
    return $matches[1];
  } else {
    return '';
  }
}

//getExtension('https://domain.com/fil.com');
