#ifndef UTILS_H
#define UTILS_H

int getRandom(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

#endif