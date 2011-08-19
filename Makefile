# Makefile for lines
    CC     = gcc
    CFLAGS = $(shell pkg-config --cflags gtk+-2.0) -g -Wall
    LIBS   = $(shell pkg-config --libs gtk+-2.0)
    SRC    = lines.c rules.c child.c handlers.c menu.c hiscore.c
    HDR    = $(SRC:.c=.h)
    OBJS   = $(SRC:.c=.o)

all: tags msg lines

lines: $(OBJS)
	$(CC) $(LIBS) $(OBJS) -g -o lines

.c.o: $*.c $(HDR)
#	$(CC) $(CFLAGS) -c $*.c

$(SRC): $(HDR)

clean:
	rm -f *.o lines *~ core

tags: TAGS
TAGS: $(SRC) $(HDR)
	etags $(SRC) $(HDR)

msg: lt.po
	msgfmt lt.po -o lt/LC_MESSAGES/lines.mo
