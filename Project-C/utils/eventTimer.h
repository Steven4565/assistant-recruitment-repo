#ifndef EVENT_TIMER_H
#define EVENT_TIMER_H

#include <time.h>
#include <stdbool.h>
#include "../globals.h"

void setTimerInterval(Timer *timer)
{
	if (!timer->on)
		return;
	timer->msec = (clock() - timer->before) * 1000 / CLOCKS_PER_SEC;
}

void runEvent(Timer *timer, void (*fn)())
{
	if (timer->msec >= timer->delay)
	{
		timer->before = clock();
		fn();
	}
}

void setEventFlag(Timer *timer, bool *onEventEmitted)
{
	if (timer->on && timer->msec >= timer->delay)
	{
		timer->before = clock();
		*onEventEmitted = true;
	}
}

#endif