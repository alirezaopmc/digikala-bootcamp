<?php

class LogAuth
{
    use FileLogger;
    public function greet()
    {
        $this->log('INFO', 'Welcome new user');
    }
}
