#include<stdio.h>
/**
 * main - Prints the alphabet in lowercase then in uppercase
 * Return: Always 0 (Sucess)
 */
int main(void)
{
	char alphabetl = 'a';
	char alphabetu = 'A';

	while (alphabetl <= 'z')
	{
		putchar (alphabetl);
		alphabetl++;
	}

	while (alphabetu <= 'Z')
	{
		putchar(alphabetu);
		alphabetu++;
	}

	putchar('\n');

	return (0);
}
