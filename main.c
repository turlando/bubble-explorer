#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "utils.h"
#include "ui.h"

#define VEC_SIZE 10
#define VAL_MAX  99
#define SPAN     8
#define DELAY    2

void bubble_sort(unsigned int *vec, unsigned int size,
                 unsigned int span) {
    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = 0; j < size - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                print_vec_swap(vec, size,
                               span, size - i,
                               j, j + 1,
                               "Swap!");
                swap(vec + j, vec + j + 1);
                print_vec_swap(vec, size,
                               span, size - i,
                               j + 1, j,
                               NULL);
            } else {
                print_vec_noswap(vec, size,
                                 span, size - i,
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

    printf("Randomly picked array of %u positive integers:\n", VEC_SIZE);
    print_vec_boxed(vec, VEC_SIZE, SPAN);
    putchar('\n');

    printf("Sorting will start in a few...\n");
    sleep(DELAY);

    bubble_sort(vec, VEC_SIZE, SPAN);
    print_vec_boxed(vec, VEC_SIZE, SPAN);

    return 0;
}
