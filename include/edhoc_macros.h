/**
 * \file    edhoc_macros.h
 * \author  Kamil Kielbasa
 * \brief   EDHOC macros and functionlike macros.
 * \version 0.4
 * \date    2024-01-01
 * 
 * \copyright Copyright (c) 2024
 * 
 */

/* Header guard ------------------------------------------------------------ */
#ifndef EDHOC_MACROS_H
#define EDHOC_MACROS_H

/* Include files ----------------------------------------------------------- */
/* Defines ----------------------------------------------------------------- */
/* Types and type definitions ---------------------------------------------- */

#if defined(_WIN32) || defined(_MSC_VER)
    #include <malloc.h>
    #define ALLOCATE_ARRAY(type, name, size) \
        type *name = (type*)_alloca(size * sizeof(type)); \
        size_t name##_size = size * sizeof(type)
    #define ALLOCATE_ARRAY_SIZEOF(name) name##_size
#else
    #define ALLOCATE_ARRAY(type, name, size) \
        type name[size]
    #define ALLOCATE_ARRAY_SIZEOF(name) sizeof(name)
#endif

/**
 * \brief Macro for calculating arrays length.
 */
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#define ARRAY_SIZE_VLA(x) (ALLOCATE_ARRAY_SIZEOF(x) / sizeof(x[0]))

/**
 * \brief Macro which allows for private access into structure members.
 */
#ifndef EDHOC_ALLOW_PRIVATE_ACCESS
#define EDHOC_PRIVATE(member) private_##member
#else
#define EDHOC_PRIVATE(member) member
#endif

/* Module interface variables and constants -------------------------------- */
/* Extern variables and constant declarations ------------------------------ */
/* Module interface function declarations ---------------------------------- */

#endif /* EDHOC_MACROS_H */
