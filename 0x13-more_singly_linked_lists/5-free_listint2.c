#include "lists.h"

/**
 * free_listint2 - frees a listint_t list and sets head to NULL
 * @head: pointer to pointer to the head of the list
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

/* Traverse the list, freeing each node */
	while (*head != NULL)
	{
/* Store the current node */
	current = *head;
/* Move head to the next node */
	*head = (*head)->next;
/* Free the current node */
	free(current);
	}
	if (head == NULL)
	{
		return;
	}

/* Set head to NULL to indicate an empty list */
*head = NULL;
}
