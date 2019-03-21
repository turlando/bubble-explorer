#ifndef BUBBLE_UI
#define BUBBLE_UI

#define SEPARATOR_CHAR '|'

void print_vec_item(unsigned int *, unsigned int, unsigned int);
void print_item_separator(unsigned int);
void print_separator_line(unsigned int, unsigned int);
void print_vec_noswap(unsigned int *, unsigned int,
                      unsigned int, unsigned int,
                      unsigned int);

void print_vec_swap(unsigned int *, unsigned int,
                    unsigned int, unsigned int,
                    unsigned int, unsigned int,
                    const char *);

#endif /* BUBBLE_UI */
