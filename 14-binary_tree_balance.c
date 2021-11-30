#include "binary_trees.h"

/**
* max - function to check which of two int is larger
*
* @num1: num 1
* @num2: num 2
* Return: the largest
*/
int max(int num1, int num2)
{
	return ((num1 > num2) ? num1 : num2);
}

/**
* height - function to return the height of a node
*
* @tree: The node
* Return: The height
*/

int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + max(height(tree->left), height(tree->right)));
}
/**
* binary_tree_balance - A function that calculates the balance of a tree
* @tree: The node in discussion
* Return: The balance
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int hr, hl;

	hl = height(tree->left);
	hr = height(tree->right);

	return (hl - hr);
}
