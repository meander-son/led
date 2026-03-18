#include "emotions.h"
#include <stdlib.h>

static bool closed = false;

bool checkEyesClosed(void)
{
    return closed;
}

uint8_t eyesClosed(uint8_t i)
{
	if (i < 10)
	{
		i +=3;
	}
	if (i >= 10)
	{
		i = 10;
		closed = true;
	}

	return i;
}
uint8_t eyesOpen(uint8_t i)
{
	if (i >= 3)
	{
		i -= 3;
	}
	else
	{
		i = 0;
		closed = false;
	}
	return i;
}
uint8_t openClose(uint8_t i)
{
	if (closed == false )
	{
		if (i == 0 && (rand() % 8) != 0)
			return i;
		i = eyesClosed(i);
	}
	else
	{
		i = eyesOpen(i);
	}
	return i;
}

