#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 *
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current = NULL;
	bst_t *parent = NULL;
	bst_t *new_node = NULL;

	if (!tree)
		return (NULL);

	/* If the tree is empty, create a new node as the root */
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	current = *tree;

	/* Traverse the tree to find the appropriate position */
	while (current)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else /* Value already exists in the tree */
			return (NULL);
	}

	/* Create a new node */
	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	/* Insert the new node based on its value */
	if (parent == NULL)
		parent = new_node;
	else if (value < parent->n)
	{
		parent->left = new_node;
		new_node->parent = parent;
	}
	else
	{
		parent->right = new_node;
		new_node->parent = parent;
	}

	return (new_node);
}
