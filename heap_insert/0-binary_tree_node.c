#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
* binary_tree_node - Binary tree node
*
* @parent: Pointer to the parent node
* @value: int
* Return: binary_tree_t
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->n = value;
	if (!parent)
		node->parent = NULL;
	else
		node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
