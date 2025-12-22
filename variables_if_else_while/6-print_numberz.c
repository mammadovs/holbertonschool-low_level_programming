#include <stdio.h>

/**
 * main - prints single digit numbers from 0 to 9
 *
 * Return: Always 0.
 */
int main(void)
{
	int a;

	for (a = 0; a < 10; a++)
		putchar(a + '0');

	putchar('\n');

	return (0);
}
