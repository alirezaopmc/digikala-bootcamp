<?php

trait StdOutLogger
{
    public function log($type, $message)
    {
        $date = date('Y-m-d H:i:s');

        echo "$date [$type] $message\n";
    }
}