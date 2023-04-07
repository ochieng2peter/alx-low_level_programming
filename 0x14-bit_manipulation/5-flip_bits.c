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
	unsigned long int xor = n ^ m;
	unsigned int count = 0;


	while (xor != 0)
	{
		count += xor & 1; /* If least significant bit is set, increment count */
		xor >>= 1; /* Shift right to check the next bit */
	}

	return (count);
}
