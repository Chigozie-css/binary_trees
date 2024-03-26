#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures height of a binary tree for a balanced tree
 *
 * This function recursively calculates the height of a binary tree for a
 * balanced tree. The height of a balanced binary tree is defined as the
 * length of the longest path from the root node to a leaf node.
 *
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree == NULL)
		return (0);

	l = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
	r = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;

	return (l > r ? l : r);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * This function calculates the balance factor of a binary tree. The balance
 * factor of a binary tree is defined as the difference between the height
 * of the left subtree and the height of the right subtree.
 *
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: The balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0;

	if (tree)
	{
		left = (int)binary_tree_height_b(tree->left);
		right = (int)binary_tree_height_b(tree->right);
	}

	return (left - right);
}
