/* J2735 sSM definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __J2735_SSM_H__
#define __J2735_SSM_H__

#include "j2735_data_component.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SignalStatusMessage {
    BOOL timeStamp_option;
    int32_t timeStamp; /* MinuteOfTheYear (0..527040) */
    int32_t second;    /* DSecond (0..65535) */
    BOOL sequenceNumber_option;
    int32_t sequenceNumber; /* MsgCount (0..127) */
    SignalStatusList status;
    BOOL regional_option;
    Reg_SignalStatusMessageList regional;
} SignalStatusMessage;

#ifdef __cplusplus
}
#endif

#endif /* __J2735_SSM_H__ */
