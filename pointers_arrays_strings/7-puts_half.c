#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: string to print
 */
void puts_half(char *str)
{
	int len;
	int i;
	int start;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	if (len % 2 == 0)
	{
		start = len / 2;
	}
	else
	{
		start = (len + 1) / 2;
	}

	for (i = start; i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
