#ifndef EVENT_H
#define EVENT_H

#include <stdbool.h>
#include <ncurses.h>

#define KEY_ESC 27

bool event_check_exit(int key);
void event_lose();
void event_win();

#endif /* EVENT_H */
