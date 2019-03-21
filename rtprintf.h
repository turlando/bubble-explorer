#ifndef BUBBLE_RTPRINTF
#define BUBBLE_RTPRINTF

#define ANSI_RESET  "\033[0m"

#define ANSI_FG_BLACK   "\033[30;1m"
#define ANSI_FG_RED     "\033[31;1m"
#define ANSI_FG_GREEN   "\033[32;1m"
#define ANSI_FG_YELLOW  "\033[33;1m"
#define ANSI_FG_BLUE    "\033[34;1m"
#define ANSI_FG_MAGENTA "\033[35;1m"
#define ANSI_FG_CYAN    "\033[36;1m"
#define ANSI_FG_WHITE   "\033[37;1m"

enum rt_style {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};


int rtprintf(enum rt_style style, const char *fmt, ...);

#endif /* BUBBLE_RTPRINTF */
