#include"main.h"
/**
 * _strlen - retourne la longueur d'une chaîne de caractère
 * @s: pointeur vres la chaîne
 * Return: nombre de cartères avant la fin
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
