/**
 * \file    edhoc_ead.h
 * \author  Kamil Kielbasa
 * \brief   EDHOC External Authorization Data (EAD) interface.
 * \version 0.2
 * \date    2024-01-01
 * 
 * \copyright Copyright (c) 2024
 * 
 */

/* Header guard ------------------------------------------------------------ */
#ifndef EDHOC_EAD_H
#define EDHOC_EAD_H

/* Include files ----------------------------------------------------------- */
#include <stdint.h>
#include <stddef.h>

/* Defines ----------------------------------------------------------------- */
/* Types and type definitions ---------------------------------------------- */

/**
 * @brief RFC 9528: 3.1. General.
 */
enum edhoc_message {
	EDHOC_MSG_1,
	EDHOC_MSG_2,
	EDHOC_MSG_3,
	EDHOC_MSG_4,
};

/**
 * @brief RFC 9528: 3.8. External Authorization Data (EAD).
 */
struct edhoc_ead_token {
	int32_t label;

	const uint8_t *value;
	size_t value_len;
};

/** 
 * \brief Callback for external authorization data (EAD) composing.
 *
 * \param[in] user_context      User context.
 * \param message               Message number for context information. (EAD_1, EAD_2, EAD_3 or EAD_4)
 * \param[in,out] ead_token     Buffer where the generated EAD tokens is to be written.
 * \param ead_token_size        Number of the \p ead_token.
 * \param[out] ead_token_len    On success, the number of written EAD tokens.
 *
 * \return EDHOC_SUCCESS on success, otherwise failure.
 */
typedef int (*edhoc_ead_compose)(void *user_context, enum edhoc_message message,
				 struct edhoc_ead_token *ead_token,
				 size_t ead_token_size, size_t *ead_token_len);

/** 
 * \brief Callback for external authorization data (EAD) processing.
 *
 * \param[in] user_context      User context.
 * \param message               Message number for context information. (EAD_1, EAD_2, EAD_3 or EAD_4)
 * \param[in] ead_token         Buffer containing the EAD tokens.
 * \param ead_token_size        Number of the received EAD tokens in \p ead_token.
 *
 * \return EDHOC_SUCCESS on success, otherwise failure.
 */
typedef int (*edhoc_ead_process)(void *user_context, enum edhoc_message message,
				 const struct edhoc_ead_token *ead_token,
				 size_t ead_token_size);

/**
 * \brief Bind structure for EAD operations.
 */
struct edhoc_ead {
	edhoc_ead_compose compose;
	edhoc_ead_process process;
};

/* Module interface variables and constants -------------------------------- */
/* Extern variables and constant declarations ------------------------------ */
/* Module interface function declarations ---------------------------------- */

#endif /* EDHOC_EAD_H */
