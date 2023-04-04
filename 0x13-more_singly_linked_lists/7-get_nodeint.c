#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the head of the linked list
 * @index: index of the node, starting at 0
 * Return: pointer to the nth node or NULL if the node doesn't exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	/* Traverse through the list until index is reached */
	for (i = 0; head != NULL; i++)
	{
		if (i == index)
			return (head); /* return the node at the given index */
		head = head->next;
	}
	return (NULL); /* return NULL if node at index doesn't exist */
}
