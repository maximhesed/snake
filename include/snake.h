#ifndef SNAKE_H
#define SNAKE_H

#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

#include "unit.h"
#include "food.h"

#define SNAKE_MAX_LENGTH 100
#define SNAKE_START_POS_X 10
#define SNAKE_START_POS_Y 6
#define SNAKE_START_LENGTH 2
#define SNAKE_TAIL_SYM '+'
#define SNAKE_SPEED 10

extern struct food food;

struct snake {
	struct unit *u;
	int len;
	int score;
};

struct snake * snake_init(void);
void snake_refresh_dir(struct snake *s, int key);
void snake_refresh_head(struct snake *s);
void snake_draw(struct snake *s);
void snake_move(struct snake *s);
void snake_erase_tail_end(struct snake *s);
bool snake_check_collide_self(struct snake *s);
bool snake_check_collide_board(struct snake *s);
void snake_check_collide_food(struct snake *s, struct food *f);
bool snake_check_max_length(struct snake *s);

#endif /* SNAKE_H */
