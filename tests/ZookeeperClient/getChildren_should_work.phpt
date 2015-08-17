--TEST--
GetChildren should work
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
$path = '/parent_test_node';
$zc->create($path);
$zc->create($path . '/child');
var_dump($zc->getChildren($path));
$zc->delete($path . '/child');
$zc->delete($path);
?>
--EXPECT--
array(1) {
  [0]=>
  string(5) "child"
}
