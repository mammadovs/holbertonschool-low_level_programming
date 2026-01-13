#include <stddef.h>

/**
 * print_name - prints a name using a function pointer
 * @name: name to print
 * @f: pointer to function that prints the name
 *
 * Description: Calls the function pointed by f with name as argument.
 * If name or f is NULL, does nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (f != NULL && name != NULL)
		f(name);
}
