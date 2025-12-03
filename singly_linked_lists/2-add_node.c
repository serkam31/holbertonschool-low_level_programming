#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to the pointer of the head node
 * @str: string to duplicate and store in the new node
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
    list_t *new_node;
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
    new_node->next = *head;
    *head = new_node;

    return (new_node);
}
