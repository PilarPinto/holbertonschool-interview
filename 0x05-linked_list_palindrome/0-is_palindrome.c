#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * condition_pal - If the structre is a palindorme
 * @left: double pointer to left node
 * @right: double pointer to right node
 * Return: 0 or 1 if a palindrome
 */
int condition_pal(listint_t **left, listint_t *right)
{
	int p;

	if (right == NULL)
		return (1);

	p = condition_pal(left, right->next);

	if (p == 0)
		return (0);

	p = (right->n == (*left)->n);
	*left = (*left)->next;

	return (p);
}
/**
 * is_palindrome - palindrome function
 * @head: double pinter to head node
 * Return: the result palindrome
 */
int is_palindrome(listint_t **head)
{
	int palindrome = condition_pal(head, *head);

	return (palindrome);
}
