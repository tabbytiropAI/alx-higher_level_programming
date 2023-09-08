#include "hash_tables.h"

/**
 * key_index - function that returns the index to place an item in the hasht
 * @key: the items to be placed
 * @size: size of the array of hash table
 * Return: the index of the key
 * key_index - Get the index at which a key/value pair should
 *             be stored in array of a hash table.
 * @key: The key to get the index of.
 * @size: The size of the array of the hash table.
 *
 * Return: The index of the key.
 *
 * Description: Uses the djb2 algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value = hash_djb2(key);
	unsigned long int index = hash_value % size;

	return (index);
	return (hash_djb2(key) % size);
}
