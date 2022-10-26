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

void emitEvent(Timer *timer, bool *onEventEmitted)
{
	if (timer->msec >= timer->delay)
	{
		timer->before = clock();
		*onEventEmitted = true;
	}
}

#endif