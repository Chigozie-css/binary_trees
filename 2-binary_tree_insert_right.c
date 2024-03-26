#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 *
 * This function inserts a new node with the specified value as the right child
 * of the given parent node. If the parent already has a right child, the new
 * node will take its place, and the old right child will be set as the
 * right-child of the new node.
 *
 * @parent: Pointer to the node to insert the right-child in
 * @value: The value to store in the new node
 *
 * Return: A pointer to the created node, or NULL on failure
 * or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = parent->right;

	parent->right = new_node;
	if (new_node->right)
		new_node->right->parent = new_node;

	return (new_node);
}
