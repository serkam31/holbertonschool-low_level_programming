#include "main.h"
/**
 * print_rev - affiche une chaîne de caractères à l'envers
 * @s: pointe vers la chaîne à afficher
 */
void print_rev(char *s)
{
	int i = 0;
	int r;

	while (s[i] != '\0')
		i++;

	r = i - 1;
	while (r >= 0)
	{
		_putchar(s[r]);
		r--;
	}

	_putchar('\n');
}
