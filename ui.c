#include "ui.h"

#include <stdio.h>
#include "rtprintf.h"

static void print_vec_item(unsigned int *v, unsigned int i,
                           unsigned int span_size) {
    printf("%*u", span_size, v[i]);
}

static void rtprint_vec_item(unsigned int *v, unsigned int i,
                             unsigned int span_size, enum rt_style style) {
    rtprintf(style, "%*u", span_size, v[i]);
}

static void print_item_separator(unsigned int span_size) {
    printf("%*c", span_size, SEPARATOR_CHAR);
}

static void print_separator_line(unsigned int span_size,
                                 unsigned int span_item) {
    printf("%*c\n", span_size * (span_item + 1), SEPARATOR_CHAR);
}

void print_vec_boxed(unsigned int *v, unsigned int size,
               unsigned int span_size) {
    for (unsigned int i = 0; i < size * (span_size + 1); ++i)
        putchar('-');
    putchar('\n');

    for (unsigned int i = 0; i < size; ++i) {
        print_vec_item(v, i, span_size);
    }

    putchar('\n');

    for (unsigned int i = 0; i < size * (span_size + 1); ++i)
        putchar('-');
    putchar('\n');
}

void print_vec_swap(unsigned int *v, unsigned int size,
                    unsigned int span_size, unsigned int separator_item,
                    unsigned int a, unsigned int b,
                    const char *notes) {
    print_separator_line(span_size, separator_item);

    for (unsigned int i = 0; i < size; ++i) {
        if (i == a)
            rtprint_vec_item(v, i, span_size, RED);
        else if (i == b)
            rtprint_vec_item(v, i, span_size, CYAN);
        else
            print_vec_item(v, i, span_size);

        if (i == separator_item - 1)
            print_item_separator(span_size);
    }

    if (notes != NULL)
        printf("%*s\n", 2 * span_size, notes);
    else
        putchar('\n');

    print_separator_line(span_size, separator_item);
}

void print_vec_noswap(unsigned int *v, unsigned int size,
                      unsigned int span_size, unsigned int separator_item,
                      unsigned int a) {
    print_separator_line(span_size, separator_item);

    for (unsigned int i = 0; i < size; ++i) {
        if (i == a || i == a + 1)
            rtprint_vec_item(v, i, span_size, GREEN);
        else
            print_vec_item(v, i, span_size);

        if (i == separator_item - 1)
            print_item_separator(span_size);
    }

    putchar('\n');
    print_separator_line(span_size, separator_item);
}
