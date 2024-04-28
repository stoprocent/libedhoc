/**
 * \file    edhoc_crypto.h
 * \author  Kamil Kielbasa
 * \brief   EDHOC cryptographic interface.
 * \version 0.2
 * \date    2024-01-01
 * 
 * \copyright Copyright (c) 2024
 * 
 */

/* Header guard ------------------------------------------------------------ */
#ifndef EDHOC_CRYPTO_H
#define EDHOC_CRYPTO_H

/* Include files ----------------------------------------------------------- */
#include <stdint.h>
#include <stddef.h>

/* Defines ----------------------------------------------------------------- */
/* Types and type definitions ---------------------------------------------- */

/**
 * \brief Structure for cipher suite value and related algorithms lengths in bytes.
 */
struct edhoc_cipher_suite {
	/* IANA registery value. */
	int32_t value;

	/* EDHOC AEAD algorithm: key & tag & IV lengths in bytes. */
	size_t aead_key_length;
	size_t aead_tag_length;
	size_t aead_iv_length;

	/* EDHOC hash algorithm: hash length in bytes. */
	size_t hash_length;

	/* EDHOC MAC length in bytes. */
	size_t mac_length;

	/* EDHOC ECC algorithm: key & sign lengths in bytes. */
	size_t ecc_key_length;
	size_t ecc_sign_length;
};

/**
 * \brief EDHOC key types.
 */
enum edhoc_key_type {
	EDHOC_KT_MAKE_KEY_PAIR,
	EDHOC_KT_KEY_AGREEMENT,

	EDHOC_KT_SIGNATURE,
	EDHOC_KT_VERIFY,

	EDHOC_KT_EXTRACT,
	EDHOC_KT_EXPAND,

	EDHOC_KT_ENCRYPT,
	EDHOC_KT_DECRYPT,
};

/**
 * \brief Cryptographic function for key identifier generation.
 *
 * \param key_type                      Requested key type.
 * \param[in] raw_key                   Key material in binary format.
 * \param raw_key_length                Size of the \p raw_key buffer in bytes.
 * \param[out] key_id                   Key identifier.
 *
 * \return EDHOC_SUCCESS on success, otherwise failure.
 */
typedef int (*edhoc_generate_key_t)(enum edhoc_key_type key_type,
				    const uint8_t *raw_key,
				    size_t raw_key_length, void *key_id);

/**
 * \brief Cryptographic function for key identifier destroying.
 *
 * \param[in] key_id                    Key identifier.
 *
 * \return EDHOC_SUCCESS on success, otherwise failure.
 */
typedef int (*edhoc_destroy_key_t)(void *key_id);

/**
 * \brief Bind structure for cryptographic key identifiers.
 */
struct edhoc_keys {
	edhoc_generate_key_t generate_key;
	edhoc_destroy_key_t destroy_key;
};

/**
 * \brief Cryptographic function for generating ephemeral ECDH key pair.
 *
 * \param[in] key_id                    Key identifier.
 * \param[out] private_key              Private ephemeral ECDH key.
 * \param private_key_size              Size of the \p private_key buffer in bytes.
 * \param[out] private_key_length       On success, the number of bytes that make up the ECDH private key.
 * \param[out] public_key               Public ephemeral ECDH key.
 * \param public_key_size               Size of the \p public_key buffer in bytes.
 * \param[out] public_key_length        On success, the number of bytes that make up the ECDH private key.
 *
 * \return EDHOC_SUCCESS on success, otherwise failure.
 */
typedef int (*edhoc_make_key_pair_t)(const void *key_id,
				     uint8_t *restrict private_key,
				     size_t private_key_size,
				     size_t *restrict private_key_length,
				     uint8_t *restrict public_key,
				     size_t public_key_size,
				     size_t *restrict public_key_length);

/**
 * \brief Cryptographic function for computing ECDH key agreement.
 *
 * \param[in] key_id                    Key identifier.
 * \param[in] peer_public_key           Peer public ECDH key.
 * \param peer_public_key_length        Size of the \p peer_public_key buffer in bytes.
 * \param[out] shared_secret            ECDH shared secret.
 * \param shared_secret_size            Size of the \p shared_secret buffer in bytes.
 * \param[out] shared_secret_length     On success, the number of bytes that make up the ECDH shared secret.
 *
 * \return EDHOC_SUCCESS on success, otherwise failure.
 */
typedef int (*edhoc_key_agreement_t)(const void *key_id,
				     const uint8_t *peer_public_key,
				     size_t peer_public_key_length,
				     uint8_t *shared_secret,
				     size_t shared_secret_size,
				     size_t *shared_secret_length);

/**
 * \brief Cryptographic function for generating ECDSA sign.
 *
 * \param[in] key_id                    Key identifier.
 * \param[in] input                     Input message to sign.
 * \param input_length                  Size of the \p input buffer in bytes.
 * \param[out] signature                Buffer where the signature is to be written.
 * \param signature_size                Size of the \p signature buffer in bytes.
 * \param[out] signature_length         On success, the number of bytes that make up the signature.
 *
 * \return EDHOC_SUCCESS on success, otherwise failure.
 */
typedef int (*edhoc_signature_t)(const void *key_id, const uint8_t *input,
				 size_t input_length, uint8_t *signature,
				 size_t signature_size,
				 size_t *signature_length);

/**
 * \brief Cryptographic function for ECDSA signature verification.
 *
 * \param[in] key_id                    Key identifier.
 * \param[in] input                     Input message to verify.
 * \param input_length                  Size of the \p input buffer in bytes.
 * \param[in] signature                 Buffer where the signature is to be written.
 * \param signature_length              Size of the \p signature buffer in bytes.
 *
 * \return EDHOC_SUCCESS on success, otherwise failure.
 */
typedef int (*edhoc_verify_t)(const void *key_id, const uint8_t *input,
			      size_t input_length, const uint8_t *signature,
			      size_t signature_length);

/**
 * \brief Cryptographic function for HKDF extracting.
 *
 * \param[in] key_id                    Key identifier.
 * \param[in] salt                      Salt for extract.
 * \param salt_len                      Size of the \p salt buffer in bytes.
 * \param[out] psuedo_random_key        Buffer where the psuedo random key is to be written.
 * \param psuedo_random_key_size        Size of the \p psuedo_random_key buffer in bytes.
 * \param[out] psuedo_random_key_length On success, the number of bytes that make up the psuedo random key.
 *
 * \return EDHOC_SUCCESS on success, otherwise failure.
 */
typedef int (*edhoc_extract_t)(const void *key_id, const uint8_t *salt,
			       size_t salt_len, uint8_t *psuedo_random_key,
			       size_t psuedo_random_key_size,
			       size_t *psuedo_random_key_length);

/**
 * \brief Cryptographic function for HKDF expanding.
 *
 * \param[in] key_id                    Key identifier.
 * \param[in] info                      Information context.
 * \param info_length                   Size of the \p info buffer in bytes.
 * \param[out] output_keying_material   Buffer where the output keying material is to be written.
 * \param output_keying_material_length Size of the \p output_keying_material buffer in bytes.
 *
 * \return EDHOC_SUCCESS on success, otherwise failure.
 */
typedef int (*edhoc_expand_t)(const void *key_id, const uint8_t *info,
			      size_t info_length,
			      uint8_t *output_keying_material,
			      size_t output_keying_material_length);

/**
 * \brief Cryptographic function for AEAD encryption.
 *
 * \param[in] key_id                    Key identifier.
 * \param[in] nonce                     Nonce or IV to use.
 * \param nonce_length                  Size of the \p nonce buffer in bytes.
 * \param[in] additional_data           Additional data that will be authenticated but not encrypted.
 * \param additional_data_length        Size of the \p additional_data buffer in bytes.
 * \param[in] plaintext                 Data that will be authenticated and encrypted.
 * \param plaintext_length              Size of the \p plaintext buffer in bytes.
 * \param[out] ciphertext               Buffer where the authenticated and encrypted data is to be written.
 * \param ciphertext_size               Size of the \p ciphertext buffer in bytes.
 * \param[out] ciphertext_length        On success, the number of bytes that make up the ciphertext.
 *
 * \return EDHOC_SUCCESS on success, otherwise failure.
 */
typedef int (*edhoc_encrypt_t)(
	const void *key_id, const uint8_t *nonce, size_t nonce_length,
	const uint8_t *additional_data, size_t additional_data_length,
	const uint8_t *plaintext, size_t plaintext_length, uint8_t *ciphertext,
	size_t ciphertext_size, size_t *ciphertext_length);

/**
 * \brief Cryptographic function for AEAD decryption.
 *
 * \param[in] key_id                    Key identifier.
 * \param[in] nonce                     Nonce or IV to use.
 * \param nonce_len                     Size of the \p nonce buffer in bytes.
 * \param[in] additional_data           Additional data that will be authenticated but not encrypted.
 * \param additional_data_length        Size of the \p additional_data buffer in bytes.
 * \param[in] ciphertext                Buffer where the data that has been authenticated and encrypted.
 * \param ciphertext_length             Size of the \p ciphertext buffer in bytes.
 * \param[out] plaintext                Buffer where the decrypted data is to be written.
 * \param plaintext_size                Size of the \p plaintext buffer in bytes.
 * \param[out] plaintext_length         On success, the number of bytes that make up the plaintext.
 *
 * \return EDHOC_SUCCESS on success, otherwise failure.
 */
typedef int (*edhoc_decrypt_t)(const void *key_id, const uint8_t *nonce,
			       size_t nonce_length,
			       const uint8_t *additional_data,
			       size_t additional_data_length,
			       const uint8_t *ciphertext,
			       size_t ciphertext_length, uint8_t *plaintext,
			       size_t plaintext_size, size_t *plaintext_length);

/**
 * \brief Cryptographic function for hash computing.
 *
 * \param[in] input                     Input message to hash.
 * \param input_length                  Size of the \p input buffer in bytes.
 * \param[in] hash                      Buffer where the hash is to be written.
 * \param hash_size                     Size of the \p hash buffer in bytes.
 * \param[out] hash_length              On success, the number of bytes that make up the hash.
 *
 * \return EDHOC_SUCCESS on success, otherwise failure.
 */
typedef int (*edhoc_hash_t)(const uint8_t *input, size_t input_length,
			    uint8_t *hash, size_t hash_size,
			    size_t *hash_length);

/**
 * \brief Bind structure for cryptographics operations.
 */
struct edhoc_crypto {
	edhoc_make_key_pair_t make_key_pair;
	edhoc_key_agreement_t key_agreement;

	edhoc_signature_t signature;
	edhoc_verify_t verify;

	edhoc_extract_t extract;
	edhoc_expand_t expand;

	edhoc_encrypt_t encrypt;
	edhoc_decrypt_t decrypt;

	edhoc_hash_t hash;
};

/* Module interface variables and constants -------------------------------- */
/* Extern variables and constant declarations ------------------------------ */
/* Module interface function declarations ---------------------------------- */

#endif /* EDHOC_CRYPTO_H */
