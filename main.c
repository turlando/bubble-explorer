#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "utils.h"
#include "ui.h"

#define VEC_SIZE 10
#define VAL_MAX  99
#define SPAN     8
#define DELAY    2

void bubble_sort(unsigned int *vec, unsigned int size) {
    for (unsigned int i = 0; i < size - 1; i++) {
        for (unsigned int j = 0; j < size - i - 1; j++) {
            if (vec[j] > vec[j+1]) {
                print_vec_swap(vec, VEC_SIZE,
                               SPAN, VEC_SIZE - i,
                               j, j + 1,
                               "Swap!");
                swap(vec + j, vec + j + 1);
                print_vec_swap(vec, VEC_SIZE,
                               SPAN, VEC_SIZE - i,
                               j + 1, j,
                               NULL);
            } else {
                print_vec_noswap(vec, VEC_SIZE,
                                 SPAN, VEC_SIZE - i,
                                 j);
            }
            sleep(DELAY);
        }
    }
}

int main(void) {
    srand(time(NULL));

    unsigned int vec[VEC_SIZE];
    vec_init(vec, VEC_SIZE, VAL_MAX);

    print_vec_boxed(vec, VEC_SIZE, SPAN);
    bubble_sort(vec, VEC_SIZE);
    print_vec_boxed(vec, VEC_SIZE, SPAN);

    return 0;
}
