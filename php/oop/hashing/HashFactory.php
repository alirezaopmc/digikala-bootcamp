<?php

require_once './HashStrategy.php';

class HashFactory
{
    private array $strategies = [];

    public function register($name, HashStrategy $strategy)
    {
        $this->strategies[$name] = $strategy;
    }

    /**
     * @throws Exception
     */
    public function make($name)
    {
        if (! array_key_exists($name, $this->strategies)) {
            throw new Exception('Strategy Not Supported');
        }

        return $this->strategies[$name];
    }
}