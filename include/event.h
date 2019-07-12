#ifndef EVENT_H
#define EVENT_H

#include <stdbool.h>
#include <ncurses.h>

bool event_check_exit(int key);
void event_win();

#endif /* EVENT_H */
