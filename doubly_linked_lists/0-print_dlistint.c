#include "lists.h"

/**
 * print_dlistint - all the elements of a dlist_t list.
 * @h: pointer to node
 * Return: count
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
	return (count);
}
