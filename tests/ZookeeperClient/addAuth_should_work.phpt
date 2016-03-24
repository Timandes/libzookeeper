--TEST--
AddAuth should work
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
$zc->addAuth("digest", "user:password");
?>
--EXPECT--
