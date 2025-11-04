#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - prints the sum of the two diagonals
 * @a: pointer to the first element of the matrix
 * @size: of the square matrix
 */
void print_diagsums(int *a, int size)
{
	int i;
	int d1 = 0, d2 = 0;

	for (i = 0; i < size; i++)
	{
		d1 = d1 + *(a + i * size + i);
		d2 = d2 + *(a + i * size + (size - 1 - i));
	}
	printf("%d, %d\n", d1, d2);
}
