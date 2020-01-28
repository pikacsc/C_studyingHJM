#pragma once

static unsigned int seed;

int my_rand()
{
	seed = seed * 1103515245 + 1234;
	seed = (unsigned int)(seed / 65536) % 32768;

	return seed;
}

void my_srand(unsigned int _seed)
{
	seed = _seed;
}