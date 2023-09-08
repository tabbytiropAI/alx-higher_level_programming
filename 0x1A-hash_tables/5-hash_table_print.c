#include "hash_tables.h"

/**
 * hash_table_print - function that displays the hash table
 * @ht: the harshtable to be displayed
 * Return: nothing
 * hash_table_print - Prints a hash table.
 * @ht: A pointer to the hash table to print.
 *
 * Description: Key/value pairs are printed in the order
 *              they appear in the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int w; /*index*/
	hash_node_t *node;
	int hasprinted = 0;
	unsigned long int i;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (w = 0; w < ht->size; w++)
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[w];
		while (node != NULL)
		if (ht->array[i] != NULL)
		{
			if (hasprinted == 1)
			if (comma_flag == 1)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			hasprinted = 1;
			node = node->next;

			node = ht->array[i];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
					printf(", ");
			}
			comma_flag = 1;
		}
	}
	printf("}\n");

