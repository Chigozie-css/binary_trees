#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 *
 * This function recursively counts the number of nodes with at least one child
 * in a binary tree.
 *
 * @tree: Pointer to the root node of the tree to count nodes from
 *
 * Return: Number of nodes counted, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	return (binary_tree_size(tree) - binary_tree_leaves(tree));
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
 * binary_tree_leaves - Counts the leaves in a binary tree
 *
 * This function recursively counts the number of leaves in a binary tree.
 * A leaf node is a node with no children.
 *
 * @tree: Pointer to the root node of the tree to count leaves from
 *
 * Return: Number of leaves, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
