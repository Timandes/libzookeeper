--TEST--
Method create n addAuth n set (Fail)
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
$path = '/create_n_addAuth_n_set_fail';
$acls = array (
    'world:anyone' => \ZookeeperClient::PERM_READ,
    'digest:user0:RRZx311/2ghAkuJ0fGTErRjup2I=' => \ZookeeperClient::PERM_ALL,
    'digest:user1:oMOD60B8cRkgiY51xfdG0FFW3FI=' => \ZookeeperClient::PERM_CREATE & \ZookeeperClient::PERM_DELETE,
    );
$zc->create($path, null, $acls);
$zc->addAuth("digest", "user1:user1");
try {
    $zc->set($path, "foo");
} catch (ZookeeperClientCoreException $zcce) {
    fprintf(STDOUT, "[#%d] %s\n", $zcce->getCode(), $zcce->getMessage());
}
$zc->delete($path);
?>
--EXPECT--
[#-102] not authenticated