/*
 * Utility function definitions for J2735 data frame
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */
#ifndef __J2735_DF_UTILS_H__
#define __J2735_DF_UTILS_H__
#include "asn1helper_if.h"
#include "j2735_data_component.h"

/**
 * allocate the memory of the data frame which is inside union type
 *
 * The union type is not allocated by j2735_msg_prealloc()
 * because there is no way to know the choice of user.
 * This function does the allocation upon the choice field inside "data"
 * with the same policy of j2735_msg_prealloc().
 * The supported data frame are listed in DataFrameID in j2735_msg.h
 * This is designed to be used with j2735_dataframe_dealloc() in pairs.
 * e.g.
 *   typedef struct PartIIcontent {
 *     PartII_Id partII_Id;
 *     ...
 *     union {
 *       VehicleSafetyExtensions *safetyExt;
 *       SpecialVehicleExtensions *specialExt;
 *       SupplementalVehicleExtensions *supplementalExt;
 *       void *data;
 *       OctetString unknown;
 *     } u;
 *   } PartIIcontent;
 *
 *   PartIIcontent part2;
 *   part2.partII_Id = VehicleSafetyExt;
 *   j2735_dataframe_prealloc(PartIIcontent_Id, &part2);
 *
 *   The memory of part2.u.safetyExt and fields inside it are
 *   allocated recursively with max. size defined in J2735 ASN.1
 *   definitions.
 *
 * @param[in]  df_id The supported data frame
 * @param[in,out]  data The address of the structure memory corresponding to df_id
 * @retval -1 Failed
 *         0 Successful
 */
extern int j2735_dataframe_prealloc(DataFrameID df_id, void *data);

/**
 * free the memory of the data frame which is inside union type
 *
 * The union type is not freed by j2735_msg_dealloc()
 * because there is no way to know the choice of user.
 * This function does the free upon the choice field inside "data"
 * with the same policy of j2735_msg_dealloc().
 * The supported data frame are listed in DataFrameID in j2735_msg.h
 * This is designed to be used with j2735_dataframe_prealloc() in pairs.
 *
 * @param[in]  df_id The supported data frame.
 * @param[in,out]  data The address of the structure memory corresponding to df_id.
 * @retval -1 Failed
 *         0 Successful
 */
extern int j2735_dataframe_dealloc(DataFrameID df_id, void *data);

#endif /* __J2735_DF_UTILS_H__ */
