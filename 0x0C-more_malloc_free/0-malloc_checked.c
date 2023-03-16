#include "main.h"
#include <stdlib.h>
/**
 * malloc_checked - allocates memory.
 * @b: amounts of bytes.
 * Return: pointer to the allocated memory.
 * if malloc fails, status value returned is 98.
 */
void *malloc_checked(unsigned int b)
{
	char *k;

	k = malloc(b);
	if (k == NULL)
		exit(98);
	return (k);
}
