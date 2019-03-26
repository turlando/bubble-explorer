#include "utils.h"

#include <stdlib.h>

unsigned int rand_int(unsigned int max) {
    return rand() % (max + 1);
}

void swap(unsigned int *a, unsigned int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void vec_init(unsigned int *v, unsigned int size, unsigned int max) {
    for (unsigned int i = 0; i < size; ++i) {
        v[i] = rand_int(max);
    }
}
