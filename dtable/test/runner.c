#include <assert.h>
#include "../dtable.h"

int main() {
    dtable_char *test_t = table_init(0);
    assert(0 == test_t -> size);

    table_append(test_t, 'a');
    assert(1 == test_t -> size); // expansion
    table_append(test_t, 'b');
    assert(2 == test_t -> size); // expansion
    table_append(test_t, 'c');
    assert(4 == test_t -> size); // expansion
    table_append(test_t, 'd');
    table_append(test_t, 'e');
    assert(8 == test_t -> size); // expansion

    assert('c' == table_get(test_t, 2));
    assert('e' == table_get(test_t, 4));

    assert('e' == table_pop(test_t));
    assert(8 == test_t -> size); // contraction
    assert('d' == table_pop(test_t));
    assert('c' == table_pop(test_t));
    assert(4 == test_t -> size); // contraction
    assert('b' == table_pop(test_t));
    assert(2 == test_t -> size); // contraction
    assert('a' == table_pop(test_t));
    assert(1 == test_t -> size); // contraction

    table_free(test_t);
    assert(0 == test_t -> size);
}
