#ifndef VIEW_H
#define VIEW_H

#include "../database/api/viewEntry.h"
#include <math.h>

void viewStock()
{
	double idx = viewEntry();
	if (round(idx) != 0)
	{
		printf("\nIDX Componsite: %.3lf\n\n", idx);
	}
	puts("Press enter to continue...");
	getchar();
}

#endif