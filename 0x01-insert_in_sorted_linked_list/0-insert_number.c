#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Insert a node in a SLL
 * @head: Is the pointer to direction of a list
 * @number: Is the data value
 * Return:The new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = *head;
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL || head == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL || (*head)->n > new_node->n)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		while (current->next != NULL && current->next->n < new_node->n)
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}
	return (new_node);
}
