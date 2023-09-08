#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - function that retrieves a value from the hash table
 * @ht: the hash table
 * @key: key associated with the value
 * Return: key if found, NULLL if not
 * hash_table_get - Retrieve the value associated with
 *                  a key in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int w; /*index*/
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	if (ht == NULL || key == NULL)
	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);
	w = key_index((const unsigned char *)key, ht->size);
	node = ht->array[w];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next; /*tranverse to the next node as it checks*/
	}
	return (NULL);
	node = ht->array[index];
	while (node && strcmp(node->key, key) != 0)
		node = node->next;

	return ((node == NULL) ? NULL : node->value);
}
