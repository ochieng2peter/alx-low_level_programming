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
	/* Check if index is out of range */
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	/* Create a mask with only the desired bit set to 0 */
	unsigned long int msk = ~(1UL << index);

	/* Perform bitwise AND with the mask to clear the bit at the given index */
	*n &= msk;
	return (1);
}
