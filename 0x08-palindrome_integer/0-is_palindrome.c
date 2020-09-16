#include "palindrome.h"

/**
 * is_palindrome - Check if a number is palindrome
 * @n: Number to check
 * Return: 1 if is palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev, rem, copy;

	rev = 0;
	rem = 0;
	copy = n;
	while (copy != 0)
	{
		rem = copy % 10;
		rev = rev * 10 + rem;
		copy = copy / 10;
	}

	if (rev == n)
		return (1);
	return (0);
}
