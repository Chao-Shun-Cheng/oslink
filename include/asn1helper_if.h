/*
 * ASN1 helper functions for interface accessing
 * Copyright (C) Unex Technology Corporation - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */
#ifndef __ASN1_HELPER_IF
#define __ASN1_HELPER_IF

#include "asn1defs_if.h"

/**
 * allocate memory for bitstring storage
 *
 * WARN: DO NOT mix the usage with j2735_msg_prealloc() and j2735_dataframe_prealloc()
 *
 * @param[in,out]  bstr Address of bitstring.
 * @param[in]  bit_size The size in bit to be allocated
 */
extern void asn1_bstr_alloc(BitString *bstr, unsigned int bit_size);

/**
 * Set the bit to 1 in the bitstring by the index
 *
 * The index starts from 0 (MSB) defined by ASN.1 UPER
 * and max. index is the "bstr->len - 1".
 * e.g.
 *     bit index 0: MSB of bstr->buf[0]
 *     bit index 7: LSB of bstr->buf[0]
 *     bit index 8: MSB of bstr->buf[1]
 *
 *
 * @param[in,out]  bstr Address of bitstring.
 * @param[in]  idx The index of bit which will be set to 1
 */
extern void asn1_bstr_set_bit(BitString *bstr, unsigned int idx);

/**
 * Clear the bit in the bitstring by the index
 *
 * The index starts from 0 (MSB) defined by ASN.1 UPER
 * and max. index is the "bstr->len - 1".
 * e.g.
 *     bit index 0: MSB of bstr->buf[0]
 *     bit index 7: LSB of bstr->buf[0]
 *     bit index 8: MSB of bstr->buf[1]
 *
 *
 * @param[in,out]  bstr Address of bitstring.
 * @param[in]  idx The index of bit which will be set to 1
 */
extern void asn1_bstr_clr_bit(BitString *bstr, unsigned int idx);

/**
 * Check the bit is set or not
 *
 * The index starts from 0 (MSB) defined by ASN.1 UPER
 * and max. index is the "bstr->len - 1".
 * e.g.
 *     bit index 0: MSB of bstr->buf[0]
 *     bit index 7: LSB of bstr->buf[0]
 *     bit index 8: MSB of bstr->buf[1]
 *
 * @param[in,out]  bstr Address of bitstring.
 * @param[in]  idx The index of bit which will be set to 1
 * @return  The index of bit is set or not
 * @retval  1 the bit is set
 * @retval  0 the bit is not set
 * @retval  <0 error
 */
extern int asn1_bstr_is_bit_set(const BitString *bstr, const unsigned int idx);

/**
 * Clear all bit to 0 in the bstr
 *
 * @param[in,out]  bstr Address of bitstring.
 */
extern void asn1_bstr_clr(BitString *bstr);

/**
 * Clear all bits to 0 in the bstr and then set
 *
 * Equivalent to j2735_bstr_clr() and j2735_bstr_set_bit
 *
 * @param[in,out]  bstr Address of bitstring.
 * @param[in]  idx The index of bit which will be set to 1
 */
extern void asn1_bstr_clr_set_bit(BitString *bstr, unsigned int idx);

/**
 * Allocate the memory for bitstring storage and set a bit to 1
 *
 * Equivalent to j2735_bstr_alloc() and j2735_bstr_set_bit
 *
 * WARN: DO NOT mix the usage with j2735_msg_prealloc() and j2735_dataframe_prealloc()
 *
 * @param[in,out]  bstr Address of bitstring.
 *                      bstr->buf will contains the address of allocated memory.
 * @param[in]  bit_size The size in bit to be allocated
 * @param[in]  idx The index of bit which will be set to 1
 */
extern void asn1_bstr_alloc_set_bit(BitString *bstr, unsigned int bit_size, unsigned int idx);

/**
 * free memory of bitstring storage
 *
 * WARN: DO NOT mix the usage with j2735_msg_dealloc() and j2735_dataframe_dealloc()
 *
 * @param[in,out]  bstr Address of bitstring.
 */
extern void asn1_bstr_free(BitString *bstr);

/**
 * Find the first set bit in the bitstring
 *
 * The searching starts from index 0 and return the index of first one bit which is set to 1.
 * e.g.
 *     bit index 0: MSB of bstr->buf[0]
 *     bit index 7: LSB of bstr->buf[0]
 *     bit index 8: MSB of bstr->buf[1]
 *
 * @param[in]  bstr Address of bitstring.
 * @return  The index of the first set bit
 * @retval -1  Not found.
 */
extern int asn1_bstr_ffs(BitString *bstr);

/**
 * Clone the C-style string
 *
 * If the storage of the ostr is NULL or not bigger enough,
 * the memory will alloc or realloc based on the size and copy the content.
 * If the storage is bigger enough, just copy the content.
 * The ostr should be well initialized because of the comparison of storage size.
 *
 * WARN: DO NOT mix the usage with j2735_msg_dealloc() and j2735_dataframe_dealloc()
 *
 * @param[in,out] ostr Address of octet string structure
 * @param[in] str Address of c-style string
 * @param[in] str_len Length of str
 */
extern void asn1_ostr_clone_cstr(OctetString *ostr, const char *str, unsigned int str_len);

/**
 * Free the memory of octet string storage
 *
 * WARN: DO NOT mix the usage with j2735_msg_dealloc() and j2735_dataframe_dealloc()
 *
 * @param[in,out] ostr Address of octet string structure
 */
extern void asn1_ostr_free(OctetString *ostr);

/**
 * To allocate and initialize a big integer according to inputting unsigned 64 value.
 *
 * WARN: DO NOT mix the usage with j2735_msg_dealloc() and j2735_dataframe_dealloc()
 */
extern void asn1_new_integer_u64(BigInteger *r, uint64_t v);

/**
 * To allocate and initialize a big integer according to inputting signed 64 value.
 *
 * WARN: DO NOT mix the usage with j2735_msg_dealloc() and j2735_dataframe_dealloc()
 */
extern void asn1_new_integer_s64(BigInteger *r, int64_t v);

/**
 * To release a allocated a big integer buffer.
 *
 * WARN: DO NOT mix the usage with j2735_msg_dealloc() and j2735_dataframe_dealloc()
 */
extern void asn1_free_integer(BigInteger *r);

/**
 * Extract signed 64 value from big integer buffer, return 0 if OK, -1 if overflow.
 */
extern int32_t asn1_get_integer_si64_ov(const BigInteger *r, int64_t *pval);

#endif /* __ASN1_HELPER_IF */
