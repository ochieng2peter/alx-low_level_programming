#include "main.h"

/**
 * set_bit - Set the value of a bit at given indexes.
 *
 * @n: Pointer to the unsigned long int no.
 * @index: The index of the bit to set, starting from 0.
 *
 * Return: 1 on success, -1 on error (invalid index).
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m;

	if (index > 63)
		return (-1);
	/* Bitwise shift to the left by index positions*/
	m = 1UL << index;
	*n = (*n | m); /* Bitwise OR operation to set the bit at the index*/
	return (1);
}
