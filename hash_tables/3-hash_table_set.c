#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * create_new_node - Creates a new hash node
 * @key: The key
 * @value: The value
 *
 * Return: Pointer to new node or NULL on failure
 */
hash_node_t *create_new_node(const char *key, const char *value)
{
	hash_node_t *new_node;
	char *key_copy, *value_copy;

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (NULL);

	key_copy = strdup(key);
	if (!key_copy)
	{
		free(new_node);
		return (NULL);
	}

	value_copy = strdup(value);
	if (!value_copy)
	{
		free(key_copy);
		free(new_node);
		return (NULL);
	}

	new_node->key = key_copy;
	new_node->value = value_copy;
	new_node->next = NULL;

	return (new_node);
}

/**
 * hash_table_set - Add or update an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon success - 1.
 *         Upon failure - 0.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node, *new_node;
	unsigned long int idx;
	char *value_copy;

	if (!ht || !key || !*key)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	node = ht->array[idx];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			value_copy = strdup(value);
			if (!value_copy)
				return (0);
			free(node->value);
			node->value = value_copy;
			return (1);
		}
		node = node->next;
	}

	new_node = create_new_node(key, value);
	if (!new_node)
		return (0);

	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;

	return (1);
}
