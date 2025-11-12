#include "main.h"
#include <stdlib.h>
/**
 * array_range - creates an array of integers in a specified range.
 * @min: the minimum value in the range.
 * @max: the maximum value in the range.
 *
 * Return: pointer to the newly created array, or NULL on failure.
 */
int *array_range(int min, int max)
{
	int *array;
	int i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	array = malloc(size * sizeof(int));
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = min + i;

	return (array);
}
