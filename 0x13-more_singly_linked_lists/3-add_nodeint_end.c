#include "lists.h"

/**
	* add_nodeint_end - function that adds a new node at the end of a listint_t
	*                   list
	*
	* @head: pointer to a pointer to the first node of the list
	* @n: integer value to be stored in the new node
	*
	* Return: the address of the new element, or NULL if it failed
	**/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node, *current;
/* allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
	return (NULL);
	}

/* set the value and the next pointer of the new node */
	new_node->n = n;
	new_node->next = NULL;

/* if the list is empty, the new node becomes the first node */
	if (*head == NULL)
	{
	*head = new_node;
	return (new_node);
	}
/* traverse the list until the last node is reached */
	current = *head;
	while (current->next != NULL)
	{
	current = current->next;
	}
/* set the next pointer of the last node to point to the new node */
	current->next = new_node;
	return (new_node);
}
