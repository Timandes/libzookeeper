--TEST--
GetChildren should work
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
var_dump($zc->getChildren('/zookeeper'));
?>
--EXPECT--
array('quota');