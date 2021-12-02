#include "binary_trees.h"

/**
* bst_insert - a function that inserts a new node in search tree
* @tree: The root node
* Return: The new node
*/

bst_t *bst_insert(bst_t **tree, int value)
{
	int duplicate = 0;

	if (tree == NULL)
		return (NULL);
	duplicate = bs_tree_preorder((*tree), value);
	printf("\nduplicated == %d\n", duplicate);
	if (duplicate == 0)
		return (NULL);
	if ((*tree) == NULL)
		return (binary_tree_node((*tree), value));

	if (value < (*tree)->n)
		(*tree)->left = bst_insert(&(*tree)->left, value);
	else if (value > (*tree)->n)
		(*tree)->right = bst_insert(&(*tree)->right, value);
	else if (value == (*tree)->n)
		return (NULL);
	if ((*tree) == NULL)
		return (NULL);
	return (*tree);
}

/**
 * bs_tree_preorder - goes through a binary tree
 * using pre-order traversal
 * @tree: pointer to the root node
 * @n: pointer to a function to call for each node.
 * Return: 0 for true or 1 for false
 */

int bs_tree_preorder(bst_t *tree, int n)
{
	int leftr, rightr;

	if (tree == NULL)
		return (1);
	if (tree->n == n)
		return (0);
	leftr = bs_tree_preorder(tree->left, n);
	rightr = bs_tree_preorder(tree->right, n);
	return (leftr * rightr);
}
