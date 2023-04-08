#include "main.h"

/**
 * binary_to_uint - Convert binary to unsigned int.
 *
 * @b: Pointer to a string of binary digits (0 or 1).
 *
 * Return: Converted unsigned int, or 0 if there is one or more chars
 *	in the string b that is not 0 or 1, or if b is NULL.
 */

unsigned int binary_to_uint(const char *b)
{
	if (b == NULL)
	{
		return (0);
	}

	unsigned int rslt = 0;
	int r = 0;

	while (b[r] != '\0')
	{
		if (b[r] != '0' && b[r] != '1')
		{
			return (0);
		}
		rslt = rslt * 2 + (b[r] - '0');
		r++;
	}
	return (rslt);
}
