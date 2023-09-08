#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - function that adds an element to the harsh table
 * @ht: the hashtable
 * @key: key/ item to be placed in the hash tablle
 * @value: value associated with the key
 * Return: 1 if success , 0 otherwise
 * hash_table_set - Add or update an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int w = 0; /*index*/
	hash_node_t *newnode = NULL;
	hash_node_t *temp = NULL; /*tranverses the linked List*/
	hash_node_t *new;
	char *value_copy;
	unsigned long int index, i;

	if (ht == NULL || key == NULL || (strcmp(key, "") == 0))
	{
		return (0); /* input that is invalid*/
	}
	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	w = key_index((unsigned char *)key, ht->size);
	temp = ht->array[w];
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	if (temp && strcmp(key, temp->key) == 0)
	index = key_index((const unsigned char *)key, ht->size);
	for (i = index; ht->array[i]; i++)
	{
		free(temp->value);
		temp->value = strdup(value);
		return (1);
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = value_copy;
			return (1);
		}
	}

	newnode = malloc(sizeof(hash_node_t));

	if (newnode == NULL)
	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);

	newnode->key = strdup(key);
	newnode->value = strdup(value);

	newnode->next = ht->array[w]; /**
				       *set the next ptr of newnode to point to the
				       *current head of the linked list at the calcluated in
				       */
	ht->array[w] = newnode;/**
				*we update the array at the calcluated index to point to
				*the newnode, by doing this we make the newnode the new
				*head of the linked list at the index
				*/
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}
