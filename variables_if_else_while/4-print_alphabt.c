#include<stdio.h>
/**
 * main - Prints the alphabet in lowercase except e and q
 * Return: Always 0 (Success)
 */
int main(void)
{
	char alphabet = 'a';

	while (alphabet <= 'z')
	{
		if (alphabet != 'e' && alphabet != 'q')
		putchar(alphabet);
		alphabet++;
	}
	putchar('\n');

	return (0);
}
