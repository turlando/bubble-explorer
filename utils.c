#include "utils.h"

#include <stdlib.h>

/* Return a natural number between zero and max.
 */
unsigned int rand_int(unsigned int max) {
    return rand() % (max + 1);
}

/* Swap the content of two unsigned integers.
 */
void swap(unsigned int *a, unsigned int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Replace the content of each item in the vector v with a random
 * natural number between zero and max.
 */
void vec_init(unsigned int *v, unsigned int size, unsigned int max) {
    for (unsigned int i = 0; i < size; ++i) {
        v[i] = rand_int(max);
    }
}

/* Copy src vector to dst.
 */
void vec_dup(unsigned int *dst, unsigned int *src, unsigned int size) {
    for (unsigned int i = 0; i < size; ++i) {
        dst[i] = src[i];
    }
}
