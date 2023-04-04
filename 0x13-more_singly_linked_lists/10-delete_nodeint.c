#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index
 *		of a listint_t linked list
 * @head: pointer to the head node pointer of the list
 * @index: index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current = *head, *prev = NULL;
	unsigned int i = 0;

	while (current != NULL)
	{
		if (i == index)
		{
			if (prev == NULL) /* deleting the head node */
				*head = current->next;
			else
				prev->next = current->next;
			free(current);
			return (1);
		}
		prev = current;
		current = current->next;
		i++;
	}

	return (-1); /* index not found */
}




