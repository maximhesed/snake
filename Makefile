CC=gcc

CFLAGS=-Wall -Iinclude
LDFLAGS=-g -lncurses

SRCDIR=src
OBJDIR=obj
BINDIR=bin

SRCS=$(addprefix $(SRCDIR)/,%.c)
OBJS=$(addprefix $(OBJDIR)/,main.o snake.o unit.o food.o event.o board.o)
DEPS=

PROGNAME=snake

$(OBJDIR)/%.o: $(SRCS) $(DEPS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJS) | $(BINDIR)
	$(CC) -o $(BINDIR)/$(PROGNAME) $^ $(LDFLAGS)

$(OBJDIR):
	mkdir $(OBJDIR)

$(BINDIR):
	mkdir $(BINDIR)

.PHONY: clean
clean:
	rm -rf $(BINDIR) $(OBJDIR)
