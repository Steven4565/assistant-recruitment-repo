#ifndef EVENT_TIMER_H
#define EVENT_TIMER_H

#include <time.h>
#include <stdbool.h>

typedef struct Timer
{
	clock_t before;
	int delay;
	int msec;
} Timer;

void getTimerInterval(Timer *timer)
{
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

void emitEvent(Timer *timer, bool *onEventEmitted)
{
	if (timer->msec >= timer->delay)
	{
		timer->before = clock();
		*onEventEmitted = true;
	}
}

#endif