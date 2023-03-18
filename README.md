# Bitset
### C library for working with bitfields.

Static C library which allows you to store information in bitfields. Very effective if you need large data consisting of boolean values.
Tested with Eratosthenes sieve algorithm (230 000 000 numbers in 1.34 seconds ( Intel(R) Xeon(R) Silver 4214R CPU @ 2.40GHz ) with -O2 optimalizations toggled on).

## Build
Refer to Makefile.
Needs to be linked with error.c.

## Inline option
Compile with -DUSE_INLINE to use inline functions instead of macros.
