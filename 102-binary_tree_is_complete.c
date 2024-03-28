#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * This function determines whether a binary tree is complete, meaning all
 * levels are completely filled except possibly for the last level, and all
 * nodes are as far left as possible.
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (btic_helper(tree, 0, size));
}

/**
 * btic_helper - Helper function to check completeness of a binary tree
 *
 * This function recursively checks if a binary tree is complete by traversing
 * the tree in a depth-first manner.
 *
 * @tree: Pointer to the current node in the traversal
 * @index: Index of the current node in a complete binary tree array
 * @size: Total number of nodes in the binary tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btic_helper(tree->left, 2 * index + 1, size) &&
			btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * This function determines the size of a binary tree.
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
			binary_tree_size(tree->right) + 1);
}
