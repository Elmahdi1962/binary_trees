#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * Return: 1 or 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int flag;

	if (tree == NULL)
		return (FALSE);
	flag = is_complete(tree);

	return (flag >= 1 ? TRUE : FALSE);
}

/**
 * is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * Return: 0 or 1 or number bigger than 1
 */

int is_complete(const binary_tree_t *tree)
{
	int rflag = 1, lflag = 1;
	size_t lh, rh;

	if (tree == NULL)
		return (FALSE);

	lh = binary_tree_height(tree->left) + 1;
	rh = binary_tree_height(tree->right) + 1;

	if ((int)rh > (int)lh)
		return (FALSE);

	if (tree->left == NULL && tree->right == NULL)
		return (TRUE);
	else if (tree->left != NULL && tree->right == NULL)
		return (2);
	else if (tree->left == NULL && tree->right != NULL)
		return (FALSE);
	else if (tree->left->left == NULL && (tree->right->right != NULL ||
			 tree->right->left != NULL))
		return (FALSE);
	else if (tree->left->right == NULL && (tree->right->right != NULL ||
			 tree->right->left != NULL))
		return (FALSE);

	lflag *= is_complete(tree->left);
	rflag *= is_complete(tree->right);

	if (lflag == 2 && rflag == 2)
		return (FALSE);
	return (lflag * rflag);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: the size or 0 if tree is null
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int counter;

	if (tree == NULL)
		return (0);

	counter = tree_height(tree);

	return ((size_t)counter);
}

/**
 * tree_height - count node tree height
 * @node: node to measure
 * Return: height
 */

int tree_height(const binary_tree_t *node)
{
	int lDepth, rDepth;

	if (node == NULL)
		return (-1);

	lDepth = tree_height(node->left);
	rDepth = tree_height(node->right);

	if (lDepth > rDepth)
		return (lDepth + 1);
	else
		return (rDepth + 1);
}
