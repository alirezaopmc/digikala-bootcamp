<?php

class PrintAuth
{
    use StdOutLogger;
    public function greet()
    {
        $this->log('INFO', 'Welcome new user');
    }
}
