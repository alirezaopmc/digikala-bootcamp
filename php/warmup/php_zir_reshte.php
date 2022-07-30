<?php

function repeatInString($text, $pattern): int
{
  $n = strlen($text);
  $m = strlen($pattern);
  $len = $n - $m + 1;

  $cnt = 0;
  for($i=0; $i<$len; $i++) {
    for($j=0; $j<$m; $j++) {
      if ($text[$i+$j] != $pattern[$j]) break;
      if ($j == $m-1) $cnt++;
    }
  }

  return $cnt;
}

//echo repeatInString('ssss', 'ss');
