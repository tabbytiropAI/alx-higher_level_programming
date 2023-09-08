#include "hash_tables.h"

/**
 * hash_table_delete - deletes the hash table
 * @ht: the hash table
 * Return: nothing
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int w;
	hash_node_t *node;
	hash_node_t *tempo;

	if (ht == NULL)
		return;
	hash_table_t *head = ht;
	hash_node_t *node, *tmp;
	unsigned long int i;

	for (w = 0; w < ht->size; w++)
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[w];
		while (node != NULL)
		if (ht->array[i] != NULL)
		{
			tempo = node;
			node = node->next;
			free(tempo->key);
			free(tempo->value);
			free(tempo);
			node = ht->array[i];
			while (node != NULL)
			{
				tmp = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = tmp;
			}
		}
		ht->array[w] = NULL;
	}
	free(ht->array);
	free(ht);
	free(head->array);
	free(head);
}
