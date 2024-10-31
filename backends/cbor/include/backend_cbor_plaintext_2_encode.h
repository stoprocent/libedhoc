/*
 * Generated using zcbor version 0.8.1
 * https://github.com/NordicSemiconductor/zcbor
 * Generated with a --default-max-qty of 3
 */

#ifndef BACKEND_CBOR_PLAINTEXT_2_ENCODE_H__
#define BACKEND_CBOR_PLAINTEXT_2_ENCODE_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "backend_cbor_x509_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#if DEFAULT_MAX_QTY != 3
#error "The type file was generated with a different default_max_qty than this file"
#endif


int cbor_encode_plaintext_2(
		uint8_t *payload, size_t payload_len,
		const struct plaintext_2 *input,
		size_t *payload_len_out);


#ifdef __cplusplus
}
#endif

#endif /* BACKEND_CBOR_PLAINTEXT_2_ENCODE_H__ */
