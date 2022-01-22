/* J2735 message definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __J2735_MSG_H__
#define __J2735_MSG_H__
#include "j2735_bsm.h"
#include "j2735_map.h"
#include "j2735_rtcm.h"
#include "j2735_spat.h"
#include "j2735_srm.h"
#include "j2735_ssm.h"
#include "j2735_tim.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum DSRCmsgID {
    MessageFrame_Id = 0,
    MapData_Id = 18,
    SPAT_Id = 19,
    BasicSafetyMessage_Id = 20,
    CommonSafetyRequest_Id = 21,
    EmergencyVehicleAlert_Id = 22,
    IntersectionCollision_Id = 23,
    NmeaCorrections_Id = 24,
    ProbeDataManagement_Id = 25,
    ProbeVehicleData_Id = 26,
    RoadSideAlert_Id = 27,
    RtcmCorrections_Id = 28,
    SignalRequestMessage_Id = 29,
    SignalStatusMessage_Id = 30,
    TravelerInformation_Id = 31,
    PersonalSafetyMessage_Id = 32,
    DSRCmsgID_MAX = UINT_MAX
} DSRCmsgID;

typedef struct MessageFrame {
    DSRCmsgID messageId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} MessageFrame;

#ifdef __cplusplus
}
#endif

#endif /* __J2735_MSG_H__ */
