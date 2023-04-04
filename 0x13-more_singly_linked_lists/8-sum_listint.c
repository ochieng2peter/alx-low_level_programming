#include "lists.h"
/**
 * sum_listint - Returns the sum of all the data(n)listint_t linked list.
 * @head: Pointer to the head of the linked list
 *
 * Return: Sum of all the data (n) of a listint_t linked list.
 *         0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL) /* Loop through each node in the linked list */
	{
		sum += head->n; /* Add the data of the current node to the sum */
		head = head->next; /* Move to the next node */
	}

	return (sum); /* Return the total sum of all data in the list */
}
