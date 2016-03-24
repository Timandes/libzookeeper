--TEST--
Method create n addAuth n set (Success)
--SKIPIF--
<?php if (!extension_loaded("libzookeeper")) print "skip"; ?>
--FILE--
<?php
$zc = new ZookeeperClient();
$zc->connect('localhost:2181');
$path = '/create_n_addAuth_n_set_success';
$acls = array (
    'world:anyone' => \ZookeeperClient::PERM_READ,
    'digest:user0:RRZx311/2ghAkuJ0fGTErRjup2I=' => \ZookeeperClient::PERM_ALL,
    'digest:user1:oMOD60B8cRkgiY51xfdG0FFW3FI=' => \ZookeeperClient::PERM_CREATE & \ZookeeperClient::PERM_DELETE,
    );
$zc->create($path, null, $acls);
$zc->addAuth("digest", "user0:user0");
$zc->set($path, "foo");
$zc->delete($path);
?>
--EXPECT--
