<?php

function split_and_clean($separator, $text) {
    $result_array = explode($separator, $text);

    for($i=0; $i<sizeof($result_array); $i++) {
        $result_array[$i] = trim($result_array[$i]);
    }

    return $result_array;
}

function make_an_object($keys, $values) {
    $object = new stdClass();

    for($i=0; $i<sizeof($keys); $i++) {
        $key = $keys[$i];
        $value = $values[$i];
        $object->$key = $value;
    }

    return $object;
}

try {
    $filename = $_FILES['file']['tmp_name'];
    if ($file = fopen($filename, 'r')) {
        $data_array = [];
        $keys = split_and_clean(',', fgets($file));
        while (! feof($file)) {
            $values = split_and_clean(',', fgets($file));
            if (sizeof($values) == sizeof($keys)) {
                $data_array[] = make_an_object($keys, $values);
            }
        }
        $result = json_encode($data_array, JSON_PRETTY_PRINT);
        $result = preg_replace('/\//', '/', $result);

        echo $result;
    }
} catch (Exception $e) {

}
