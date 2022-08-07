<?php

trait FileLogger
{
    public function log(string $type, $message)
    {
        $path = 'quera.log';

        $flag = file_exists($path);
        $file = fopen($path, 'a');
        $date = date('Y-m-d H:i:s');
        $log = "$date [$type] $message";
        if ($flag) {
            $log = "\n$log";
        }
        fwrite($file, $log);
        fclose($file);
    }
}