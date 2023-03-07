/* main.h */

#ifndef MAIN_H
#define MAIN_H

unsigned int _strspn(const char *s, const char *accept);

#endif /* MAIN_H */


/* main.c */

#include "main.h"

/**
 * _strspn - gets the length of a prefix substring.
 * @s: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */
unsigned int _strspn(const char *s, const char *accept)
{
	unsigned int i, j, found;

	for (i = 0; s[i] != '\0'; i++)
	{
		found = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}
		if (!found)
			break;
	}
	return i;
}