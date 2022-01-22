/*
 * J2735 encoder and decoder definitions
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */
#ifndef __J2735_CODEC_H__
#define __J2735_CODEC_H__
#include "asn1helper_if.h"
#include "j2735_df_utils.h"
#include "j2735_msg.h"

typedef struct J2735Config {
    uint8_t *mem_pool_buf; /* Address of large memory as heap for internal dynamic memory usage  */
    int mem_pool_sz;       /* the size of the above memory pool */
} J2735Config;

typedef struct J2735CodecErr {
    int bit_pos; /* used for PER decoding */
    int msg_size;
    int msg_len;
    char *msg; /* message */
} J2735CodecErr;

/**
 * do the initialization of J2735 library
 *
 * @param[in]  cfg Address of the configuration of J2735 library.
 *
 * @retval -1  Fail.
 *          0  Success.
 */
extern int j2735_init(const J2735Config *cfg);

/**
 * Configure the size of error msg
 *
 * The default size is 256 bytes without any configuration.
 *
 * @param[in]  sz Size of error msg in byte.
 *
 */
extern void j2735_set_error_msg_size(uint32_t sz);

/**
 * Get the size of error msg
 *
 * The default size is 256 bytes without any configuration.
 *
 * @return The size of error msg in byte.
 */
extern unsigned int j2735_get_error_msg_size();

/**
 * Allocate the memory of J2735 message structure
 *
 * Recursively allocate memory of each fields with list(sequence-of),
 * octec string, bitstring type in the message structure.
 * The allocated size of memory is the max size defined in J2735 ASN.1 definitions.
 * The len of octec and bit string type is filled with the max size.
 * The count of list type is filled with 0.
 * All other memory content are initialized as zero.
 * The memory of field with union type will not be allocated.
 * This is designed to be used with j2735_msg_dealloc() in pairs.
 *
 * @param[in]  msg_id The msg type (BSM, SPAT, MAP, ...).
 * @return It is the address of the memory of message structure.
 * @retval NULL Failed
 */
extern void *j2735_msg_prealloc(DSRCmsgID msg_id);

/**
 * Free the memory of J2735 message structure
 *
 * Recursively free memory of each fields with list(sequence-of),
 * octec string, bitstring type in the message structure.
 * The memory of field with union type will not be freed.
 * This is designed to be used with j2735_msg_prealloc() in pairs.
 *
 * @param[in]  msg_id The msg type (BSM, SPAT, MAP, ...)
 * @param[in]  msg The address of the message structure.
 * @retval -1 The msg_id is out of valid range
 *         0 The msg_id is valid
 */
extern int j2735_msg_dealloc(DSRCmsgID msg_id, void *msg);

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

/**
 * Encode the pre-defined message structure as UPER format for tansmitting
 *
 * Because user has no way to determine the size of result,
 * the memory is allocated inside the function.
 *
 * @param[in,out]  buf The address for the encoder to store the address of allocated memory
 *                     where the encoded result is stored
 *                     if error, it is NULL and no memory is allocated.
 * @param[in]  msg The message to be encoded
 * @param[in,out]  err The address of the J2735CodecErr structure which is for recording
 *                     the error message if encode fail.
 *                     It could be NULL if it is not necessary.
 * @return It is the size in byte of encoded result, the space which *buf point to.
 * @retval -1 Failed.
 */
extern int j2735_msg_encode(uint8_t **buf, MessageFrame *msg, J2735CodecErr *err);

/**
 * Decode the UPER format data to pre-defined message structure for processing
 *
 * Because user has no way to determine the type of message after decoding,
 * the memory of decoded message structure is allocated inside the function.
 * The type of decoded message could be gotten from (*msg)->messageId if decode successfully.
 *
 *
 * @param[in,out]  msg The address for the encoder to store the address of allocated memory
 *                     of decoded message structure.
 *                     if error, it is NULL and no memory is allocated.
 * @param[in]  buf The UPER format data to be decoded
 * @param[in]  buf_len The length of buf in bytes
 * @param[in,out]  err The address of the J2735CodecErr structure which is for recording
 *                     the error message if encode fail.
 *                     It could be NULL if it is not necessary.
 * @return The number of consumed bytes.
 * @retval -1 Failed.
 */
extern int j2735_msg_decode(MessageFrame **msg, const uint8_t *buf, const unsigned int buf_len, J2735CodecErr *err);

/**
 * Free the memory of message structure
 *
 * Recursively free memory of each fields inside the message structue
 * only when the field is presented which means mandatory field or
 * optional field with presented flag (TRUE).
 * It is designed mainly to free the memory allocated by decoder.
 *
 * WANR: DO NOT use the function to free the memory allocated by j2735_msg_peralloc().
 *       It will cause memory leakage.
 *
 * @param[in]  msg_id The msg type (MessageFrame, BSM, SPAT, MAP, ...)
 * @param[in]  msg The address of message structue to be freed
 * @retval -1 The msg_id is out of valid range
 *         0  The msg_id is valid
 */
extern int j2735_msg_free(DSRCmsgID msg_id, void *msg);

/**
 * Free the memory of MessageFrame structure
 *
 * It is just a wrapper of j2735_msg_free() for using friendly.
 * Please find more details in the description of j2735_msg_free().
 * It is designed mainly to free the memory allocated by decoder.
 *
 * WANR: DO NOT use the function to free the memory allocated by j2735_msg_peralloc().
 *       It will cause memory leakage.
 *
 * @param[in]  p_msgf The address of MessageFrame structue to be freed
 */
#define J2735_FREE_MSG_FRAME(p_msgf) j2735_msg_free(MessageFrame_Id, p_msgf)

/**
 * free the memory of a buffer
 *
 * It just a wrapper of free() in the standard library of C
 * in most of system.
 * To utilize this function is for portability to a RTOS
 * without the standard library of C. It is designed mainly
 * to free the memory allocated by decoding function, j2735_msg_encode().
 *
 * @param[in] buf The address of memory pointed by the buffer
 */
extern void j2735_buf_free(void *buf);

#endif /* __J2735_CODEC_H__ */
