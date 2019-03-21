#include "utils.h"

unsigned int rand_int(unsigned int max) {
    return rand() % (max + 1);
}

void swap(unsigned int *a, unsigned int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
