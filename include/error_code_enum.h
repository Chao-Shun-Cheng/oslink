/**
 *******************************************************************************
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * @file    error_code_enum.h
 * @brief   This header is generated automatically for Unex V2X SDK v1.6.3
 *          please do not modify this file manually.
 * @author  Unex
 *******************************************************************************
 */

#ifndef __ERROR_CODE_ENUM_H__
#define __ERROR_CODE_ENUM_H__

/* Error code definition for Unex V2X SDK v1.6.3 */
typedef enum error_code {

    /* generic */
    SUCCESS = 0,                      /* No error */
    ERROR_NULL_POINTER = -1,          /* Null pointer access */
    ERROR_INIT_FAIL = -2,             /* Initialization failed */
    ERROR_NOT_INIT = -3,              /* Not yet initialized */
    ERROR_INVALID_ARGS = -4,          /* Value of argument is invalid */
    ERROR_NO_MEMORY = -5,             /* No more memory */
    ERROR_TIMEOUT = -6,               /* Timeout */
    ERROR_UNSPECIFIED = -7,           /* Unspecified error */
    ERROR_UNSUPPORT_TYPE = -8,        /* Unsupported type */
    ERROR_NO_RESOURCE = -9,           /* No resource */
    ERROR_BUSY = -10,                 /* Busy */
    ERROR_CONN_FAIL = -11,            /* Connect failed */
    ERROR_FILE_NOT_EXISTS = -12,      /* Can't find the file */
    ERROR_FILE_CONTENT_INVALID = -13, /* File content is invalid */

    /* poti */
    ERROR_POTI_SHM_VER_ERROR = -1024, /* Version of poti shm is wrong */
    ERROR_NOT_SET_TAI_OFFSET = -1025, /* System TAI offset is not set */

    /* gn */
    ERROR_GN_HDLR_IPC_ALLOCATE = -2048,         /* Can't allocate GN IPC interface */
    ERROR_GN_HDLR_IPC_SET_CFG = -2049,          /* Can't setup GN IPC interface */
    ERROR_GN_HDLR_IPC_INVALID_IDX = -2050,      /* Invalid GN handler index */
    ERROR_GN_HDLR_IPC_INVALID_LOCK = -2051,     /* Invalid GN IPC lock */
    ERROR_GN_HDLR_IPC_CONN_PUBLIC_IF = -2052,   /* Can't connect to GN public channel, please make sure GN daemon is activated */
    ERROR_GN_HDLR_IPC_VERSION_MISMATCH = -2053, /* The IPC version is mismatched */
    ERROR_GN_HDLR_IPC_REQ_SIZE_INVALID = -2054, /* Wrong GN IPC request message size */
    ERROR_GN_HDLR_IPC_REQ_ISSUE_FAIL = -2055,   /* Can't issue GN IPC request */
    ERROR_GN_HDLR_IPC_RSP_SIZE_INVALID = -2056, /* Wrong GN IPC response message size */
    ERROR_GN_HDLR_IPC_RSP_HDR_INVALID = -2057,  /* Wrong GN IPC response content */
    ERROR_GN_HDLR_IPC_RSP_REJECT = -2058,       /* Rejected by GN service */

    ERROR_GN_HDLR_MGNT_IPC_ESTI_FAIL = -2080,   /* Can't estimate GN MGNT service connection */
    ERROR_GN_HDLR_MGNT_IPC_IDX_INVALID = -2081, /* Wrong GN MGNT service connection index */
    ERROR_GN_HDLR_MGNT_SECURITY_MIB_DISABLED =
        -2082, /* btp_config.security.type is BY_PROFILE, but "is_mib_its_gn_security_enabled" is false in gnd.json */
    ERROR_GN_HDLR_MGNT_SECURITY_TYPE_INVALID = -2083, /* Incorrect security type */
    ERROR_GN_HDLR_MGNT_SECURITY_TYPE_UNSECURED_OPERATION =
        -2084, /* btp_config.security.type is UNSECURED, but "is_mib_its_gn_security_enabled" is true in gnd.json */
    ERROR_GN_HDLR_MGNT_SECURITY_AID_INVALID = -2085,  /* This ITS-AID is invalid and should not be used */
    ERROR_GN_HDLR_MGNT_SECURITY_AID_CONFLICT = -2086, /* This ITS-AID is occupied by other APP */

    ERROR_GN_HDLR_TX_IPC_ESTI_FAIL = -2112,                  /* Can't estimate GN TX service connection */
    ERROR_GN_HDLR_TX_IPC_IDX_INVALID = -2113,                /* Wrong GN TX service connection index */
    ERROR_GN_HDLR_TX_PAYLOAD_EMPTY = -2114,                  /* TX payload is empty */
    ERROR_GN_HDLR_TX_PAYLOAD_TOO_LONG = -2115,               /* TX payload size is too large */
    ERROR_GN_HDLR_TX_NETWORK_HDR_TYPE_UNSUPPORTED = -2116,   /* Unsupported TX network header type */
    ERROR_GN_HDLR_TX_TRANSPORT_HDR_TYPE_UNSUPPORTED = -2117, /* Unsupported TX transport header type */
    ERROR_GN_HDLR_TX_SRC_PORT_NOT_BIND = -2118,              /* TX source port is not binded */
    ERROR_GN_HDLR_TX_DEST_AREA_INVALID_TYPE = -2119,         /* TX dest area type setting is invalid */
    ERROR_GN_HDLR_TX_DEST_AREA_DISTANCE_IS_ZERO = -2120,     /* TX dest area distance setting is zero */
    ERROR_GN_HDLR_TX_DEST_AREA_INVALID_LATITUDE = -2121,     /* TX dest area latitude setting is invalid */
    ERROR_GN_HDLR_TX_DEST_AREA_INVALID_LONGITUDE = -2122,    /* TX dest area longitude setting is invalid */
    ERROR_GN_HDLR_TX_SSP_LEN_TOO_LONG = -2123,               /* The length of SSP is too large */
    ERROR_GN_HDLR_TX_TRAFFIC_CLASS_ID_INVALID = -2124,       /* The inputted traffic class ID is invalid */

    ERROR_GN_HDLR_RX_IPC_ESTI_FAIL = -2144,                   /* Can't estimate GN RX service connection */
    ERROR_GN_HDLR_RX_IPC_IDX_INVALID = -2145,                 /* Wrong GN RX IPC interface index */
    ERROR_GN_HDLR_RX_TRANSPORT_HDR_TYPE_UNSUPPORTTED = -2146, /* Unsupported RX transport header type */
    ERROR_GN_HDLR_RX_PKT_SIZE_INVALID = -2147,                /* Incorrect RX packet size */
    ERROR_GN_HDLR_RX_BUF_TOO_SHORT = -2148,                   /* RX packet is larger than inputted buffer */
    ERROR_GN_HDLR_RX_DUPLICATE_BIND = -2149,                  /* This handler had already been binded before */

    /* dot3 */
    ERROR_DOT3_PARAMS_INVALID = -3072,     /* Input parameters are invalid */
    ERROR_DOT3_PACKET_TRUNCATED = -3073,   /* Received packet is truncated */
    ERROR_DOT3_ENTRY_NOT_FOUND = -3074,    /* Requesting entry is not found */
    ERROR_DOT3_CHANNEL_NOT_FOUND = -3075,  /* Requesting channel is not found */
    ERROR_DOT3_PSID_CONFLIT = -3076,       /* Requesting PSID has been registered */
    ERROR_DOT3_OUT_OF_RESOURCE = -3077,    /* System resourece is full */
    ERROR_DOT3_UNSPEC = -3078,             /* Unspecified error */
    ERROR_DOT3_SYS_REINIT = -3079,         /* System has been initialized */
    ERROR_DOT3_SYS_NOT_INITED = -3080,     /* System has not been initialized */
    ERROR_DOT3_SYS_HANDLE_INVALID = -3081, /* Input handle is invalid */
    ERROR_DOT3_SYS_ERR_INTERNAL = -3082,   /* System internal error */
    ERROR_DOT3_SYS_LOSS_OF_IPC = -3083,    /* IPC has been closed */
    ERROR_DOT3_SYS_TIMEOUT = -3084,        /* Request is timeout */
    ERROR_DOT3_SYS_OUT_OF_MEM = -3085,     /* System is out of memory */

    /* its_security */
    ERROR_ITS_SEC_OPEN_UPDATE_DIR_ERROR = -4096,                 /* Open Update Dir fail */
    ERROR_ITS_SEC_OPEN_UPDATE_CA_DIR_ERROR = -4097,              /* Open Update CA Dir fail */
    ERROR_ITS_SEC_OPEN_UPDATE_EE_DIR_ERROR = -4098,              /* Open Update EE Dir fail */
    ERROR_ISC_DELETE_UPDATE_FOLDER_ERROR = -4099,                /* Delete update folder fail */
    ERROR_ISC_MAKE_UPDATE_FOLDER_ERROR = -4100,                  /* Make update folder fail */
    ERROR_ISC_MAKE_UPDATE_CA_FOLDER_ERROR = -4101,               /* Make update CA folder fail */
    ERROR_ISC_MAKE_UPDATE_EE_FOLDER_ERROR = -4102,               /* Make update EE folder fail */
    ERROR_ITS_SEC_CERT_FILE_ERROR = -4103,                       /* Can't access this certificate file or it doesn't exist */
    ERROR_ITS_SEC_STORE_CA_CERT_ERROR = -4104,                   /* Store CA certificate fail */
    ERROR_ITS_SEC_STORE_AT_CERT_ERROR = -4105,                   /* Store AT certificate fail */
    ERROR_ITS_SEC_PRI_KEY_FILE_ERROR = -4106,                    /* Private key file access fail */
    ERROR_ITS_SEC_BUF_SIZE_NOT_ENOUGH = -4107,                   /* Buf size isn't enough */
    ERROR_ITS_SEC_TBL_NON_EXIST = -4108,                         /* This table doesn't exist */
    ERROR_ITS_SEC_CMH_EXAHSTED = -4109,                          /* Dot2 CMH exausted */
    ERROR_ITS_SEC_SET_REPETITIVE_AID_PROFILE_MAPPING = -4110,    /* This AID has been mapped to a security profile */
    ERROR_ITS_SEC_PROFILE_MAPPING_NON_EXIST = -4111,             /* This AID associates with profile doesn't exist in mapping table */
    ERROR_ITS_SEC_PROFILE_NON_EXIST = -4112,                     /* This security profile doesn't exist */
    ERROR_ITS_SEC_PROFILE_NOT_SUPPORT_VERIFY_SIGNED_MSG = -4113, /* This security profile doesn't support to verify signed message */
    ERROR_ITS_SEC_CERT_NON_EXIST = -4114,                        /* The corresponding certificate doesn't exist, can't sign/encrypt message */
    ERROR_ITS_SEC_DEL_CERT_NUM_INCONSISTENT = -4115,             /* Number of deleted certs are not the same as number of whole cert */
    ERROR_ITS_SEC_CMNG_INIT_FAIL = -4116,                        /* ISC Certificate manager init fail */
    ERROR_ITS_SEC_ENCAP_UNSECURE_ERROR = -4117,                  /* Encap UnsecuredData fail */
    ERROR_ITS_SEC_SIGN_DATA_ERROR = -4118,                       /* Sign data fail */
    ERROR_ITS_SEC_VERIFY_DATA_ERROR = -4119,                     /* Verify data fail */
    ERROR_ITS_SEC_INVALID_AID = -4120,                           /* This AID value is invalid */
    ERROR_ITS_SEC_NO_CERT_INFO = -4121,                          /* Can't find certificate information */
    ERROR_ITS_SEC_CERT_EXPIRETIME_EXPIRED = -4122,               /* Certificate expired */
    ERROR_ITS_SEC_CERT_NO_PERMISSION = -4123,                    /* This certificate don't have enough Service Specific permission(SSP) */
    ERROR_ITS_SEC_INVALID_PROFILE_NAME = -4124,                  /* Invalid profile name */
    ERROR_ITS_SEC_DECAP_INVALID_FMT = -4125,                     /* Invalid EtsiTs103097 format */
    ERROR_ITS_SEC_DECAP_RAW_BUF_SIZE_NOT_ENOUGH = -4126,         /* Plaintext buffer size isn't enough */
    ERROR_ITS_SEC_DECAP_TOBESIGN_BUF_SIZE_NOT_ENOUGH = -4127,    /* Internal ToBeSign buffer size isn't enough */
    ERROR_ITS_SEC_DECAP_NO_CERT = -4128,                         /* SignerID: certificate, Can't be find in SPDU */
    ERROR_ITS_SEC_DECAP_CERT_CHAIN_EXCEED_SUPPORT_LEN = -4129,   /* Certificate chain exceed length of support */
    ERROR_ITS_SEC_DECAP_PREPROCESS_FAIL = -4130,                 /* Preprocess message fail */
    ERROR_ITS_SEC_NO_GPS = -4131,                                /* The GPS location is not available */
    ERROR_ITS_SEC_PKT_VER_ERR = -4132,                           /* The packet version is wrong */
    ERROR_ITS_SEC_PKT_CONTENT_ERR = -4133,                       /* The packet content is wrong */
    ERROR_ITS_SEC_GET_MATERIAL_CATALOG_ERROR = -4134,            /* Get material catalog from libdot2 fail */
    ERROR_ITS_SEC_DOT2_INIT_FAIL = -4135,                        /* (dot2)Fail to init the dot2 */
    ERROR_ITS_SEC_DOT2_EXIT_FAIL = -4136,                        /* (dot2)Fail to exit the dot2 */
    ERROR_ITS_SEC_DOT2_GEN_KEY_ERROR = -4137,                    /* (dot2)Fail to generate the key-pair */
    ERROR_ITS_SEC_DOT2_GET_CERT_HASH_ERROR = -4138,              /* (dot2)Fail to get the hashID of cert */
    ERROR_ITS_SEC_DOT2_GET_CMH_ERROR = -4139,                    /* (dot2)Fail to get the cmh */
    ERROR_ITS_SEC_CCMS_GET_CERT_ERROR = -4140,                   /* (CCMS)Fail to get the cert */
    ERROR_ITS_SEC_CCMS_INFO_EXISTED = -4141,                     /* (CCMS)Info is existed */
    ERROR_ITS_SEC_CCMS_DEL_INFO_ERROR = -4142,                   /* (CCMS)Fail to delete the info */
    ERROR_ITS_SEC_CCMS_HANDLE_AUTH_CERT_ERROR = -4143,           /* (CCMS)Fail to handle the authority cert */
    ERROR_ITS_SEC_CCMS_GET_EC_ERROR = -4144,                     /* (CCMS)Fail to get the EC */
    ERROR_ITS_SEC_CCMS_PKT_VER_ERROR = -4145,                    /* (CCMS)The pkt ver is wrong */
    ERROR_ITS_SEC_CCMS_PKT_CONTENT_ERROR = -4146,                /* (CCMS)The pkt content is wrong */
    ERROR_ITS_SEC_ASN1_MEM_ERROR = -4147,                        /* Fail to get the mem by asn1_parser */
    ERROR_ITS_SEC_DELETE_STORED_CERT_FAIL = -4148,               /* Delete those certificates and keys storing in libdot2 fail */

    /* dsrc_security */
    ERROR_DSC_INVALID_PSID = -5120,                                   /* Invalid PSID */
    ERROR_DSC_DELETE_STORED_CERT_FAIL = -5121,                        /* Delete those certificates and keys storing in libdot2 fail */
    ERROR_DSC_LOAD_SIGNING_PRI_KEY_FAIL = -5122,                      /* Load ECDSA signging private key fail */
    ERROR_DSC_LOAD_ENCRYPT_PRI_KEY_FAIL = -5123,                      /* Load ECIES encrypt private key fail */
    ERROR_DSC_CMH_EXAHSTED = -5124,                                   /* dot2 CMH has exahsted, Can't acquire cmh more */
    ERROR_DSC_IMPORT_CA_CERT_ERROR = -5125,                           /* Import CA certificate error */
    ERROR_DSC_SAVE_CA_CERT_ERROR = -5126,                             /* Save CA certificate error */
    ERROR_DSC_IMPORT_EE_CERT_AND_KEY_ERROR = -5127,                   /* Import EE certificate and keys error */
    ERROR_DSC_SAVE_EE_CERT_AND_KEY_ERROR = -5128,                     /* Save EE certificate and keys error */
    ERROR_DSC_OPEN_UPDATE_CA_DIR_ERROR = -5129,                       /* Open update CA folder fail */
    ERROR_DSC_OPEN_UPDATE_EE_DIR_ERROR = -5130,                       /* Open update EE folder fail */
    ERROR_DSC_SET_REPETITIVE_PSID_PROFILE_MAPPING = -5131,            /* This PSID has been set to map other security profile */
    ERROR_DSC_SEC_PROFILE_TABLE_SIZE_NOT_ENOUGH = -5132,              /* The size of security profile table isn't enough */
    ERROR_DSC_FOLDER_PATH_BUF_SIZE_NOT_ENOUGH = -5133,                /* The size of folder path buffer isn't enough */
    ERROR_DSC_UPDATE_DIR_NOT_EXIST = -5134,                           /* Update folder dosen't exist */
    ERROR_DSC_CA_CERT_NOT_EXIST = -5135,                              /* CA certificates don't exist */
    ERROR_DSC_EE_CERT_NOT_EXIST = -5136,                              /* EE certificates or keys don't exist */
    ERROR_DSC_NONE_VALID_CERT = -5137,                                /* None valid certificate */
    ERROR_DSC_DELETE_CMD_BUF_SIZE_NOT_ENOUGH = -5138,                 /* The buffer size of deleted command isn't enough */
    ERROR_DSC_DELETE_UPDATE_FOLDER_ERROR = -5139,                     /* Delete folder for updating certificates fail */
    ERROR_DSC_MAKE_UPDATE_FOLDER_ERROR = -5140,                       /* Make Update folder fail */
    ERROR_DSC_MAKE_UPDATE_CA_FOLDER_ERROR = -5141,                    /* Make Update CA folder fail */
    ERROR_DSC_MAKE_UPDATE_EE_FOLDER_ERROR = -5142,                    /* Make Update EE folder fail */
    ERROR_DSC_OPEN_CERT_FILE_ERROR = -5143,                           /* Open certificate file fail */
    ERROR_DSC_CERT_MAPPING_TBL_SIZE_NOT_ENOUGH = -5144,               /* The size of certificate mapping table isn't enough */
    ERROR_DSC_OPEN_SECURITY_CONFIG_FILE_ERROR = -5145,                /* Open security config file fail */
    ERROR_DSC_PARSE_SECURITY_CONFIG_FILE_ERROR = -5146,               /* Parse security config file fail */
    ERROR_DSC_GET_MATERIAL_CATALOG_ERROR = -5147,                     /* Get material catalog from libdot2 fail */
    ERROR_DSC_SECURITY_CONFIG_FILE_PROFILE_TYPE_ERROR = -5148,        /* The profile type of security config file is incorrect */
    ERROR_DSC_SECURITY_SYS_PROFILE_NON_EXIST = -5149,                 /* This security system build-in profile doesn't exist */
    ERROR_DSC_SECURITY_USR_PROFILE_NON_EXIST = -5150,                 /* This security user customzied profile doesn't exist */
    ERROR_DSC_SECURITY_PROFILE_MAPPING_NON_EXIST = -5151,             /* This security profile mapping doesn't exist */
    ERROR_DSC_SECURITY_PROFILE_NOT_SUPPORT_VERIFY_SIGNED_MSG = -5152, /* This security profile dosen't support to verify signed message */
    ERROR_DSC_SECURITY_UNKNOWN_PROFILE_TYPE = -5153,                  /* This security profile type is unsuppoted */
    ERROR_DSC_CONFIG_UNKNOWN_PROFILE_TYPE = -5154,                    /* This is a unknown config profile type */
    ERROR_DSC_ENCAP_UNSECURE_MSG_ERROR = -5155,                       /* Encap unsecured msg fail */
    ERROR_DSC_ENCAP_SIGN_MSG_ERROR = -5156,                           /* Encap signed msg fail */
    ERROR_DSC_CERT_EXPIRE = -5157,                                    /* Expiry time of certificate is invalid */
    ERROR_DSC_DECAP_INVALID_FMT = -5158,                              /* Invalid ieee1609.2 format */
    ERROR_DSC_DECAP_RAW_BUF_SIZE_NOT_ENOUGH = -5159,                  /* Plaintext buffer size isn't enough */
    ERROR_DSC_DECAP_TOBESIGN_BUF_SIZE_NOT_ENOUGH = -5160,             /* Internal ToBeSign buffer size isn't enough */
    ERROR_DSC_DECAP_NO_CERT_OF_SIGNED_PKT = -5161,         /* SignerID: certificate, It can't be found for this Signed pkt that is received */
    ERROR_DSC_DECAP_CERT_CHAIN_EXCEED_SUPPORT_LEN = -5162, /* SignerID certificate chain exceed length of support */
    ERROR_DSC_DECAP_MSG_PREPROCESS_FAIL = -5163,           /* Preprocess message fail */
    ERROR_DSC_DECAP_VERIFY_DATA_ERROR = -5164,             /* Verify message fail */
    ERROR_DSC_CERT_MAPPING_TBL_NON_CERT_ITEM = -5165,      /* None certificate items of assigned psid in Certificate mapping table */
    DSC_UNSECURED_PKT = -5166,                             /* This pkt format is an unsecured dot2 pkt */
    ERROR_DSC_ENCAP_OUTPUT_BUF_SIZE_NOT_ENOUGH = -5167,    /* The output msg buffer is not enough for encapsulated SPDU */
    ERROR_DSC_LOAD_EE_MATERIAL_ERROR = -5168,              /* Load EE cert and keys into dot2 CMH error */
    ERROR_DSC_CERT_APP_PERMISSION_NOT_SUPPORT = -5169,     /* EE cert doesn't support this specific APP permission */

    /* v2xcast */
    ERROR_V2XCAST_SERVICE_COMM_CONFIG_INVAILD = -6144,                      /* Communication config is invalid */
    ERROR_V2XCAST_SERVICE_CASTER_LIMIT = -6145,                             /* Caster Input parameters are invalid */
    ERROR_V2XCAST_SERVICE_CASTER_EXISTS = -6146,                            /* Caster exists */
    ERROR_V2XCAST_SERVICE_CASTER_INVALID = -6147,                           /* Caster invalid */
    ERROR_V2XCAST_SERVICE_CASTER_CREATE_FAIL = -6148,                       /* Caster creation fail */
    ERROR_V2XCAST_SERVICE_CASTER_RELEASE_FAIL = -6149,                      /* Caster release fail */
    ERROR_V2XCAST_SERVICE_CASTER_DESTROYED = -6150,                         /* Caster destroyed */
    ERROR_V2XCAST_SERVICE_CASTER_CARRIER_FAIL = -6151,                      /* Caster carrier fail */
    ERROR_V2XCAST_SERVICE_CASTER_UNKNOWN_REQUEST_TYPE = -6152,              /* Caster unknown request type */
    ERROR_V2XCAST_SERVICE_POTI_CREATE_FAIL = -6153,                         /* Poti creation fail */
    ERROR_V2XCAST_SERVICE_POTI_RX_FAIL = -6154,                             /* Poti receiving fail */
    ERROR_V2XCAST_SERVICE_POTI_RELEASE_FAIL = -6155,                        /* Poti release fail */
    ERROR_V2XCAST_SERVICE_POTI_CARRIER_FAIL = -6156,                        /* Poti carrier fail */
    ERROR_V2XCAST_SESSION_CREATE_FAIL = -6157,                              /* Session creation fail */
    ERROR_V2XCAST_SESSION_CONNECT_FAIL = -6158,                             /* Session connection fail */
    ERROR_V2XCAST_SESSION_CLOSE_FAIL = -6159,                               /* Session close fail */
    ERROR_V2XCAST_SESSION_TRANSMIT_FAIL = -6160,                            /* Session transmition fail */
    ERROR_V2XCAST_SESSION_INIT_RESOURCE_FAIL = -6161,                       /* Session init resource fail */
    ERROR_V2XCAST_SESSION_RECEIVE_FAIL = -6162,                             /* Session receiving fail */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_COMMON_CONFIG_INVALID = -6163,         /* Caster create fail due to invalid common config */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_IP_CONFIG_INVALID = -6164,             /* Caster create fail due to invalid IP config */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_CASTER_NUMBER_OVER_LIMIT = -6165,      /* Caster create fail due to caster number over limit */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_SETUP_SIGNAL_FAIL = -6166,             /* Caster create fail due to setup signal fail */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_V2XCAST_SERVICE_NOT_AVAILABLE = -6167, /* Caster create fail due to V2Xcast service is not available */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_TX_SESSION_CREATE_FAIL = -6168,        /* Caster create fail due to TX session create fail */
    ERROR_V2XCAST_CASTER_CREATE_FAIL_RX_SESSION_CREATE_FAIL = -6169,        /* Caster create fail due to RX session create fail */
    ERROR_V2XCAST_CASTER_TX_FAIL_CASTER_NOT_EXIST = -6170,                  /* Caster TX fail due to caster not exist */
    ERROR_V2XCAST_CASTER_TX_FAIL_COMMUNICATION_MODE_MISMTACH =
        -6171, /* Caster TX fail due to communication mode mismatch between requested caster and configured caster */
    ERROR_V2XCAST_CASTER_TX_FAIL_SESSION_CREATE_FAIL = -6172, /* Caster TX fail due to session create fail */
    ERROR_V2XCAST_CASTER_TX_FAIL_CARRIER_ALLOC_FAIL = -6173,  /* Caster TX fail due to carrier allocate fail */
    ERROR_V2XCAST_CASTER_TX_FAIL_CARRIER_ENCODE_FAIL = -6174, /* Caster TX fail due to carrier encode fail */
    ERROR_V2XCAST_CASTER_TX_FAIL_CARRIER_DECODE_FAIL = -6175, /* Caster TX fail due to carrier decode fail */
    ERROR_V2XCAST_CASTER_TX_FAIL_TX_REQ_SEND_FAIL = -6176,    /* Caster TX fail due to TX REQ send fail */
    ERROR_V2XCAST_CASTER_TX_FAIL_TX_RSP_RECEIVE_FAIL = -6177, /* Caster TX fail due to TX RSP receive fail */
    ERROR_V2XCAST_CASTER_RX_FAIL_CASTER_NOT_EXIST = -6178,    /* Caster RX fail due to caster not exist */
    ERROR_V2XCAST_CASTER_RX_FAIL_COMMUNICATION_MODE_MISMTACH =
        -6179, /* Caster RX fail due to communication mode mismatch between requested caster and configured caster */
    ERROR_V2XCAST_CASTER_RX_FAIL_RX_SUB_FAIL = -6180,                           /* Caster RX fail due to RX SUB fail */
    ERROR_V2XCAST_CASTER_SPLMNT_REQ_SEND_FAIL = -6181,                          /* Caster SPLMNT REQ send fail */
    ERROR_V2XCAST_CASTER_SPLMNT_RSP_RECEIVE_FAIL = -6182,                       /* Caster SPLMNT RSP receive fail */
    ERROR_V2XCAST_CASTER_RELEASE_FAIL_CASTER_NOT_EXIST = -6183,                 /* Caster release fail due to caster not exist */
    ERROR_V2XCAST_SERVICE_BTP_INIT_FAIL_BTP_TYPE_INVALID = -6184,               /* Service BTP create fail due to invalid BTP type */
    ERROR_V2XCAST_SERVICE_BTP_INIT_FAIL_BTP_DIRECTION_INVALID = -6185,          /* Service BTP create fail due to invalid BTP direction */
    ERROR_V2XCAST_SERVICE_TX_THREAD_CREATE_FAIL = -6186,                        /* Service TX thread create fail */
    ERROR_V2XCAST_SERVICE_TX_SESSION_CREATE_FAIL = -6187,                       /* Service TX session create fail */
    ERROR_V2XCAST_SERVICE_TX_NOT_CARRIER_MODE = -6188,                          /* Service TX is not carrier mode */
    ERROR_V2XCAST_SERVICE_TX_RSP_CARRIER_ALLOC_FAIL = -6189,                    /* Service TX RSP carrier allocate fail */
    ERROR_V2XCAST_SERVICE_TX_RSP_CARRIER_ENCODE_FAIL = -6190,                   /* Service TX RSP carrier encode fail */
    ERROR_V2XCAST_SERVICE_TX_RSP_CARRIER_DECODE_FAIL = -6191,                   /* Service TX RSP carrier decode fail */
    ERROR_V2XCAST_SERVICE_TX_REQ_RECEIVE_FAIL = -6192,                          /* Service TX REQ receive fail */
    ERROR_V2XCAST_SERVICE_TX_RSP_SEND_FAIL = -6193,                             /* Service TX RSP send fail */
    ERROR_V2XCAST_SERVICE_RX_THREAD_CREATE_FAIL = -6194,                        /* Service RX thread create fail */
    ERROR_V2XCAST_SERVICE_RX_SESSION_CREATE_FAIL = -6195,                       /* Service RX session create fail */
    ERROR_V2XCAST_SERVICE_RX_PUB_CARRIER_ALLOC_FAIL = -6196,                    /* Service RX PUB carrier allocate fail */
    ERROR_V2XCAST_SERVICE_RX_PUB_CARRIER_ENCODE_FAIL = -6197,                   /* Service RX PUB carrier encode fail */
    ERROR_V2XCAST_SERVICE_RX_PUB_SEND_FAIL = -6198,                             /* Service RX PUB send fail */
    ERROR_V2XCAST_SERVICE_SPLMNT_THREAD_CREATE_FAIL = -6199,                    /* Service SPLMNT thread create fail */
    ERROR_V2XCAST_SERVICE_SPLMNT_SESSION_CREATE_FAIL = -6200,                   /* Service SPLMNT session create fail */
    ERROR_V2XCAST_SERVICE_SPLMNT_REQ_RECEIVE_FAIL = -6201,                      /* Service SPLMNT REQ receive fail */
    ERROR_V2XCAST_SERVICE_SPLMNT_RSP_SEND_FAIL = -6202,                         /* Service SPLMNT RSP send fail */
    ERROR_V2XCAST_POTI_CASTER_CREATE_FAIL_COMMON_CONFIG_INVALID = -6203,        /* POTI caster create fail due to invalid common config */
    ERROR_V2XCAST_POTI_CASTER_CREATE_FAIL_IP_CONFIG_INVALID = -6204,            /* POTI caster create fail due to invalid IP config */
    ERROR_V2XCAST_POTI_CASTER_CREATE_FAIL_CASTER_NUMBER_OVER_LIMIT = -6205,     /* POTI caster create fail due to caster number over limit */
    ERROR_V2XCAST_POTI_CASTER_CREATE_FAIL_SETUP_SIGNAL_FAIL = -6206,            /* POTI caster create fail due to setup signal fail */
    ERROR_V2XCAST_POTI_CASTER_GNSS_INFO_GET_FAIL_CASTER_NOT_EXIST = -6207,      /* POTI caster GNSS info get fail due to caster not exist */
    ERROR_V2XCAST_POTI_CASTER_GNSS_INFO_GET_FAIL_REQ_ENCODE_FAIL = -6208,       /* POTI caster GNSS info get fail due to REQ encode fail */
    ERROR_V2XCAST_POTI_CASTER_GNSS_INFO_GET_FAIL_REQ_SEND_FAIL = -6209,         /* POTI caster GNSS info get fail due to RX REQ send fail */
    ERROR_V2XCAST_POTI_CASTER_GNSS_INFO_GET_FAIL_RSP_RECEIVE_FAIL = -6210,      /* POTI caster GNSS info get fail due to RSP receive fail */
    ERROR_V2XCAST_POTI_CASTER_GNSS_INFO_GET_FAIL_RSP_DECODE_FAIL = -6211,       /* POTI caster GNSS info get fail due to RSP decode fail */
    ERROR_V2XCAST_POTI_CASTER_FIX_DATA_GET_FAIL_CASTER_NOT_EXIST = -6212,       /* POTI caster fix data get fail due to caster not exist */
    ERROR_V2XCAST_POTI_CASTER_FIX_DATA_GET_FAIL_REQ_ENCODE_FAIL = -6213,        /* POTI caster fix data get fail due to REQ encode fail */
    ERROR_V2XCAST_POTI_CASTER_FIX_DATA_GET_FAIL_REQ_SEND_FAIL = -6214,          /* POTI caster fix data get fail due to RX REQ send fail */
    ERROR_V2XCAST_POTI_CASTER_FIX_DATA_GET_FAIL_RSP_RECEIVE_FAIL = -6215,       /* POTI caster fix data get fail due to RSP receive fail */
    ERROR_V2XCAST_POTI_CASTER_FIX_DATA_GET_FAIL_RSP_DECODE_FAIL = -6216,        /* POTI caster fix data get fail due to RSP decode fail */
    ERROR_V2XCAST_POTI_CASTER_RELEASE_FAIL_CASTER_NOT_EXIST = -6217,            /* POTI caster release fail due to caster not exist */
    ERROR_V2XCAST_POTI_SERVICE_SETUP_SIGNAL_FAIL = -6218,                       /* POTI service setup signal fail */
    ERROR_V2XCAST_POTI_SERVICE_CREATE_FAIL = -6219,                             /* POTI service create fail */
    ERROR_V2XCAST_POTI_SERVICE_REQ_TYPE_INVALID = -6220,                        /* POTI service REQ type invalid */
    ERROR_V2XCAST_POTI_SERVICE_GNSS_INFO_PROVIDE_FAIL_REQ_RECEIVE_FAIL = -6221, /* POTI service GNSS info provide due to REQ receive fail */
    ERROR_V2XCAST_POTI_SERVICE_GNSS_INFO_PROVIDE_FAIL_REQ_DECODE_FAIL = -6222,  /* POTI service GNSS info provide due to REQ decode fail */
    ERROR_V2XCAST_POTI_SERVICE_GNSS_INFO_PROVIDE_FAIL_RSP_ENCODE_FAIL = -6223,  /* POTI service GNSS info provide due to RSP encode fail */
    ERROR_V2XCAST_POTI_SERVICE_GNSS_INFO_PROVIDE_FAIL_RSP_SEND_FAIL = -6224,    /* POTI service GNSS info provide due to RSP send fail */
    ERROR_V2XCAST_POTI_SERVICE_FIX_DATA_PROVIDE_FAIL_REQ_RECEIVE_FAIL = -6225,  /* POTI service fix data provide due to REQ receive fail */
    ERROR_V2XCAST_POTI_SERVICE_FIX_DATA_PROVIDE_FAIL_REQ_DECODE_FAIL = -6226,   /* POTI service fix data provide due to REQ decode fail */
    ERROR_V2XCAST_POTI_SERVICE_FIX_DATA_PROVIDE_FAIL_RSP_ENCODE_FAIL = -6227,   /* POTI service fix data provide due to RSP encode fail */
    ERROR_V2XCAST_POTI_SERVICE_FIX_DATA_PROVIDE_FAIL_RSP_SEND_FAIL = -6228,     /* POTI service fix data provide due to RSP send fail */
    ERROR_V2XCAST_CONFIG_GBC_BUT_NO_POSITION_INFO = -6229,                      /* Config GBC, but no position info */
    ERROR_V2XCAST_CONFIG_GBC_AREA_DISTANCE_IS_ZERO = -6230,                     /* Config GBC area distance is zero */
    ERROR_V2XCAST_CONFIG_SECURITY_PROFILE_NOT_FOUND = -6231,                    /* Config security prifile is not found */
    ERROR_V2XCAST_CONFIG_SSP_INVAILD_PERMISSIONS = -6232,                       /* Config SSP is invalid permissions */
    ERROR_V2XCAST_CONFIG_SECURITY_FLAG_IS_ON_BUT_GN_CONFIG_SECURITY_NOT_ACTIVATED = -6233, /* Config security flag on, but GN security is off */
    ERROR_V2XCAST_CONFIG_SECURITY_FLAG_IS_OFF_BUT_GN_CONFIG_SECURITY_ACTIVATED = -6234,    /* Config security flag off, but GN security is on */
    ERROR_V2XCAST_CONFIG_AID_CERTIFICATE_NOT_FOUND = -6235,                                /* Config AID cert is not found */
    ERROR_V2XCAST_CONFIG_AID_ALREADY_USED = -6236,                                         /* Config AID is used */
    ERROR_V2XCAST_CONFIG_AID_INVALID = -6237,                                              /* Config AID is invalid */
    ERROR_V2XCAST_UNKNOWN = -6238,                                                         /* Unknown error */

    /* dot2 */
    ERROR_DOT2_FOLDER_CREATE_ERROR = -7168,                     /* Create dot2 internal folder fail */
    ERROR_DOT2_CATALOG_DB_ACCESS_ERROR = -7169,                 /* Access dot2 database error */
    ERROR_DOT2_JSON_ENCODE_ERROR = -7170,                       /* Encode JSON of material error */
    ERROR_DOT2_JSON_DECODE_ERROR = -7171,                       /* Decode JSON of material error */
    ERROR_DOT2_JSON_DB_OPERATE_ERROR = -7172,                   /* Operate apis of JDB  error */
    ERROR_DOT2_OPEN_SECURE_MATERIAL_ERROR = -7173,              /* Open secure material error */
    ERROR_DOT2_DELETE_SECURE_MATERIAL_ERROR = -7174,            /* Delete secure material error */
    ERROR_DOT2_WRITE_SECURE_MATERIAL_ERROR = -7175,             /* WRITE secure material error */
    ERROR_DOT2_READ_SECURE_MATERIAL_ERROR = -7176,              /* READ secure material error */
    ERROR_DOT2_NON_EXIST_SECURE_MATERIAL = -7177,               /* None secure material */
    ERROR_DOT2_HSM_MATERIAL_WRITE_ERROR = -7178,                /* Write HSM material error */
    ERROR_DOT2_HSM_MATERIAL_READ_ERROR = -7179,                 /* Read HSM material error */
    ERROR_DOT2_HSM_MATERIAL_DELETE_ERROR = -7180,               /* Delete HSM material error */
    ERROR_DOT2_MATERIAL_IS_EXISTED_IN_DB = -7181,               /* This material has been existed in database */
    ERROR_DOT2_DB_NAME_OF_UNIQUE_KEY_GET_ERROR = -7182,         /* Get name of unique key of database error */
    ERROR_DOT2_PARSE_CERT_FAIL = -7183,                         /* Parse certificate failed, it is invalid format */
    ERROR_DOT2_RECONSTRUCT_PUBLIC_KEY_ERROR = -7184,            /* Reconstrct public key error */
    ERROR_DOT2_RECONSTRUCT_PRIVATE_KEY_ERROR = -7185,           /* Reconstrct private key error */
    ERROR_DOT2_KEYPAIR_NOT_MATCH = -7186,                       /* The private key and corresponding public key , they don't match */
    ERROR_DOT2_GET_MATCHABLE_PUBKEY_FAIL = -7187,               /* Get the corresponding matchable public key fail */
    ERROR_DOT2_SIGNER_CERT_CHAIN_OVER_SUPPORTED_LENGTH = -7188, /* Length of signer certificate chain over supported lengh */
    ERROR_DOT2_ASN1_ENCODE_ERROR = -7189,                       /* DOT2 asn1 encode fail */
    ERROR_DOT2_ASN1_DECODE_ERROR = -7190,                       /* DOT2 asn1 decode fail */
    ERROR_DOT2_TOBESIGN_DATA_EXCEED_BUF_SIZE = -7191,           /* The length of tobesign data exceeds buffer size */
    ERROR_DOT2_CERT_LENGTH_EXCEED_BUF_SIZE = -7192,             /* The length of certificate exceeds buffer size */
    ERROR_DOT2_UNSECURED_DATA_EXCEED_BUF_SIZE = -7193,          /* The length of unsecured data exceeds buffer size */
    ERROR_DOT2_SIGNED_DATA_EXCEED_BUF_SIZE = -7194,             /* The length of signed data exceeds buffer size */
    ERROR_DOT2_ENCRYPTED_DATA_EXCEED_BUF_SIZE = -7195,          /* The length of encrypted data exceeds buffer size */
    ERROR_DOT2_DECRYPTED_DATA_EXCEED_BUF_SIZE = -7196,          /* The length of decrypted data exceeds buffer size */
    ERROR_DOT2_UNSUPPORT_RECIPIENTINFO_TYPE = -7197,            /* Currently, unsupport this recipientinfo type */
    ERROR_DOT2_GET_CERT_RECIPIENTINFO_FAIL = -7198,             /* Get the certificate recipientinfo fail, it didn't be loaded into CMH */
    ERROR_DOT2_SPDU_SIGNER_CERT_NUM_EXCEED_LIMIT = -7199,       /* Number of signer ceritifcate of SPDU exceeds limited number */
    ERROR_DOT2_RECONSTRUCT_PRIVKEY_FAIL = -7200,                /* Reconstruct privkey fail */
    ERROR_DOT2_RECONSTRUCT_PUBKEY_FAIL = -7201,                 /* Reconstruct pubkey fail */
    ERROR_DOT2_NO_RECIPIENT_INFO = -7202,                       /* No corresponding recipient info */
    ERROR_DOT2_NO_CERT_OF_SIGNED_PKT = -7203,                   /* No corresponding certificate for this signed packet */
    ERROR_DOT2_GET_CERT_SSP_FAIL = -7204,                       /* Get SSP of certificate fail */
    ERROR_DOT2_GET_CERT_APP_PERMISSION_FAIL = -7205,            /* Get app permission of certificate fail */
    ERROR_DOT2_GET_CERT_ISSUE_PERMISSION_FAIL = -7206,          /* Get issue permission of certificate fail */
    ERROR_DOT2_HSM_INIT_FAIL = -7207,                           /* Initialize HSM fail */
    ERROR_DOT2_GPS_INIT_FAIL = -7208,                           /* Initialize GPS fail */
    ERROR_DOT2_VERIFY_MSG_FAIL = -7209,                         /* Verify message fail */
    ERROR_DOT2_HASH_MSG_FAIL = -7210,                           /* Hash message fail */
    ERROR_DOT2_SIGN_MSG_FAIL = -7211,                           /* Sign message fail */
    ERROR_DOT2_ENCRYPT_MSG_FAIL = -7212,                        /* Encrypt message fail */
    ERROR_DOT2_DECRYPT_MSG_FAIL = -7213,                        /* Decrypt message fail */
    ERROR_DOT2_GEN_ENCRYPTED_ENCRYPTION_KEY_FAIL = -7214,       /* Generate encrypted encryption key fail */
    ERROR_DOT2_ECC_COMPRESS_FAIL = -7215,                       /* ECC compress fail */
    ERROR_DOT2_ECC_DECOMPRESS_FAIL = -7216,                     /* ECC decompress fail */
    ERROR_DOT2_CREATE_ECC_PRIVKEY_FAIL = -7217,                 /* Create ECC private key fail */
    ERROR_DOT2_IMPORT_HSM_ECC_PRIVKEY_FAIL = -7218,             /* Import HSM ECC private key fail */
    ERROR_DOT2_DELETE_HSM_ECC_PRIVKEY_FAIL = -7219,             /* Delete HSM ECC private key fail */
    ERROR_DOT2_GET_HSM_ECC_PUBKEY_FAIL = -7220,                 /* Get HSM ECC public key fail */
    ERROR_DOT2_GEN_RAND_DATA_FAIL = -7221,                      /* Generate random data fail */
    ERROR_DOT2_DECRYPT_ENCRYPTION_KEY_FAIL = -7222,             /* Decrypt encrypted encryption key fail */
    ERROR_DOT2_PUB_CMH_NO_SIGNER_CERT = -7223,                  /* No signer certificate in public crypto material handler */
    ERROR_DOT2_SAVE_PUBLIC_CERT_FAIL = -7224,                   /* Import certificate in public crypto material handler fail */
    ERROR_DOT2_KICK_OFF_PUBLIC_CERT = -7225,                    /* Kick off certificate in crypto material handler */
    ERROR_DOT2_CMH_NOT_IN_CORRECT_STATUS = -7226,               /* CMH handler isn't in correct status */
    ERROR_DOT2_CMH_NO_PRIVATE_SEED = -7227,             /* Can't find private seed that can be used to reconstruct private key in CMH Handler */
    ERROR_DOT2_REQUEST_CMH_HANDLER_FAIL = -7228,        /* Request a avaliable crypto material handler fail */
    ERROR_DOT2_RELEASE_CMH_HANDLER_FAIL = -7229,        /* Release a avaliable crypto material handler error */
    ERROR_DOT2_GET_CMH_PRIVKEY_IDX_FAIL = -7230,        /* Get privkey idx in crypto material handler fail */
    ERROR_DOT2_GET_CMH_CERT_HASHID_FAIL = -7231,        /* Get hashid of certificate in crypto material handler fail */
    ERROR_DOT2_GET_CMH_CERT_DATA_FAIL = -7232,          /* Get data of certificate in crypto material handler fail */
    ERROR_DOT2_GET_CMH_ECC_CURVE_FAIL = -7233,          /* Get ecc curve in crypto material handler fail */
    ERROR_DOT2_GET_CMH_SIGNER_CERT_FAIL = -7234,        /* Get specific signer certificate in crypto material handler fail */
    ERROR_DOT2_SKH_NOT_IN_CORRECT_STATUS = -7235,       /* symmetric key handler isn't in correct status */
    ERROR_DOT2_REQUEST_SKH_HANDLER_FAIL = -7236,        /* Request a avaliable symmetric key handler fail */
    ERROR_DOT2_RELEASE_SKH_HANDLER_FAIL = -7237,        /* Release a avaliable symmetric key handler error */
    ERROR_DOT2_REPLAYED_MSG = -7238,                    /* That is a replayed message */
    ERROR_DOT2_GET_GPS_DATA_FAIL = -7239,               /* Get GPS data fail */
    ERROR_DOT2_CALC_DISTANCE_FAIL = -7240,              /* Calculate Distance fail */
    ERROR_DOT2_INVALID_DISTANCE = -7241,                /* The distance of location is invalid  */
    ERROR_DOT2_MSG_PSID_INCONSISTENT_WITH_CERT = -7242, /* PSIDs of SPDU are inconsistent with PSIDs of certificate */
    ERROR_DOT2_CERT_ISSUE_PERMISSION_INCONSISTENT_WITH_SIGNER_CERT =
        -7243,                                                    /* Issue permission of certificate is inconsistent with signer certificate */
    ERROR_DOT2_CERT_IN_INVALID_REGION = -7244,                    /* The ceritificate is invalid in current region */
    ERROR_DOT2_MSG_EXPIRE_TIME_LATER_THAN_CERT = -7245,           /* The expire data of message is later than certificate */
    ERROR_DOT2_MSG_EXPIRE_TIME_EARLIER_THAN_CERT = -7246,         /* The expire data of message is earlier than certificate */
    ERROR_DOT2_CERT_IS_EXPIRED_COMPARE_TO_THE_MSG = -7247,        /* Comparing to signed message, the certificate is expired */
    ERROR_DOT2_MSG_IS_EXPIRED_COMPARE_TO_THE_CERT = -7248,        /* Comparing to certificate, the message is expired */
    ERROR_DOT2_MSG_IS_EXPIRED_COMPARE_TO_CURR_TIME = -7249,       /* Comparing to current time, the signed message is expired */
    ERROR_DOT2_MSG_NO_AVALIABLE_LOC_DATA = -7250,                 /* The location of message is invalid */
    ERROR_DOT2_INVALID_MSG_GEN_TIME = -7251,                      /* The generation time of message is invalid */
    ERROR_DOT2_INVALID_MSG_EXPIRE_TIME = -7252,                   /* The expire time of message is invalid */
    ERROR_DOT2_INCOMPLETE_CERT_CHAIN = -7253,                     /* Incomplete certificate chain for verification */
    ERROR_DOT2_CERT_EXPIRE_TIME_LATER_THAN_SIGNER_CERT = -7254,   /* The expire time of certificate is later than signer cerificate */
    ERROR_DOT2_CERT_EXPIRE_TIME_EARLIER_THAN_SIGNER_CERT = -7255, /* The expire time of certificate is earlier than signer cerificate */
    ERROR_DOT2_SIGNED_CERT_REQ_DATA_EXCEED_BUF_SIZE = -7256,      /* The length of signedCertificateRequest data exceeds buffer size */
    ERROR_DOT2_MATERIAL_HAS_BEEN_LOADED_INTO_HANDLER = -7257,     /* This material has been loaded into handler */
    ERROR_DOT2_GET_PSK_RECIPIENTINFO_FAIL = -7258,                /* Get the preShareKey recipientinfo fail, it didn't be loaded into SCMH */
    ERROR_DOT2_CERT_IS_EXPIRED = -7259,                           /* the certificate is expired */
    ERROR_DOT2_SSP_PERMISSION_DENIED = -7260,                     /* Service Specific Permission denied */

    /* v2xcastd */
    ERROR_V2XCASTD_START_END_UPLD_QUERY_STR_INVALID = -8192, /* Invalid query string of start/end upload */
    ERROR_V2XCASTD_MATERIAL_UPLD_QUERY_STR_INVALID = -8193,  /* Invalid query string of secure material upload */
    ERROR_V2XCASTD_READ_UPLD_STATUS_FAIL = -8194,            /* Read uploading status fail */
    WRONG_V2XCASTD_UPLD_STATUS_INSTALL_MATERIAL = -8195,     /* Upload status: Installing */
    WRONG_V2XCASTD_UPLD_STATUS_NOT_UPLOADING = -8196,        /* Upload status: Not uploading */
    ERROR_V2XCASTD_WRITE_MATERIAL_FAIL = -8197,              /* Write material fail */
    ERROR_V2XCASTD_GET_UPLD_FOLDER_PATH_FAIL = -8198,        /* Get folder path of uploaded material fail */
    ERROR_V2XCASTD_INIT_UPLD_STATUS_FAIL = -8199,            /* Init status of uploading fail */
    ERROR_V2XCASTD_INIT_UPLD_FOLDER_FAIL = -8200,            /* Init folder of uploading fail */
    ERROR_V2XCASTD_SECURITY_DISABLE = -8201,                 /* V2Xcast security disable */

} error_code_e;

#endif  // __ERROR_CODE_ENUM_H__