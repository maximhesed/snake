#include "event.h"

bool
event_check_exit(int key) {
	if (key == KEY_ESC) {
		if (getch() == -1)
			return true;
	}

	return false;
}

void
event_lose(void) {

}

void
event_win(void) {

}
