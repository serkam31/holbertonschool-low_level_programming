#include "lists.h"

/**
 * add_node_end - adds a new node at the end of the list.
 * @head: pointer to head adress
 * @str: pointer to the string
 * Return: node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newnode, *last;
	unsigned int length = 0;

	while (str[length] != '\0')
		length++;

	if (str == NULL)
		return (NULL);

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
		return (NULL);

	newnode->str = strdup(str);
	if (newnode->str == NULL)
	{
		free(newnode);
		return (NULL);
	}

	newnode->len = length;
	newnode->next = NULL;
	if (*head == NULL)
	{
		*head = newnode;
		return (newnode);
	}

	last = *head;
	while (last->next)
		last = last->next;

	last->next = newnode;

	return (newnode);
}
