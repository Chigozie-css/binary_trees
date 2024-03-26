#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 *
 * This function finds the sibling node of a given node in a binary tree.
 * The sibling node is another node in the tree that shares the same parent.
 *
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, or NULL under the following conditions:
 *         - If node is NULL
 *         - If the parent of node is NULL
 *         - If node has no siblings
 *         (i.e., if it is the only child of its parent)
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);

	return (node->parent->left);
}
