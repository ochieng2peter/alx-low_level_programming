#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 *
 * @n: The unsigned long int number to get the bit from.
 * @index: The index of the bit to retrieve, starting from 0.
 *
 * Return: The value of the bit at the given index (0 or 1),
 *         or -1 if an error occurrs ("invalid index").
 */
int get_bit(unsigned long int n, unsigned int index)
{
	/* Ensure that index is valid */
	if (index >= (sizeof(unsigned long int) * 8))
	{
		/* Invalid index, return -1 */
		_putchar('-');
		_putchar('1');
		_putchar('\n');
		return (-1);
	}

	/* Create a mask with the bit at the index set to 1 */
	unsigned long int msk = 1UL << index;

	if ((n & msk) == 0)
	{
		/* Bit is 0 */
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	else
	{
		/* Bit is 1 */
		_putchar('1');
		_putchar('\n');
		return (1);
	}
}
