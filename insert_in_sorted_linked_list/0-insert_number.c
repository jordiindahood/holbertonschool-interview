#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
* insert_node - prints all elements of a listint_t list
* @head: pointer to head of list
* @number: value
* Return: number of nodes
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *index;

	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);
	node->n = number;
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (*head);
	}
	index = *head;

	if (node->n < index->n)
	{
		node->next = index;
		*head = node;
		return (*head);
	}

	while (index->next != NULL)
	{
		if (node->n < index->next->n || index->next == NULL)
			{
			node->next = index->next;
			index->next = node;
			return (*head);
			}
		index = index->next;
		}
	return (NULL);
}
