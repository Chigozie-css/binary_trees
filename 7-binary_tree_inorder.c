#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverse a binary tree using in-order traversal
 *
 * This function recursively traverses a binary tree using in-order traversal
 * and calls a given function for each visited node.
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
