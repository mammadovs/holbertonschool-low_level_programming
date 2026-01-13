#include <stddef.h>

/**
 * array_iterator - executes a function on each element of an array
 * @array: array to iterate over
 * @size: size of the array
 * @action: pointer to function to execute on each element
 *
 * Description: Applies the function action to each element of array.
 * If array or action is NULL, does nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
