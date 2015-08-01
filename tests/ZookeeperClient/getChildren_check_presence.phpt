--TEST--
Check for method getChildren presence
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
var_dump(method_exists($zc, "getChildren"));
?>
--EXPECT--
bool(true)
