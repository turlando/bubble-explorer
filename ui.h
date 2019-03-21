#ifndef BUBBLE_UI
#define BUBBLE_UI

#define SEPARATOR_CHAR '|'

#define COLOR_RESET "\033[0m"
#define COLOR_A     "\033[31;1m"
#define COLOR_B     "\033[36;1m"
#define COLOR_C     "\033[32;1m"

void print_vec_item(unsigned int *, unsigned int, unsigned int);
void print_item_separator(unsigned int);
void print_separator_line(unsigned int, unsigned int);
void print_vec_color_1(unsigned int *, unsigned int,
                       unsigned int, unsigned int,
                       unsigned int);

void print_vec_color_2(unsigned int *, unsigned int,
                       unsigned int, unsigned int,
                       unsigned int, unsigned int);

#endif /* BUBBLE_UI */
