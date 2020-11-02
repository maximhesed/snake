#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <ncurses.h>

#include "board.h"
#include "event.h"
#include "snake.h"

int main(void)
{
    SCREEN *scr = newterm(NULL, stdout, stdin);
    struct snake *s;
    struct food *f;
    int key;

    if (has_colors()) {
        start_color();

        init_pair(1, COLOR_BLACK, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        init_pair(4, COLOR_YELLOW, COLOR_BLACK);
        init_pair(5, COLOR_BLUE, COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_CYAN, COLOR_BLACK);
        init_pair(8, COLOR_WHITE, COLOR_BLACK);
    }
    else {
        printf("The your terminal isn't supports the colors.\n");

        getch();
    }

    noecho();
    curs_set(0);
    nodelay(stdscr, true);
    keypad(stdscr, true);
    intrflush(stdscr, true);

    board_draw();

    s = snake_init();
    f = food_init();

    food_gen(f, s);

    while (1) {
        key = getch();

        move(BOARD_TOP, BOARD_RIGHT + 2);
        printw("length = %d", s->len - 1);
        move(BOARD_TOP + 1, BOARD_RIGHT + 2);
        printw("score = %d", s->score);

        food_draw(f);

        snake_refresh_dir(s, key);
        snake_refresh_head(s);

        if (snake_check_collide_board(s) ||
            snake_check_collide_self(s)) {
            event_lose();

            break;
        }

        snake_erase_tail_end(s);
        snake_move(s);
        snake_draw(s);
        snake_check_collide_food(s, f);

        if (snake_check_max_length(s)) {
            event_win();

            break;
        }

        if (event_check_exit(key))
            break;

        usleep(500000 / SNAKE_SPEED);
    }

    endwin();
    delscreen(scr);

    free(s->u);
    free(s);
    free(f);

    return 0;
}
