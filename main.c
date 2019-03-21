#include <stdio.h>
#include "utils.h"
#include "ui.h"

#define VEC_SIZE 10
#define VAL_MAX  99
#define SPAN     8

void vec_init(unsigned int *v, unsigned int size) {
    for (unsigned int i = 0; i < size; ++i) {
        v[i] = rand_int(VAL_MAX);
    }
}

void bubble_sort(unsigned int *vec, unsigned int size) {
    for (unsigned int i = 0; i < size - 1; i++) {
        for (unsigned int j = 0; j < size - i - 1; j++) {
            if (vec[j] > vec[j+1]) {
                print_vec_color_2(vec, VEC_SIZE, SPAN, VEC_SIZE - i, j, j + 1);
                swap(vec + j, vec + j + 1);
                print_vec_color_2(vec, VEC_SIZE, SPAN, VEC_SIZE - i, j + 1, j);
            } else {
                print_vec_color_1(vec, VEC_SIZE, SPAN, VEC_SIZE - i, j);
            }
        }
    }
}

int main(void) {
    unsigned int vec[VEC_SIZE];
    vec_init(vec, VEC_SIZE);

    bubble_sort(vec, VEC_SIZE);

    return 0;
}
