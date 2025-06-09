#include "binary_trees.h"

/**
 * heapify_down - Rebuilds the Max Heap property from a given node downwards
 * @node: Pointer to the root node of the heap
 */
void heapify_down(heap_t *node)
{
	heap_t *largest = node;
	heap_t *left = node->left;
	heap_t *right = node->right;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;

	if (largest != node)
	{
		int temp = node->n;

		node->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

/**
 * get_height - Calculates the height of the heap
 * @node: Pointer to root node
 * Return: Height
 */
int get_height(const heap_t *node)
{
	if (!node)
		return (0);

	int left = get_height(node->left);
	int right = get_height(node->right);

	return (1 + (left > right ? left : right));
}

/**
 * get_last_node - Finds the last node in level order traversal
 * @root: Pointer to root node
 * @height: Current height
 * Return: Pointer to last node
 */
heap_t *get_last_node(heap_t *root, int height)
{
	if (!root)
		return (NULL);
	if (height == 1)
		return (root);

	heap_t *right = get_last_node(root->right, height - 1);
	heap_t *left = get_last_node(root->left, height - 1);

	return (right ? right : left);
}

/**
 * heap_extract - Extracts root from Max Binary Heap
 * @root: Double pointer to the root node
 * Return: Value of the extracted root or 0 on failure
 */
int heap_extract(heap_t **root)
{
	if (!root || !*root)
		return (0);

	int value = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	int height = get_height(*root);
	heap_t *last = get_last_node(*root, height);

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	(*root)->n = last->n;
	free(last);
	heapify_down(*root);

	return (value);
}
