#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node
 * @value: value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
avl_t *binary_tree_node(avl_t *parent, int value)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * array_to_avl_recursive - recursively builds an AVL tree from a
 *                           sorted sub-array
 * @parent: pointer to the parent node of the subtree being built
 * @array: pointer to the sorted array
 * @first: index of the first element of the sub-array
 * @last: index of the last element of the sub-array
 *
 * Return: pointer to the root of the created subtree, or NULL on failure
 */
avl_t *array_to_avl_recursive(avl_t *parent, int *array, int first, int last)
{
	avl_t *root;
	int mid;

	if (first > last)
		return (NULL);

	mid = first + (last - first) / 2;

	root = binary_tree_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = array_to_avl_recursive(root, array, first, mid - 1);
	root->right = array_to_avl_recursive(root, array, mid + 1, last);

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL
 *         on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (array_to_avl_recursive(NULL, array, 0, (int)size - 1));
}