CFLAGS = -std=c11 -pedantic -Wall -Wextra -g -O2
INLINE = -DUSE_INLINE

CC = gcc

all: error.o bitset.o bitset-i.o

bitset.o: bitset.c bitset.h
	$(CC) bitset.c $(CFLAGS) -c -o bitset.o 

bitset-i.o: bitset.c bitset.h
	$(CC) bitset.c $(CFLAGS) $(INLINE) -c -o bitset-i.o  

error.o: error.c error.h
	$(CC) error.c $(CFLAGS) -c -o error.o