/* J2735 data frame and element defintions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

#ifndef __J2735_DATA_COMPONENT_H__
#define __J2735_DATA_COMPONENT_H__
#include <limits.h>

#include "asn1defs_if.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ConnectionManeuverAssist_addGrpC ConnectionManeuverAssist_addGrpC;
typedef struct ConnectionTrajectory_addGrpC ConnectionTrajectory_addGrpC;
typedef struct IntersectionState_addGrpC IntersectionState_addGrpC;
typedef struct Control_addGrpC Control_addGrpC;
typedef struct LaneDataAttribute_addGrpB LaneDataAttribute_addGrpB;
typedef struct MovementEvent_addGrpB MovementEvent_addGrpB;
typedef struct NodeOffsetPointXY_addGrpB NodeOffsetPointXY_addGrpB;
typedef struct Position3D_addGrpB Position3D_addGrpB;
typedef struct Position3D_addGrpC Position3D_addGrpC;
typedef struct RestrictionUserType_addGrpC RestrictionUserType_addGrpC;
typedef struct SignalStatusPackage_addGrpC SignalStatusPackage_addGrpC;
typedef struct MapData_addGrpC MapData_addGrpC;
typedef struct VehicleSafetyExtensions VehicleSafetyExtensions;
typedef struct SpecialVehicleExtensions SpecialVehicleExtensions;
typedef struct SupplementalVehicleExtensions SupplementalVehicleExtensions;

typedef enum {
    IDmapType_MIN = 0,
    PartIIcontent_DF, /* PartIIcontent */
    Reg_MapData_DF,   /* Reg_MapData */
    IDmapType_MAX,
    ChoiceType_MIN = 0xffff,
    NodeListXY_DF, /* NodeListXY */
    ChoiceType_MAX
} DataFrameID;

typedef struct PositionalAccuracy {
    int32_t semiMajor;   /* SemiMajorAxisAccuracy (0..255) */
    int32_t semiMinor;   /* SemiMinorAxisAccuracy (0..255) */
    int32_t orientation; /* SemiMajorAxisOrientation (0..65535) */
} PositionalAccuracy;

typedef enum TransmissionState {
    TransmissionState_neutral,
    TransmissionState_park,
    TransmissionState_forwardGears,
    TransmissionState_reverseGears,
    TransmissionState_reserved1,
    TransmissionState_reserved2,
    TransmissionState_reserved3,
    TransmissionState_unavailable,
    TransmissionState_MAX = UINT_MAX
} TransmissionState;

typedef struct AccelerationSet4Way {
    int32_t Long; /* Acceleration (-2000..2001) */
    int32_t lat;  /* Acceleration (-2000..2001) */
    int32_t vert; /* VerticalAcceleration (-127..127) */
    int32_t yaw;  /* YawRate (-32767..32767) */
} AccelerationSet4Way;

#define BrakeAppliedStatus_MAX_BITS 5
/* Bit position of BitString: BrakeAppliedStatus */
typedef enum {
    BrakeAppliedStatus_unavailable = 0,
    BrakeAppliedStatus_leftFront = 1,
    BrakeAppliedStatus_leftRear = 2,
    BrakeAppliedStatus_rightFront = 3,
    BrakeAppliedStatus_rightRear = 4,
} BrakeAppliedStatus;

typedef enum TractionControlStatus {
    TractionControlStatus_unavailable,
    TractionControlStatus_off,
    TractionControlStatus_on,
    TractionControlStatus_engaged,
    TractionControlStatus_MAX = UINT_MAX
} TractionControlStatus;

typedef enum AntiLockBrakeStatus {
    AntiLockBrakeStatus_unavailable,
    AntiLockBrakeStatus_off,
    AntiLockBrakeStatus_on,
    AntiLockBrakeStatus_engaged,
    AntiLockBrakeStatus_MAX = UINT_MAX
} AntiLockBrakeStatus;

typedef enum StabilityControlStatus {
    StabilityControlStatus_unavailable,
    StabilityControlStatus_off,
    StabilityControlStatus_on,
    StabilityControlStatus_engaged,
    StabilityControlStatus_MAX = UINT_MAX
} StabilityControlStatus;

typedef enum BrakeBoostApplied {
    BrakeBoostApplied_unavailable,
    BrakeBoostApplied_off,
    BrakeBoostApplied_on,
    BrakeBoostApplied_MAX = UINT_MAX
} BrakeBoostApplied;

typedef enum AuxiliaryBrakeStatus {
    AuxiliaryBrakeStatus_unavailable,
    AuxiliaryBrakeStatus_off,
    AuxiliaryBrakeStatus_on,
    AuxiliaryBrakeStatus_reserved,
    AuxiliaryBrakeStatus_MAX = UINT_MAX
} AuxiliaryBrakeStatus;

typedef struct BrakeSystemStatus {
    BitString wheelBrakes; /* BrakeAppliedStatus (5..5) */
    TractionControlStatus traction;
    AntiLockBrakeStatus abs;
    StabilityControlStatus scs;
    BrakeBoostApplied brakeBoost;
    AuxiliaryBrakeStatus auxBrakes;
} BrakeSystemStatus;

typedef struct VehicleSize {
    int32_t width;  /* VehicleWidth (0..1023) */
    int32_t length; /* VehicleLength (0..4095) */
} VehicleSize;

typedef struct BSMcoreData {
    int32_t msgCnt;  /* MsgCount (0..127) */
    OctetString id;  /* TemporaryID (4..4) */
    int32_t secMark; /* DSecond (0..65535) */
    int32_t lat;     /* Latitude (-900000000..900000001) */
    int32_t Long;    /* Longitude (-1799999999..1800000001) */
    int32_t elev;    /* Elevation (-4096..61439) */
    PositionalAccuracy accuracy;
    TransmissionState transmission;
    int32_t speed;   /* Speed (0..8191) */
    int32_t heading; /* Heading (0..28800) */
    int32_t angle;   /* SteeringWheelAngle (-126..127) */
    AccelerationSet4Way accelSet;
    BrakeSystemStatus brakes;
    VehicleSize size;
} BSMcoreData;

typedef enum { VehicleSafetyExt = 0, SpecialVehicleExt = 1, SupplementalVehicleExt = 2, PartII_Id_MAX = UINT_MAX } PartII_Id;

typedef struct PartIIcontent {
    PartII_Id partII_Id;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        VehicleSafetyExtensions *safetyExt;
        SpecialVehicleExtensions *specialExt;
        SupplementalVehicleExtensions *supplementalExt;
        void *data;
        OctetString unknown;
    } u;
} PartIIcontent;

#define PartIIcontentList_MAX_SIZE 8
typedef struct PartIIcontentList {
    PartIIcontent *tab;
    int32_t count;
} PartIIcontentList;

typedef enum { NoRegion = 0, AddGrpA = 1, AddGrpB = 2, AddGrpC = 3, RegionID_MAX = UINT_MAX } RegionId;

typedef struct Reg_BasicSafetyMessage {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_BasicSafetyMessage;

#define Reg_BasicSafetyMessageList_MAX_SIZE 4
typedef struct Reg_BasicSafetyMessageList {
    Reg_BasicSafetyMessage *tab;
    int32_t count;
} Reg_BasicSafetyMessageList;

typedef enum LayerType {
    LayerType_none,
    LayerType_mixedContent,
    LayerType_generalMapData,
    LayerType_intersectionData,
    LayerType_curveData,
    LayerType_roadwaySectionData,
    LayerType_parkingAreaData,
    LayerType_sharedLaneData,
    LayerType_MAX = UINT_MAX
} LayerType;

typedef struct IntersectionReferenceID {
    BOOL region_option;
    int32_t region; /* RoadRegulatorID (0..65535) */
    int32_t id;     /* IntersectionID (0..65535) */
} IntersectionReferenceID;

typedef struct Reg_Position3D {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        Position3D_addGrpB *grpb;
        Position3D_addGrpC *grpc;
        void *data;
        OctetString unknown;
    } u;
} Reg_Position3D;

#define Reg_Position3DList_MAX_SIZE 4
typedef struct Reg_Position3DList {
    Reg_Position3D *tab;
    int32_t count;
} Reg_Position3DList;

typedef struct Position3D {
    int32_t lat;  /* Latitude (-900000000..900000001) */
    int32_t Long; /* Longitude (-1799999999..1800000001) */
    BOOL elevation_option;
    int32_t elevation; /* Elevation (-4096..61439) */
    BOOL regional_option;
    Reg_Position3DList regional;
} Position3D;

typedef enum SpeedLimitType {
    SpeedLimitType_unknown,
    SpeedLimitType_maxSpeedInSchoolZone,
    SpeedLimitType_maxSpeedInSchoolZoneWhenChildrenArePresent,
    SpeedLimitType_maxSpeedInConstructionZone,
    SpeedLimitType_vehicleMinSpeed,
    SpeedLimitType_vehicleMaxSpeed,
    SpeedLimitType_vehicleNightMaxSpeed,
    SpeedLimitType_truckMinSpeed,
    SpeedLimitType_truckMaxSpeed,
    SpeedLimitType_truckNightMaxSpeed,
    SpeedLimitType_vehiclesWithTrailersMinSpeed,
    SpeedLimitType_vehiclesWithTrailersMaxSpeed,
    SpeedLimitType_vehiclesWithTrailersNightMaxSpeed,
    SpeedLimitType_MAX = UINT_MAX
} SpeedLimitType;

typedef struct RegulatorySpeedLimit {
    SpeedLimitType type;
    int32_t speed; /* Velocity (0..8191) */
} RegulatorySpeedLimit;

#define SpeedLimitList_MAX_SIZE 9
typedef struct SpeedLimitList {
    RegulatorySpeedLimit *tab;
    int32_t count;
} SpeedLimitList;

#define LaneDirection_MAX_BITS 2
/* Bit position of BitString: LaneDirection */
typedef enum {
    LaneDirection_ingressPath = 0,
    LaneDirection_egressPath = 1,
} LaneDirection;

#define LaneSharing_MAX_BITS 10
/* Bit position of BitString: LaneSharing */
typedef enum {
    LaneSharing_overlappingLaneDescriptionProvided = 0,
    LaneSharing_multipleLanesTreatedAsOneLane = 1,
    LaneSharing_otherNonMotorizedTrafficTypes = 2,
    LaneSharing_individualMotorizedVehicleTraffic = 3,
    LaneSharing_busVehicleTraffic = 4,
    LaneSharing_taxiVehicleTraffic = 5,
    LaneSharing_pedestriansTraffic = 6,
    LaneSharing_cyclistVehicleTraffic = 7,
    LaneSharing_trackedVehicleTraffic = 8,
    LaneSharing_pedestrianTraffic = 9,
} LaneSharing;

#define LaneAttributes_Vehicle_MAX_BITS 8
/* Bit position of BitString: LaneAttributes_Vehicle */
typedef enum {
    LaneAttributes_Vehicle_isVehicleRevocableLane = 0,
    LaneAttributes_Vehicle_isVehicleFlyOverLane = 1,
    LaneAttributes_Vehicle_hovLaneUseOnly = 2,
    LaneAttributes_Vehicle_restrictedToBusUse = 3,
    LaneAttributes_Vehicle_restrictedToTaxiUse = 4,
    LaneAttributes_Vehicle_restrictedFromPublicUse = 5,
    LaneAttributes_Vehicle_hasIRbeaconCoverage = 6,
    LaneAttributes_Vehicle_permissionOnRequest = 7,
} LaneAttributes_Vehicle;

#define LaneAttributes_Crosswalk_MAX_BITS 16
/* Bit position of BitString: LaneAttributes_Crosswalk */
typedef enum {
    LaneAttributes_Crosswalk_crosswalkRevocableLane = 0,
    LaneAttributes_Crosswalk_bicyleUseAllowed = 1,
    LaneAttributes_Crosswalk_isXwalkFlyOverLane = 2,
    LaneAttributes_Crosswalk_fixedCycleTime = 3,
    LaneAttributes_Crosswalk_biDirectionalCycleTimes = 4,
    LaneAttributes_Crosswalk_hasPushToWalkButton = 5,
    LaneAttributes_Crosswalk_audioSupport = 6,
    LaneAttributes_Crosswalk_rfSignalRequestPresent = 7,
    LaneAttributes_Crosswalk_unsignalizedSegmentsPresent = 8,
} LaneAttributes_Crosswalk;

#define LaneAttributes_Bike_MAX_BITS 16
/* Bit position of BitString: LaneAttributes_Bike */
typedef enum {
    LaneAttributes_Bike_bikeRevocableLane = 0,
    LaneAttributes_Bike_pedestrianUseAllowed = 1,
    LaneAttributes_Bike_isBikeFlyOverLane = 2,
    LaneAttributes_Bike_fixedCycleTime = 3,
    LaneAttributes_Bike_biDirectionalCycleTimes = 4,
    LaneAttributes_Bike_isolatedByBarrier = 5,
    LaneAttributes_Bike_unsignalizedSegmentsPresent = 6,
} LaneAttributes_Bike;

#define LaneAttributes_Sidewalk_MAX_BITS 16
/* Bit position of BitString: LaneAttributes_Sidewalk */
typedef enum {
    LaneAttributes_Sidewalk_sidewalk_RevocableLane = 0,
    LaneAttributes_Sidewalk_bicyleUseAllowed = 1,
    LaneAttributes_Sidewalk_isSidewalkFlyOverLane = 2,
    LaneAttributes_Sidewalk_walkBikes = 3,
} LaneAttributes_Sidewalk;

#define LaneAttributes_Barrier_MAX_BITS 16
/* Bit position of BitString: LaneAttributes_Barrier */
typedef enum {
    LaneAttributes_Barrier_median_RevocableLane = 0,
    LaneAttributes_Barrier_median = 1,
    LaneAttributes_Barrier_whiteLineHashing = 2,
    LaneAttributes_Barrier_stripedLines = 3,
    LaneAttributes_Barrier_doubleStripedLines = 4,
    LaneAttributes_Barrier_trafficCones = 5,
    LaneAttributes_Barrier_constructionBarrier = 6,
    LaneAttributes_Barrier_trafficChannels = 7,
    LaneAttributes_Barrier_lowCurbs = 8,
    LaneAttributes_Barrier_highCurbs = 9,
} LaneAttributes_Barrier;

#define LaneAttributes_Striping_MAX_BITS 16
/* Bit position of BitString: LaneAttributes_Striping */
typedef enum {
    LaneAttributes_Striping_stripeToConnectingLanesRevocableLane = 0,
    LaneAttributes_Striping_stripeDrawOnLeft = 1,
    LaneAttributes_Striping_stripeDrawOnRight = 2,
    LaneAttributes_Striping_stripeToConnectingLanesLeft = 3,
    LaneAttributes_Striping_stripeToConnectingLanesRight = 4,
    LaneAttributes_Striping_stripeToConnectingLanesAhead = 5,
} LaneAttributes_Striping;

#define LaneAttributes_TrackedVehicle_MAX_BITS 16
/* Bit position of BitString: LaneAttributes_TrackedVehicle */
typedef enum {
    LaneAttributes_TrackedVehicle_spec_RevocableLane = 0,
    LaneAttributes_TrackedVehicle_spec_commuterRailRoadTrack = 1,
    LaneAttributes_TrackedVehicle_spec_lightRailRoadTrack = 2,
    LaneAttributes_TrackedVehicle_spec_heavyRailRoadTrack = 3,
    LaneAttributes_TrackedVehicle_spec_otherRailType = 4,
} LaneAttributes_TrackedVehicle;

#define LaneAttributes_Parking_MAX_BITS 16
/* Bit position of BitString: LaneAttributes_Parking */
typedef enum {
    LaneAttributes_Parking_parkingRevocableLane = 0,
    LaneAttributes_Parking_parallelParkingInUse = 1,
    LaneAttributes_Parking_headInParkingInUse = 2,
    LaneAttributes_Parking_doNotParkZone = 3,
    LaneAttributes_Parking_parkingForBusUse = 4,
    LaneAttributes_Parking_parkingForTaxiUse = 5,
    LaneAttributes_Parking_noPublicParkingUse = 6,
} LaneAttributes_Parking;

typedef enum {
    LaneTypeAttributes_vehicle,
    LaneTypeAttributes_crosswalk,
    LaneTypeAttributes_bikeLane,
    LaneTypeAttributes_sidewalk,
    LaneTypeAttributes_median,
    LaneTypeAttributes_striping,
    LaneTypeAttributes_trackedVehicle,
    LaneTypeAttributes_parking,
} LaneTypeAttributes_choice;

typedef struct LaneTypeAttributes {
    LaneTypeAttributes_choice choice;
    union {
        BitString vehicle;        /* LaneAttributes_Vehicle (8..8) */
        BitString crosswalk;      /* LaneAttributes_Crosswalk (16..16) */
        BitString bikeLane;       /* LaneAttributes_Bike (16..16) */
        BitString sidewalk;       /* LaneAttributes_Sidewalk (16..16) */
        BitString median;         /* LaneAttributes_Barrier (16..16) */
        BitString striping;       /* LaneAttributes_Striping (16..16) */
        BitString trackedVehicle; /* LaneAttributes_TrackedVehicle (16..16) */
        BitString parking;        /* LaneAttributes_Parking (16..16) */
    } u;
} LaneTypeAttributes;

typedef struct Reg_LaneAttributes {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_LaneAttributes;

typedef struct LaneAttributes {
    BitString directionalUse; /* LaneDirection (2..2) */
    BitString sharedWith;     /* LaneSharing (10..10) */
    LaneTypeAttributes laneType;
    BOOL regional_option;
    Reg_LaneAttributes regional;
} LaneAttributes;

#define AllowedManeuvers_MAX_BITS 12
/* Bit position of BitString: AllowedManeuvers */
typedef enum {
    AllowedManeuvers_maneuverStraightAllowed = 0,
    AllowedManeuvers_maneuverLeftAllowed = 1,
    AllowedManeuvers_maneuverRightAllowed = 2,
    AllowedManeuvers_maneuverUTurnAllowed = 3,
    AllowedManeuvers_maneuverLeftTurnOnRedAllowed = 4,
    AllowedManeuvers_maneuverRightTurnOnRedAllowed = 5,
    AllowedManeuvers_maneuverLaneChangeAllowed = 6,
    AllowedManeuvers_maneuverNoStoppingAllowed = 7,
    AllowedManeuvers_yieldAllwaysRequired = 8,
    AllowedManeuvers_goWithHalt = 9,
    AllowedManeuvers_caution = 10,
    AllowedManeuvers_reserved1 = 11,
} AllowedManeuvers;

typedef struct Node_XY_20b {
    int32_t x; /* Offset_B10 (-512..511) */
    int32_t y; /* Offset_B10 (-512..511) */
} Node_XY_20b;

typedef struct Node_XY_22b {
    int32_t x; /* Offset_B11 (-1024..1023) */
    int32_t y; /* Offset_B11 (-1024..1023) */
} Node_XY_22b;

typedef struct Node_XY_24b {
    int32_t x; /* Offset_B12 (-2048..2047) */
    int32_t y; /* Offset_B12 (-2048..2047) */
} Node_XY_24b;

typedef struct Node_XY_26b {
    int32_t x; /* Offset_B13 (-4096..4095) */
    int32_t y; /* Offset_B13 (-4096..4095) */
} Node_XY_26b;

typedef struct Node_XY_28b {
    int32_t x; /* Offset_B14 (-8192..8191) */
    int32_t y; /* Offset_B14 (-8192..8191) */
} Node_XY_28b;

typedef struct Node_XY_32b {
    int32_t x; /* Offset_B16 (-32768..32767) */
    int32_t y; /* Offset_B16 (-32768..32767) */
} Node_XY_32b;

typedef struct Node_LLmD_64b {
    int32_t lon; /* Longitude (-1799999999..1800000001) */
    int32_t lat; /* Latitude (-900000000..900000001) */
} Node_LLmD_64b;

typedef struct Reg_NodeOffsetPointXY {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        NodeOffsetPointXY_addGrpB *grpb;
        void *data;
        OctetString unknown;
    } u;
} Reg_NodeOffsetPointXY;

typedef enum {
    NodeOffsetPointXY_node_XY1,
    NodeOffsetPointXY_node_XY2,
    NodeOffsetPointXY_node_XY3,
    NodeOffsetPointXY_node_XY4,
    NodeOffsetPointXY_node_XY5,
    NodeOffsetPointXY_node_XY6,
    NodeOffsetPointXY_node_LatLon,
    NodeOffsetPointXY_regional,
} NodeOffsetPointXY_choice;

typedef struct NodeOffsetPointXY {
    NodeOffsetPointXY_choice choice;
    union {
        Node_XY_20b node_XY1;
        Node_XY_22b node_XY2;
        Node_XY_24b node_XY3;
        Node_XY_26b node_XY4;
        Node_XY_28b node_XY5;
        Node_XY_32b node_XY6;
        Node_LLmD_64b node_LatLon;
        Reg_NodeOffsetPointXY regional;
    } u;
} NodeOffsetPointXY;

typedef enum NodeAttributeXY {
    NodeAttributeXY_reserved,
    NodeAttributeXY_stopLine,
    NodeAttributeXY_roundedCapStyleA,
    NodeAttributeXY_roundedCapStyleB,
    NodeAttributeXY_mergePoint,
    NodeAttributeXY_divergePoint,
    NodeAttributeXY_downstreamStopLine,
    NodeAttributeXY_downstreamStartNode,
    NodeAttributeXY_closedToTraffic,
    NodeAttributeXY_safeIsland,
    NodeAttributeXY_curbPresentAtStepOff,
    NodeAttributeXY_hydrantPresent,
    NodeAttributeXY_MAX = UINT_MAX
} NodeAttributeXY;

#define NodeAttributeXYList_MAX_SIZE 8
typedef struct NodeAttributeXYList {
    NodeAttributeXY *tab;
    int32_t count;
} NodeAttributeXYList;

typedef enum SegmentAttributeXY {
    SegmentAttributeXY_reserved,
    SegmentAttributeXY_doNotBlock,
    SegmentAttributeXY_whiteLine,
    SegmentAttributeXY_mergingLaneLeft,
    SegmentAttributeXY_mergingLaneRight,
    SegmentAttributeXY_curbOnLeft,
    SegmentAttributeXY_curbOnRight,
    SegmentAttributeXY_loadingzoneOnLeft,
    SegmentAttributeXY_loadingzoneOnRight,
    SegmentAttributeXY_turnOutPointOnLeft,
    SegmentAttributeXY_turnOutPointOnRight,
    SegmentAttributeXY_adjacentParkingOnLeft,
    SegmentAttributeXY_adjacentParkingOnRight,
    SegmentAttributeXY_adjacentBikeLaneOnLeft,
    SegmentAttributeXY_adjacentBikeLaneOnRight,
    SegmentAttributeXY_sharedBikeLane,
    SegmentAttributeXY_bikeBoxInFront,
    SegmentAttributeXY_transitStopOnLeft,
    SegmentAttributeXY_transitStopOnRight,
    SegmentAttributeXY_transitStopInLane,
    SegmentAttributeXY_sharedWithTrackedVehicle,
    SegmentAttributeXY_safeIsland,
    SegmentAttributeXY_lowCurbsPresent,
    SegmentAttributeXY_rumbleStripPresent,
    SegmentAttributeXY_audibleSignalingPresent,
    SegmentAttributeXY_adaptiveTimingPresent,
    SegmentAttributeXY_rfSignalRequestPresent,
    SegmentAttributeXY_partialCurbIntrusion,
    SegmentAttributeXY_taperToLeft,
    SegmentAttributeXY_taperToRight,
    SegmentAttributeXY_taperToCenterLine,
    SegmentAttributeXY_parallelParking,
    SegmentAttributeXY_headInParking,
    SegmentAttributeXY_freeParking,
    SegmentAttributeXY_timeRestrictionsOnParking,
    SegmentAttributeXY_costToPark,
    SegmentAttributeXY_midBlockCurbPresent,
    SegmentAttributeXY_unEvenPavementPresent,
    SegmentAttributeXY_MAX = UINT_MAX
} SegmentAttributeXY;

#define SegmentAttributeXYList_MAX_SIZE 8
typedef struct SegmentAttributeXYList {
    SegmentAttributeXY *tab;
    int32_t count;
} SegmentAttributeXYList;

typedef struct Reg_LaneDataAttribute {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        LaneDataAttribute_addGrpB *grpb;
        void *data;
        OctetString unknown;
    } u;
} Reg_LaneDataAttribute;

#define Reg_LaneDataAttributeList_MAX_SIZE 4
typedef struct Reg_LaneDataAttributeList {
    Reg_LaneDataAttribute *tab;
    int32_t count;
} Reg_LaneDataAttributeList;

typedef enum {
    LaneDataAttribute_pathEndPointAngle,
    LaneDataAttribute_laneCrownPointCenter,
    LaneDataAttribute_laneCrownPointLeft,
    LaneDataAttribute_laneCrownPointRight,
    LaneDataAttribute_laneAngle,
    LaneDataAttribute_speedLimits,
    LaneDataAttribute_regional,
} LaneDataAttribute_choice;

typedef struct LaneDataAttribute {
    LaneDataAttribute_choice choice;
    union {
        int32_t pathEndPointAngle;    /* DeltaAngle (-150..150) */
        int32_t laneCrownPointCenter; /* RoadwayCrownAngle (-128..127) */
        int32_t laneCrownPointLeft;   /* RoadwayCrownAngle (-128..127) */
        int32_t laneCrownPointRight;  /* RoadwayCrownAngle (-128..127) */
        int32_t laneAngle;            /* MergeDivergeNodeAngle (-180..180) */
        SpeedLimitList speedLimits;
        Reg_LaneDataAttributeList regional;
    } u;
} LaneDataAttribute;

#define LaneDataAttributeList_MAX_SIZE 8
typedef struct LaneDataAttributeList {
    LaneDataAttribute *tab;
    int32_t count;
} LaneDataAttributeList;

typedef struct Reg_NodeAttributeSetXY {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        Control_addGrpC *grpc;
        void *data;
        OctetString unknown;
    } u;
} Reg_NodeAttributeSetXY;

#define Reg_NodeAttributeSetXYList_MAX_SIZE 4
typedef struct Reg_NodeAttributeSetXYList {
    Reg_NodeAttributeSetXY *tab;
    int32_t count;
} Reg_NodeAttributeSetXYList;

typedef struct NodeAttributeSetXY {
    BOOL localNode_option;
    NodeAttributeXYList localNode;
    BOOL disabled_option;
    SegmentAttributeXYList disabled;
    BOOL enabled_option;
    SegmentAttributeXYList enabled;
    BOOL data_option;
    LaneDataAttributeList data;
    BOOL dWidth_option;
    int32_t dWidth; /* Offset_B10 (-512..511) */
    BOOL dElevation_option;
    int32_t dElevation; /* Offset_B10 (-512..511) */
    BOOL regional_option;
    Reg_NodeAttributeSetXYList regional;
} NodeAttributeSetXY;

typedef struct NodeXY {
    NodeOffsetPointXY delta;
    BOOL attributes_option;
    NodeAttributeSetXY attributes;
} NodeXY;

#define NodeSetXY_MAX_SIZE 63
typedef struct NodeSetXY {
    NodeXY *tab;
    int32_t count;
} NodeSetXY;

typedef enum {
    OffsetAxis_small,
    OffsetAxis_large,
} OffsetAxis_choice;

typedef struct OffsetAxis {
    OffsetAxis_choice choice;
    union {
        int32_t small; /* DrivenLineOffsetSm (-2047..2047) */
        int32_t large; /* DrivenLineOffsetLg (-32767..32767) */
    } u;
} OffsetAxis;

typedef struct Reg_ComputedLane {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_ComputedLane;

#define Reg_ComputedLaneList_MAX_SIZE 4
typedef struct Reg_ComputedLaneList {
    Reg_ComputedLane *tab;
    int32_t count;
} Reg_ComputedLaneList;

typedef struct ComputedLane {
    int32_t referenceLaneId; /* LaneID (0..255) */
    OffsetAxis offsetXaxis;
    OffsetAxis offsetYaxis;
    BOOL rotateXY_option;
    int32_t rotateXY; /* Angle (0..28800) */
    BOOL scaleXaxis_option;
    int32_t scaleXaxis; /* Scale_B12 (-2048..2047) */
    BOOL scaleYaxis_option;
    int32_t scaleYaxis; /* Scale_B12 (-2048..2047) */
    BOOL regional_option;
    Reg_ComputedLaneList regional;
} ComputedLane;

typedef enum {
    NodeListXY_nodes,
    NodeListXY_computed,
} NodeListXY_choice;

typedef struct NodeListXY {
    NodeListXY_choice choice;
    union {
        NodeSetXY nodes;
        ComputedLane computed;
    } u;
} NodeListXY;

typedef struct ConnectingLane {
    int32_t lane; /* LaneID (0..255) */
    BOOL maneuver_option;
    BitString maneuver; /* AllowedManeuvers (12..12) */
} ConnectingLane;

typedef struct Connection {
    ConnectingLane connectingLane;
    BOOL remoteIntersection_option;
    IntersectionReferenceID remoteIntersection;
    BOOL signalGroup_option;
    int32_t signalGroup; /* SignalGroupID (0..255) */
    BOOL userClass_option;
    int32_t userClass; /* RestrictionClassID (0..255) */
    BOOL connectionID_option;
    int32_t connectionID; /* LaneConnectionID (0..255) */
} Connection;

#define ConnectsToList_MAX_SIZE 16
typedef struct ConnectsToList {
    Connection *tab;
    int32_t count;
} ConnectsToList;

#define OverlayLaneList_MAX_SIZE 5
typedef struct OverlayLaneList {
    int32_t *tab; /* LaneID (0..255) */
    int32_t count;
} OverlayLaneList;

typedef struct Reg_GenericLane {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        ConnectionTrajectory_addGrpC *grpc;
        void *data;
        OctetString unknown;
    } u;
} Reg_GenericLane;

#define Reg_GenericLaneList_MAX_SIZE 4
typedef struct Reg_GenericLaneList {
    Reg_GenericLane *tab;
    int32_t count;
} Reg_GenericLaneList;

typedef struct GenericLane {
    int32_t laneID; /* LaneID (0..255) */
    BOOL name_option;
    OctetString name; /* DescriptiveName (1..63) */
    BOOL ingressApproach_option;
    int32_t ingressApproach; /* ApproachID (0..15) */
    BOOL egressApproach_option;
    int32_t egressApproach; /* ApproachID (0..15) */
    LaneAttributes laneAttributes;
    BOOL maneuvers_option;
    BitString maneuvers; /* AllowedManeuvers (12..12) */
    NodeListXY nodeList;
    BOOL connectsTo_option;
    ConnectsToList connectsTo;
    BOOL overlays_option;
    OverlayLaneList overlays;
    BOOL regional_option;
    Reg_GenericLaneList regional;
} GenericLane;

#define LaneList_MAX_SIZE 255
typedef struct LaneList {
    GenericLane *tab;
    int32_t count;
} LaneList;

typedef struct Reg_SignalControlZone {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_SignalControlZone;

typedef struct SignalControlZone {
    Reg_SignalControlZone zone;
} SignalControlZone;

#define PreemptPriorityList_MAX_SIZE 32
typedef struct PreemptPriorityList {
    SignalControlZone *tab;
    int32_t count;
} PreemptPriorityList;

typedef struct Reg_IntersectionGeometry {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_IntersectionGeometry;

#define Reg_IntersectionGeometryList_MAX_SIZE 4
typedef struct Reg_IntersectionGeometryList {
    Reg_IntersectionGeometry *tab;
    int32_t count;
} Reg_IntersectionGeometryList;

typedef struct IntersectionGeometry {
    BOOL name_option;
    OctetString name; /* DescriptiveName (1..63) */
    IntersectionReferenceID id;
    int32_t revision; /* MsgCount (0..127) */
    Position3D refPoint;
    BOOL laneWidth_option;
    int32_t laneWidth; /* LaneWidth (0..32767) */
    BOOL speedLimits_option;
    SpeedLimitList speedLimits;
    LaneList laneSet;
    BOOL preemptPriorityData_option;
    PreemptPriorityList preemptPriorityData;
    BOOL regional_option;
    Reg_IntersectionGeometryList regional;
} IntersectionGeometry;

#define IntersectionGeometryList_MAX_SIZE 32
typedef struct IntersectionGeometryList {
    IntersectionGeometry *tab;
    int32_t count;
} IntersectionGeometryList;

typedef struct RoadSegmentReferenceID {
    BOOL region_option;
    int32_t region; /* RoadRegulatorID (0..65535) */
    int32_t id;     /* RoadSegmentID (0..65535) */
} RoadSegmentReferenceID;

#define RoadLaneSetList_MAX_SIZE 255
typedef struct RoadLaneSetList {
    GenericLane *tab;
    int32_t count;
} RoadLaneSetList;

typedef struct Reg_RoadSegment {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_RoadSegment;

#define Reg_RoadSegmentList_MAX_SIZE 4
typedef struct Reg_RoadSegmentList {
    Reg_RoadSegment *tab;
    int32_t count;
} Reg_RoadSegmentList;

typedef struct RoadSegment {
    BOOL name_option;
    OctetString name; /* DescriptiveName (1..63) */
    RoadSegmentReferenceID id;
    int32_t revision; /* MsgCount (0..127) */
    Position3D refPoint;
    BOOL laneWidth_option;
    int32_t laneWidth; /* LaneWidth (0..32767) */
    BOOL speedLimits_option;
    SpeedLimitList speedLimits;
    RoadLaneSetList roadLaneSet;
    BOOL regional_option;
    Reg_RoadSegmentList regional;
} RoadSegment;

#define RoadSegmentList_MAX_SIZE 32
typedef struct RoadSegmentList {
    RoadSegment *tab;
    int32_t count;
} RoadSegmentList;

typedef struct DataParameters {
    BOOL processMethod_option;
    OctetString processMethod;
    BOOL processAgency_option;
    OctetString processAgency;
    BOOL lastCheckedDate_option;
    OctetString lastCheckedDate;
    BOOL geoidUsed_option;
    OctetString geoidUsed;
} DataParameters;

typedef enum RestrictionAppliesTo {
    RestrictionAppliesTo_none,
    RestrictionAppliesTo_equippedTransit,
    RestrictionAppliesTo_equippedTaxis,
    RestrictionAppliesTo_equippedOther,
    RestrictionAppliesTo_emissionCompliant,
    RestrictionAppliesTo_equippedBicycle,
    RestrictionAppliesTo_weightCompliant,
    RestrictionAppliesTo_heightCompliant,
    RestrictionAppliesTo_pedestrians,
    RestrictionAppliesTo_slowMovingPersons,
    RestrictionAppliesTo_wheelchairUsers,
    RestrictionAppliesTo_visualDisabilities,
    RestrictionAppliesTo_audioDisabilities,
    RestrictionAppliesTo_otherUnknownDisabilities,
    RestrictionAppliesTo_MAX = UINT_MAX
} RestrictionAppliesTo;

typedef struct Reg_RestrictionUserType {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        RestrictionUserType_addGrpC *grpc;
        void *data;
        OctetString unknown;
    } u;
} Reg_RestrictionUserType;

#define Reg_RestrictionUserTypeList_MAX_SIZE 4
typedef struct Reg_RestrictionUserTypeList {
    Reg_RestrictionUserType *tab;
    int32_t count;
} Reg_RestrictionUserTypeList;

typedef enum {
    RestrictionUserType_basicType,
    RestrictionUserType_regional,
} RestrictionUserType_choice;

typedef struct RestrictionUserType {
    RestrictionUserType_choice choice;
    union {
        RestrictionAppliesTo basicType;
        Reg_RestrictionUserTypeList regional;
    } u;
} RestrictionUserType;

#define RestrictionUserTypeList_MAX_SIZE 16
typedef struct RestrictionUserTypeList {
    RestrictionUserType *tab;
    int32_t count;
} RestrictionUserTypeList;

typedef struct RestrictionClassAssignment {
    int32_t id; /* RestrictionClassID (0..255) */
    RestrictionUserTypeList users;
} RestrictionClassAssignment;

#define RestrictionClassList_MAX_SIZE 254
typedef struct RestrictionClassList {
    RestrictionClassAssignment *tab;
    int32_t count;
} RestrictionClassList;

typedef struct Reg_MapData {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        MapData_addGrpC *grpc;
        void *data;
        OctetString unknown;
    } u;
} Reg_MapData;

#define Reg_MapDataList_MAX_SIZE 4
typedef struct Reg_MapDataList {
    Reg_MapData *tab;
    int32_t count;
} Reg_MapDataList;

#define IntersectionStatusObject_MAX_BITS 16
/* Bit position of BitString: IntersectionStatusObject */
typedef enum {
    IntersectionStatusObject_manualControlIsEnabled = 0,
    IntersectionStatusObject_stopTimeIsActivated = 1,
    IntersectionStatusObject_failureFlash = 2,
    IntersectionStatusObject_preemptIsActive = 3,
    IntersectionStatusObject_signalPriorityIsActive = 4,
    IntersectionStatusObject_fixedTimeOperation = 5,
    IntersectionStatusObject_trafficDependentOperation = 6,
    IntersectionStatusObject_standbyOperation = 7,
    IntersectionStatusObject_failureMode = 8,
    IntersectionStatusObject_off = 9,
    IntersectionStatusObject_recentMAPmessageUpdate = 10,
    IntersectionStatusObject_recentChangeInMAPassignedLanesIDsUsed = 11,
    IntersectionStatusObject_noValidMAPisAvailableAtThisTime = 12,
    IntersectionStatusObject_noValidSPATisAvailableAtThisTime = 13,
} IntersectionStatusObject;

#define EnabledLaneList_MAX_SIZE 16
typedef struct EnabledLaneList {
    int32_t *tab; /* LaneID (0..255) */
    int32_t count;
} EnabledLaneList;

typedef enum MovementPhaseState {
    MovementPhaseState_unavailable,
    MovementPhaseState_dark,
    MovementPhaseState_stop_Then_Proceed,
    MovementPhaseState_stop_And_Remain,
    MovementPhaseState_pre_Movement,
    MovementPhaseState_permissive_Movement_Allowed,
    MovementPhaseState_protected_Movement_Allowed,
    MovementPhaseState_permissive_clearance,
    MovementPhaseState_protected_clearance,
    MovementPhaseState_caution_Conflicting_Traffic,
    MovementPhaseState_MAX = UINT_MAX
} MovementPhaseState;

typedef struct TimeChangeDetails {
    BOOL startTime_option;
    int32_t startTime;  /* TimeMark (0..36001) */
    int32_t minEndTime; /* TimeMark (0..36001) */
    BOOL maxEndTime_option;
    int32_t maxEndTime; /* TimeMark (0..36001) */
    BOOL likelyTime_option;
    int32_t likelyTime; /* TimeMark (0..36001) */
    BOOL confidence_option;
    int32_t confidence; /* TimeIntervalConfidence (0..15) */
    BOOL nextTime_option;
    int32_t nextTime; /* TimeMark (0..36001) */
} TimeChangeDetails;

typedef enum AdvisorySpeedType {
    AdvisorySpeedType_none,
    AdvisorySpeedType_greenwave,
    AdvisorySpeedType_ecoDrive,
    AdvisorySpeedType_transit,
    AdvisorySpeedType_MAX = UINT_MAX
} AdvisorySpeedType;

typedef enum SpeedConfidence {
    SpeedConfidence_unavailable,
    SpeedConfidence_prec100ms,
    SpeedConfidence_prec10ms,
    SpeedConfidence_prec5ms,
    SpeedConfidence_prec1ms,
    SpeedConfidence_prec0_1ms,
    SpeedConfidence_prec0_05ms,
    SpeedConfidence_prec0_01ms,
    SpeedConfidence_MAX = UINT_MAX
} SpeedConfidence;

typedef struct Reg_AdvisorySpeed {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_AdvisorySpeed;

#define Reg_AdvisorySpeedList_MAX_SIZE 4
typedef struct Reg_AdvisorySpeedList {
    Reg_AdvisorySpeed *tab;
    int32_t count;
} Reg_AdvisorySpeedList;

typedef struct AdvisorySpeed {
    AdvisorySpeedType type;
    BOOL speed_option;
    int32_t speed; /* SpeedAdvice (0..500) */
    BOOL confidence_option;
    SpeedConfidence confidence;
    BOOL distance_option;
    int32_t distance; /* ZoneLength (0..10000) */
    BOOL Class_option;
    int32_t Class; /* RestrictionClassID (0..255) */
    BOOL regional_option;
    Reg_AdvisorySpeedList regional;
} AdvisorySpeed;

#define AdvisorySpeedList_MAX_SIZE 16
typedef struct AdvisorySpeedList {
    AdvisorySpeed *tab;
    int32_t count;
} AdvisorySpeedList;

typedef struct Reg_MovementEvent {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        MovementEvent_addGrpB *grpb;
        void *data;
        OctetString unknown;
    } u;
} Reg_MovementEvent;

#define Reg_MovementEventList_MAX_SIZE 4
typedef struct Reg_MovementEventList {
    Reg_MovementEvent *tab;
    int32_t count;
} Reg_MovementEventList;

typedef struct MovementEvent {
    MovementPhaseState eventState;
    BOOL timing_option;
    TimeChangeDetails timing;
    BOOL speeds_option;
    AdvisorySpeedList speeds;
    BOOL regional_option;
    Reg_MovementEventList regional;
} MovementEvent;

#define MovementEventList_MAX_SIZE 16
typedef struct MovementEventList {
    MovementEvent *tab;
    int32_t count;
} MovementEventList;

typedef struct Reg_ConnectionManeuverAssist {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        ConnectionManeuverAssist_addGrpC *grpc;
        void *data;
        OctetString unknown;
    } u;
} Reg_ConnectionManeuverAssist;

#define Reg_ConnectionManeuverAssistList_MAX_SIZE 4
typedef struct Reg_ConnectionManeuverAssistList {
    Reg_ConnectionManeuverAssist *tab;
    int32_t count;
} Reg_ConnectionManeuverAssistList;

typedef struct ConnectionManeuverAssist {
    int32_t connectionID; /* LaneConnectionID (0..255) */
    BOOL queueLength_option;
    int32_t queueLength; /* ZoneLength (0..10000) */
    BOOL availableStorageLength_option;
    int32_t availableStorageLength; /* ZoneLength (0..10000) */
    BOOL waitOnStop_option;
    BOOL waitOnStop; /* WaitOnStopline */
    BOOL pedBicycleDetect_option;
    BOOL pedBicycleDetect; /* PedestrianBicycleDetect */
    BOOL regional_option;
    Reg_ConnectionManeuverAssistList regional;
} ConnectionManeuverAssist;

#define ManeuverAssistList_MAX_SIZE 16
typedef struct ManeuverAssistList {
    ConnectionManeuverAssist *tab;
    int32_t count;
} ManeuverAssistList;

typedef struct Reg_MovementState {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_MovementState;

#define Reg_MovementStateList_MAX_SIZE 4
typedef struct Reg_MovementStateList {
    Reg_MovementState *tab;
    int32_t count;
} Reg_MovementStateList;

typedef struct MovementState {
    BOOL movementName_option;
    OctetString movementName; /* DescriptiveName (1..63) */
    int32_t signalGroup;      /* SignalGroupID (0..255) */
    MovementEventList state_time_speed;
    BOOL maneuverAssistList_option;
    ManeuverAssistList maneuverAssistList;
    BOOL regional_option;
    Reg_MovementStateList regional;
} MovementState;

#define MovementList_MAX_SIZE 255
typedef struct MovementList {
    MovementState *tab;
    int32_t count;
} MovementList;

typedef struct Reg_IntersectionState {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        IntersectionState_addGrpC *grpc;
        void *data;
        OctetString unknown;
    } u;
} Reg_IntersectionState;

#define Reg_IntersectionStateList_MAX_SIZE 4
typedef struct Reg_IntersectionStateList {
    Reg_IntersectionState *tab;
    int32_t count;
} Reg_IntersectionStateList;

typedef struct IntersectionState {
    BOOL name_option;
    OctetString name; /* DescriptiveName (1..63) */
    IntersectionReferenceID id;
    int32_t revision; /* MsgCount (0..127) */
    BitString status; /* IntersectionStatusObject (16..16) */
    BOOL moy_option;
    int32_t moy; /* MinuteOfTheYear (0..527040) */
    BOOL timeStamp_option;
    int32_t timeStamp; /* DSecond (0..65535) */
    BOOL enabledLanes_option;
    EnabledLaneList enabledLanes;
    MovementList states;
    BOOL maneuverAssistList_option;
    ManeuverAssistList maneuverAssistList;
    BOOL regional_option;
    Reg_IntersectionStateList regional;
} IntersectionState;

#define IntersectionStateList_MAX_SIZE 32
typedef struct IntersectionStateList {
    IntersectionState *tab;
    int32_t count;
} IntersectionStateList;

typedef struct Reg_SPAT {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_SPAT;

#define Reg_SPATList_MAX_SIZE 4
typedef struct Reg_SPATList {
    Reg_SPAT *tab;
    int32_t count;
} Reg_SPATList;

typedef enum RequestedItem {
    RequestedItem_reserved,
    RequestedItem_itemA,
    RequestedItem_itemB,
    RequestedItem_itemC,
    RequestedItem_itemD,
    RequestedItem_itemE,
    RequestedItem_itemF,
    RequestedItem_itemG,
    RequestedItem_itemI,
    RequestedItem_itemJ,
    RequestedItem_itemK,
    RequestedItem_itemL,
    RequestedItem_itemM,
    RequestedItem_itemN,
    RequestedItem_itemO,
    RequestedItem_itemP,
    RequestedItem_itemQ,
    RequestedItem_MAX = UINT_MAX
} RequestedItem;

#define RequestedItemList_MAX_SIZE 32
typedef struct RequestedItemList {
    RequestedItem *tab;
    int32_t count;
} RequestedItemList;

typedef struct Reg_CommonSafetyRequest {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_CommonSafetyRequest;

#define Reg_CommonSafetyRequestList_MAX_SIZE 4
typedef struct Reg_CommonSafetyRequestList {
    Reg_CommonSafetyRequest *tab;
    int32_t count;
} Reg_CommonSafetyRequestList;

#define ITIScodesList_MAX_SIZE 8
typedef struct ITIScodesList {
    int32_t *tab; /* ITIScodes (0..65535) */
    int32_t count;
} ITIScodesList;

#define HeadingSlice_MAX_BITS 16
/* Bit position of BitString: HeadingSlice */
typedef enum {
    HeadingSlice_from000_0to022_5degrees = 0,
    HeadingSlice_from022_5to045_0degrees = 1,
    HeadingSlice_from045_0to067_5degrees = 2,
    HeadingSlice_from067_5to090_0degrees = 3,
    HeadingSlice_from090_0to112_5degrees = 4,
    HeadingSlice_from112_5to135_0degrees = 5,
    HeadingSlice_from135_0to157_5degrees = 6,
    HeadingSlice_from157_5to180_0degrees = 7,
    HeadingSlice_from180_0to202_5degrees = 8,
    HeadingSlice_from202_5to225_0degrees = 9,
    HeadingSlice_from225_0to247_5degrees = 10,
    HeadingSlice_from247_5to270_0degrees = 11,
    HeadingSlice_from270_0to292_5degrees = 12,
    HeadingSlice_from292_5to315_0degrees = 13,
    HeadingSlice_from315_0to337_5degrees = 14,
    HeadingSlice_from337_5to360_0degrees = 15,
} HeadingSlice;

typedef enum Extent {
    Extent_useInstantlyOnly,
    Extent_useFor3meters,
    Extent_useFor10meters,
    Extent_useFor50meters,
    Extent_useFor100meters,
    Extent_useFor500meters,
    Extent_useFor1000meters,
    Extent_useFor5000meters,
    Extent_useFor10000meters,
    Extent_useFor50000meters,
    Extent_useFor100000meters,
    Extent_useFor500000meters,
    Extent_useFor1000000meters,
    Extent_useFor5000000meters,
    Extent_useFor10000000meters,
    Extent_forever,
    Extent_MAX = UINT_MAX
} Extent;

typedef struct DDateTime {
    BOOL year_option;
    int32_t year; /* DYear (0..4095) */
    BOOL month_option;
    int32_t month; /* DMonth (0..12) */
    BOOL day_option;
    int32_t day; /* DDay (0..31) */
    BOOL hour_option;
    int32_t hour; /* DHour (0..31) */
    BOOL minute_option;
    int32_t minute; /* DMinute (0..60) */
    BOOL second_option;
    int32_t second; /* DSecond (0..65535) */
    BOOL offset_option;
    int32_t offset; /* DOffset (-840..840) */
} DDateTime;

typedef struct TransmissionAndSpeed {
    TransmissionState transmisson;
    int32_t speed; /* Velocity (0..8191) */
} TransmissionAndSpeed;

typedef enum TimeConfidence {
    TimeConfidence_unavailable,
    TimeConfidence_time_100_000,
    TimeConfidence_time_050_000,
    TimeConfidence_time_020_000,
    TimeConfidence_time_010_000,
    TimeConfidence_time_002_000,
    TimeConfidence_time_001_000,
    TimeConfidence_time_000_500,
    TimeConfidence_time_000_200,
    TimeConfidence_time_000_100,
    TimeConfidence_time_000_050,
    TimeConfidence_time_000_020,
    TimeConfidence_time_000_010,
    TimeConfidence_time_000_005,
    TimeConfidence_time_000_002,
    TimeConfidence_time_000_001,
    TimeConfidence_time_000_000_5,
    TimeConfidence_time_000_000_2,
    TimeConfidence_time_000_000_1,
    TimeConfidence_time_000_000_05,
    TimeConfidence_time_000_000_02,
    TimeConfidence_time_000_000_01,
    TimeConfidence_time_000_000_005,
    TimeConfidence_time_000_000_002,
    TimeConfidence_time_000_000_001,
    TimeConfidence_time_000_000_000_5,
    TimeConfidence_time_000_000_000_2,
    TimeConfidence_time_000_000_000_1,
    TimeConfidence_time_000_000_000_05,
    TimeConfidence_time_000_000_000_02,
    TimeConfidence_time_000_000_000_01,
    TimeConfidence_time_000_000_000_005,
    TimeConfidence_time_000_000_000_002,
    TimeConfidence_time_000_000_000_001,
    TimeConfidence_time_000_000_000_000_5,
    TimeConfidence_time_000_000_000_000_2,
    TimeConfidence_time_000_000_000_000_1,
    TimeConfidence_time_000_000_000_000_05,
    TimeConfidence_time_000_000_000_000_02,
    TimeConfidence_time_000_000_000_000_01,
    TimeConfidence_MAX = UINT_MAX
} TimeConfidence;

typedef enum PositionConfidence {
    PositionConfidence_unavailable,
    PositionConfidence_a500m,
    PositionConfidence_a200m,
    PositionConfidence_a100m,
    PositionConfidence_a50m,
    PositionConfidence_a20m,
    PositionConfidence_a10m,
    PositionConfidence_a5m,
    PositionConfidence_a2m,
    PositionConfidence_a1m,
    PositionConfidence_a50cm,
    PositionConfidence_a20cm,
    PositionConfidence_a10cm,
    PositionConfidence_a5cm,
    PositionConfidence_a2cm,
    PositionConfidence_a1cm,
    PositionConfidence_MAX = UINT_MAX
} PositionConfidence;

typedef enum ElevationConfidence {
    ElevationConfidence_unavailable,
    ElevationConfidence_elev_500_00,
    ElevationConfidence_elev_200_00,
    ElevationConfidence_elev_100_00,
    ElevationConfidence_elev_050_00,
    ElevationConfidence_elev_020_00,
    ElevationConfidence_elev_010_00,
    ElevationConfidence_elev_005_00,
    ElevationConfidence_elev_002_00,
    ElevationConfidence_elev_001_00,
    ElevationConfidence_elev_000_50,
    ElevationConfidence_elev_000_20,
    ElevationConfidence_elev_000_10,
    ElevationConfidence_elev_000_05,
    ElevationConfidence_elev_000_02,
    ElevationConfidence_elev_000_01,
    ElevationConfidence_MAX = UINT_MAX
} ElevationConfidence;

typedef struct PositionConfidenceSet {
    PositionConfidence pos;
    ElevationConfidence elevation;
} PositionConfidenceSet;

typedef enum HeadingConfidence {
    HeadingConfidence_unavailable,
    HeadingConfidence_prec10deg,
    HeadingConfidence_prec05deg,
    HeadingConfidence_prec01deg,
    HeadingConfidence_prec0_1deg,
    HeadingConfidence_prec0_05deg,
    HeadingConfidence_prec0_01deg,
    HeadingConfidence_prec0_0125deg,
    HeadingConfidence_MAX = UINT_MAX
} HeadingConfidence;

typedef enum ThrottleConfidence {
    ThrottleConfidence_unavailable,
    ThrottleConfidence_prec10percent,
    ThrottleConfidence_prec1percent,
    ThrottleConfidence_prec0_5percent,
    ThrottleConfidence_MAX = UINT_MAX
} ThrottleConfidence;

typedef struct SpeedandHeadingandThrottleConfidence {
    HeadingConfidence heading;
    SpeedConfidence speed;
    ThrottleConfidence throttle;
} SpeedandHeadingandThrottleConfidence;

typedef struct FullPositionVector {
    BOOL utcTime_option;
    DDateTime utcTime;
    int32_t Long; /* Longitude (-1799999999..1800000001) */
    int32_t lat;  /* Latitude (-900000000..900000001) */
    BOOL elevation_option;
    int32_t elevation; /* Elevation (-4096..61439) */
    BOOL heading_option;
    int32_t heading; /* Heading (0..28800) */
    BOOL speed_option;
    TransmissionAndSpeed speed;
    BOOL posAccuracy_option;
    PositionalAccuracy posAccuracy;
    BOOL timeConfidence_option;
    TimeConfidence timeConfidence;
    BOOL posConfidence_option;
    PositionConfidenceSet posConfidence;
    BOOL speedConfidence_option;
    SpeedandHeadingandThrottleConfidence speedConfidence;
} FullPositionVector;

typedef struct Reg_RoadSideAlert {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_RoadSideAlert;

#define Reg_RoadSideAlertList_MAX_SIZE 4
typedef struct Reg_RoadSideAlertList {
    Reg_RoadSideAlert *tab;
    int32_t count;
} Reg_RoadSideAlertList;

typedef enum ResponseType {
    ResponseType_notInUseOrNotEquipped,
    ResponseType_emergency,
    ResponseType_nonEmergency,
    ResponseType_pursuit,
    ResponseType_stationary,
    ResponseType_slowMoving,
    ResponseType_stopAndGoMovement,
    ResponseType_MAX = UINT_MAX
} ResponseType;

typedef enum SirenInUse { SirenInUse_unavailable, SirenInUse_notInUse, SirenInUse_inUse, SirenInUse_reserved, SirenInUse_MAX = UINT_MAX } SirenInUse;

typedef enum LightbarInUse {
    LightbarInUse_unavailable,
    LightbarInUse_notInUse,
    LightbarInUse_inUse,
    LightbarInUse_yellowCautionLights,
    LightbarInUse_schooldBusLights,
    LightbarInUse_arrowSignsActive,
    LightbarInUse_slowMovingVehicle,
    LightbarInUse_freqStops,
    LightbarInUse_MAX = UINT_MAX
} LightbarInUse;

typedef enum MultiVehicleResponse {
    MultiVehicleResponse_unavailable,
    MultiVehicleResponse_singleVehicle,
    MultiVehicleResponse_multiVehicle,
    MultiVehicleResponse_reserved,
    MultiVehicleResponse_MAX = UINT_MAX
} MultiVehicleResponse;

#define PrivilegedEventFlags_MAX_BITS 16
/* Bit position of BitString: PrivilegedEventFlags */
typedef enum {
    PrivilegedEventFlags_peUnavailable = 0,
    PrivilegedEventFlags_peEmergencyResponse = 1,
    PrivilegedEventFlags_peEmergencyLightsActive = 2,
    PrivilegedEventFlags_peEmergencySoundActive = 3,
    PrivilegedEventFlags_peNonEmergencyLightsActive = 4,
    PrivilegedEventFlags_peNonEmergencySoundActive = 5,
} PrivilegedEventFlags;

typedef struct PrivilegedEvents {
    int32_t sspRights; /* SSPindex (0..31) */
    BitString event;   /* PrivilegedEventFlags (16..16) */
} PrivilegedEvents;

typedef struct EmergencyDetails {
    int32_t sspRights; /* SSPindex (0..31) */
    SirenInUse sirenUse;
    LightbarInUse lightsUse;
    MultiVehicleResponse multi;
    BOOL events_option;
    PrivilegedEvents events;
    BOOL responseType_option;
    ResponseType responseType;
} EmergencyDetails;

typedef enum VehicleType {
    VehicleType_none,
    VehicleType_unknown,
    VehicleType_special,
    VehicleType_moto,
    VehicleType_car,
    VehicleType_carOther,
    VehicleType_bus,
    VehicleType_axleCnt2,
    VehicleType_axleCnt3,
    VehicleType_axleCnt4,
    VehicleType_axleCnt4Trailer,
    VehicleType_axleCnt5Trailer,
    VehicleType_axleCnt6Trailer,
    VehicleType_axleCnt5MultiTrailer,
    VehicleType_axleCnt6MultiTrailer,
    VehicleType_axleCnt7MultiTrailer,
    VehicleType_MAX = UINT_MAX
} VehicleType;

typedef enum VehicleGroupAffected {
    VehicleGroupAffected_all_vehicles,
    VehicleGroupAffected_bicycles,
    VehicleGroupAffected_motorcycles,
    VehicleGroupAffected_cars,
    VehicleGroupAffected_light_vehicles,
    VehicleGroupAffected_cars_and_light_vehicles,
    VehicleGroupAffected_cars_with_trailers,
    VehicleGroupAffected_cars_with_recreational_trailers,
    VehicleGroupAffected_vehicles_with_trailers,
    VehicleGroupAffected_heavy_vehicles,
    VehicleGroupAffected_trucks,
    VehicleGroupAffected_buses,
    VehicleGroupAffected_articulated_buses,
    VehicleGroupAffected_school_buses,
    VehicleGroupAffected_vehicles_with_semi_trailers,
    VehicleGroupAffected_vehicles_with_double_trailers,
    VehicleGroupAffected_high_profile_vehicles,
    VehicleGroupAffected_wide_vehicles,
    VehicleGroupAffected_long_vehicles,
    VehicleGroupAffected_hazardous_loads,
    VehicleGroupAffected_exceptional_loads,
    VehicleGroupAffected_abnormal_loads,
    VehicleGroupAffected_convoys,
    VehicleGroupAffected_maintenance_vehicles,
    VehicleGroupAffected_delivery_vehicles,
    VehicleGroupAffected_vehicles_with_even_numbered_license_plates,
    VehicleGroupAffected_vehicles_with_odd_numbered_license_plates,
    VehicleGroupAffected_vehicles_with_parking_permits,
    VehicleGroupAffected_vehicles_with_catalytic_converters,
    VehicleGroupAffected_vehicles_without_catalytic_converters,
    VehicleGroupAffected_gas_powered_vehicles,
    VehicleGroupAffected_diesel_powered_vehicles,
    VehicleGroupAffected_lPG_vehicles,
    VehicleGroupAffected_military_convoys,
    VehicleGroupAffected_military_vehicles,
    VehicleGroupAffected_MAX = UINT_MAX
} VehicleGroupAffected;

typedef enum IncidentResponseEquipment {
    IncidentResponseEquipment_ground_fire_suppression,
    IncidentResponseEquipment_heavy_ground_equipment,
    IncidentResponseEquipment_aircraft,
    IncidentResponseEquipment_marine_equipment,
    IncidentResponseEquipment_support_equipment,
    IncidentResponseEquipment_medical_rescue_unit,
    IncidentResponseEquipment_other,
    IncidentResponseEquipment_ground_fire_suppression_other,
    IncidentResponseEquipment_engine,
    IncidentResponseEquipment_truck_or_aerial,
    IncidentResponseEquipment_quint,
    IncidentResponseEquipment_tanker_pumper_combination,
    IncidentResponseEquipment_brush_truck,
    IncidentResponseEquipment_aircraft_rescue_firefighting,
    IncidentResponseEquipment_heavy_ground_equipment_other,
    IncidentResponseEquipment_dozer_or_plow,
    IncidentResponseEquipment_tractor,
    IncidentResponseEquipment_tanker_or_tender,
    IncidentResponseEquipment_aircraft_other,
    IncidentResponseEquipment_aircraft_fixed_wing_tanker,
    IncidentResponseEquipment_helitanker,
    IncidentResponseEquipment_helicopter,
    IncidentResponseEquipment_marine_equipment_other,
    IncidentResponseEquipment_fire_boat_with_pump,
    IncidentResponseEquipment_boat_no_pump,
    IncidentResponseEquipment_support_apparatus_other,
    IncidentResponseEquipment_breathing_apparatus_support,
    IncidentResponseEquipment_light_and_air_unit,
    IncidentResponseEquipment_medical_rescue_unit_other,
    IncidentResponseEquipment_rescue_unit,
    IncidentResponseEquipment_urban_search_rescue_unit,
    IncidentResponseEquipment_high_angle_rescue,
    IncidentResponseEquipment_crash_fire_rescue,
    IncidentResponseEquipment_bLS_unit,
    IncidentResponseEquipment_aLS_unit,
    IncidentResponseEquipment_mobile_command_post,
    IncidentResponseEquipment_chief_officer_car,
    IncidentResponseEquipment_hAZMAT_unit,
    IncidentResponseEquipment_type_i_hand_crew,
    IncidentResponseEquipment_type_ii_hand_crew,
    IncidentResponseEquipment_privately_owned_vehicle,
    IncidentResponseEquipment_other_apparatus_resource,
    IncidentResponseEquipment_ambulance,
    IncidentResponseEquipment_bomb_squad_van,
    IncidentResponseEquipment_combine_harvester,
    IncidentResponseEquipment_construction_vehicle,
    IncidentResponseEquipment_farm_tractor,
    IncidentResponseEquipment_grass_cutting_machines,
    IncidentResponseEquipment_hAZMAT_containment_tow,
    IncidentResponseEquipment_heavy_tow,
    IncidentResponseEquipment_light_tow,
    IncidentResponseEquipment_flatbed_tow,
    IncidentResponseEquipment_hedge_cutting_machines,
    IncidentResponseEquipment_mobile_crane,
    IncidentResponseEquipment_refuse_collection_vehicle,
    IncidentResponseEquipment_resurfacing_vehicle,
    IncidentResponseEquipment_road_sweeper,
    IncidentResponseEquipment_roadside_litter_collection_crews,
    IncidentResponseEquipment_salvage_vehicle,
    IncidentResponseEquipment_sand_truck,
    IncidentResponseEquipment_snowplow,
    IncidentResponseEquipment_steam_roller,
    IncidentResponseEquipment_swat_team_van,
    IncidentResponseEquipment_track_laying_vehicle,
    IncidentResponseEquipment_unknown_vehicle,
    IncidentResponseEquipment_white_lining_vehicle,
    IncidentResponseEquipment_dump_truck,
    IncidentResponseEquipment_supervisor_vehicle,
    IncidentResponseEquipment_snow_blower,
    IncidentResponseEquipment_rotary_snow_blower,
    IncidentResponseEquipment_road_grader,
    IncidentResponseEquipment_steam_truck,
    IncidentResponseEquipment_MAX = UINT_MAX
} IncidentResponseEquipment;

typedef enum ResponderGroupAffected {
    ResponderGroupAffected_emergency_vehicle_units,
    ResponderGroupAffected_federal_law_enforcement_units,
    ResponderGroupAffected_state_police_units,
    ResponderGroupAffected_county_police_units,
    ResponderGroupAffected_local_police_units,
    ResponderGroupAffected_ambulance_units,
    ResponderGroupAffected_rescue_units,
    ResponderGroupAffected_fire_units,
    ResponderGroupAffected_hAZMAT_units,
    ResponderGroupAffected_light_tow_unit,
    ResponderGroupAffected_heavy_tow_unit,
    ResponderGroupAffected_freeway_service_patrols,
    ResponderGroupAffected_transportation_response_units,
    ResponderGroupAffected_private_contractor_response_units,
    ResponderGroupAffected_MAX = UINT_MAX
} ResponderGroupAffected;

typedef struct Reg_EmergencyVehicleAlert {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_EmergencyVehicleAlert;

#define Reg_EmergencyVehicleAlertList_MAX_SIZE 4
typedef struct Reg_EmergencyVehicleAlertList {
    Reg_EmergencyVehicleAlert *tab;
    int32_t count;
} Reg_EmergencyVehicleAlertList;

#define GNSSstatus_MAX_BITS 8
/* Bit position of BitString: GNSSstatus */
typedef enum {
    GNSSstatus_unavailable = 0,
    GNSSstatus_isHealthy = 1,
    GNSSstatus_isMonitored = 2,
    GNSSstatus_baseStationType = 3,
    GNSSstatus_aPDOPofUnder5 = 4,
    GNSSstatus_inViewOfUnder5 = 5,
    GNSSstatus_localCorrectionsPresent = 6,
    GNSSstatus_networkCorrectionsPresent = 7,
} GNSSstatus;

typedef struct PathHistoryPoint {
    int32_t latOffset;       /* OffsetLL_B18 (-131072..131071) */
    int32_t lonOffset;       /* OffsetLL_B18 (-131072..131071) */
    int32_t elevationOffset; /* VertOffset_B12 (-2048..2047) */
    int32_t timeOffset;      /* TimeOffset (1..65535) */
    BOOL speed_option;
    int32_t speed; /* Speed (0..8191) */
    BOOL posAccuracy_option;
    PositionalAccuracy posAccuracy;
    BOOL heading_option;
    int32_t heading; /* CoarseHeading (0..240) */
} PathHistoryPoint;

#define PathHistoryPointList_MAX_SIZE 23
typedef struct PathHistoryPointList {
    PathHistoryPoint *tab;
    int32_t count;
} PathHistoryPointList;

typedef struct PathHistory {
    BOOL initialPosition_option;
    FullPositionVector initialPosition;
    BOOL currGNSSstatus_option;
    BitString currGNSSstatus; /* GNSSstatus (8..8) */
    PathHistoryPointList crumbData;
} PathHistory;

typedef struct PathPrediction {
    int32_t radiusOfCurve; /* RadiusOfCurvature (-32767..32767) */
    int32_t confidence;    /* Confidence (0..200) */
} PathPrediction;

typedef enum {
    ApproachOrLane_approach,
    ApproachOrLane_lane,
} ApproachOrLane_choice;

typedef struct ApproachOrLane {
    ApproachOrLane_choice choice;
    union {
        int32_t approach; /* ApproachID (0..15) */
        int32_t lane;     /* LaneID (0..255) */
    } u;
} ApproachOrLane;

#define VehicleEventFlags_MAX_BITS 13
/* Bit position of BitString: VehicleEventFlags */
typedef enum {
    VehicleEventFlags_eventHazardLights = 0,
    VehicleEventFlags_eventStopLineViolation = 1,
    VehicleEventFlags_eventABSactivated = 2,
    VehicleEventFlags_eventTractionControlLoss = 3,
    VehicleEventFlags_eventStabilityControlactivated = 4,
    VehicleEventFlags_eventHazardousMaterials = 5,
    VehicleEventFlags_eventReserved1 = 6,
    VehicleEventFlags_eventHardBraking = 7,
    VehicleEventFlags_eventLightsChanged = 8,
    VehicleEventFlags_eventWipersChanged = 9,
    VehicleEventFlags_eventFlatTire = 10,
    VehicleEventFlags_eventDisabledVehicle = 11,
    VehicleEventFlags_eventAirBagDeployment = 12,
} VehicleEventFlags;

typedef struct Reg_IntersectionCollision {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_IntersectionCollision;

#define Reg_IntersectionCollisionList_MAX_SIZE 4
typedef struct Reg_IntersectionCollisionList {
    Reg_IntersectionCollision *tab;
    int32_t count;
} Reg_IntersectionCollisionList;

typedef enum NMEA_Revision {
    NMEA_Revision_unknown,
    NMEA_Revision_reserved,
    NMEA_Revision_rev1,
    NMEA_Revision_rev2,
    NMEA_Revision_rev3,
    NMEA_Revision_rev4,
    NMEA_Revision_rev5,
    NMEA_Revision_MAX = UINT_MAX
} NMEA_Revision;

typedef struct Reg_NMEAcorrections {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_NMEAcorrections;

#define Reg_NMEAcorrectionsList_MAX_SIZE 4
typedef struct Reg_NMEAcorrectionsList {
    Reg_NMEAcorrections *tab;
    int32_t count;
} Reg_NMEAcorrectionsList;

typedef struct Sample {
    int32_t sampleStart;
    int32_t sampleEnd;
} Sample;

typedef enum {
    TermConfig_termtime,
    TermConfig_termDistance,
} TermConfig_choice;

typedef struct TermConfig {
    TermConfig_choice choice;
    union {
        int32_t termtime;     /* TermTime (1..1800) */
        int32_t termDistance; /* TermDistance (1..30000) */
    } u;
} TermConfig;

typedef struct SnapshotTime {
    int32_t speed1; /* GrossSpeed (0..31) */
    int32_t time1;  /* SecondOfTime (0..61) */
    int32_t speed2; /* GrossSpeed (0..31) */
    int32_t time2;  /* SecondOfTime (0..61) */
} SnapshotTime;

typedef struct SnapshotDistance {
    int32_t distance1; /* GrossDistance (0..1023) */
    int32_t speed1;    /* GrossSpeed (0..31) */
    int32_t distance2; /* GrossDistance (0..1023) */
    int32_t speed2;    /* GrossSpeed (0..31) */
} SnapshotDistance;

typedef enum {
    SnapshotConfig_snapshotTime,
    SnapshotConfig_snapshotDistance,
} SnapshotConfig_choice;

typedef struct SnapshotConfig {
    SnapshotConfig_choice choice;
    union {
        SnapshotTime snapshotTime;
        SnapshotDistance snapshotDistance;
    } u;
} SnapshotConfig;

typedef enum VehicleStatusDeviceTypeTag {
    VehicleStatusDeviceTypeTag_unknown,
    VehicleStatusDeviceTypeTag_lights,
    VehicleStatusDeviceTypeTag_wipers,
    VehicleStatusDeviceTypeTag_brakes,
    VehicleStatusDeviceTypeTag_stab,
    VehicleStatusDeviceTypeTag_trac,
    VehicleStatusDeviceTypeTag_abs,
    VehicleStatusDeviceTypeTag_sunS,
    VehicleStatusDeviceTypeTag_rainS,
    VehicleStatusDeviceTypeTag_airTemp,
    VehicleStatusDeviceTypeTag_steering,
    VehicleStatusDeviceTypeTag_vertAccelThres,
    VehicleStatusDeviceTypeTag_vertAccel,
    VehicleStatusDeviceTypeTag_hozAccelLong,
    VehicleStatusDeviceTypeTag_hozAccelLat,
    VehicleStatusDeviceTypeTag_hozAccelCon,
    VehicleStatusDeviceTypeTag_accel4way,
    VehicleStatusDeviceTypeTag_confidenceSet,
    VehicleStatusDeviceTypeTag_obDist,
    VehicleStatusDeviceTypeTag_obDirect,
    VehicleStatusDeviceTypeTag_yaw,
    VehicleStatusDeviceTypeTag_yawRateCon,
    VehicleStatusDeviceTypeTag_dateTime,
    VehicleStatusDeviceTypeTag_fullPos,
    VehicleStatusDeviceTypeTag_position2D,
    VehicleStatusDeviceTypeTag_position3D,
    VehicleStatusDeviceTypeTag_vehicle,
    VehicleStatusDeviceTypeTag_speedHeadC,
    VehicleStatusDeviceTypeTag_speedC,
    VehicleStatusDeviceTypeTag_MAX = UINT_MAX
} VehicleStatusDeviceTypeTag;

typedef struct VehicleStatusRequest {
    VehicleStatusDeviceTypeTag dataType;
    BOOL subType_option;
    int32_t subType;
    BOOL sendOnLessThenValue_option;
    int32_t sendOnLessThenValue;
    BOOL sendOnMoreThenValue_option;
    int32_t sendOnMoreThenValue;
    BOOL sendAll_option;
    BOOL sendAll;
} VehicleStatusRequest;

#define VehicleStatusRequestList_MAX_SIZE 32
typedef struct VehicleStatusRequestList {
    VehicleStatusRequest *tab;
    int32_t count;
} VehicleStatusRequestList;

typedef struct Reg_ProbeDataManagement {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_ProbeDataManagement;

#define Reg_ProbeDataManagementList_MAX_SIZE 4
typedef struct Reg_ProbeDataManagementList {
    Reg_ProbeDataManagement *tab;
    int32_t count;
} Reg_ProbeDataManagementList;

typedef enum {
    VehicleID_entityID,
    VehicleID_stationID,
} VehicleID_choice;

typedef struct VehicleID {
    VehicleID_choice choice;
    union {
        OctetString entityID; /* TemporaryID (4..4) */
        uint32_t stationID;   /* StationID (0..4294967295) */
    } u;
} VehicleID;

typedef enum {
    VehicleClass_vGroup,
    VehicleClass_rGroup,
    VehicleClass_rEquip,
} VehicleClass_choice;

typedef struct VehicleClass {
    VehicleClass_choice choice;
    union {
        VehicleGroupAffected vGroup;
        ResponderGroupAffected rGroup;
        IncidentResponseEquipment rEquip;
    } u;
} VehicleClass;

typedef struct VehicleIdent {
    BOOL name_option;
    OctetString name; /* DescriptiveName (1..63) */
    BOOL vin_option;
    OctetString vin; /* VINstring (1..17) */
    BOOL ownerCode_option;
    OctetString ownerCode;
    BOOL id_option;
    VehicleID id;
    BOOL vehicleType_option;
    VehicleType vehicleType;
    BOOL vehicleClass_option;
    VehicleClass vehicleClass;
} VehicleIdent;

typedef enum BasicVehicleRole {
    BasicVehicleRole_basicVehicle,
    BasicVehicleRole_publicTransport,
    BasicVehicleRole_specialTransport,
    BasicVehicleRole_dangerousGoods,
    BasicVehicleRole_roadWork,
    BasicVehicleRole_roadRescue,
    BasicVehicleRole_emergency,
    BasicVehicleRole_safetyCar,
    BasicVehicleRole_none_unknown,
    BasicVehicleRole_truck,
    BasicVehicleRole_motorcycle,
    BasicVehicleRole_roadSideSource,
    BasicVehicleRole_police,
    BasicVehicleRole_fire,
    BasicVehicleRole_ambulance,
    BasicVehicleRole_dot,
    BasicVehicleRole_transit,
    BasicVehicleRole_slowMoving,
    BasicVehicleRole_stopNgo,
    BasicVehicleRole_cyclist,
    BasicVehicleRole_pedestrian,
    BasicVehicleRole_nonMotorized,
    BasicVehicleRole_military,
    BasicVehicleRole_MAX = UINT_MAX
} BasicVehicleRole;

typedef struct Reg_VehicleClassification {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_VehicleClassification;

#define Reg_VehicleClassificationList_MAX_SIZE 4
typedef struct Reg_VehicleClassificationList {
    Reg_VehicleClassification *tab;
    int32_t count;
} Reg_VehicleClassificationList;

typedef struct VehicleClassification {
    BOOL keyType_option;
    int32_t keyType; /* BasicVehicleClass (0..255) */
    BOOL role_option;
    BasicVehicleRole role;
    BOOL iso3883_option;
    int32_t iso3883; /* Iso3833VehicleType (0..100) */
    BOOL hpmsType_option;
    VehicleType hpmsType;
    BOOL vehicleType_option;
    VehicleGroupAffected vehicleType;
    BOOL responseEquip_option;
    IncidentResponseEquipment responseEquip;
    BOOL responderType_option;
    ResponderGroupAffected responderType;
    BOOL fuelType_option;
    int32_t fuelType; /* FuelType (0..15) */
    BOOL regional_option;
    Reg_VehicleClassificationList regional;
} VehicleClassification;

#define ExteriorLights_MAX_BITS 9
/* Bit position of BitString: ExteriorLights */
typedef enum {
    ExteriorLights_lowBeamHeadlightsOn = 0,
    ExteriorLights_highBeamHeadlightsOn = 1,
    ExteriorLights_leftTurnSignalOn = 2,
    ExteriorLights_rightTurnSignalOn = 3,
    ExteriorLights_hazardSignalOn = 4,
    ExteriorLights_automaticLightControlOn = 5,
    ExteriorLights_daytimeRunningLightsOn = 6,
    ExteriorLights_fogLightOn = 7,
    ExteriorLights_parkingLightsOn = 8,
} ExteriorLights;

typedef struct VehicleSafetyExtensions {
    BOOL events_option;
    BitString events; /* VehicleEventFlags (13..13) */
    BOOL pathHistory_option;
    PathHistory pathHistory;
    BOOL pathPrediction_option;
    PathPrediction pathPrediction;
    BOOL lights_option;
    BitString lights; /* ExteriorLights (9..9) */
} VehicleSafetyExtensions;

typedef enum WiperStatus {
    WiperStatus_unavailable,
    WiperStatus_off,
    WiperStatus_intermittent,
    WiperStatus_low,
    WiperStatus_high,
    WiperStatus_washerInUse,
    WiperStatus_automaticPresent,
    WiperStatus_MAX = UINT_MAX
} WiperStatus;

typedef struct WiperSet {
    WiperStatus statusFront;
    int32_t rateFront; /* WiperRate (0..127) */
    BOOL statusRear_option;
    WiperStatus statusRear;
    BOOL rateRear_option;
    int32_t rateRear; /* WiperRate (0..127) */
} WiperSet;

typedef enum BrakeAppliedPressure {
    BrakeAppliedPressure_unavailable,
    BrakeAppliedPressure_minPressure,
    BrakeAppliedPressure_bkLvl_2,
    BrakeAppliedPressure_bkLvl_3,
    BrakeAppliedPressure_bkLvl_4,
    BrakeAppliedPressure_bkLvl_5,
    BrakeAppliedPressure_bkLvl_6,
    BrakeAppliedPressure_bkLvl_7,
    BrakeAppliedPressure_bkLvl_8,
    BrakeAppliedPressure_bkLvl_9,
    BrakeAppliedPressure_bkLvl_10,
    BrakeAppliedPressure_bkLvl_11,
    BrakeAppliedPressure_bkLvl_12,
    BrakeAppliedPressure_bkLvl_13,
    BrakeAppliedPressure_bkLvl_14,
    BrakeAppliedPressure_maxPressure,
    BrakeAppliedPressure_MAX = UINT_MAX
} BrakeAppliedPressure;

typedef enum RainSensor {
    RainSensor_none,
    RainSensor_lightMist,
    RainSensor_heavyMist,
    RainSensor_lightRainOrDrizzle,
    RainSensor_rain,
    RainSensor_moderateRain,
    RainSensor_heavyRain,
    RainSensor_heavyDownpour,
    RainSensor_MAX = UINT_MAX
} RainSensor;

typedef enum SteeringWheelAngleConfidence {
    SteeringWheelAngleConfidence_unavailable,
    SteeringWheelAngleConfidence_prec2deg,
    SteeringWheelAngleConfidence_prec1deg,
    SteeringWheelAngleConfidence_prec0_02deg,
    SteeringWheelAngleConfidence_MAX = UINT_MAX
} SteeringWheelAngleConfidence;

typedef struct Steering {
    int32_t angle; /* SteeringWheelAngle (-126..127) */
    BOOL confidence_option;
    SteeringWheelAngleConfidence confidence;
    BOOL rate_option;
    int32_t rate; /* SteeringWheelAngleRateOfChange (-127..127) */
    BOOL wheels_option;
    int32_t wheels; /* DrivingWheelAngle (-128..127) */
} Steering;

#define VerticalAccelerationThreshold_MAX_BITS 5
/* Bit position of BitString: VerticalAccelerationThreshold */
typedef enum {
    VerticalAccelerationThreshold_notEquipped = 0,
    VerticalAccelerationThreshold_leftFront = 1,
    VerticalAccelerationThreshold_leftRear = 2,
    VerticalAccelerationThreshold_rightFront = 3,
    VerticalAccelerationThreshold_rightRear = 4,
} VerticalAccelerationThreshold;

typedef enum YawRateConfidence {
    YawRateConfidence_unavailable,
    YawRateConfidence_degSec_100_00,
    YawRateConfidence_degSec_010_00,
    YawRateConfidence_degSec_005_00,
    YawRateConfidence_degSec_001_00,
    YawRateConfidence_degSec_000_10,
    YawRateConfidence_degSec_000_05,
    YawRateConfidence_degSec_000_01,
    YawRateConfidence_MAX = UINT_MAX
} YawRateConfidence;

typedef enum AccelerationConfidence {
    AccelerationConfidence_unavailable,
    AccelerationConfidence_accl_100_00,
    AccelerationConfidence_accl_010_00,
    AccelerationConfidence_accl_005_00,
    AccelerationConfidence_accl_001_00,
    AccelerationConfidence_accl_000_10,
    AccelerationConfidence_accl_000_05,
    AccelerationConfidence_accl_000_01,
    AccelerationConfidence_MAX = UINT_MAX
} AccelerationConfidence;

typedef struct AccelSteerYawRateConfidence {
    YawRateConfidence yawRate;
    AccelerationConfidence acceleration;
    SteeringWheelAngleConfidence steeringWheelAngle;
} AccelSteerYawRateConfidence;

typedef struct ConfidenceSet {
    BOOL accelConfidence_option;
    AccelSteerYawRateConfidence accelConfidence;
    BOOL speedConfidence_option;
    SpeedandHeadingandThrottleConfidence speedConfidence;
    BOOL timeConfidence_option;
    TimeConfidence timeConfidence;
    BOOL posConfidence_option;
    PositionConfidenceSet posConfidence;
    BOOL steerConfidence_option;
    SteeringWheelAngleConfidence steerConfidence;
    BOOL headingConfidence_option;
    HeadingConfidence headingConfidence;
    BOOL throttleConfidence_option;
    ThrottleConfidence throttleConfidence;
} ConfidenceSet;

typedef struct AccelSets {
    BOOL accel4way_option;
    AccelerationSet4Way accel4way;
    BOOL vertAccelThres_option;
    BitString vertAccelThres; /* VerticalAccelerationThreshold (5..5) */
    BOOL yawRateCon_option;
    YawRateConfidence yawRateCon;
    BOOL hozAccelCon_option;
    AccelerationConfidence hozAccelCon;
    BOOL confidenceSet_option;
    ConfidenceSet confidenceSet;
} AccelSets;

typedef struct DetectedObject {
    int32_t obDist;   /* ObstacleDistance (0..32767) */
    int32_t obDirect; /* Angle (0..28800) */
    DDateTime dateTime;
} DetectedObject;

typedef struct BumperHeights {
    int32_t front; /* BumperHeight (0..127) */
    int32_t rear;  /* BumperHeight (0..127) */
} BumperHeights;

typedef struct VehicleProfile {
    int32_t height; /* VehicleHeight (0..127) */
    BumperHeights bumpers;
    int32_t mass;          /* VehicleMass (0..255) */
    int32_t trailerWeight; /* TrailerWeight (0..64255) */
    VehicleType type;
} VehicleProfile;

typedef enum WheelSensorStatus {
    WheelSensorStatus_off,
    WheelSensorStatus_on,
    WheelSensorStatus_notDefined,
    WheelSensorStatus_notSupported,
    WheelSensorStatus_MAX = UINT_MAX
} WheelSensorStatus;

typedef enum WheelEndElectFault {
    WheelEndElectFault_isOk,
    WheelEndElectFault_isNotDefined,
    WheelEndElectFault_isError,
    WheelEndElectFault_isNotSupported,
    WheelEndElectFault_MAX = UINT_MAX
} WheelEndElectFault;

typedef enum TirePressureThresholdDetection {
    TirePressureThresholdDetection_noData,
    TirePressureThresholdDetection_overPressure,
    TirePressureThresholdDetection_noWarningPressure,
    TirePressureThresholdDetection_underPressure,
    TirePressureThresholdDetection_extremeUnderPressure,
    TirePressureThresholdDetection_undefined,
    TirePressureThresholdDetection_errorIndicator,
    TirePressureThresholdDetection_notAvailable,
    TirePressureThresholdDetection_MAX = UINT_MAX
} TirePressureThresholdDetection;

typedef struct TireData {
    BOOL location_option;
    int32_t location; /* TireLocation (0..255) */
    BOOL pressure_option;
    int32_t pressure; /* TirePressure (0..250) */
    BOOL temp_option;
    int32_t temp; /* TireTemp (-8736..55519) */
    BOOL wheelSensorStatus_option;
    WheelSensorStatus wheelSensorStatus;
    BOOL wheelEndElectFault_option;
    WheelEndElectFault wheelEndElectFault;
    BOOL leakageRate_option;
    int32_t leakageRate; /* TireLeakageRate (0..64255) */
    BOOL detection_option;
    TirePressureThresholdDetection detection;
} TireData;

#define TireDataList_MAX_SIZE 16
typedef struct TireDataList {
    TireData *tab;
    int32_t count;
} TireDataList;

typedef struct AxleWeightSet {
    BOOL location_option;
    int32_t location; /* AxleLocation (0..255) */
    BOOL weight_option;
    int32_t weight; /* AxleWeight (0..64255) */
} AxleWeightSet;

#define AxleWeightList_MAX_SIZE 16
typedef struct AxleWeightList {
    AxleWeightSet *tab;
    int32_t count;
} AxleWeightList;

typedef struct J1939data {
    BOOL tires_option;
    TireDataList tires;
    BOOL axles_option;
    AxleWeightList axles;
    BOOL trailerWeight_option;
    int32_t trailerWeight; /* TrailerWeight (0..64255) */
    BOOL cargoWeight_option;
    int32_t cargoWeight; /* CargoWeight (0..64255) */
    BOOL steeringAxleTemperature_option;
    int32_t steeringAxleTemperature; /* SteeringAxleTemperature (-40..210) */
    BOOL driveAxleLocation_option;
    int32_t driveAxleLocation; /* DriveAxleLocation (0..255) */
    BOOL driveAxleLiftAirPressure_option;
    int32_t driveAxleLiftAirPressure; /* DriveAxleLiftAirPressure (0..1000) */
    BOOL driveAxleTemperature_option;
    int32_t driveAxleTemperature; /* DriveAxleTemperature (-40..210) */
    BOOL driveAxleLubePressure_option;
    int32_t driveAxleLubePressure; /* DriveAxleLubePressure (0..250) */
    BOOL steeringAxleLubePressure_option;
    int32_t steeringAxleLubePressure; /* SteeringAxleLubePressure (0..250) */
} J1939data;

typedef enum EssPrecipYesNo { EssPrecipYesNo_precip, EssPrecipYesNo_noPrecip, EssPrecipYesNo_error, EssPrecipYesNo_MAX = UINT_MAX } EssPrecipYesNo;

typedef enum EssPrecipSituation {
    EssPrecipSituation_other,
    EssPrecipSituation_unknown,
    EssPrecipSituation_noPrecipitation,
    EssPrecipSituation_unidentifiedSlight,
    EssPrecipSituation_unidentifiedModerate,
    EssPrecipSituation_unidentifiedHeavy,
    EssPrecipSituation_snowSlight,
    EssPrecipSituation_snowModerate,
    EssPrecipSituation_snowHeavy,
    EssPrecipSituation_rainSlight,
    EssPrecipSituation_rainModerate,
    EssPrecipSituation_rainHeavy,
    EssPrecipSituation_frozenPrecipitationSlight,
    EssPrecipSituation_frozenPrecipitationModerate,
    EssPrecipSituation_frozenPrecipitationHeavy,
    EssPrecipSituation_MAX = UINT_MAX
} EssPrecipSituation;

typedef struct WeatherStatus {
    EssPrecipYesNo isRaining;
    BOOL rainRate_option;
    int32_t rainRate; /* EssPrecipRate (0..65535) */
    BOOL precipSituation_option;
    EssPrecipSituation precipSituation;
    BOOL solarRadiation_option;
    int32_t solarRadiation; /* EssSolarRadiation (0..65535) */
    BOOL friction_option;
    int32_t friction; /* EssMobileFriction (0..101) */
} WeatherStatus;

typedef struct VehicleStatus {
    BOOL lights_option;
    BitString lights; /* ExteriorLights (9..9) */
    BOOL lightBar_option;
    LightbarInUse lightBar;
    BOOL wipers_option;
    WiperSet wipers;
    BOOL brakeStatus_option;
    BrakeSystemStatus brakeStatus;
    BOOL brakePressure_option;
    BrakeAppliedPressure brakePressure;
    BOOL roadFriction_option;
    int32_t roadFriction; /* CoefficientOfFriction (0..50) */
    BOOL sunData_option;
    int32_t sunData; /* SunSensor (0..1000) */
    BOOL rainData_option;
    RainSensor rainData;
    BOOL airTemp_option;
    int32_t airTemp; /* AmbientAirTemperature (0..191) */
    BOOL airPres_option;
    int32_t airPres; /* AmbientAirPressure (0..255) */
    BOOL steering_option;
    Steering steering;
    BOOL accelSets_option;
    AccelSets accelSets;
    BOOL object_option;
    DetectedObject object;
    BOOL fullPos_option;
    FullPositionVector fullPos;
    BOOL throttlePos_option;
    int32_t throttlePos; /* ThrottlePosition (0..200) */
    BOOL speedHeadC_option;
    SpeedandHeadingandThrottleConfidence speedHeadC;
    BOOL speedC_option;
    SpeedConfidence speedC;
    BOOL vehicleData_option;
    VehicleProfile vehicleData;
    BOOL vehicleIdent_option;
    VehicleIdent vehicleIdent;
    BOOL j1939data_option;
    J1939data j1939data;
    BOOL weatherReport_option;
    WeatherStatus weatherReport;
    BOOL gnssStatus_option;
    BitString gnssStatus; /* GNSSstatus (8..8) */
} VehicleStatus;

typedef struct Snapshot {
    FullPositionVector thePosition;
    BOOL safetyExt_option;
    VehicleSafetyExtensions safetyExt;
    BOOL dataSet_option;
    VehicleStatus dataSet;
} Snapshot;

#define SnapshotList_MAX_SIZE 32
typedef struct SnapshotList {
    Snapshot *tab;
    int32_t count;
} SnapshotList;

typedef struct Reg_ProbeVehicleData {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_ProbeVehicleData;

#define Reg_ProbeVehicleDataList_MAX_SIZE 4
typedef struct Reg_ProbeVehicleDataList {
    Reg_ProbeVehicleData *tab;
    int32_t count;
} Reg_ProbeVehicleDataList;

typedef enum RTCM_Revision {
    RTCM_Revision_unknown,
    RTCM_Revision_rtcmRev2,
    RTCM_Revision_rtcmRev3,
    RTCM_Revision_reserved,
    RTCM_Revision_MAX = UINT_MAX
} RTCM_Revision;

typedef struct AntennaOffsetSet {
    int32_t antOffsetX; /* Offset_B12 (-2048..2047) */
    int32_t antOffsetY; /* Offset_B09 (-256..255) */
    int32_t antOffsetZ; /* Offset_B10 (-512..511) */
} AntennaOffsetSet;

typedef struct RTCMheader {
    BitString status; /* GNSSstatus (8..8) */
    AntennaOffsetSet offsetSet;
} RTCMheader;

#define RTCMmessageList_MAX_SIZE 5
typedef struct RTCMmessageList {
    OctetString *tab; /* RTCMmessage (1..1023) */
    int32_t count;
} RTCMmessageList;

typedef struct Reg_RTCMcorrections {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_RTCMcorrections;

#define Reg_RTCMcorrectionsList_MAX_SIZE 4
typedef struct Reg_RTCMcorrectionsList {
    Reg_RTCMcorrections *tab;
    int32_t count;
} Reg_RTCMcorrectionsList;

typedef enum PriorityRequestType {
    PriorityRequestType_priorityRequestTypeReserved,
    PriorityRequestType_priorityRequest,
    PriorityRequestType_priorityRequestUpdate,
    PriorityRequestType_priorityCancellation,
    PriorityRequestType_MAX = UINT_MAX
} PriorityRequestType;

typedef enum {
    IntersectionAccessPoint_lane,
    IntersectionAccessPoint_approach,
    IntersectionAccessPoint_connection,
} IntersectionAccessPoint_choice;

typedef struct IntersectionAccessPoint {
    IntersectionAccessPoint_choice choice;
    union {
        int32_t lane;       /* LaneID (0..255) */
        int32_t approach;   /* ApproachID (0..15) */
        int32_t connection; /* LaneConnectionID (0..255) */
    } u;
} IntersectionAccessPoint;

typedef struct Reg_SignalRequest {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_SignalRequest;

#define Reg_SignalRequestList_MAX_SIZE 4
typedef struct Reg_SignalRequestList {
    Reg_SignalRequest *tab;
    int32_t count;
} Reg_SignalRequestList;

typedef struct SignalRequest {
    IntersectionReferenceID id;
    int32_t requestID; /* RequestID (0..255) */
    PriorityRequestType requestType;
    IntersectionAccessPoint inBoundLane;
    BOOL outBoundLane_option;
    IntersectionAccessPoint outBoundLane;
    BOOL regional_option;
    Reg_SignalRequestList regional;
} SignalRequest;

typedef struct Reg_SignalRequestPackage {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_SignalRequestPackage;

#define Reg_SignalRequestPackageList_MAX_SIZE 4
typedef struct Reg_SignalRequestPackageList {
    Reg_SignalRequestPackage *tab;
    int32_t count;
} Reg_SignalRequestPackageList;

typedef struct SignalRequestPackage {
    SignalRequest request;
    BOOL minute_option;
    int32_t minute; /* MinuteOfTheYear (0..527040) */
    BOOL second_option;
    int32_t second; /* DSecond (0..65535) */
    BOOL duration_option;
    int32_t duration; /* DSecond (0..65535) */
    BOOL regional_option;
    Reg_SignalRequestPackageList regional;
} SignalRequestPackage;

#define SignalRequestList_MAX_SIZE 32
typedef struct SignalRequestList {
    SignalRequestPackage *tab;
    int32_t count;
} SignalRequestList;

typedef enum RequestSubRole {
    RequestSubRole_requestSubRoleUnKnown,
    RequestSubRole_requestSubRole1,
    RequestSubRole_requestSubRole2,
    RequestSubRole_requestSubRole3,
    RequestSubRole_requestSubRole4,
    RequestSubRole_requestSubRole5,
    RequestSubRole_requestSubRole6,
    RequestSubRole_requestSubRole7,
    RequestSubRole_requestSubRole8,
    RequestSubRole_requestSubRole9,
    RequestSubRole_requestSubRole10,
    RequestSubRole_requestSubRole11,
    RequestSubRole_requestSubRole12,
    RequestSubRole_requestSubRole13,
    RequestSubRole_requestSubRole14,
    RequestSubRole_requestSubRoleReserved,
    RequestSubRole_MAX = UINT_MAX
} RequestSubRole;

typedef enum RequestImportanceLevel {
    RequestImportanceLevel_requestImportanceLevelUnKnown,
    RequestImportanceLevel_requestImportanceLevel1,
    RequestImportanceLevel_requestImportanceLevel2,
    RequestImportanceLevel_requestImportanceLevel3,
    RequestImportanceLevel_requestImportanceLevel4,
    RequestImportanceLevel_requestImportanceLevel5,
    RequestImportanceLevel_requestImportanceLevel6,
    RequestImportanceLevel_requestImportanceLevel7,
    RequestImportanceLevel_requestImportanceLevel8,
    RequestImportanceLevel_requestImportanceLevel9,
    RequestImportanceLevel_requestImportanceLevel10,
    RequestImportanceLevel_requestImportanceLevel11,
    RequestImportanceLevel_requestImportanceLevel12,
    RequestImportanceLevel_requestImportanceLevel13,
    RequestImportanceLevel_requestImportanceLevel14,
    RequestImportanceLevel_requestImportanceReserved,
    RequestImportanceLevel_MAX = UINT_MAX
} RequestImportanceLevel;

typedef struct Reg_RequestorType {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_RequestorType;

typedef struct RequestorType {
    BasicVehicleRole role;
    BOOL subrole_option;
    RequestSubRole subrole;
    BOOL request_option;
    RequestImportanceLevel request;
    BOOL iso3883_option;
    int32_t iso3883; /* Iso3833VehicleType (0..100) */
    BOOL hpmsType_option;
    VehicleType hpmsType;
    BOOL regional_option;
    Reg_RequestorType regional;
} RequestorType;

typedef struct RequestorPositionVector {
    Position3D position;
    BOOL heading_option;
    int32_t heading; /* Angle (0..28800) */
    BOOL speed_option;
    TransmissionAndSpeed speed;
} RequestorPositionVector;

#define TransitVehicleStatus_MAX_BITS 8
/* Bit position of BitString: TransitVehicleStatus */
typedef enum {
    TransitVehicleStatus_loading = 0,
    TransitVehicleStatus_anADAuse = 1,
    TransitVehicleStatus_aBikeLoad = 2,
    TransitVehicleStatus_doorOpen = 3,
    TransitVehicleStatus_charging = 4,
    TransitVehicleStatus_atStopLine = 5,
} TransitVehicleStatus;

typedef enum TransitVehicleOccupancy {
    TransitVehicleOccupancy_occupancyUnknown,
    TransitVehicleOccupancy_occupancyEmpty,
    TransitVehicleOccupancy_occupancyVeryLow,
    TransitVehicleOccupancy_occupancyLow,
    TransitVehicleOccupancy_occupancyMed,
    TransitVehicleOccupancy_occupancyHigh,
    TransitVehicleOccupancy_occupancyNearlyFull,
    TransitVehicleOccupancy_occupancyFull,
    TransitVehicleOccupancy_MAX = UINT_MAX
} TransitVehicleOccupancy;

typedef struct Reg_RequestorDescription {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_RequestorDescription;

#define Reg_RequestorDescriptionList_MAX_SIZE 4
typedef struct Reg_RequestorDescriptionList {
    Reg_RequestorDescription *tab;
    int32_t count;
} Reg_RequestorDescriptionList;

typedef struct RequestorDescription {
    VehicleID id;
    BOOL type_option;
    RequestorType type;
    BOOL position_option;
    RequestorPositionVector position;
    BOOL name_option;
    OctetString name; /* DescriptiveName (1..63) */
    BOOL routeName_option;
    OctetString routeName; /* DescriptiveName (1..63) */
    BOOL transitStatus_option;
    BitString transitStatus; /* TransitVehicleStatus (8..8) */
    BOOL transitOccupancy_option;
    TransitVehicleOccupancy transitOccupancy;
    BOOL transitSchedule_option;
    int32_t transitSchedule; /* DeltaTime (-122..121) */
    BOOL regional_option;
    Reg_RequestorDescriptionList regional;
} RequestorDescription;

typedef struct Reg_SignalRequestMessage {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_SignalRequestMessage;

#define Reg_SignalRequestMessageList_MAX_SIZE 4
typedef struct Reg_SignalRequestMessageList {
    Reg_SignalRequestMessage *tab;
    int32_t count;
} Reg_SignalRequestMessageList;

typedef struct SignalRequesterInfo {
    VehicleID id;
    int32_t request;        /* RequestID (0..255) */
    int32_t sequenceNumber; /* MsgCount (0..127) */
    BOOL role_option;
    BasicVehicleRole role;
    BOOL typeData_option;
    RequestorType typeData;
} SignalRequesterInfo;

typedef enum PrioritizationResponseStatus {
    PrioritizationResponseStatus_unknown,
    PrioritizationResponseStatus_requested,
    PrioritizationResponseStatus_processing,
    PrioritizationResponseStatus_watchOtherTraffic,
    PrioritizationResponseStatus_granted,
    PrioritizationResponseStatus_rejected,
    PrioritizationResponseStatus_maxPresence,
    PrioritizationResponseStatus_reserviceLocked,
    PrioritizationResponseStatus_MAX = UINT_MAX
} PrioritizationResponseStatus;

typedef struct Reg_SignalStatusPackage {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        SignalStatusPackage_addGrpC *grpc;
        void *data;
        OctetString unknown;
    } u;
} Reg_SignalStatusPackage;

#define Reg_SignalStatusPackageList_MAX_SIZE 4
typedef struct Reg_SignalStatusPackageList {
    Reg_SignalStatusPackage *tab;
    int32_t count;
} Reg_SignalStatusPackageList;

typedef struct SignalStatusPackage {
    BOOL requester_option;
    SignalRequesterInfo requester;
    IntersectionAccessPoint inboundOn;
    BOOL outboundOn_option;
    IntersectionAccessPoint outboundOn;
    BOOL minute_option;
    int32_t minute; /* MinuteOfTheYear (0..527040) */
    BOOL second_option;
    int32_t second; /* DSecond (0..65535) */
    BOOL duration_option;
    int32_t duration; /* DSecond (0..65535) */
    PrioritizationResponseStatus status;
    BOOL regional_option;
    Reg_SignalStatusPackageList regional;
} SignalStatusPackage;

#define SignalStatusPackageList_MAX_SIZE 32
typedef struct SignalStatusPackageList {
    SignalStatusPackage *tab;
    int32_t count;
} SignalStatusPackageList;

typedef struct Reg_SignalStatus {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_SignalStatus;

#define Reg_SignalStatusList_MAX_SIZE 4
typedef struct Reg_SignalStatusList {
    Reg_SignalStatus *tab;
    int32_t count;
} Reg_SignalStatusList;

typedef struct SignalStatus {
    int32_t sequenceNumber; /* MsgCount (0..127) */
    IntersectionReferenceID id;
    SignalStatusPackageList sigStatus;
    BOOL regional_option;
    Reg_SignalStatusList regional;
} SignalStatus;

#define SignalStatusList_MAX_SIZE 32
typedef struct SignalStatusList {
    SignalStatus *tab;
    int32_t count;
} SignalStatusList;

typedef struct Reg_SignalStatusMessage {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_SignalStatusMessage;

#define Reg_SignalStatusMessageList_MAX_SIZE 4
typedef struct Reg_SignalStatusMessageList {
    Reg_SignalStatusMessage *tab;
    int32_t count;
} Reg_SignalStatusMessageList;

typedef enum TravelerInfoType {
    TravelerInfoType_unknown,
    TravelerInfoType_advisory,
    TravelerInfoType_roadSignage,
    TravelerInfoType_commercialSignage,
    TravelerInfoType_MAX = UINT_MAX
} TravelerInfoType;

typedef enum MUTCDCode {
    MUTCDCode_none,
    MUTCDCode_regulatory,
    MUTCDCode_warning,
    MUTCDCode_maintenance,
    MUTCDCode_motoristService,
    MUTCDCode_guide,
    MUTCDCode_rec,
    MUTCDCode_MAX = UINT_MAX
} MUTCDCode;

typedef struct RoadSignID {
    Position3D position;
    BitString viewAngle; /* HeadingSlice (16..16) */
    BOOL mutcdCode_option;
    MUTCDCode mutcdCode;
    BOOL crc_option;
    OctetString crc; /* MsgCRC (2..2) */
} RoadSignID;

typedef enum {
    TDFmsgId_furtherInfoID,
    TDFmsgId_roadSignID,
} TDFmsgId_choice;

typedef struct TDFmsgId {
    TDFmsgId_choice choice;
    union {
        OctetString furtherInfoID; /* FurtherInfoID (2..2) */
        RoadSignID roadSignID;
    } u;
} TDFmsgId;

typedef enum DirectionOfUse {
    DirectionOfUse_unavailable,
    DirectionOfUse_forward,
    DirectionOfUse_reverse,
    DirectionOfUse_both,
    DirectionOfUse_MAX = UINT_MAX
} DirectionOfUse;

typedef struct Node_LL_24B {
    int32_t lon; /* OffsetLL_B12 (-2048..2047) */
    int32_t lat; /* OffsetLL_B12 (-2048..2047) */
} Node_LL_24B;

typedef struct Node_LL_28B {
    int32_t lon; /* OffsetLL_B14 (-8192..8191) */
    int32_t lat; /* OffsetLL_B14 (-8192..8191) */
} Node_LL_28B;

typedef struct Node_LL_32B {
    int32_t lon; /* OffsetLL_B16 (-32768..32767) */
    int32_t lat; /* OffsetLL_B16 (-32768..32767) */
} Node_LL_32B;

typedef struct Node_LL_36B {
    int32_t lon; /* OffsetLL_B18 (-131072..131071) */
    int32_t lat; /* OffsetLL_B18 (-131072..131071) */
} Node_LL_36B;

typedef struct Node_LL_44B {
    int32_t lon; /* OffsetLL_B22 (-2097152..2097151) */
    int32_t lat; /* OffsetLL_B22 (-2097152..2097151) */
} Node_LL_44B;

typedef struct Node_LL_48B {
    int32_t lon; /* OffsetLL_B24 (-8388608..8388607) */
    int32_t lat; /* OffsetLL_B24 (-8388608..8388607) */
} Node_LL_48B;

typedef struct Reg_NodeOffsetPointLL {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_NodeOffsetPointLL;

typedef enum {
    NodeOffsetPointLL_node_LL1,
    NodeOffsetPointLL_node_LL2,
    NodeOffsetPointLL_node_LL3,
    NodeOffsetPointLL_node_LL4,
    NodeOffsetPointLL_node_LL5,
    NodeOffsetPointLL_node_LL6,
    NodeOffsetPointLL_node_LatLon,
    NodeOffsetPointLL_regional,
} NodeOffsetPointLL_choice;

typedef struct NodeOffsetPointLL {
    NodeOffsetPointLL_choice choice;
    union {
        Node_LL_24B node_LL1;
        Node_LL_28B node_LL2;
        Node_LL_32B node_LL3;
        Node_LL_36B node_LL4;
        Node_LL_44B node_LL5;
        Node_LL_48B node_LL6;
        Node_LLmD_64b node_LatLon;
        Reg_NodeOffsetPointLL regional;
    } u;
} NodeOffsetPointLL;

typedef enum NodeAttributeLL {
    NodeAttributeLL_reserved,
    NodeAttributeLL_stopLine,
    NodeAttributeLL_roundedCapStyleA,
    NodeAttributeLL_roundedCapStyleB,
    NodeAttributeLL_mergePoint,
    NodeAttributeLL_divergePoint,
    NodeAttributeLL_downstreamStopLine,
    NodeAttributeLL_downstreamStartNode,
    NodeAttributeLL_closedToTraffic,
    NodeAttributeLL_safeIsland,
    NodeAttributeLL_curbPresentAtStepOff,
    NodeAttributeLL_hydrantPresent,
    NodeAttributeLL_MAX = UINT_MAX
} NodeAttributeLL;

#define NodeAttributeLLList_MAX_SIZE 8
typedef struct NodeAttributeLLList {
    NodeAttributeLL *tab;
    int32_t count;
} NodeAttributeLLList;

typedef enum SegmentAttributeLL {
    SegmentAttributeLL_reserved,
    SegmentAttributeLL_doNotBlock,
    SegmentAttributeLL_whiteLine,
    SegmentAttributeLL_mergingLaneLeft,
    SegmentAttributeLL_mergingLaneRight,
    SegmentAttributeLL_curbOnLeft,
    SegmentAttributeLL_curbOnRight,
    SegmentAttributeLL_loadingzoneOnLeft,
    SegmentAttributeLL_loadingzoneOnRight,
    SegmentAttributeLL_turnOutPointOnLeft,
    SegmentAttributeLL_turnOutPointOnRight,
    SegmentAttributeLL_adjacentParkingOnLeft,
    SegmentAttributeLL_adjacentParkingOnRight,
    SegmentAttributeLL_adjacentBikeLaneOnLeft,
    SegmentAttributeLL_adjacentBikeLaneOnRight,
    SegmentAttributeLL_sharedBikeLane,
    SegmentAttributeLL_bikeBoxInFront,
    SegmentAttributeLL_transitStopOnLeft,
    SegmentAttributeLL_transitStopOnRight,
    SegmentAttributeLL_transitStopInLane,
    SegmentAttributeLL_sharedWithTrackedVehicle,
    SegmentAttributeLL_safeIsland,
    SegmentAttributeLL_lowCurbsPresent,
    SegmentAttributeLL_rumbleStripPresent,
    SegmentAttributeLL_audibleSignalingPresent,
    SegmentAttributeLL_adaptiveTimingPresent,
    SegmentAttributeLL_rfSignalRequestPresent,
    SegmentAttributeLL_partialCurbIntrusion,
    SegmentAttributeLL_taperToLeft,
    SegmentAttributeLL_taperToRight,
    SegmentAttributeLL_taperToCenterLine,
    SegmentAttributeLL_parallelParking,
    SegmentAttributeLL_headInParking,
    SegmentAttributeLL_freeParking,
    SegmentAttributeLL_timeRestrictionsOnParking,
    SegmentAttributeLL_costToPark,
    SegmentAttributeLL_midBlockCurbPresent,
    SegmentAttributeLL_unEvenPavementPresent,
    SegmentAttributeLL_MAX = UINT_MAX
} SegmentAttributeLL;

#define SegmentAttributeLLList_MAX_SIZE 8
typedef struct SegmentAttributeLLList {
    SegmentAttributeLL *tab;
    int32_t count;
} SegmentAttributeLLList;

typedef struct Reg_NodeAttributeSetLL {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_NodeAttributeSetLL;

#define Reg_NodeAttributeSetLLList_MAX_SIZE 4
typedef struct Reg_NodeAttributeSetLLList {
    Reg_NodeAttributeSetLL *tab;
    int32_t count;
} Reg_NodeAttributeSetLLList;

typedef struct NodeAttributeSetLL {
    BOOL localNode_option;
    NodeAttributeLLList localNode;
    BOOL disabled_option;
    SegmentAttributeLLList disabled;
    BOOL enabled_option;
    SegmentAttributeLLList enabled;
    BOOL data_option;
    LaneDataAttributeList data;
    BOOL dWidth_option;
    int32_t dWidth; /* Offset_B10 (-512..511) */
    BOOL dElevation_option;
    int32_t dElevation; /* Offset_B10 (-512..511) */
    BOOL regional_option;
    Reg_NodeAttributeSetLLList regional;
} NodeAttributeSetLL;

typedef struct NodeLL {
    NodeOffsetPointLL delta;
    BOOL attributes_option;
    NodeAttributeSetLL attributes;
} NodeLL;

#define NodeSetLL_MAX_SIZE 63
typedef struct NodeSetLL {
    NodeLL *tab;
    int32_t count;
} NodeSetLL;

typedef enum {
    NodeListLL_nodes,
} NodeListLL_choice;

typedef struct NodeListLL {
    NodeListLL_choice choice;
    union {
        NodeSetLL nodes;
    } u;
} NodeListLL;

typedef enum {
    OffsetValue_xy,
    OffsetValue_ll,
} OffsetValue_choice;

typedef struct OffsetValue {
    OffsetValue_choice choice;
    union {
        NodeListXY xy;
        NodeListLL ll;
    } u;
} OffsetValue;

typedef struct OffsetSystem {
    BOOL scale_option;
    int32_t scale; /* Zoom (0..15) */
    OffsetValue offset;
} OffsetSystem;

typedef enum DistanceUnits {
    DistanceUnits_centimeter,
    DistanceUnits_cm2_5,
    DistanceUnits_decimeter,
    DistanceUnits_meter,
    DistanceUnits_kilometer,
    DistanceUnits_foot,
    DistanceUnits_yard,
    DistanceUnits_mile,
    DistanceUnits_MAX = UINT_MAX
} DistanceUnits;

typedef struct Circle {
    Position3D center;
    int32_t radius; /* Radius_B12 (0..4095) */
    DistanceUnits units;
} Circle;

typedef struct Reg_GeometricProjection {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_GeometricProjection;

#define Reg_GeometricProjectionList_MAX_SIZE 4
typedef struct Reg_GeometricProjectionList {
    Reg_GeometricProjection *tab;
    int32_t count;
} Reg_GeometricProjectionList;

typedef struct GeometricProjection {
    BitString direction; /* HeadingSlice (16..16) */
    BOOL extent_option;
    Extent extent;
    BOOL laneWidth_option;
    int32_t laneWidth; /* LaneWidth (0..32767) */
    Circle circle;
    BOOL regional_option;
    Reg_GeometricProjectionList regional;
} GeometricProjection;

typedef struct ShapePointSet {
    BOOL anchor_option;
    Position3D anchor;
    BOOL laneWidth_option;
    int32_t laneWidth; /* LaneWidth (0..32767) */
    BOOL directionality_option;
    DirectionOfUse directionality;
    NodeListXY nodeList;
} ShapePointSet;

typedef struct RegionOffsets {
    int32_t xOffset; /* OffsetLL_B16 (-32768..32767) */
    int32_t yOffset; /* OffsetLL_B16 (-32768..32767) */
    BOOL zOffset_option;
    int32_t zOffset; /* OffsetLL_B16 (-32768..32767) */
} RegionOffsets;

#define RegionList_MAX_SIZE 64
typedef struct RegionList {
    RegionOffsets *tab;
    int32_t count;
} RegionList;

typedef struct RegionPointSet {
    BOOL anchor_option;
    Position3D anchor;
    BOOL scale_option;
    int32_t scale; /* Zoom (0..15) */
    RegionList nodeList;
} RegionPointSet;

typedef enum {
    ValidRegionArea_shapePointSet,
    ValidRegionArea_circle,
    ValidRegionArea_regionPointSet,
} ValidRegionArea_choice;

typedef struct ValidRegionArea {
    ValidRegionArea_choice choice;
    union {
        ShapePointSet shapePointSet;
        Circle circle;
        RegionPointSet regionPointSet;
    } u;
} ValidRegionArea;

typedef struct ValidRegion {
    BitString direction; /* HeadingSlice (16..16) */
    BOOL extent_option;
    Extent extent;
    ValidRegionArea area;
} ValidRegion;

typedef enum {
    GeographicalPathDescription_path,
    GeographicalPathDescription_geometry,
    GeographicalPathDescription_oldRegion,
} GeographicalPathDescription_choice;

typedef struct GeographicalPathDescription {
    GeographicalPathDescription_choice choice;
    union {
        OffsetSystem path;
        GeometricProjection geometry;
        ValidRegion oldRegion;
    } u;
} GeographicalPathDescription;

typedef struct Reg_GeographicalPath {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_GeographicalPath;

#define Reg_GeographicalPathList_MAX_SIZE 4
typedef struct Reg_GeographicalPathList {
    Reg_GeographicalPath *tab;
    int32_t count;
} Reg_GeographicalPathList;

typedef struct GeographicalPath {
    BOOL name_option;
    OctetString name; /* DescriptiveName (1..63) */
    BOOL id_option;
    RoadSegmentReferenceID id;
    BOOL anchor_option;
    Position3D anchor;
    BOOL laneWidth_option;
    int32_t laneWidth; /* LaneWidth (0..32767) */
    BOOL directionality_option;
    DirectionOfUse directionality;
    BOOL closedPath_option;
    BOOL closedPath;
    BOOL direction_option;
    BitString direction; /* HeadingSlice (16..16) */
    BOOL description_option;
    GeographicalPathDescription description;
    BOOL regional_option;
    Reg_GeographicalPathList regional;
} GeographicalPath;

#define GeographicalPathList_MAX_SIZE 16
typedef struct GeographicalPathList {
    GeographicalPath *tab;
    int32_t count;
} GeographicalPathList;

typedef enum {
    ITIScodesAndTextItem_itis,
    ITIScodesAndTextItem_text,
} ITIScodesAndTextItem_choice;

typedef struct ITIScodesAndTextItem {
    ITIScodesAndTextItem_choice choice;
    union {
        int32_t itis;     /* ITIScodes (0..65535) */
        OctetString text; /* ITIStext (1..500) */
    } u;
} ITIScodesAndTextItem;

#define ITIScodesAndText_MAX_SIZE 100
typedef struct ITIScodesAndText {
    ITIScodesAndTextItem *tab;
    int32_t count;
} ITIScodesAndText;

typedef enum {
    ITISitem_itis,
    ITISitem_text,
} ITISitem_choice;

typedef struct ITISitem {
    ITISitem_choice choice;
    union {
        int32_t itis;     /* ITIScodes (0..65535) */
        OctetString text; /* ITIStextPhrase (1..16) */
    } u;
} ITISitem;

#define WorkZone_MAX_SIZE 16
typedef struct WorkZone {
    ITISitem *tab;
    int32_t count;
} WorkZone;

#define GenericSignage_MAX_SIZE 16
typedef struct GenericSignage {
    ITISitem *tab;
    int32_t count;
} GenericSignage;

#define SpeedLimit_MAX_SIZE 16
typedef struct SpeedLimit {
    ITISitem *tab;
    int32_t count;
} SpeedLimit;

#define ExitService_MAX_SIZE 16
typedef struct ExitService {
    ITISitem *tab;
    int32_t count;
} ExitService;

typedef enum {
    TDFcontent_advisory,
    TDFcontent_workZone,
    TDFcontent_genericSign,
    TDFcontent_speedLimit,
    TDFcontent_exitService,
} TDFcontent_choice;

typedef struct TDFcontent {
    TDFcontent_choice choice;
    union {
        ITIScodesAndText advisory;
        WorkZone workZone;
        GenericSignage genericSign;
        SpeedLimit speedLimit;
        ExitService exitService;
    } u;
} TDFcontent;

typedef struct TravelerDataFrame {
    int32_t sspTimRights; /* SSPindex (0..31) */
    TravelerInfoType frameType;
    TDFmsgId msgId;
    BOOL startYear_option;
    int32_t startYear;         /* DYear (0..4095) */
    int32_t startTime;         /* MinuteOfTheYear (0..527040) */
    int32_t duratonTime;       /* MinutesDuration (0..32000) */
    int32_t priority;          /* SignPrority (0..7) */
    int32_t sspLocationRights; /* SSPindex (0..31) */
    GeographicalPathList regions;
    int32_t sspMsgRights1; /* SSPindex (0..31) */
    int32_t sspMsgRights2; /* SSPindex (0..31) */
    TDFcontent content;
    BOOL url_option;
    OctetString url; /* URL_Short (1..15) */
} TravelerDataFrame;

#define TravelerDataFrameList_MAX_SIZE 8
typedef struct TravelerDataFrameList {
    TravelerDataFrame *tab;
    int32_t count;
} TravelerDataFrameList;

typedef struct Reg_TravelerInformation {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TravelerInformation;

#define Reg_TravelerInformationList_MAX_SIZE 4
typedef struct Reg_TravelerInformationList {
    Reg_TravelerInformation *tab;
    int32_t count;
} Reg_TravelerInformationList;

typedef enum PersonalDeviceUserType {
    PersonalDeviceUserType_unavailable,
    PersonalDeviceUserType_aPEDESTRIAN,
    PersonalDeviceUserType_aPEDALCYCLIST,
    PersonalDeviceUserType_aPUBLICSAFETYWORKER,
    PersonalDeviceUserType_anANIMAL,
    PersonalDeviceUserType_MAX = UINT_MAX
} PersonalDeviceUserType;

typedef enum HumanPropelledType {
    HumanPropelledType_unavailable,
    HumanPropelledType_otherTypes,
    HumanPropelledType_onFoot,
    HumanPropelledType_skateboard,
    HumanPropelledType_pushOrKickScooter,
    HumanPropelledType_wheelchair,
    HumanPropelledType_MAX = UINT_MAX
} HumanPropelledType;

typedef enum AnimalPropelledType {
    AnimalPropelledType_unavailable,
    AnimalPropelledType_otherTypes,
    AnimalPropelledType_animalMounted,
    AnimalPropelledType_animalDrawnCarriage,
    AnimalPropelledType_MAX = UINT_MAX
} AnimalPropelledType;

typedef enum MotorizedPropelledType {
    MotorizedPropelledType_unavailable,
    MotorizedPropelledType_otherTypes,
    MotorizedPropelledType_wheelChair,
    MotorizedPropelledType_bicycle,
    MotorizedPropelledType_scooter,
    MotorizedPropelledType_selfBalancingDevice,
    MotorizedPropelledType_MAX = UINT_MAX
} MotorizedPropelledType;

typedef enum {
    PropelledInformation_human,
    PropelledInformation_animal,
    PropelledInformation_motor,
} PropelledInformation_choice;

typedef struct PropelledInformation {
    PropelledInformation_choice choice;
    union {
        HumanPropelledType human;
        AnimalPropelledType animal;
        MotorizedPropelledType motor;
    } u;
} PropelledInformation;

#define PersonalDeviceUsageState_MAX_BITS 9
/* Bit position of BitString: PersonalDeviceUsageState */
typedef enum {
    PersonalDeviceUsageState_unavailable = 0,
    PersonalDeviceUsageState_other = 1,
    PersonalDeviceUsageState_idle = 2,
    PersonalDeviceUsageState_listeningToAudio = 3,
    PersonalDeviceUsageState_typing = 4,
    PersonalDeviceUsageState_calling = 5,
    PersonalDeviceUsageState_playingGames = 6,
    PersonalDeviceUsageState_reading = 7,
    PersonalDeviceUsageState_viewing = 8,
} PersonalDeviceUsageState;

typedef enum NumberOfParticipantsInCluster {
    NumberOfParticipantsInCluster_unavailable,
    NumberOfParticipantsInCluster_small,
    NumberOfParticipantsInCluster_medium,
    NumberOfParticipantsInCluster_large,
    NumberOfParticipantsInCluster_MAX = UINT_MAX
} NumberOfParticipantsInCluster;

typedef enum PublicSafetyEventResponderWorkerType {
    PublicSafetyEventResponderWorkerType_unavailable,
    PublicSafetyEventResponderWorkerType_towOperater,
    PublicSafetyEventResponderWorkerType_fireAndEMSWorker,
    PublicSafetyEventResponderWorkerType_aDOTWorker,
    PublicSafetyEventResponderWorkerType_lawEnforcement,
    PublicSafetyEventResponderWorkerType_hazmatResponder,
    PublicSafetyEventResponderWorkerType_animalControlWorker,
    PublicSafetyEventResponderWorkerType_otherPersonnel,
    PublicSafetyEventResponderWorkerType_MAX = UINT_MAX
} PublicSafetyEventResponderWorkerType;

#define PublicSafetyAndRoadWorkerActivity_MAX_BITS 6
/* Bit position of BitString: PublicSafetyAndRoadWorkerActivity */
typedef enum {
    PublicSafetyAndRoadWorkerActivity_unavailable = 0,
    PublicSafetyAndRoadWorkerActivity_workingOnRoad = 1,
    PublicSafetyAndRoadWorkerActivity_settingUpClosures = 2,
    PublicSafetyAndRoadWorkerActivity_respondingToEvents = 3,
    PublicSafetyAndRoadWorkerActivity_directingTraffic = 4,
    PublicSafetyAndRoadWorkerActivity_otherActivities = 5,
} PublicSafetyAndRoadWorkerActivity;

#define PublicSafetyDirectingTrafficSubType_MAX_BITS 7
/* Bit position of BitString: PublicSafetyDirectingTrafficSubType */
typedef enum {
    PublicSafetyDirectingTrafficSubType_unavailable = 0,
    PublicSafetyDirectingTrafficSubType_policeAndTrafficOfficers = 1,
    PublicSafetyDirectingTrafficSubType_trafficControlPersons = 2,
    PublicSafetyDirectingTrafficSubType_railroadCrossingGuards = 3,
    PublicSafetyDirectingTrafficSubType_civilDefenseNationalGuardMilitaryPolice = 4,
    PublicSafetyDirectingTrafficSubType_emergencyOrganizationPersonnel = 5,
    PublicSafetyDirectingTrafficSubType_highwayServiceVehiclePersonnel = 6,
} PublicSafetyDirectingTrafficSubType;

#define PersonalAssistive_MAX_BITS 6
#define UserSizeAndBehaviour_MAX_BITS 5
/* Bit position of BitString: UserSizeAndBehaviour */
typedef enum {
    UserSizeAndBehaviour_unavailable = 0,
    UserSizeAndBehaviour_smallStature = 1,
    UserSizeAndBehaviour_largeStature = 2,
    UserSizeAndBehaviour_erraticMoving = 3,
    UserSizeAndBehaviour_slowMoving = 4,
} UserSizeAndBehaviour;

typedef enum Attachment {
    Attachment_unavailable,
    Attachment_stroller,
    Attachment_bicycleTrailer,
    Attachment_cart,
    Attachment_wheelchair,
    Attachment_otherWalkAssistAttachments,
    Attachment_pet,
    Attachment_MAX = UINT_MAX
} Attachment;

typedef enum AnimalType { AnimalType_unavailable, AnimalType_serviceUse, AnimalType_pet, AnimalType_farm, AnimalType_MAX = UINT_MAX } AnimalType;

typedef struct Reg_PersonalSafetyMessage {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_PersonalSafetyMessage;

#define Reg_PersonalSafetyMessageList_MAX_SIZE 4
typedef struct Reg_PersonalSafetyMessageList {
    Reg_PersonalSafetyMessage *tab;
    int32_t count;
} Reg_PersonalSafetyMessageList;

typedef struct Header {
    BOOL year_option;
    int32_t year; /* DYear (0..4095) */
    BOOL timeStamp_option;
    int32_t timeStamp; /* MinuteOfTheYear (0..527040) */
    BOOL secMark_option;
    int32_t secMark; /* DSecond (0..65535) */
    BOOL msgIssueRevision_option;
    int32_t msgIssueRevision; /* MsgCount (0..127) */
} Header;

typedef struct Reg_TestMessage00 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage00;

typedef struct Reg_TestMessage01 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage01;

typedef struct Reg_TestMessage02 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage02;

typedef struct Reg_TestMessage03 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage03;

typedef struct Reg_TestMessage04 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage04;

typedef struct Reg_TestMessage05 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage05;

typedef struct Reg_TestMessage06 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage06;

typedef struct Reg_TestMessage07 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage07;

typedef struct Reg_TestMessage08 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage08;

typedef struct Reg_TestMessage09 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage09;

typedef struct Reg_TestMessage10 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage10;

typedef struct Reg_TestMessage11 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage11;

typedef struct Reg_TestMessage12 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage12;

typedef struct Reg_TestMessage13 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage13;

typedef struct Reg_TestMessage14 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage14;

typedef struct Reg_TestMessage15 {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_TestMessage15;

typedef struct Reg_EventDescription {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_EventDescription;

#define Reg_EventDescriptionList_MAX_SIZE 4
typedef struct Reg_EventDescriptionList {
    Reg_EventDescription *tab;
    int32_t count;
} Reg_EventDescriptionList;

typedef struct EventDescription {
    int32_t typeEvent; /* ITIScodes (0..65535) */
    BOOL description_option;
    ITIScodesList description;
    BOOL priority_option;
    OctetString priority; /* Priority (1..1) */
    BOOL heading_option;
    BitString heading; /* HeadingSlice (16..16) */
    BOOL extent_option;
    Extent extent;
    BOOL regional_option;
    Reg_EventDescriptionList regional;
} EventDescription;

typedef struct PivotPointDescription {
    int32_t pivotOffset; /* Offset_B11 (-1024..1023) */
    int32_t pivotAngle;  /* Angle (0..28800) */
    BOOL pivots;         /* PivotingAllowed */
} PivotPointDescription;

typedef struct TrailerHistoryPoint {
    int32_t pivotAngle; /* Angle (0..28800) */
    int32_t timeOffset; /* TimeOffset (1..65535) */
    Node_XY_24b positionOffset;
    BOOL elevationOffset_option;
    int32_t elevationOffset; /* VertOffset_B07 (-64..63) */
    BOOL heading_option;
    int32_t heading; /* CoarseHeading (0..240) */
} TrailerHistoryPoint;

#define TrailerHistoryPointList_MAX_SIZE 23
typedef struct TrailerHistoryPointList {
    TrailerHistoryPoint *tab;
    int32_t count;
} TrailerHistoryPointList;

typedef struct TrailerUnitDescription {
    BOOL isDolly;   /* IsDolly */
    int32_t width;  /* VehicleWidth (0..1023) */
    int32_t length; /* VehicleLength (0..4095) */
    BOOL height_option;
    int32_t height; /* VehicleHeight (0..127) */
    BOOL mass_option;
    int32_t mass; /* TrailerMass (0..255) */
    BOOL bumperHeights_option;
    BumperHeights bumperHeights;
    BOOL centerOfGravity_option;
    int32_t centerOfGravity; /* VehicleHeight (0..127) */
    PivotPointDescription frontPivot;
    BOOL rearPivot_option;
    PivotPointDescription rearPivot;
    BOOL rearWheelOffset_option;
    int32_t rearWheelOffset; /* Offset_B12 (-2048..2047) */
    Node_XY_24b positionOffset;
    BOOL elevationOffset_option;
    int32_t elevationOffset; /* VertOffset_B07 (-64..63) */
    BOOL crumbData_option;
    TrailerHistoryPointList crumbData;
} TrailerUnitDescription;

#define TrailerUnitDescriptionList_MAX_SIZE 8
typedef struct TrailerUnitDescriptionList {
    TrailerUnitDescription *tab;
    int32_t count;
} TrailerUnitDescriptionList;

typedef struct TrailerData {
    int32_t sspRights; /* SSPindex (0..31) */
    PivotPointDescription connection;
    TrailerUnitDescriptionList units;
} TrailerData;

typedef struct SpecialVehicleExtensions {
    BOOL vehicleAlerts_option;
    EmergencyDetails vehicleAlerts;
    BOOL description_option;
    EventDescription description;
    BOOL trailers_option;
    TrailerData trailers;
} SpecialVehicleExtensions;

typedef struct VehicleData {
    BOOL height_option;
    int32_t height; /* VehicleHeight (0..127) */
    BOOL bumpers_option;
    BumperHeights bumpers;
    BOOL mass_option;
    int32_t mass; /* VehicleMass (0..255) */
    BOOL trailerWeight_option;
    int32_t trailerWeight; /* TrailerWeight (0..64255) */
} VehicleData;

typedef struct WeatherReport {
    EssPrecipYesNo isRaining;
    BOOL rainRate_option;
    int32_t rainRate; /* EssPrecipRate (0..65535) */
    BOOL precipSituation_option;
    EssPrecipSituation precipSituation;
    BOOL solarRadiation_option;
    int32_t solarRadiation; /* EssSolarRadiation (0..65535) */
    BOOL friction_option;
    int32_t friction; /* EssMobileFriction (0..101) */
    BOOL roadFriction_option;
    int32_t roadFriction; /* CoefficientOfFriction (0..50) */
} WeatherReport;

typedef struct WeatherProbe {
    BOOL airTemp_option;
    int32_t airTemp; /* AmbientAirTemperature (0..191) */
    BOOL airPressure_option;
    int32_t airPressure; /* AmbientAirPressure (0..255) */
    BOOL rainRates_option;
    WiperSet rainRates;
} WeatherProbe;

typedef enum GenericLocations {
    GenericLocations_on_bridges,
    GenericLocations_in_tunnels,
    GenericLocations_entering_or_leaving_tunnels,
    GenericLocations_on_ramps,
    GenericLocations_in_road_construction_area,
    GenericLocations_around_a_curve,
    GenericLocations_on_curve,
    GenericLocations_on_tracks,
    GenericLocations_in_street,
    GenericLocations_shoulder,
    GenericLocations_on_minor_roads,
    GenericLocations_in_the_opposing_lanes,
    GenericLocations_adjacent_to_roadway,
    GenericLocations_across_tracks,
    GenericLocations_on_bend,
    GenericLocations_intersection,
    GenericLocations_entire_intersection,
    GenericLocations_in_the_median,
    GenericLocations_moved_to_side_of_road,
    GenericLocations_moved_to_shoulder,
    GenericLocations_on_the_roadway,
    GenericLocations_dip,
    GenericLocations_traffic_circle,
    GenericLocations_crossover,
    GenericLocations_cross_road,
    GenericLocations_side_road,
    GenericLocations_to,
    GenericLocations_by,
    GenericLocations_through,
    GenericLocations_area_of,
    GenericLocations_under,
    GenericLocations_over,
    GenericLocations_from,
    GenericLocations_approaching,
    GenericLocations_entering_at,
    GenericLocations_exiting_at,
    GenericLocations_in_shaded_areas,
    GenericLocations_in_low_lying_areas,
    GenericLocations_in_the_downtown_area,
    GenericLocations_in_the_inner_city_area,
    GenericLocations_in_parts,
    GenericLocations_in_some_places,
    GenericLocations_in_the_ditch,
    GenericLocations_in_the_valley,
    GenericLocations_on_hill_top,
    GenericLocations_near_the_foothills,
    GenericLocations_at_high_altitudes,
    GenericLocations_near_the_lake,
    GenericLocations_near_the_shore,
    GenericLocations_nearby_basin,
    GenericLocations_over_the_crest_of_a_hill,
    GenericLocations_other_than_on_the_roadway,
    GenericLocations_near_the_beach,
    GenericLocations_near_beach_access_point,
    GenericLocations_mountain_pass,
    GenericLocations_lower_level,
    GenericLocations_upper_level,
    GenericLocations_airport,
    GenericLocations_concourse,
    GenericLocations_gate,
    GenericLocations_baggage_claim,
    GenericLocations_customs_point,
    GenericLocations_reservation_center,
    GenericLocations_station,
    GenericLocations_platform,
    GenericLocations_dock,
    GenericLocations_depot,
    GenericLocations_ev_charging_point,
    GenericLocations_information_welcome_point,
    GenericLocations_at_rest_area,
    GenericLocations_at_service_area,
    GenericLocations_at_weigh_station,
    GenericLocations_roadside_park,
    GenericLocations_picnic_areas,
    GenericLocations_rest_area,
    GenericLocations_service_stations,
    GenericLocations_toilets,
    GenericLocations_bus_stop,
    GenericLocations_park_and_ride_lot,
    GenericLocations_on_the_right,
    GenericLocations_on_the_left,
    GenericLocations_in_the_center,
    GenericLocations_in_the_opposite_direction,
    GenericLocations_cross_traffic,
    GenericLocations_northbound_traffic,
    GenericLocations_eastbound_traffic,
    GenericLocations_southbound_traffic,
    GenericLocations_westbound_traffic,
    GenericLocations_north,
    GenericLocations_south,
    GenericLocations_east,
    GenericLocations_west,
    GenericLocations_northeast,
    GenericLocations_northwest,
    GenericLocations_southeast,
    GenericLocations_southwest,
    GenericLocations_MAX = UINT_MAX
} GenericLocations;

typedef struct ObstacleDetection {
    int32_t obDist;   /* ObstacleDistance (0..32767) */
    int32_t obDirect; /* ObstacleDirection */
    BOOL description_option;
    int32_t description; /* ITIScodes_2 (523..541) */
    BOOL locationDetails_option;
    GenericLocations locationDetails;
    DDateTime dateTime;
    BOOL vertEvent_option;
    BitString vertEvent; /* VerticalAccelerationThreshold (5..5) */
} ObstacleDetection;

typedef struct DisabledVehicle {
    int32_t statusDetails; /* ITIScodes_1 (523..541) */
    BOOL locationDetails_option;
    GenericLocations locationDetails;
} DisabledVehicle;

#define asn1_type_SpeedProfileMeasurement asn1_type_GrossSpeed

#define SpeedProfileMeasurementList_MAX_SIZE 20
typedef struct SpeedProfileMeasurementList {
    int32_t *tab; /* SpeedProfileMeasurement */
    int32_t count;
} SpeedProfileMeasurementList;

typedef struct SpeedProfile {
    SpeedProfileMeasurementList speedReports;
} SpeedProfile;

typedef struct RTCMPackage {
    BOOL rtcmHeader_option;
    RTCMheader rtcmHeader;
    RTCMmessageList msgs;
} RTCMPackage;

typedef struct Reg_SupplementalVehicleExtensions {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_SupplementalVehicleExtensions;

#define Reg_SupplementalVehicleExtensionsList_MAX_SIZE 4
typedef struct Reg_SupplementalVehicleExtensionsList {
    Reg_SupplementalVehicleExtensions *tab;
    int32_t count;
} Reg_SupplementalVehicleExtensionsList;

typedef struct SupplementalVehicleExtensions {
    BOOL classification_option;
    int32_t classification; /* BasicVehicleClass (0..255) */
    BOOL classDetails_option;
    VehicleClassification classDetails;
    BOOL vehicleData_option;
    VehicleData vehicleData;
    BOOL weatherReport_option;
    WeatherReport weatherReport;
    BOOL weatherProbe_option;
    WeatherProbe weatherProbe;
    BOOL obstacle_option;
    ObstacleDetection obstacle;
    BOOL status_option;
    DisabledVehicle status;
    BOOL speedProfile_option;
    SpeedProfile speedProfile;
    BOOL theRTCM_option;
    RTCMPackage theRTCM;
    BOOL regional_option;
    Reg_SupplementalVehicleExtensionsList regional;
} SupplementalVehicleExtensions;

typedef struct DDate {
    int32_t year;  /* DYear (0..4095) */
    int32_t month; /* DMonth (0..12) */
    int32_t day;   /* DDay (0..31) */
} DDate;

typedef struct DFullTime {
    int32_t year;   /* DYear (0..4095) */
    int32_t month;  /* DMonth (0..12) */
    int32_t day;    /* DDay (0..31) */
    int32_t hour;   /* DHour (0..31) */
    int32_t minute; /* DMinute (0..60) */
} DFullTime;

typedef struct DMonthDay {
    int32_t month; /* DMonth (0..12) */
    int32_t day;   /* DDay (0..31) */
} DMonthDay;

typedef struct DTime {
    int32_t hour;   /* DHour (0..31) */
    int32_t minute; /* DMinute (0..60) */
    int32_t second; /* DSecond (0..65535) */
    BOOL offset_option;
    int32_t offset; /* DOffset (-840..840) */
} DTime;

typedef struct DYearMonth {
    int32_t year;  /* DYear (0..4095) */
    int32_t month; /* DMonth (0..12) */
} DYearMonth;

typedef struct Reg_VerticalOffset {
    RegionId regionId;
    uintptr_t *asn1Type; /* Don't modify it. It is for internal processing. */
    union {
        void *data;
        OctetString unknown;
    } u;
} Reg_VerticalOffset;

typedef enum {
    VerticalOffset_offset1,
    VerticalOffset_offset2,
    VerticalOffset_offset3,
    VerticalOffset_offset4,
    VerticalOffset_offset5,
    VerticalOffset_offset6,
    VerticalOffset_elevation,
    VerticalOffset_regional,
} VerticalOffset_choice;

typedef struct VerticalOffset {
    VerticalOffset_choice choice;
    union {
        int32_t offset1;   /* VertOffset_B07 (-64..63) */
        int32_t offset2;   /* VertOffset_B08 (-128..127) */
        int32_t offset3;   /* VertOffset_B09 (-256..255) */
        int32_t offset4;   /* VertOffset_B10 (-512..511) */
        int32_t offset5;   /* VertOffset_B11 (-1024..1023) */
        int32_t offset6;   /* VertOffset_B12 (-2048..2047) */
        int32_t elevation; /* Elevation (-4096..61439) */
        Reg_VerticalOffset regional;
    } u;
} VerticalOffset;

typedef enum Location_quality {
    Location_quality_loc_qual_bt1m,
    Location_quality_loc_qual_bt5m,
    Location_quality_loc_qual_bt12m,
    Location_quality_loc_qual_bt50m,
    Location_quality_loc_qual_bt125m,
    Location_quality_loc_qual_bt500m,
    Location_quality_loc_qual_bt1250m,
    Location_quality_loc_qual_unknown,
    Location_quality_MAX = UINT_MAX
} Location_quality;

typedef enum Location_tech {
    Location_tech_loc_tech_unknown,
    Location_tech_loc_tech_GNSS,
    Location_tech_loc_tech_DGPS,
    Location_tech_loc_tech_RTK,
    Location_tech_loc_tech_PPP,
    Location_tech_loc_tech_drGPS,
    Location_tech_loc_tech_drDGPS,
    Location_tech_loc_tech_dr,
    Location_tech_loc_tech_nav,
    Location_tech_loc_tech_fault,
    Location_tech_MAX = UINT_MAX
} Location_tech;

#define TransitStatus_MAX_BITS 6
/* Bit position of BitString: TransitStatus */
typedef enum {
    TransitStatus_none = 0,
    TransitStatus_anADAuse = 1,
    TransitStatus_aBikeLoad = 2,
    TransitStatus_doorOpen = 3,
    TransitStatus_occM = 4,
    TransitStatus_occL = 5,
} TransitStatus;

typedef struct VehicleToLanePosition {
    uint32_t stationID; /* StationID (0..4294967295) */
    int32_t laneID;     /* LaneID (0..255) */
} VehicleToLanePosition;

#define VehicleToLanePositionList_MAX_SIZE 5
typedef struct VehicleToLanePositionList {
    VehicleToLanePosition *tab;
    int32_t count;
} VehicleToLanePositionList;

#if 0

typedef struct ConnectionManeuverAssist_addGrpC {
    VehicleToLanePositionList vehicleToLanePositions;
    BOOL rsuDistanceFromAnchor_option;
    NodeOffsetPointXY rsuDistanceFromAnchor;
} ConnectionManeuverAssist_addGrpC;

typedef struct PrioritizationResponse {
    uint32_t stationID; /* StationID (0..4294967295) */
    PrioritizationResponseStatus priorState;
    int32_t signalGroup; /* SignalGroupID (0..255) */
} PrioritizationResponse;

#define PrioritizationResponseList_MAX_SIZE 10
typedef struct PrioritizationResponseList {
    PrioritizationResponse *tab;
    int32_t count;
} PrioritizationResponseList;

typedef struct IntersectionState_addGrpC {
    BOOL activePrioritizations_option;
    PrioritizationResponseList activePrioritizations;
} IntersectionState_addGrpC;

typedef struct LaneDataAttribute_addGrpB {
    uint8_t dummy_field;
} LaneDataAttribute_addGrpB;

typedef struct MovementEvent_addGrpB {
    BOOL startTime_option;
    int32_t startTime; /* TimeRemaining (0..9001) */
    int32_t minEndTime; /* MinTimetoChange (0..2402) */
    BOOL maxEndTime_option;
    int32_t maxEndTime; /* MaxTimetoChange (0..2402) */
    BOOL likelyTime_option;
    int32_t likelyTime; /* TimeRemaining (0..9001) */
    BOOL confidence_option;
    int32_t confidence; /* TimeIntervalConfidence (0..15) */
    BOOL nextTime_option;
    int32_t nextTime; /* TimeRemaining (0..9001) */
} MovementEvent_addGrpB;

typedef struct Node_LLdms_48b {
    int32_t lon; /* LongitudeDMS (-64800000..64800000) */
    int32_t lat; /* LatitudeDMS (-32400000..32400000) */
} Node_LLdms_48b;

typedef struct LongitudeDMS2 {
    int32_t d; /* DegreesLong (-180..180) */
    int32_t m; /* MinutesAngle (0..59) */
    int32_t s; /* SecondsAngle (0..5999) */
} LongitudeDMS2;

typedef struct LatitudeDMS2 {
    int32_t d; /* DegreesLat (-90..90) */
    int32_t m; /* MinutesAngle (0..59) */
    int32_t s; /* SecondsAngle (0..5999) */
} LatitudeDMS2;

typedef struct Node_LLdms_80b {
    LongitudeDMS2 lon;
    LatitudeDMS2 lat;
} Node_LLdms_80b;

typedef enum {
    NodeOffsetPointXY_addGrpB_posA,
    NodeOffsetPointXY_addGrpB_posB,
} NodeOffsetPointXY_addGrpB_choice;

typedef struct NodeOffsetPointXY_addGrpB {
    NodeOffsetPointXY_addGrpB_choice choice;
    union {
        Node_LLdms_48b posA;
        Node_LLdms_80b posB;
    } u;
} NodeOffsetPointXY_addGrpB;

typedef struct Position3D_addGrpB {
    LatitudeDMS2 latitude;
    LongitudeDMS2 longitude;
    int32_t elevation; /* Elevation_addGrpB (-32768..32767) */
} Position3D_addGrpB;

typedef enum AltitudeConfidence {
    AltitudeConfidence_alt_000_01,
    AltitudeConfidence_alt_000_02,
    AltitudeConfidence_alt_000_05,
    AltitudeConfidence_alt_000_10,
    AltitudeConfidence_alt_000_20,
    AltitudeConfidence_alt_000_50,
    AltitudeConfidence_alt_001_00,
    AltitudeConfidence_alt_002_00,
    AltitudeConfidence_alt_005_00,
    AltitudeConfidence_alt_010_00,
    AltitudeConfidence_alt_020_00,
    AltitudeConfidence_alt_050_00,
    AltitudeConfidence_alt_100_00,
    AltitudeConfidence_alt_200_00,
    AltitudeConfidence_outOfRange,
    AltitudeConfidence_unavailable,
    AltitudeConfidence_MAX = UINT_MAX
} AltitudeConfidence;

typedef struct Altitude {
    int32_t value; /* AltitudeValue (-100000..800001) */
    AltitudeConfidence confidence;
} Altitude;

typedef struct Position3D_addGrpC {
    Altitude altitude;
} Position3D_addGrpC;

typedef enum EmissionType {
    EmissionType_typeA,
    EmissionType_typeB,
    EmissionType_typeC,
    EmissionType_typeD,
    EmissionType_typeE,
    EmissionType_MAX = UINT_MAX
} EmissionType;

typedef struct RestrictionUserType_addGrpC {
    BOOL emission_option;
    EmissionType emission;
} RestrictionUserType_addGrpC;

typedef struct SignalHeadLocation {
    NodeOffsetPointXY node;
    int32_t signalGroupID; /* SignalGroupID (0..255) */
} SignalHeadLocation;

#define SignalHeadLocationList_MAX_SIZE 20
typedef struct SignalHeadLocationList {
    SignalHeadLocation *tab;
    int32_t count;
} SignalHeadLocationList;

typedef struct MapData_addGrpC {
    BOOL signalHeadLocations_option;
    SignalHeadLocationList signalHeadLocations;
} MapData_addGrpC;

typedef enum DayOfWeek {
    DayOfWeek_unknown,
    DayOfWeek_monday,
    DayOfWeek_tuesday,
    DayOfWeek_wednesday,
    DayOfWeek_thursday,
    DayOfWeek_friday,
    DayOfWeek_saturday,
    DayOfWeek_sunday,
    DayOfWeek_MAX = UINT_MAX
} DayOfWeek;

typedef enum Holiday {
    Holiday_weekday,
    Holiday_holiday,
    Holiday_MAX = UINT_MAX
} Holiday;

typedef enum SummerTime {
    SummerTime_notInSummerTime,
    SummerTime_inSummerTime,
    SummerTime_MAX = UINT_MAX
} SummerTime;
#endif

#ifdef __cplusplus
}
#endif

#endif /* __J2735_DATA_COMPONENT_H__ */
