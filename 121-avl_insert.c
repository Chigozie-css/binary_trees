#include "binary_trees.h"

/**
 * r_insert_node - Recursively inserts a node value in an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree.
 * @parent: The parent node of the current node.
 * @new: A double pointer to the new node being inserted.
 * @nval: The value to insert.
 *
 * Return: A pointer to the new root after insertion, otherwise NULL.
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int nval)
{
	int balance;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, nval));

	if ((*tree)->n > nval)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, new, nval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < nval)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, new, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}

	balance = binary_tree_balance(*tree);
	if (balance > 1 && (*tree)->left->n > nval)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance > 1 && (*tree)->left->n < nval)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1 && (*tree)->right->n < nval)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance < -1 && (*tree)->right->n > nval)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the inserted node, or NULL if insertion fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	r_insert_node(tree, *tree, &new, value);
	return (new);
}
