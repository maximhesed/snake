#ifndef BOARD_H
#define BOARD_H

#include <unistd.h>
#include <ncurses.h>

#define BOARD_LEFT 0
#define BOARD_RIGHT 44
#define BOARD_TOP 0
#define BOARD_BOTTOM 20
#define BOARD_SYM '@'

void board_draw(void);

#endif /* BOARD_H */
