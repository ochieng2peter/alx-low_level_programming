#include "main.h"

/**
 * binary_to_uint - Convert binary to unsigned int.
 *
 * @b: Pointer to a string of binary digits (0 or 1).
 *
 * Return: Converted unsigned int, or 0 if there is one or more chars
 *         in the string b that is not 0 or 1, or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int rslt = 0;
	int itr = 0;

	if (b == NULL)
	{
		/* Return 0 if b is NULL */
		return (0);
	}

	while (b[itr] != '\0')
	{
		/* Check if the character is not '0' or '1' */
		if (b[itr] != '0' && b[itr] != '1')
		{
			return (0); /* Return 0 if invalid character found */
		}
		rslt *= 2; /* Multiply the result by 2 */
		rslt += (b[itr] - '0'); /* Add the binary digit to the result */
		itr++;
	}

	return (rslt);
}
