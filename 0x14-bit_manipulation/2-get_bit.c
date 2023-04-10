#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 *
 * @n: The unsigned long int number to get the bit from.
 * @index: The index of the bit to retrieve, starting from 0.
 *
 * Return: The value of the bit at the given index (0 or 1),
 *	or -1 if an error occurrs ("invalid index").
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int itr;

	if (n == 0 && index < 64)
		return (0);

	for (itr = 0; itr <= 63; n >>= 1, itr++)
	{
		if (index == itr)
		{
			return (n & 1);
		}
	}
	return (-1);
}
