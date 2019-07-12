#ifndef FOOD_H
#define FOOD_H

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ncurses.h>

#include "board.h"

struct food {
	int x;
	int y;
	char sym;
	int color;
	int score;
};

struct food * food_init(void);
void food_gen(struct food *f);
void food_draw(struct food *f);

#endif /* FOOD_H */
