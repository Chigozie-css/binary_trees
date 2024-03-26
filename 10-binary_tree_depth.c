#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 *
 * This function calculates the depth of a given node in a binary tree.
 * The depth is defined as the number of edges from
 * the node to the tree's root.
 *
 * @tree: Pointer to the node to calculate the depth of
 *
 * Return: Depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
