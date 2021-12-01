#include "binary_trees.h"
int isValid(binary_tree_t *root);
void inorder(binary_tree_t *root, binary_tree_t *prev[], int isvalid[]);
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the tree tree of the tree
 * Return: 1 if true or 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (isValid((binary_tree_t *)tree));
}

int isValid(binary_tree_t *root)
{
	int isvalid[] = {1};
	binary_tree_t *prev[] = {NULL};

	inorder(root, prev, isvalid);
	return (isvalid[0]);
}

void inorder(binary_tree_t *root, binary_tree_t *prev[], int isvalid[])
{
	if (root != NULL)
	{
		inorder(root->left, prev, isvalid);

		if (prev[0] != NULL && prev[0]->n >= root->n)
		{
			isvalid[0] = 0;
			return;
		}
		prev[0] = root;
		inorder(root->right, prev, isvalid);
	}
}
