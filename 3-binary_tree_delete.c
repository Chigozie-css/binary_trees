#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 *
 * This function recursively deletes all nodes of the binary tree rooted at the
 * given node. If the tree is NULL, no action is taken.
 *
 * @tree: A pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	/* Recursively delete the right subtree */
	binary_tree_delete(tree->right);

	/* Recursively delete the left subtree */
	binary_tree_delete(tree->left);

	/* Free the current node */
	free(tree);
}
