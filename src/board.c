#include "board.h"

void
board_draw(void) {
	int i;

	for (i = BOARD_LEFT; i < (BOARD_RIGHT + 1); i++) {
		mvaddch(BOARD_TOP, i, BOARD_SYM);
		mvaddch(BOARD_BOTTOM, i, BOARD_SYM);
		refresh();
		usleep(10 * 1000);
	}

	for (i = BOARD_TOP; i < (BOARD_BOTTOM + 1); i++) {
		mvaddch(i, BOARD_LEFT, BOARD_SYM);
		mvaddch(i, BOARD_RIGHT, BOARD_SYM);
		refresh();
		usleep(10 * 1000);
	}
}
