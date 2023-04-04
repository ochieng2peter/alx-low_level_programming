#include "lists.h"

/**
 * free_listint2 - a function that frees the list and sets head to NULL
 *
 * @head: pointer to the first node
 *
 * Return: nothing
*/

void free_listint2(listint_t **head)
{

	listint_t *crnt, *tmp;

	/* check if the head pointer is not null*/
	if (head != NULL)
	{
		crnt = *head;

		while ((tmp = crnt) != NULL)
		{
/*assign the next node in the linked list to current*/
			crnt = crnt->next;
/* free the memory allocated for the current node*/
			free(temp);
		}
/* set the head pointer to null, effectively freeing the entire linked list*/
		*head = NULL;
	}
}
