#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: the size or 0 if tree is null
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t lcounter, rcounter;

    if (tree == NULL)
        return (0);

    lcounter = binary_tree_height(tree->left);

    rcounter = binary_tree_height(tree->right);
    if (lcounter > rcounter)
    {
        if (lcounter == 1)
            return (1);
        return (lcounter + 1);
    } else
    {
        if (rcounter == 1)
            return (1);
        return (rcounter + 1);
    }
}
