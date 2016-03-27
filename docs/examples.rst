.. _examples:

Examples
========

No.1
-----

::

    <?php
    $zc = new ZookeeperClient();
    $zc->connect('localhost:2181');
    var_dump($zc->get('/zookeeper'));
    ?>


Create Node
-----------

::

    <?php
    $zc = new \ZookeeperClient();
    $zc->connect('localhost:2181');

    $acls = array (
        'world:anyone' => \ZookeeperClient::PERM_READ,
        'digest:user0:4LVnEr8VX5VVtn/KiU6Aff8jqh8=' => \ZookeeperClient::PERM_ALL,
        'digest:user1:4LVnEr8VX5VVtn/KiU6Aff8jqh8=' => \ZookeeperClient::PERM_CREATE & \ZookeeperClient::PERM_DELETE,
        );
    $zc->create('/zookeeper/node0', 'value0', $acls);


Add Auth
--------

::

    <?php
    $zc = new \ZookeeperClient();
    $zc->connect('localhost:2181');

    $zc->addAuth('digest', 'user0:password0');


Get Acls
--------

::

    <?php
    $zc = new \ZookeeperClient();
    $zc->connect('localhost:2181');

    $acls = $zc->getAcls('/zookeeper/node0');
    var_dump($acls);


Set Acls
--------

::

    <?php
    $zc = new \ZookeeperClient();
    $zc->connect('localhost:2181');

    $acls = array (
        'world:anyone' => \ZookeeperClient::PERM_READ,
        'digest:user0:4LVnEr8VX5VVtn/KiU6Aff8jqh8=' => \ZookeeperClient::PERM_ALL,
        'digest:user1:4LVnEr8VX5VVtn/KiU6Aff8jqh8=' => \ZookeeperClient::PERM_CREATE & \ZookeeperClient::PERM_DELETE,
        );
    $zc->setAcls('/zookeeper/node0', $acls);

