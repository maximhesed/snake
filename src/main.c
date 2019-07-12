#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <ncurses.h>

#include "board.h"
#include "event.h"
#include "snake.h"

int
main(void) {
	initscr();

	if (!has_colors()) {
		printf("Sorry, but your terminal don't support colors!\n");
		return -1;
	}

	start_color();
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);

	noecho();
	curs_set(0);
	nodelay(stdscr, true);
	keypad(stdscr, true);

	board_draw();

	/* snake init */
	struct snake *s = NULL;
	s = snake_init();

	/* food init */
	struct food *f = NULL;
	f = food_init();
	food_gen(f);

	int key;

	while (1) {
		key = getch();

		move(BOARD_TOP, BOARD_RIGHT + 2);
		printw("length = %d", s->len - 2);

		food_draw(f);

		snake_refresh_dir(s, key);
		snake_refresh_head(s);
		snake_move(s);
		snake_draw(s);
		snake_erase_tail_end(s);
		snake_check_collide_food(s, f);

		if (snake_check_length(s)) {
			event_win();
			break;
		}

		if (event_check_exit(key))
			break;

		usleep(50 * 1000);
	}

	echo();
	curs_set(2);
	nodelay(stdscr, false);
	keypad(stdscr, false);
	endwin();

	free(f);
	free(s);

	return 0;
}
