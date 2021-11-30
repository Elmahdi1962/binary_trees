#include "binary_trees.h"

/**
* perfect - a function that checks for perfection
*
* @tree: The tree to be checked
* @d: the depth
* Return: 1 or 0
*/

int perfect(binary_tree_t *tree, int d)
{
	int level, checkl, checkr;

	level = 0;

	if (tree == NULL)
	return (true);

	if (tree->left == NULL && tree->right == NULL)
	return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
 	return (false);

 	checkl = perfect(tree->left, d);
 	checkr = perfect(tree->right, d);

 	return (checkr && checkl);
}

/**
* binary_tree_is_perfect - A function that checks if a tree is perfect
* @tree: The tree in discussion
* Return: 0 or 1
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (tree == NULL)
		return (true);

	d = 0;

	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}
	return (perfect(tree, d));
}
