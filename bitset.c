/**
 * @file    bitset.c
 * @brief   Řešení IJC-DU1, příklad A)
 *          Deklarace rozhraní pro práci s polem bitů
 * @author  Ondřej Hruboš (xhrubo01), FIT
 * @date    04.03.2023
 */

#include "bitset.h"

#ifdef USE_INLINE

void bitset_free(bitset_t* jmeno_pole);
bitset_index_t bitset_size(bitset_t* jmeno_pole);
void bitset_setbit(bitset_t* jmeno_pole, bitset_index_t index, bool vyraz);
bool bitset_getbit(bitset_t* jmeno_pole, bitset_index_t index);

#endif  // !USE_INLINE
