#ifndef UNIT_H
#define UNIT_H

#include <ncurses.h>

enum dir {
    DIR_LEFT,
    DIR_RIGHT,
    DIR_UP,
    DIR_DOWN
};

struct unit {
    int x;
    int y;
    char c;
    int color;
    enum dir dir;
    int px;
    int py;
};

void unit_set_prev(struct unit *u, int px, int py);
void unit_set_dir(struct unit *u, int dir);
void unit_set_pos(struct unit *u, int x, int y);
void unit_follow_to_unit(struct unit *u1, struct unit *u2);
void unit_move(struct unit *u);
void unit_draw(struct unit *u);
void unit_refresh_dir(struct unit *u, int key);

#endif /* UNIT_H */
