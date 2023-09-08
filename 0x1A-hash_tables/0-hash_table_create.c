#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - function that creates a hash table
 * @size: size of the array
 * Return: the newly created hast table
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_htable;
	unsigned long int w; /*counter of the array*/
	hash_table_t *ht;
	unsigned long int i;

	new_htable = (hash_table_t *)malloc(sizeof(hash_table_t));
	if (new_htable == NULL)
	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	new_htable->array = (hash_node_t **)malloc(sizeof(hash_node_t *) * size);
	if (new_htable->array == NULL)
	{
		free(new_htable);
	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	}
	for (w = 0; w < size; w++)
	{
		new_htable->array[w] = NULL;
	}
	new_htable->size = size;
	return (new_htable);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	return (ht);
}
