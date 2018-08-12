#ifndef DYN_TABLE_LIBRARY_H
#define DYN_TABLE_LIBRARY_H

#include <sys/types.h>

#define EXP_MULTI 2 // expansion / contraction multiplier
#define L_FACTOR 1/4 // load factor

#define error(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); exit(1); }

typedef struct {
    size_t p; // boundary index, i.e. where the next element will be put
    size_t size;
    char *table;
} dtable_char;

dtable_char *table_init(size_t initial_size);

void table_free(dtable_char *t);

void table_append(dtable_char *t, char x);

char table_pop(dtable_char *t);

char table_get(dtable_char *t, size_t i);

void table_contract(dtable_char *t);

#endif