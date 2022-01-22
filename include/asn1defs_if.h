/*
 * ASN1 definitions for interface
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */
#ifndef __ASN1_DEFS_IF_H__
#define __ASN1_DEFS_IF_H__

#include <stdint.h>

#ifndef _BOOL_defined
#define _BOOL_defined

typedef int BOOL;
enum {
    FALSE = 0,
    TRUE = 1,
};
#endif

typedef struct OctetString {
    uint8_t *buf;
    int len; /* len is in bytes */
} OctetString;

typedef struct BitString {
    uint8_t *buf;
    int len; /* len is in bits. buf contains ceil(len/8) bytes */
} BitString;

typedef struct BigInteger {
    uint32_t *data;
    int len;           /* 0 is represented as len = 0 and negative = 0 or 1 */
    int allocated_len; /* length (>= len) allocated for tab */
    int negative;      /* 0 = positive, 1 = negative */
} BigInteger;

#endif /* __ASN1_DEFS_IF_H__ */
