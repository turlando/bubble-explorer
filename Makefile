NAME:= main

CFLAGS:= -std=c99 -pedantic -g -Wall -Wextra
LDFLAGS:=

SRC:= $(wildcard *.c)
OBJ:= $(SRC:.c=.o)
DEP:= $(OBJ:.o=.d)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) \
	    -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) \
	    -c \
	    -MMD -MF $(patsubst %.o, %.d, $@) \
	    -o $@ $<

-include $(DEP)

.PHONY: clean
clean:
	rm -f $(OBJ)
	rm -f $(DEP)

.PHONY: distclean
distclean: clean
	rm -f $(NAME)
