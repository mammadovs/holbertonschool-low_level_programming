#include "main.h"

/**
 * _strchr - locates the first occurrence of a character in a string
 * @s: string to search
 * @c: character to find
 *
 * Return: pointer to the first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (s + i);
	}

	if (c == '\0')
		return (s + i);

	return (0);
}
