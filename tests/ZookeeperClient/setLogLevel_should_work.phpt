--TEST--
SetLogLevel should work
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
ZookeeperClient::setLogLevel(ZookeeperClient::LOG_LEVEL_NONE);
?>
--EXPECT--
