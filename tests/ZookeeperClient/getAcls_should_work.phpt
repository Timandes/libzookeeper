--TEST--
GetAcls should work
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
var_dump($zc->getAcls('/zookeeper'));
?>
--EXPECT--
array(1) {
  ["world:anyone"]=>
  int(31)
}