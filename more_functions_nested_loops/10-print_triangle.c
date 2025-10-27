#include "main.h"
/**
 * print_triangle - print a triangle
 * @size: size of the triangle
 * Return: void
 */
void print_triangle(int size)
{
	int line, space, kr;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (line = 0; line < size; line++)
	{
		for (space = size - line - 1; space > 0; space--)
		_putchar(' ');

		for (kr = 0; kr <= line; kr++)
		_putchar('#');

	_putchar('\n');
	}

}
