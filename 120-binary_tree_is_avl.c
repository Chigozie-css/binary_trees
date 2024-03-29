#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is an AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - Helper function to check if a binary tree is an AVL tree.
 * @tree: A pointer to the root node of the tree.
 * @min: The minimum allowed value in the tree.
 * @max: The maximum allowed value in the tree.
 *
 * Return: 1 if the tree is an AVL tree, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height;

	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(left_height - right_height) > 1)
		return (0);

	return (is_avl_helper(tree->left, min, tree->n - 1) &&
		is_avl_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree, or 0 if the tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
