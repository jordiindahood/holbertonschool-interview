#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
* check_cycle - Checks if a singly linked list has a cycle.
* @list: A pointer to the head of the linked list.
*
* Return: 1 if there is a cycle, 0 otherwise.
*/
int check_cycle(listint_t *list)
{
	listint_t *p, *q;

	if (list == NULL || list->next == NULL)
		return (0);

	p = list;
	q = list->next;

	while (q != NULL && q->next != NULL)
	{
		if (p == q)
			return (1);

		p = p->next;
		q = q->next->next;
	}

	return (0);
}
