#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_size-measures the size of a binary tree
 * @tree: Is the pointer to the binary tree
 * Return: Tje size of the binary tree
 */
int binary_tree_size(const binary_tree_t *tree)
{
	int size_l, size_r, total;

	if (!tree)
		return (0);

	size_l = binary_tree_size(tree->left);
	size_r = binary_tree_size(tree->right);
	total = size_l + size_r;

	return (total + 1);
}

/**
 * binary_tree_is_full-checks if a binary tree is full
 * @tree: Is the pointer to binary tree
 * Return: 1 if is full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if(!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if ((tree->left) && (tree->right))
		return (binary_tree_is_full(tree->left)
			&& binary_tree_is_full(tree->right));
	return (0);
}

/**
 * binary_tree_is_perfect-function that checks if a binary tree is perfec
 * @tree: Is the pointer to the binary tree
 * Return: If is perfect 1
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (!tree)
		return (0);

	left_h = binary_tree_size(tree->left);
	right_h = binary_tree_size(tree->right);

	if (binary_tree_is_full(tree) && left_h == right_h)
		return (1);
	return (0);
}

/**
 * parent_addr - checks a parent node to insert a child
 * @root: Is the pointer to address
 * Return: Pointer to parent node
 */
heap_t *parent_addr(heap_t *root)
{
	heap_t *parent;
	int size_l, size_r, l_leaf, r_leaf;

	if (!root)
		return (NULL);

	parent = root;

	size_l = binary_tree_size(parent->left);
	size_r = binary_tree_size(parent->right);
	l_leaf = binary_tree_is_perfect(parent->left);
	r_leaf = binary_tree_is_perfect(parent->right);

	if (!size_l || !size_r)
		return (parent);

	if (!l_leaf || (l_leaf && r_leaf && size_l == size_r))
		return (parent_addr(parent->left));

	else if (!r_leaf || (l_leaf && r_leaf && size_l > size_r))
		return (parent_addr(parent->right));
	return (parent);
}

/**
 * swap_nodes - Compare  Heap
 * @insert_n: Is the pointer to the direction of the root
 * Return: The new created node, a leaf
 */
void swap_nodes(heap_t **insert_n)
{
	heap_t *current;
	int temp;

	current = *insert_n;
	while (current->parent)
	{
		if (current->parent->n < current->n)
		{
			temp = current->parent->n;
			current->parent->n = current->n;
			current->n = temp;
			*insert_n = current->parent;
		}
		current = current->parent;
	}
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: Is the pointer to the direction of the root
 * @value: Is the value in the current inserted node
 * Return: The new created node, a leaf
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_n;
	heap_t *parent;

	if (!root)
		return (NULL);

	parent = parent_addr(*root);
	new_n = binary_tree_node(parent, value);

	if (!new_n)
		return (NULL);

	if (!parent)
		*root = new_n;
	else if (parent->left == NULL)
		parent->left = new_n;
	else
		parent->right = new_n;

	swap_nodes(&new_n);

	return (new_n);
}
