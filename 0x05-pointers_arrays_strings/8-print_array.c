#include"main.h"
#include<stdio.h>
/**
 * print_array - prints n elements of an array of integers.
 *
 * @n: elements parameter input
 * @a: string parameter input
 *
 * Return: Nothing
*/

void print_array(int *a, int n)
{
	int i = 0;

	for (; i = 0; i < n; ++i)
	{
		printf("%d\n", *(a + i));
		if (i != (n - 1))
			printf(", ");
	}
		printf("\n");
}
