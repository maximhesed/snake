#include "unit.h"

void
unit_set_prev(struct unit *u, int px, int py)
{
    u->px = px;
    u->py = py;
}

void
unit_set_dir(struct unit *u, int dir)
{
    u->dir = dir;
}

void
unit_set_pos(struct unit *u, int x, int y)
{
    u->x = x;
    u->y = y;
}

void
unit_follow_to_unit(struct unit *u1, struct unit *u2)
{
    if (u2->dir == DIR_LEFT) {
        u1->x = u2->x + 1;
        u1->y = u2->y;
    }

    if (u2->dir == DIR_RIGHT) {
        u1->x = u2->x - 1;
        u1->y = u2->y;
    }

    if (u2->dir == DIR_UP) {
        u1->x = u2->x;
        u1->y = u2->y + 1;
    }

    if (u2->dir == DIR_DOWN) {
        u1->x = u2->x;
        u1->y = u2->y - 1;
    }
}

void
unit_move(struct unit *u)
{
    if (u->dir == DIR_LEFT)
        u->x--;

    if (u->dir == DIR_RIGHT)
        u->x++;

    if (u->dir == DIR_UP)
        u->y--;

    if (u->dir == DIR_DOWN)
        u->y++;
}

void
unit_draw(struct unit *u)
{
    attron(COLOR_PAIR(u->color));
    mvaddch(u->y, u->x, u->c);
    attroff(COLOR_PAIR(u->color));
}

void
unit_refresh_dir(struct unit *u, int key)
{
    if (key == KEY_LEFT && u->py != u->y)
        u->dir = DIR_LEFT;

    if (key == KEY_RIGHT && u->py != u->y)
        u->dir = DIR_RIGHT;

    if (key == KEY_UP && u->px != u->x)
        u->dir = DIR_UP;

    if (key == KEY_DOWN && u->px != u->x)
        u->dir = DIR_DOWN;
}
