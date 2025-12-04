#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of the dlist.
 * @head: pointer to head adress
 * @n: integer
 * Return: node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newnode, *current;

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	if (*head == NULL)
	{
		*head = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
		return (newnode);
	}

	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = newnode;
	newnode->prev = current;
	newnode->next = NULL;

	return (newnode);
}
