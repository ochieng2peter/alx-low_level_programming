#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: A pointer to the head of the linked list.
 * @idx: The index of the list where the new node should be added.
 * @n: The integer value to be stored in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current;
	unsigned int index;

	current = *head; /* Assign the head node to current */

	/* Allocate memory for new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	/* Assign the value of n to the new node */
	new_node->n = n;

	/* If idx is 0, new node will be added at the beginning */
	if (idx == 0)
	{
		new_node->next = *head; /* New node points to the current head */
		*head = new_node; /* Head is now the new node */
		return (new_node);
	}

	/* Traverse the linked list to find the node at idx - 1 */
	for (index = 0; current != NULL && index < idx - 1; index++)
		current = current->next;

	/* If node at idx - 1 does not exist, free the new node and return NULL */
	if (current == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* Insert the new node */
	new_node->next = current->next; /* New node points to the next node */
	current->next = new_node; /* Previous node points to the new node */

	return (new_node);
}
