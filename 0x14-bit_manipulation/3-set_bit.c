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
	if (index >= (sizeof(unsigned long int) * 8))
	{
		/* Invalid index, return -1 */
		return (-1);
	}

	/* Create a mask with the bit at the index set to 1 */
	unsigned long int msk = 1UL << index;

	*n |= msk; /* Set the bit at the index to 1 using bitwise OR(|) */

	return (1);
}
