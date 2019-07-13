#include "board.h"

void
board_draw(void) {
	int i;

	attron(COLOR_PAIR(BOARD_COLOR));

	/* top and bottom boards */
	for (i = BOARD_LEFT; i < (BOARD_RIGHT + 1); i++) {
		mvaddch(BOARD_TOP, i, BOARD_SYM);
		mvaddch(BOARD_BOTTOM, i, BOARD_SYM);
		refresh();
		usleep(10000);
	}

	/* left and right boards */
	for (i = BOARD_TOP; i < (BOARD_BOTTOM + 1); i++) {
		mvaddch(i, BOARD_LEFT, BOARD_SYM);
		mvaddch(i, BOARD_RIGHT, BOARD_SYM);
		refresh();
		usleep(10000);
	}

	attroff(COLOR_PAIR(BOARD_COLOR));
}
