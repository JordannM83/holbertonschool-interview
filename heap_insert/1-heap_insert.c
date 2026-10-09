#include "binary_trees.h"

/**
 * tree_size - Counts the nodes in a binary tree.
 * @tree: Pointer to the root of the tree.
 *
 * Return: Number of nodes in the tree.
 */
static size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * insertion_parent - Finds the parent for the next complete-tree position.
 * @root: Pointer to the root of the heap.
 * @index: One-based index of the new node.
 *
 * Return: Pointer to the new node's parent.
 */
static heap_t *insertion_parent(heap_t *root, size_t index)
{
	size_t mask;
	heap_t *parent;

	mask = 1;
	while ((mask << 1) <= index)
		mask <<= 1;
	mask >>= 1;
	parent = root;

	while (mask > 1)
	{
		if (index & mask)
			parent = parent->right;
		else
			parent = parent->left;
		mask >>= 1;
	}

	return (parent);
}

/**
 * bubble_up - Restores max-heap ordering by moving a value upward.
 * @node: Node containing the value to move upward.
 *
 * Return: Node containing the inserted value.
 */
static heap_t *bubble_up(heap_t *node)
{
	heap_t *parent;
	int value;

	while (node->parent != NULL && node->n > node->parent->n)
	{
		parent = node->parent;
		value = node->n;
		node->n = parent->n;
		parent->n = value;
		node = parent;
	}

	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root of the heap.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;
	heap_t *parent;
	size_t index;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		node = binary_tree_node(NULL, value);
		*root = node;
		return (node);
	}

	index = tree_size(*root) + 1;
	parent = insertion_parent(*root, index);
	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (index & 1)
		parent->right = node;
	else
		parent->left = node;

	return (bubble_up(node));
}
