#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 *
 * This function recursively checks if a binary tree is perfect.
 * A binary tree is considered perfect if all of its levels are fully filled.
 * That is, each level except possibly the last is completely filled,
 * and all nodes are as far left as possible.
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, nodes = 0, power = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	power = (size_t)_pow_recursion(2, height + 1);
	return (power - 1 == nodes);
}

/**
 * _pow_recursion - Returns the value of x raised to the power of y
 *
 * This function recursively calculates the value of x raised to the power of y.
 *
 * @x: The value to exponentiate
 * @y: The power to raise x to
 *
 * Return: x to the power of y, or -1 if y is negative
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * This function recursively calculates the size of a binary tree.
 * The size of a binary tree is defined as the total number of nodes.
 *
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * This function recursively calculates the height of a binary tree.
 * The height of a binary tree is defined as the length of the longest path
 * from the root node to a leaf node.
 *
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
