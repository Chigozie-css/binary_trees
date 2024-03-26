#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 *
 * This function determines whether a given node is a leaf in a binary tree.
 * A leaf node is defined as a node with no children (both left and right
 * pointers are NULL).
 *
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is a leaf, 0 otherwise or if the node is NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* Check if the node is NULL or has any children */
	return ((!node || node->left || node->right) ? 0 : 1);
}
