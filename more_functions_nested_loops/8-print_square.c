#include "main.h"
/**
 * print_square - draws a square
 * @size: size of the square
 * Return: void
 */
void print_square(int size)
{
	int l, c;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (l = 0; l < size; l++)
	{
		for (c = 0; c < size; c++)
			_putchar('#');

		_putchar('\n');
	}

}
