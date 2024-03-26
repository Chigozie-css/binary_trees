#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a root
 *
 * This function determines whether a given node is a root in a binary tree.
 * A root node is defined as a node with no parent.
 *
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is a root, 0 otherwise or if the node is NULL
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	/* Check if the node is NULL or has a parent */
	return ((!node || node->parent) ? 0 : 1);
}
