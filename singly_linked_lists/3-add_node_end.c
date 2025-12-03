#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to the pointer of the head node
 * @str: string to duplicate and store in the new node
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new_node, *temp;
    char *dup;
    unsigned int len = 0;

    if (head == NULL)
        return (NULL);

    if (str != NULL)
    {
        dup = strdup(str);
        if (dup == NULL)
            return (NULL);
        while (dup[len] != '\0')
            len++;
    }
    else
    {
        dup = NULL;
        len = 0;
    }

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
    {
        if (dup)
            free(dup);
        return (NULL);
    }

    new_node->str = dup;
    new_node->len = len;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
    return (new_node);
}
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to be duplicated and added to the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *temp;
	unsigned int len = 0;

	/* Check if str is NULL */
	if (str == NULL)
		return (NULL);

	/* Calculate the length of str */
	while (str[len])
		len++;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	/* Duplicate the string */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = len;
	new_node->next = NULL;

	/* If the list is empty, make the new node the head */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	/* Otherwise, traverse to the end of the list */
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	/* Add the new node at the end */
	temp->next = new_node;

	return (new_node);
}
