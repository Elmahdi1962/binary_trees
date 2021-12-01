#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the tree tree of the tree
 * Return: 1 if true or 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	binary_tree_t *prev = NULL;

	if (tree == NULL)
		return (0);

	return (isBSTUtil((binary_tree_t *)tree, prev));
}

/**
 * isBSTUtil - checks if bt is bst
 * @root: pointer to root node
 * @prev: pointer to prev node
 * Return: 0 or 1
 */

int isBSTUtil(binary_tree_t *root, binary_tree_t *prev)
{
	if (root)
	{
		if (root->left != NULL && root->left->n > root->n) 
			return 0; 

		if (root->right != NULL && root->right->n < root->n) 
			return 0; 

		if (!isBSTUtil(root->left, prev))
			return (0);

		if (prev != NULL && root->n <= prev->n)
			return (0);

		prev = root;

		return (isBSTUtil(root->right, prev));
	}

	return (1);
}
