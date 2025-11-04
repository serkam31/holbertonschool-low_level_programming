#include "main.h"
#include <stdio.h>
/**
 * print_chessboard -prints a chessboard
 * @a: pointer to a array of chars
 */
void print_chessboard(char (*a)[8])
{
	int l, c;

	for (l = 0; l < 8; l++)
	{
		for (c = 0; c < 8; c++)
		{
			_putchar(a[l][c]);
		}
		_putchar('\n');
	}
}
