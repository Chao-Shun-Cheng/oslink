/* J2735 SRM definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __J2735_SRM_H__
#define __J2735_SRM_H__

#include "j2735_data_component.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SignalRequestMessage {
    BOOL timeStamp_option;
    int32_t timeStamp; /* MinuteOfTheYear (0..527040) */
    int32_t second;    /* DSecond (0..65535) */
    BOOL sequenceNumber_option;
    int32_t sequenceNumber; /* MsgCount (0..127) */
    BOOL requests_option;
    SignalRequestList requests;
    RequestorDescription requestor;
    BOOL regional_option;
    Reg_SignalRequestMessageList regional;
} SignalRequestMessage;

#ifdef __cplusplus
}
#endif

#endif /* __J2735_SRM_H__ */
