#include "main.h"

/**
 * _sqrt_helper - helper function to find the square root
 * @n: number to find the square root of
 * @i: current number to test
 *
 * Return: square root of n if found, -1 otherwise
 *
 */
int _sqrt_helper(int n, int i)
{
	if (n < 0)
		return (-1);
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (_sqrt_helper(n, i + 1));
}

/**
 *_sqrt_recursion - returns the natural square root of a number
 * @n: input number
 *
 * Return: natural square root or -1 if not a perfect square
 */
int _sqrt_recursion(int n)
{
	if (n == 0 || n == 1)
		return (n);
	return (_sqrt_helper(n, 1));
}
