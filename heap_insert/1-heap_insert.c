#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * insert_level_order - function that insert a node into a max binary heap
 * @root: pointer to the root of the heap
 * @idx: current index of the heap
 * @size: size of the heap
 * @value: value of the node
 * Return: pointer to the inserted node, or null on failure
 **/
void *insert_level_order(heap_t *root, int idx, int size, int value)
{
heap_t *left, *right;

if (root == NULL)
{
	return (NULL);
}
if (idx == size / 2)
{
	if (root->left == NULL)
	{
		root->left = binary_tree_node(root, value);
		return (root->left);
	}
	root->right = binary_tree_node(root, value);
	return (root->right);
}
left = insert_level_order(root->left, (2 * idx), size, value);
right = insert_level_order(root->right, (2 * idx + 1), size, value);
if (left)
{
	return (left);
}
return (right);
}

/**
 * heap_size - function that calculate the size of a heap
 * @root: pointer to the root of the heap
 * Return: heap size
 */
int heap_size(heap_t *root)
{
int left, right;

if (root == NULL)
{
	return (0);
}
left = heap_size(root->left);
right = heap_size(root->right);
return (left + right + 1);

/**
 * swap - function that swap
 * @a: first element to swap
 * @b: second element to swap
 */
void swap(int *a, int *b)
{
int tmp = *a;

*a = *b;
*b = tmp;
}
/**
 * heap_insert - function that inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
heap_t *newn;
int size;

if (*root == NULL)
{
  	newn = binary_tree_node(NULL, value);
    *root = newn;
    return (newn);
}
size = heap_size(*root) + 1;
newn = insert_level_order(*root, 1, size, value);
for(; newn->parent; newn = newn->parent)
{
	if (newn->parent->n < newn->n)
	{
		swap(&newn->parent->n, &newn->n);
	}
	else
	{
		break;
	}
}
return (newn);
}
