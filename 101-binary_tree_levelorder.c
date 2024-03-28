#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 *
 * This function traverses the binary tree in level-order, calling the provided
 * function for each node at each level.
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, max_level;

	if (!tree || !func)
		return;

	max_level = binary_tree_height(tree) + 1;

	for (level = 1; level <= max_level; level++)
		btlo_helper(tree, func, level);
}

/**
 * btlo_helper - Helper function for level-order traversal
 *
 * This function recursively traverses the binary tree in level-order,
 * calling the provided function for each node at the specified level.
 *
 * @tree: Pointer to the current node in the traversal
 * @func: Pointer to a function to call for each node
 * @level: The current level in the traversal
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		if (tree->left)
			btlo_helper(tree->left, func, level - 1);
		if (tree->right)
			btlo_helper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * This function measures the height of the binary tree.
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
