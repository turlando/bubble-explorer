#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "utils.h"
#include "ui.h"

#define VEC_SIZE 10U
#define VAL_MAX  99U
#define SPAN     8U
#define DELAY    2U

void bubble_sort(unsigned int *, unsigned int,
                 unsigned int);

int main(void) {
    unsigned int vec_unsorted[VEC_SIZE];
    unsigned int vec_sorted[VEC_SIZE];

    srand(time(NULL));

    vec_init(vec_unsorted, VEC_SIZE, VAL_MAX);
    vec_dup(vec_sorted, vec_unsorted, VEC_SIZE);

    printf("Randomly picked array of %u positive integers:\n", VEC_SIZE);
    print_vec_boxed(vec_unsorted, VEC_SIZE, SPAN);
    putchar('\n');

    printf("Sorting will start in a few...\n");
    sleep(DELAY);

    bubble_sort(vec_sorted, VEC_SIZE, SPAN);

    putchar('\n');

    printf("Before:\n");
    print_vec_boxed(vec_unsorted, VEC_SIZE, SPAN);
    putchar('\n');

    printf("After:\n");
    print_vec_boxed(vec_sorted, VEC_SIZE, SPAN);

    return 0;
}

void bubble_sort(unsigned int *vec, unsigned int size,
                 unsigned int span) {
    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = 0; j < size - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                print_vec_swap(vec, size,
                               span, size - 1 - i,
                               j, j + 1,
                               "Swap!");
                swap(vec + j, vec + j + 1);
                print_vec_swap(vec, size,
                               span, size - 1 - i,
                               j + 1, j,
                               NULL);
            } else {
                print_vec_noswap(vec, size,
                                 span, size - 1 - i,
                                 j);
            }
            sleep(DELAY);
        }
    }
}
