/* J2735 SPAT definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __J2735_SPAT_H__
#define __J2735_SPAT_H__

#include "j2735_data_component.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SPAT {
    BOOL timeStamp_option;
    int32_t timeStamp; /* MinuteOfTheYear (0..527040) */
    BOOL name_option;
    OctetString name; /* DescriptiveName (1..63) */
    IntersectionStateList intersections;
    BOOL regional_option;
    Reg_SPATList regional;
} SPAT;

#ifdef __cplusplus
}
#endif

#endif /* __J2735_SPAT_H__ */
