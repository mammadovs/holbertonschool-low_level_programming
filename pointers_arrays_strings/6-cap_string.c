#include "main.h"

/**
 * is_separator - checks if a character is a word separator
 * @c: character to check
 *
 * Return: 1 if c is a separator, 0 otherwise
 */
int is_separator(char c)
{
	char separators[] = " \t\n,;.!?\"(){}";

	int i = 0;

	while (separators[i] != '\0')
	{
		if (c == separators[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * cap_string - capitalizes all words of a string
 * @s: string to modify
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *s)
{
	int i = 0;

	if (s[i] >= 'a' && s[i] <= 'z')
		s[i] -= 'a' - 'A';
	i++;

	while (s[i] != '\0')
	{
		if (is_separator(s[i - 1]) && (s[i] >= 'a' && s[i] <= 'z'))
			s[i] -= 'a' - 'A';
		i++;
	}

	return (s);
}
