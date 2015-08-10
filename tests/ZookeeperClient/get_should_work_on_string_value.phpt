--TEST--
Get should work on string value
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
$zc->create('/get_test_node', 'abc');
echo $zc->get('/get_test_node');
$zc->delete('/get_test_node');
?>
--EXPECT--
abc
