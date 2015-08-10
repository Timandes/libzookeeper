.. _predefined_constants:

Predefined Constants
====================

ZookeeperClient::ERR_OK
    0, /*!< Everything is OK */

ZookeeperClient::ERR_APIERROR
    -100,

ZookeeperClient::ERR_NONODE
    -101, /*!< Node does not exist */

ZookeeperClient::ERR_NOAUTH
    -102, /*!< Not authenticated */

ZookeeperClient::ERR_BADVERSION
    -103, /*!< Version conflict */

ZookeeperClient::ERR_NOCHILDRENFOREPHEMERALS
    -108, /*!< Ephemeral nodes may not have children */

ZookeeperClient::ERR_NODEEXISTS
    -110, /*!< The node already exists */

ZookeeperClient::ERR_NOTEMPTY
    -111, /*!< The node has children */

ZookeeperClient::ERR_SESSIONEXPIRED
    -112, /*!< The session has been expired by the server */

ZookeeperClient::ERR_INVALIDCALLBACK
    -113, /*!< Invalid callback specified */

ZookeeperClient::ERR_INVALIDACL
    -114, /*!< Invalid ACL specified */

ZookeeperClient::ERR_AUTHFAILED
    -115, /*!< Client authentication failed */

ZookeeperClient::ERR_CLOSING
    -116, /*!< ZooKeeper is closing */

ZookeeperClient::ERR_NOTHING
    -117, /*!< (not error) no server responses to process */

ZookeeperClient::ERR_SESSIONMOVED
    -118, /*!<session moved to another server, so operation is ignored */

(Zookeeper >= 3.5.0):

ZookeeperClient::ERR_NOTREADONLY
    -119, /*!< state-changing request is passed to read-only server */

ZookeeperClient::ERR_EPHEMERALONLOCALSESSION
    -120, /*!< Attempt to create ephemeral node on a local session */

ZookeeperClient::ERR_NOWATCHER
    -121, /*!< The watcher couldn't be found */

ZookeeperClient::ERR_RWSERVERFOUND
    -122 /*!< r/w server found while in r/o mode */
