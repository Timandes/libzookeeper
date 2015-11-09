.. _predefined_constants:

Predefined Constants
====================

ZookeeperClient::ERR_OK
    0, /*!< Everything is OK */

ZookeeperClient::ERR_SYSTEMERROR
    -1,

ZookeeperClient::ERR_RUNTIMEINCONSISTENCY
    -2, /*!< A runtime inconsistency was found */

ZookeeperClient::ERR_DATAINCONSISTENCY
    -3, /*!< A data inconsistency was found */

ZookeeperClient::ERR_CONNECTIONLOSS
    -4, /*!< Connection to the server has been lost */

ZookeeperClient::ERR_MARSHALLINGERROR
    -5, /*!< Error while marshalling or unmarshalling data */

ZookeeperClient::ERR_UNIMPLEMENTED
    -6, /*!< Operation is unimplemented */

ZookeeperClient::ERR_OPERATIONTIMEOUT
    -7, /*!< Operation timeout */

ZookeeperClient::ERR_BADARGUMENTS
    -8, /*!< Invalid arguments */

ZookeeperClient::ERR_INVALIDSTATE
    -9, /*!< Invliad zhandle state */

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

ZookeeperClient::ERR_NEWCONFIGNOQUORUM
    -13, /*!< No quorum of new config is connected and up-to-date with the leader of last commmitted config - try invoking reconfiguration after new servers are connected and synced */

ZookeeperClient::ERR_RECONFIGINPROGRESS
    -14, /*!< Reconfiguration requested while another reconfiguration is currently in progress. This is currently not supported. Please retry. */

ZookeeperClient::ERR_NOTREADONLY
    -119, /*!< state-changing request is passed to read-only server */

ZookeeperClient::ERR_EPHEMERALONLOCALSESSION
    -120, /*!< Attempt to create ephemeral node on a local session */

ZookeeperClient::ERR_NOWATCHER
    -121, /*!< The watcher couldn't be found */

ZookeeperClient::ERR_RWSERVERFOUND
    -122, /*!< r/w server found while in r/o mode */


ZookeeperClient::LOG_LEVEL_NONE
    0,

ZookeeperClient::LOG_LEVEL_ERROR
    1,

ZookeeperClient::LOG_LEVEL_WARN
    2,

ZookeeperClient::LOG_LEVEL_INFO
    3,

ZookeeperClient::LOG_LEVEL_DEBUG
    4,


ZookeeperClientException::ERR_INIT_FAILURE
    1,

ZookeeperClientException::ERR_CONNECT_FIRST
    2,

ZookeeperClientException::ERR_CLOSE_FIRST
    3,
