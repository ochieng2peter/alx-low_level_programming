#include "main.h"

/**
 * print_binary - Print binary representation of a number.
 *
 * @n: Unsigned long integer to be printed in binary form.
 */
void print_binary(unsigned long int n)
{
	int flg = 0; /* Flg to indicate if the leading zeros have been printed */
	/* Initialize mask to the leftmost bit */
	unsigned long int msk = 1UL << (sizeof(unsigned long int) * 8 - 1);

	/* If n is 0, simply print 0 in binary */
	if (n == 0)
	{
		_putchar('0');
		_putchar('\n');
		return;
	}

	/* Find the highest bit that is set in n */
	while ((msk & n) == 0)
	{
		msk >>= 1;
	}

	/* Print the binary representation of n using the mask */
	while (msk > 0)
	{
		if (n & msk)
		{
			_putchar('1');
			_putchar('\n');
			flg = 1; /* Set flag to indicate leading zeros have been printed */
		}
		else if (flg)
		{
			_putchar('0'); /* Print leading zeros if flag is set */
			_putchar('\n');
		}

		msk >>= 1;
	}
}
