/*
 * Generated using zcbor version 0.8.1
 * https://github.com/NordicSemiconductor/zcbor
 * Generated with a --default-max-qty of 3
 */

#ifndef BACKEND_CBOR_MESSAGE_2_DECODE_H__
#define BACKEND_CBOR_MESSAGE_2_DECODE_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "backend_cbor_edhoc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#if DEFAULT_MAX_QTY != 3
#error "The type file was generated with a different default_max_qty than this file"
#endif


int cbor_decode_message_2_G_Y_CIPHERTEXT_2(
		const uint8_t *payload, size_t payload_len,
		struct zcbor_string *result,
		size_t *payload_len_out);


#ifdef __cplusplus
}
#endif

#endif /* BACKEND_CBOR_MESSAGE_2_DECODE_H__ */
