#include "rtprintf.h"

#include <stdarg.h>
#include <stdio.h>

/* Rich Text printf
 * Same as printf, but allows styled output through the style parameter.
 */
int rtprintf(enum rt_style style, const char *fmt, ...) {
    int ret = 0;

    va_list argp;
    va_start(argp, fmt);

    switch (style) {
        case BLACK:
            ret = printf(ANSI_FG_BLACK);
            break;
        case RED:
            ret = printf(ANSI_FG_RED);
            break;
        case GREEN:
            ret = printf(ANSI_FG_GREEN);
            break;
        case YELLOW:
            ret = printf(ANSI_FG_YELLOW);
            break;
        case BLUE:
            ret = printf(ANSI_FG_BLUE);
            break;
        case MAGENTA:
            ret = printf(ANSI_FG_MAGENTA);
            break;
        case CYAN:
            ret = printf(ANSI_FG_CYAN);
            break;
        case WHITE:
            ret = printf(ANSI_FG_WHITE);
            break;
    }

    ret += vprintf(fmt, argp);
    va_end(argp);

    ret =+ printf("\033[0m");

    return ret;
}
