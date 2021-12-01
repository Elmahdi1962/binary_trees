#include "binary_trees.h"
#include <stdbool.h>
#define MAX_Q_SIZE 500

binary_tree_t **createQueue(int *, int *);
void enQueue(binary_tree_t **, int *, binary_tree_t *);
binary_tree_t *deQueue(binary_tree_t **, int *);
bool isQueueEmpty(int *front, int *rear);


/**
 * createQueue - createQueue a queue
 * @front: pointer to the front of the queue
 * @rear: pointer to rear of the queue
 * Return: pointer to pointer to queue
 */

binary_tree_t **createQueue(int *front, int *rear)
{
	binary_tree_t **queue =
	(binary_tree_t **)malloc(sizeof(binary_tree_t *) * MAX_Q_SIZE);

	*front = *rear = 0;
	return (queue);
}

/**
 * enQueue - enQueue the new node
 * @queue: pointer to pointer to queue
 * @rear: pointer to rear of the queue
 * @new_node: pointer to the new node
 * Return: void
 */

void enQueue(binary_tree_t **queue, int *rear, binary_tree_t *new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}

/**
 * deQueue - deQueue the front node
 * @queue: pointer to pointer to queue
 * @front: pointer to front of the queue
 * Return: deQueueed node
 */

binary_tree_t *deQueue(binary_tree_t **queue, int *front)
{
	(*front)++;
	return (queue[*front - 1]);
}

/**
 * isQueueEmpty - checks queue is empty
 * @front: pointer to front of the queue
 * @rear: pointer to rear fo the queue
 * Return: True or False
 */

bool isQueueEmpty(int *front, int *rear)
{
	return (*rear == *front);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * Return: 1 or 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *root = (binary_tree_t *)tree;

	if (root == NULL)
		return (true);

	int rear, front;
	binary_tree_t **queue = createQueue(&front, &rear);

	bool flag = false;

	enQueue(queue, &rear, root);
	while (!isQueueEmpty(&front, &rear))
	{
		binary_tree_t *temp_node = deQueue(queue, &front);
		/* Check if left child is present*/
		if (temp_node->left)
		{
			if (flag == true)
				return (false);

			enQueue(queue, &rear, temp_node->left);
		}
		else
			flag = true;

		/* Check if right child is present*/
		if (temp_node->right)
		{
			if (flag == true)
				return (false);

			enQueue(queue, &rear, temp_node->right);
		}
		else
			flag = (true);
	}

	return (true);
}
