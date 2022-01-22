/* J2735 TIM definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __J2735_TIM_H__
#define __J2735_TIM_H__

#include "j2735_data_component.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TravelerInformation {
    int32_t msgCnt; /* MsgCount (0..127) */
    BOOL timeStamp_option;
    int32_t timeStamp; /* MinuteOfTheYear (0..527040) */
    BOOL packetID_option;
    OctetString packetID; /* UniqueMSGID (9..9) */
    BOOL urlB_option;
    OctetString urlB; /* URL_Base (1..45) */
    TravelerDataFrameList dataFrames;
    BOOL regional_option;
    Reg_TravelerInformationList regional;
} TravelerInformation;

#ifdef __cplusplus
}
#endif

#endif /* __J2735_TIM_H__ */
