<?php

session_start();

$session_id = session_id();

if (isset($_SESSION[$session_id])) {
  $_SESSION[$session_id] += 1;
} else {
  $_SESSION[$session_id] = 1;
}

function getOrderedExtention($cnt) {
  if ($cnt > 10 and $cnt < 20) return 'th';

  switch($cnt) {
    case 1:
      return 'st';
    case 2:
      return 'nd';
    case 3:
      return 'rd';
    default:
      return 'th';
  }
}

function getOrderedCnt($cnt) {
  return "$cnt" . getOrderedExtention($cnt);
}

function logCounter($cnt) {
  $ordered_cnt = getOrderedCnt($cnt);
  echo "This is your $ordered_cnt visit in this session.";
}

logCounter(1);
logCounter(2);
logCounter(3);
logCounter(4);
logCounter(7);
logCounter(21);
logCounter($_SESSION[$session_id]);


