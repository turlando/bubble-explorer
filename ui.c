#include "ui.h"

#include <stdio.h>
#include "rtprintf.h"

/* Print a single item indexed by i in the vector v.
 * The printed string takes span_size characters and the text is padded
 * to the right.
 */
static void print_vec_item(unsigned int *v, unsigned int i,
                           unsigned int span_size) {
    printf("%*u", span_size, v[i]);
}

/* Print a single item indexed by i in the vector v.
 * The printed string takes span_size characters and the text is padded
 * to the right.
 * The text is printed with the specified style.
 */
static void rtprint_vec_item(unsigned int *v, unsigned int i,
                             unsigned int span_size, enum rt_style style) {
    rtprintf(style, "%*u", span_size, v[i]);
}

/* Print the separator character.
 * The printed string takes span_size characters and the separator is
 * padded to the right.
 */
static void print_item_separator(unsigned int span_size) {
    printf("%*c", span_size, SEPARATOR_CHAR);
}

/* Print an empty line containing the item separator only, placed between
 * the item indexed by span_item and the following one (if any).
 */
static void print_separator_line(unsigned int span_size,
                                 unsigned int span_item) {
    printf("%*c\n", span_size * (span_item + 1), SEPARATOR_CHAR);
}

/* Print the whole vector v specifying its size and the total span_size
 * space a single item will take.
 */
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

/* Print the whole vector v specifying its size and the total span_size
 * space a single item will take.
 * A separator is placed between the item indexed by separator_item and
 * the following one (if any).
 * The items indexed by a and b are printed using two different colors.
 * All the other items are printed using the default style.
 * A simple aside note is printed (max one line wide).
 */
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

/* Print the whole vector v specifying its size and the total span_size
 * space a single item will take.
 * A separator is placed between the item indexed by separator_item and
 * the following one (if any).
 * The items indexed by a and a + 1 are printed using the same color
 * which differs from all the other items, which are printed using the
 * default style.
 */
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
