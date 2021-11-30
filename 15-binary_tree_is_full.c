#include "binary_trees.h"

/**
* binary_tree_is_full - A function that checks if a tree is full
* @tree: The tree in discussion
* Return: 0 or 1
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	   
	if (tree->left == NULL && tree->right == NULL)
		return (true)

	if ((tree->left) && (tree->right))
	{
		if (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right))
			return (true)
	}
	return (false);
}
