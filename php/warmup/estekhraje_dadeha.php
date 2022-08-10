<?php

function findPhoneNumbers($text)
{
    $phone_pattern = '/((?<![\S])09\d{9}(?![\S])' . '|' . '(?<![\S])\+9891\d{8}(?![\S]))/';

    preg_match_all($phone_pattern, $text, $matches);

    return $matches[0];
}

function findHashtags($text)
{
//    $hashtag_pattern = '/(?<![a-zA-Z0-9-])#[a-zA-Z0-9]{2,}(?![a-zA-Z0-9-])/';
    $hashtag_pattern = '/(?<![\w\.-])#[a-zA-Z0-9]{2,}(?![\w\.-])/';

    preg_match_all($hashtag_pattern, $text, $matches_1);

    $matches = [];

    array_push($matches, ...$matches_1[0]);

    return $matches_1[0];
}

function boldEmails($text)
{
    $username_pattern = '[a-zA-Z0-9_.]+';
    $domain_pattern = '[a-zA-Z0-9]+';
    $tld_pattern = '[a-zA-Z]{3}';

    $pattern = '/(?<![\w\.])(' . $username_pattern . '\@' . $domain_pattern . '\.' . $tld_pattern . ')(?![\w\.])/';
    $replace = "<b>$1</b>";

    return preg_replace($pattern, $replace, $text);
}

print_r(findPhoneNumbers("0911412312309114235621 +989114123512 09114123512 09111412836"));
//print_r(findPhoneNumbers("09111164444 In shomareye mane: 09101007567 vali behtare +989101007567 ro save koni. In 9111231234 va0914513 kar nemikonan."));
//print_r(findPhoneNumbers("09111164444"));
//print_r(findHashtags("#aghaye Salam #goodMOrning khoobi#to #4yourlove #bi-man"));
//print_r(boldEmails("Soalatono az info_test@Quera.ir ya info@Quera123.com ya test_#23@alaki.core beporsid"));
//print_r(boldEmails("2salam@quera.com Soalatono az info_test@Quera.ir ya info@Quera123.com ya test_#23@alaki.core beporsid"));
