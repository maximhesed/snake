#include "food.h"

static const char food_sym[] = {
	'$',
	'*',
	'%',
	'&'
};

static const int food_color[] = {
	2,
	3,
	4,
	5,
	6,
	7
};

static const int food_score[] = {
	5,
	10,
	25,
	100,
	250,
	500,
	1000
};

struct food *
food_init(void) {
	struct food *f = NULL;

	f = calloc(1, sizeof(struct food));

	return f;
}

void
food_gen(struct food *f) {
	srand(time(NULL));

	/* TODO: make food generation algorithm */

	f->sym = food_sym[rand() % 3];
	f->color = food_color[rand() % 5];
	f->score = food_score[rand() % 6];
}

void
food_draw(struct food *f) {
	attron(COLOR_PAIR(f->color));
	mvaddch(f->y, f->x, f->sym);
	attroff(COLOR_PAIR(f->color));
}
