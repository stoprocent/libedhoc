/*
 * Generated using zcbor version 0.7.0
 * https://github.com/NordicSemiconductor/zcbor
 * Generated with a --default-max-qty of 3
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "zcbor_encode.h"
#include "backend_cbor_id_cred_x_encode.h"

#if DEFAULT_MAX_QTY != 3
#error "The type file was generated with a different default_max_qty than this file"
#endif

static bool encode_repeated_id_cred_x_kid(zcbor_state_t *state, const struct id_cred_x_kid_ *input);
static bool encode_repeated_id_cred_x_x5bag(zcbor_state_t *state, const struct id_cred_x_x5bag *input);
static bool encode_repeated_id_cred_x_x5chain(zcbor_state_t *state, const struct id_cred_x_x5chain *input);
static bool encode_repeated_id_cred_x_x5t(zcbor_state_t *state, const struct id_cred_x_x5t_ *input);
static bool encode_id_cred_x(zcbor_state_t *state, const struct id_cred_x *input);


static bool encode_repeated_id_cred_x_kid(
		zcbor_state_t *state, const struct id_cred_x_kid_ *input)
{
	zcbor_print("%s\r\n", __func__);

	bool tmp_result = ((((zcbor_uint32_put(state, (4))))
	&& (((*input)._id_cred_x_kid_choice == _id_cred_x_kid_int) ? ((zcbor_int32_encode(state, (&(*input)._id_cred_x_kid_int))))
	: (((*input)._id_cred_x_kid_choice == _id_cred_x_kid_bstr) ? ((zcbor_bstr_encode(state, (&(*input)._id_cred_x_kid_bstr))))
	: false))));

	if (!tmp_result)
		zcbor_trace();

	return tmp_result;
}

static bool encode_repeated_id_cred_x_x5bag(
		zcbor_state_t *state, const struct id_cred_x_x5bag *input)
{
	zcbor_print("%s\r\n", __func__);

	bool tmp_result = ((((zcbor_uint32_put(state, (32))))
	&& (zcbor_bstr_encode(state, (&(*input)._id_cred_x_x5bag)))));

	if (!tmp_result)
		zcbor_trace();

	return tmp_result;
}

static bool encode_repeated_id_cred_x_x5chain(
		zcbor_state_t *state, const struct id_cred_x_x5chain *input)
{
	zcbor_print("%s\r\n", __func__);

	bool tmp_result = ((((zcbor_uint32_put(state, (33))))
	&& (zcbor_bstr_encode(state, (&(*input)._id_cred_x_x5chain)))));

	if (!tmp_result)
		zcbor_trace();

	return tmp_result;
}

static bool encode_repeated_id_cred_x_x5t(
		zcbor_state_t *state, const struct id_cred_x_x5t_ *input)
{
	zcbor_print("%s\r\n", __func__);

	bool tmp_result = ((((zcbor_uint32_put(state, (34))))
	&& (zcbor_list_start_encode(state, 2) && ((((((*input)._id_cred_x_x5t_alg_choice == _id_cred_x_x5t_alg_int) ? ((zcbor_int32_encode(state, (&(*input)._id_cred_x_x5t_alg_int))))
	: (((*input)._id_cred_x_x5t_alg_choice == _id_cred_x_x5t_alg_bstr) ? ((zcbor_bstr_encode(state, (&(*input)._id_cred_x_x5t_alg_bstr))))
	: false)))
	&& ((zcbor_bstr_encode(state, (&(*input)._id_cred_x_x5t_hash))))) || (zcbor_list_map_end_force_encode(state), false)) && zcbor_list_end_encode(state, 2))));

	if (!tmp_result)
		zcbor_trace();

	return tmp_result;
}

static bool encode_id_cred_x(
		zcbor_state_t *state, const struct id_cred_x *input)
{
	zcbor_print("%s\r\n", __func__);

	bool tmp_result = (((zcbor_map_start_encode(state, 4) && ((zcbor_present_encode(&((*input)._id_cred_x_kid_present), (zcbor_encoder_t *)encode_repeated_id_cred_x_kid, state, (&(*input)._id_cred_x_kid))
	&& zcbor_present_encode(&((*input)._id_cred_x_x5bag_present), (zcbor_encoder_t *)encode_repeated_id_cred_x_x5bag, state, (&(*input)._id_cred_x_x5bag))
	&& zcbor_present_encode(&((*input)._id_cred_x_x5chain_present), (zcbor_encoder_t *)encode_repeated_id_cred_x_x5chain, state, (&(*input)._id_cred_x_x5chain))
	&& zcbor_present_encode(&((*input)._id_cred_x_x5t_present), (zcbor_encoder_t *)encode_repeated_id_cred_x_x5t, state, (&(*input)._id_cred_x_x5t))) || (zcbor_list_map_end_force_encode(state), false)) && zcbor_map_end_encode(state, 4))));

	if (!tmp_result)
		zcbor_trace();

	return tmp_result;
}



int cbor_encode_id_cred_x(
		uint8_t *payload, size_t payload_len,
		const struct id_cred_x *input,
		size_t *payload_len_out)
{
	zcbor_state_t states[5];

	zcbor_new_state(states, sizeof(states) / sizeof(zcbor_state_t), payload, payload_len, 1);

	bool ret = encode_id_cred_x(states, input);

	if (ret && (payload_len_out != NULL)) {
		*payload_len_out = MIN(payload_len,
				(size_t)states[0].payload - (size_t)payload);
	}

	if (!ret) {
		int err = zcbor_pop_error(states);

		zcbor_print("Return error: %d\r\n", err);
		return (err == ZCBOR_SUCCESS) ? ZCBOR_ERR_UNKNOWN : err;
	}
	return ZCBOR_SUCCESS;
}
