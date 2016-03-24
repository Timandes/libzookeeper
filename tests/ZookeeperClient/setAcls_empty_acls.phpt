--TEST--
Empty acls
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
try {
    $zc->setAcls("/foo", null);
} catch (DomainException $de) {
    fprintf(STDOUT, "[#%d] %s\n", $de->getCode(), $de->getMessage());
}
?>
--EXPECTF--
[#0] Parameter `acls` must not be empty
