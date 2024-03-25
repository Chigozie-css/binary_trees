#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new node in a binary tree
 *
 * This function dynamically allocates memory for a new node in a binary tree
 * and initializes its values, including its parent, value, and children.
 *
 * @parent: A pointer to the parent node of the node to create
 * @value: The value to store in the newly created node
 *
 * Return: A pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/* Declare a pointer to hold the address of the new node */
	binary_tree_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(binary_tree_t));

	/* Check if memory allocation was successful */
	if (new_node == NULL)
	{
		/* If allocation fails, return NULL */
		return (NULL);
	}

	/* Initialize the properties of the new node */
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	/* Return a pointer to the newly created node */
	return (new_node);
}
