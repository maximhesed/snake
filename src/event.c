#include "event.h"

bool
event_check_exit(int key)
{
    return key == KEY_ESC && getch() == -1;
}

void
event_lose(void)
{

}

void
event_win(void)
{

}
