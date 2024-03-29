#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: Pointer to the first element of the array to create from.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL tree, otherwise NULL.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int i;
	avl_t *root = NULL;

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
