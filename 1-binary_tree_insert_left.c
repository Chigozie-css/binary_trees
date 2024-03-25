#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left child of another node
 *
 * This function inserts a new node with a given value as the left child of
 * a specified parent node in a binary tree. If the parent already has a
 * left child, the new node will take its place, and the old left child
 * will become the left child of the new node.
 *
 * @parent: A pointer to the node to insert the left child in
 * @value: The value to store in the new node
 *
 * Return: A pointer to the newly created node, or NULL on failure or if
 *         the parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Check if the parent node is NULL */
	if (!parent)
		return (NULL);

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	/* Initialize the new node with the given value and parent */
	new_node->n = value;
	new_node->parent = parent;
	new_node->right = NULL;
	new_node->left = parent->left;

	/* Update parent's left child to the new node */
	parent->left = new_node;

	/* Update the parent pointer of the old left child if it exists */
	if (new_node->left)
		new_node->left->parent = new_node;

	return (new_node);
}
