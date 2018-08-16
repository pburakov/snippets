#include <stdio.h>
#include <stdlib.h>
#include "dtable.h"

dtable_char *table_init(size_t initial_size) {
    dtable_char *t = malloc(sizeof(dtable_char));
    t->table = malloc(initial_size * sizeof(char));
    t->size = initial_size;
    t->p = 0;
    return t;
}

void table_free(dtable_char *t) {
    free(t->table);
    t->table = NULL;
    t->size = 0;
    t->p = 0;
    free(t);
    t = NULL;
}

void table_append(dtable_char *t, char x) {
    if (t->size == 0) {
        t->table = malloc(1 * sizeof(char));
        t->size = 1;
    }
    if (t->size == t->p) {
        t->size = EXP_MULTI * t->size;
        t->table = realloc(t->table, t->size * sizeof(char));
    }
    t->table[t->p++] = x;
}

char table_pop(dtable_char *t) {
    if (t->p < 1) error("Table underflow");
    char x = t->table[t->p - 1];
    t->p--;
    table_contract(t);
    return x;
}

char table_get(dtable_char *t, size_t i) {
    if (i >= t->p) error("No element with index %d", (int) i);
    return t->table[i];
}

void table_contract(dtable_char *t) {
    if (t->p <= t->size * L_FACTOR) {
        t->size = t->size / EXP_MULTI;
        t->table = realloc(t->table, t->size * sizeof(char));
    }
}
