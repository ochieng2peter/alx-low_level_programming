#include "main.h"

/**
 * get_endianness - function to check the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int num = 1;
	char *byte = (char *)&num;

	/* If the first byte of the integer is non-zero, system is little endian */
	if (*byte)
	{
		return (1); /* Little Endian */
	}
	else
	{
		return (0); /* Big Endian */
	}
}
