#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse a binary tree using post-order traversal
 *
 * This function recursively traverses a binary tree using post-order traversal
 * and calls a given function for each visited node.
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
