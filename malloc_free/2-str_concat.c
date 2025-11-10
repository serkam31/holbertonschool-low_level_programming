#include <stdlib.h>
/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the new string
 *
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int i = 0, j = 0, len = 0, len2 = 0;
	char *arr;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len] != '\0')
	{
		len++;
	}
	while (s2[len2]) /*avance jusqu'au caractère NULL*/
	{
		len2++;
	}

	arr = malloc((len + len2 + 1) * sizeof(char));

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		arr[i] = s1[i];
	}

	for (j = 0; j < len2; j++, i++)
	{
		arr[i] = s2[j];
	}

	arr[i] = '\0';
	return (arr);
}
