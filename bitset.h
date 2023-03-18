/**
 * @file    bitset.h
 * @brief   Řešení IJC-DU1, příklad A)
 *          Definice rozhraní pro práci s polem bitů
 * @author  Ondřej Hruboš (xhrubo01), FIT
 * @date    04.03.2023
 */

#ifndef BITSET_H
#define BITSET_H

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "error.h"

typedef unsigned long bitset_t;
typedef unsigned long bitset_index_t;
#define bitset_t_max ULONG_MAX
#define bit_size(size) ((bitset_t)size > (sizeof(bitset_index_t) * CHAR_BIT)) ? (((bitset_t)size / (sizeof(bitset_index_t) * CHAR_BIT)) + 1) : (((bitset_t)size / (sizeof(bitset_index_t) * CHAR_BIT)) + 2)

#define bitset_create(jmeno_pole, velikost)                                                           \
    static_assert(velikost > 0UL, __FILE__ ": Velikost pole musí být alespoň 1");                     \
    static_assert(velikost < bitset_t_max, __FILE__ ": Velikost pole nesmí být větší než ULONG_MAX"); \
    bitset_t jmeno_pole[bit_size(velikost)] = {0};                                                    \
    jmeno_pole[0] = (bitset_t)velikost

/**
 * Dynamicky alokované pole unsigned long
 */
#define bitset_alloc(jmeno_pole, velikost)                                                \
    assert((velikost > 0UL) && ": Velikost pole musí být alespoň 1");                     \
    assert((velikost < bitset_t_max) && ": Velikost pole nesmí být větší než ULONG_MAX"); \
    bitset_t* jmeno_pole = calloc(bit_size(velikost), sizeof(bitset_index_t) * CHAR_BIT); \
    if (jmeno_pole == NULL) {                                                             \
        error_exit(std_err_str, "Chyba alokace paměti");                                  \
    }                                                                                     \
    jmeno_pole[0] = (bitset_t)velikost

#ifndef USE_INLINE

// MAKRA
#define bitset_free(jmeno_pole) \
    free(jmeno_pole)

/**
 * Počet bitů v poli jmeno_pole (implicitně uložená informace na nultém indexu pole)
 */
#define bitset_size(jmeno_pole) jmeno_pole[0]

/**
 * Nastavení bitu na indexu index podle logické hodnoty výrazu vyraz
 */
#define bitset_setbit(jmeno_pole, index, vyraz)                                                                                                                         \
    if ((bitset_index_t)index >= jmeno_pole[0]) {                                                                                                                       \
        error_exit(std_err_str, "Přístup k indexu mimo pole");                                                                                                          \
    }                                                                                                                                                                   \
    do {                                                                                                                                                                \
        if (vyraz) {                                                                                                                                                    \
            jmeno_pole[((bitset_index_t)index / (sizeof(bitset_index_t) * CHAR_BIT)) + 1UL] |= (1UL << ((bitset_index_t)index % (sizeof(bitset_index_t) * CHAR_BIT)));  \
        } else {                                                                                                                                                        \
            jmeno_pole[((bitset_index_t)index / (sizeof(bitset_index_t) * CHAR_BIT)) + 1UL] &= ~(1UL << ((bitset_index_t)index % (sizeof(bitset_index_t) * CHAR_BIT))); \
        }                                                                                                                                                               \
    } while (0)

#define bitset_getbit(jmeno_pole, index) \
    ((bitset_index_t) index >= jmeno_pole[0] ? (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)jmeno_pole[0] - 1UL), 42) : ((jmeno_pole)[((bitset_index_t)(index) / (sizeof(bitset_index_t) * CHAR_BIT)) + 1UL] & (1UL << ((bitset_index_t)index % (sizeof(bitset_index_t) * CHAR_BIT))) ? true : false))

#else

// INLINE
inline void bitset_free(bitset_t* jmeno_pole) {
    free(jmeno_pole);
}

inline bitset_index_t bitset_size(bitset_t* jmeno_pole) {
    return jmeno_pole[0];
}

inline void bitset_setbit(bitset_t* jmeno_pole, bitset_index_t index, bool vyraz) {
    if (index >= jmeno_pole[0]) {
        error_exit(std_err_str, "Přístup k indexu mimo pole");
    }

    if (vyraz) {
        jmeno_pole[(index / (sizeof(bitset_index_t) * CHAR_BIT)) + 1UL] |= (1UL << (index % (sizeof(bitset_index_t) * CHAR_BIT)));
    } else {
        jmeno_pole[(index / (sizeof(bitset_index_t) * CHAR_BIT)) + 1UL] &= ~(1UL << (index % (sizeof(bitset_index_t) * CHAR_BIT)));
    }
}

inline bool bitset_getbit(bitset_t* jmeno_pole, bitset_index_t index) {
    if ((bitset_index_t)index >= jmeno_pole[0]) {
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)jmeno_pole[0] - 1);
    } else {
        return (jmeno_pole[(index / (sizeof(bitset_index_t) * CHAR_BIT)) + 1UL] & (1UL << (index % (sizeof(bitset_index_t) * CHAR_BIT)))) ? true : false;
    }
    return 42;
}

#endif

#endif  // !BITSET_H
