#include "ui.h"
#include <stdio.h>

void print_vec_item(unsigned int *v, unsigned int i, unsigned int span_size) {
    printf("%*u", span_size, v[i]);
}

void print_item_separator(unsigned int span_size) {
    printf("%*c", span_size, SEPARATOR_CHAR);
}

void print_separator_line(unsigned int span_size, unsigned int span_item) {
    printf("%*c\n", span_size * (span_item + 1), SEPARATOR_CHAR);
}

void print_vec_color_1(unsigned int *v, unsigned int size,
                       unsigned int span_size, unsigned int separator_item,
                       unsigned int a) {
    print_separator_line(span_size, separator_item);

    for (unsigned int i = 0; i < size; ++i) {
        if (i == a)
            printf("%s", COLOR_C);

        print_vec_item(v, i, span_size);

        if (i == a)
            printf("%s", COLOR_RESET);

        if (i == separator_item - 1)
            print_item_separator(span_size);
    }

    printf("\n");
    print_separator_line(span_size, separator_item);
}

void print_vec_color_2(unsigned int *v, unsigned int size,
                       unsigned int span_size, unsigned int separator_item,
                       unsigned int a, unsigned int b) {
    print_separator_line(span_size, separator_item);

    for (unsigned int i = 0; i < size; ++i) {
        if (i == a)
            printf("%s", COLOR_A);
        else if (i == b)
            printf("%s", COLOR_B);

        print_vec_item(v, i, span_size);

        if (i == a || i == b)
            printf("%s", COLOR_RESET);

        if (i == separator_item - 1)
            print_item_separator(span_size);
    }

    printf("\n");
    print_separator_line(span_size, separator_item);
}
