#include "snake.h"

struct snake *
snake_init(void) {
	struct snake *s = NULL;
	s = calloc(1, sizeof(struct snake));

	s->u = calloc(SNAKE_MAX_LENGTH, sizeof(struct unit));

	/* head */
	s->u[0].x = SNAKE_START_POS_X;
	s->u[0].y = SNAKE_START_POS_Y;
	s->u[0].color = 3;
	s->u[0].dir = DIR_RIGHT;
	s->u[0].px = s->u[0].x;
	s->u[0].py = s->u[0].y;

	/* tail */
	int i;

	for (i = 0 + 1; i < SNAKE_MAX_LENGTH; i++) {
		s->u[i].x = SNAKE_START_POS_X - 1;
		s->u[i].y = SNAKE_START_POS_Y;
		s->u[i].sym = SNAKE_TAIL_SYM;
		s->u[i].color = 8;
	}

	s->len = SNAKE_START_LENGTH + 2;
	s->score = 0;

	return s;
}

void
snake_refresh_dir(struct snake *s, int key) {
	int i;

	for (i = 0; i < s->len; i++)
		unit_refresh_dir(&s->u[i], key);
}

void
snake_refresh_head(struct snake *s) {
	if (s->u[0].dir == DIR_LEFT)
		s->u[0].sym = '<';

	if (s->u[0].dir == DIR_RIGHT)
		s->u[0].sym = '>';

	if (s->u[0].dir == DIR_UP)
		s->u[0].sym = '^';

	if (s->u[0].dir == DIR_DOWN)
		s->u[0].sym = 'v';
}

void
snake_draw(struct snake *s) {
	int i;

	for (i = 0; i < s->len; i++)
		unit_draw(&s->u[i]);
}

void
snake_move(struct snake *s) {
	int i;

	for (i = 0; i < s->len; i++)
		unit_set_prev(&s->u[i], s->u[i].x, s->u[i].y);

	unit_move(&s->u[0]);

	for (i = 0; i < (s->len - 1); i++) {
		unit_follow_to_unit(&s->u[i + 1], &s->u[i]);
		unit_set_pos(&s->u[i + 1], s->u[i].px, s->u[i].py);
		unit_set_dir(&s->u[i + 1], s->u[i].dir);
	}
}

void
snake_erase_tail_end(struct snake *s) {
	mvaddch(s->u[s->len - 1].y, s->u[s->len - 1].x, ' ');
}

void
snake_check_collide_self(struct snake *s) {

}

void
snake_check_collide_board(struct snake *s) {

}

void
snake_check_collide_food(struct snake *s, struct food *f) {
	if ((s->u[0].x == f->x) &&
		(s->u[0].y == f->y)) {
		s->len++;
		s->score += f->score;

		food_gen(f);
	}
}

bool
snake_check_length(struct snake *s) {
	if (s->len == SNAKE_MAX_LENGTH)
		return true;

	return false;
}
