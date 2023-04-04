#include "lists.h"

/**
 * add_nodeint - function that adds a new node at the beginning of a listint_t
 *               list
 *
 * @head: pointer to a pointer to the first node of the list
 * @n: integer value to be stored in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 **/

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

/* allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

/* set the value and the next pointer of the new node */
	new_node->n = n;
	new_node->next = *head;

/* update the head pointer to point to the new node */
	*head = new_node;

	return (new_node);
}
