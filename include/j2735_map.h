/* J2735 MAP definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __J2735_MAP_H__
#define __J2735_MAP_H__

#include "j2735_data_component.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MapData {
    BOOL timeStamp_option;
    int32_t timeStamp;        /* MinuteOfTheYear (0..527040) */
    int32_t msgIssueRevision; /* MsgCount (0..127) */
    BOOL layerType_option;
    LayerType layerType;
    BOOL layerID_option;
    int32_t layerID; /* LayerID (0..100) */
    BOOL intersections_option;
    IntersectionGeometryList intersections;
    BOOL roadSegments_option;
    RoadSegmentList roadSegments;
    BOOL dataParameters_option;
    DataParameters dataParameters;
    BOOL restrictionList_option;
    RestrictionClassList restrictionList;
    BOOL regional_option;
    Reg_MapDataList regional;
} MapData;

#ifdef __cplusplus
}
#endif

#endif /* __J2735_MAP_H__ */
