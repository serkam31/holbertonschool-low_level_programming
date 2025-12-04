#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: pointer to head adress
 * @idx: index of the node, starting from 0
 * @n: value to put in new node
 * Return: address of the new node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *newnode, *current = *h;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	while (current != NULL && i < idx)
	{
		current = current->next;
		i++;
	}

	if (current == NULL && i == idx)
		return (add_dnodeint_end(h, n));

	if (current == NULL)
		return (NULL);

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->prev = current->prev;
	newnode->next = current;

	if (current->prev)
		current->prev->next = newnode;
	current->prev = newnode;

	return (newnode);
}
