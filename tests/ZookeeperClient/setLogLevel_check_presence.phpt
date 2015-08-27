--TEST--
Check for method setLogLevel presence
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
var_dump(method_exists("ZookeeperClient", "setLogLevel"));
?>
--EXPECT--
bool(true)
