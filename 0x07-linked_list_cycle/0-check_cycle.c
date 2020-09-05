#include "lists.h"
/**
 * check_cycle - Check if a lopp exist in the linked list
 * @list: Is the pointer to the structure
 * Return: 1 if a loop exists or 0 if it does not
 */
int check_cycle(listint_t *list)
{
	listint_t *slow_p = list;
	listint_t *fast_p = list;

	if (list == NULL)
		return (0);

	fast_p = fast_p->next;

	while (slow_p != NULL && fast_p != NULL && fast_p->next != NULL)
	{
		if (fast_p == slow_p)
			return (1);
		fast_p = fast_p->next->next;
		slow_p = slow_p->next;
	}
	return (0);
}
