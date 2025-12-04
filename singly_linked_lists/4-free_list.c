#include "lists.h"
#include <stdlib.h>

/**
 * free_list - frees a list_t list
 * @head: pointer to the list to be freed
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		/* 1. On sauvegarde le suivant avant de détruire l'actuel */
		temp = head->next;

		/* 2. On libère la chaîne (car créée avec strdup/malloc) */
		free(head->str);

		/* 3. On libère le nœud lui-même */
		free(head);

		/* 4. On passe au suivant */
		head = temp;
	}
}
