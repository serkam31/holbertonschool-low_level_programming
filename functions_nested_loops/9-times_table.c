#include "main.h"
/**
 * times_table - prints the 9 times table
 */
void times_table(void)
{
	int n, x, multiple;

	for (n = 0; n <= 9; n++)
	{
		for (x = 0; x <= 9; x++)
		{
			multiple = n * x;
			if (x != 0)
			{
				_putchar(',');
				_putchar(' ');
				if (multiple < 10)
					_putchar(' ');
			}

			if (multiple >= 10)
				_putchar((multiple / 10) + '0');
			_putchar((multiple % 10) + '0');
		}
		_putchar('\n');
	}
}
