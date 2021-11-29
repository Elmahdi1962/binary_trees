#include <stdio.h>
#include "binary_trees.h"

/**
* binary_tree_depth - function that calculates the height of a node in a tree
*
* @tree: the node
* Return: The depth of the node
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;
	if (tree == NULL)
	return (0);
	
	if (tree->left != NULL)
	depth = binary_tree_depth(tree->left) + 1;

	return (depth);
}
