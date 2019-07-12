#include "event.h"

bool
event_check_exit(int key) {
	if (key == 27) {
		if (getch() == -1)
			return true;
	}

	return false;
}

void
event_win(void) {

}
