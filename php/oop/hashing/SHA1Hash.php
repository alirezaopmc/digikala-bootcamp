<?php

require_once './HashStrategy.php';

class SHA1Hash implements HashStrategy
{
    private static SHA1Hash $instance;

    private function __construct() {

    }

    public function hash($data)
    {
        return sha1($data);
    }

    public static function getInstance()
    {
        if (! isset(self::$instance)) {
            self::$instance = new SHA1Hash();
        }

        return self::$instance;
    }
}