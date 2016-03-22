--TEST--
Check for method setAcls presence
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
var_dump(method_exists($zc, "setAcls"));
?>
--EXPECT--
bool(true)
