#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list
 * and returns the head node's data (n).
 * @head: Pointer to a pointer to the first element of the list.
 *
 * Return: The head node's data (n) or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *tmp;

	if (*head == NULL) /* if list is empty */
		return (0);

	n = (*head)->n; /* store head node's data */
	tmp = (*head)->next; /* store address of next node */
	free(*head); /* free head node */
	*head = tmp; /* set next node as the new head */

	return (n);
}
