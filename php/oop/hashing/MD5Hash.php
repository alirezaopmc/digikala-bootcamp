<?php

require_once './HashStrategy.php';

class MD5Hash implements HashStrategy
{
    private static MD5Hash $instance;

    private function __construct() {

    }

    public function hash($data)
    {
        return md5($data);
    }

    public static function getInstance()
    {
        if (! isset(self::$instance)) {
            self::$instance = new MD5Hash();
        }

        return self::$instance;
    }
}
