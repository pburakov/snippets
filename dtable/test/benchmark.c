#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../dtable.h"

int main() {
    dtable_char *test_t = table_init(0);

    printf("Beginning test in 2 seconds\n");
    sleep(2);

    printf("Bloating table to 4GB...\n");
    for (unsigned long i = 0; i < 4294967296; i++)
        table_append(test_t, (char) ('A' + (random() % 26)));

    printf("Done. Waiting 2 seconds\n");
    sleep(2);

    printf("Shrinking...\n");
    for (unsigned long i = 0; i < 4294967296; i++)
        table_pop(test_t);

    printf("Shrinking done. Waiting 2 seconds\n");
    sleep(2);

    table_free(test_t);

    printf("Memory freed.\n");
}
