#include "main.h"
/**
 * _isalpha - checks for lower or uper characters
 * @c: the character to check
 * Return: Always 0(Sucess)
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));

}
