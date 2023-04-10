#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the unsigned long int to modfy.
 * @index: Index of the bit to clear (starting from 0).
 *
 * Return: 1 on success, -1 if an error/failed.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int k;

	if (index > 64)
	{
		return (-1);
	}
	k = 1 << index;

	if (*n & k)
	{
		*n ^= k;
	}
	return (1);
}
