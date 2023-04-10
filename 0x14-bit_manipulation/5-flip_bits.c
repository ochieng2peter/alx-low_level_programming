#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to flip to get from one number
 *		to another.
 *
 * @n: First unsigned long integer.
 * @m: Second unsigned long integer.
 *
 * Return: Number of bits needed to flip.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	/* Counter to keep track of number of bit flips */
	unsigned long int n_bits;

	/* Loop through each bit of n and m, from LSB to MSB */
	for (n_bits = 0; m || n; m >>= 1, n >>= 1)
	{
		/* Compare the LSBs of n and m using bitwise AND operation*/
		/* If they are different, increment the bit flip counter */
		if ((m & 1) != (n & 1))
			n_bits++;
	}

	/** Return the total number of bit flips required */
	return (n_bits);
}
