#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: pointer to head adress
 * @index: index of the node, starting from 0
 * Return: number of nodes
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *node = head;
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);

	while (node != NULL)
	{
		if (i == index)
		{
			return (node);
		}

		node = node->next;
		i++;
	}
	return (NULL);
}
