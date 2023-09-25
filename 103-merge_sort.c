#include "sort.h"

/**
 * int_array_copy - copie
 *
 * @array: array to copy
 * @size: size of copied array
 *
 * Return: new copied array
 */

int *int_array_copy(int *array, size_t size)
{
	int *n = NULL;
	size_t i;

	n = malloc(sizeof(int) * size);
	if (n)
	{
		for (i = 0; i < size; i++)
			n[i] = array[i];
	}

	return (n);
}

/**
 * top_down_merge - merges
 *
 * @a: first array
 * @b: second array
 * @size: size of array
 * @mid: middle index
 */

void top_down_merge(int *a, int *b, size_t size, size_t mid)
{
	size_t i = 0, l = 0, k;

	for (k = 0; k < size; k++)
	{
		if (l >= size - mid || (i < mid && a[i] < (a + mid)[l]))
			b[k] = a[i++];
		else
			b[k] = (a + mid)[l++];
	}

	for (k = 0; k < size; k++)
		a[k] = b[k];
}

/**
 * top_down_split_merge - merges
 *
 * @a:  first array
 * @b:  second array
 * @size:  size of array
 */

void top_down_split_merge(int *a, int *b, size_t size)
{
	size_t min = size / 2 /*, i = 0, j = 0, k*/;

	if (size < 2)
		return;

	top_down_split_merge(a, b, min);
	top_down_split_merge(a + min, b + min, size - min);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(a, min);
	printf("[right]: ");
	print_array(b + min, size - min);

	top_down_merge(a, b, size, min);

	printf("[Done]: ");
	print_array(a, size);
}

/**
 * merge_sort - sorts
 *
 * @array: array of integers
 * @size:  size of array
 */

void merge_sort(int *array, size_t size)
{
	int *i = NULL;

	i = int_array_copy(array, size);
	if (i)
	{
		top_down_split_merge(array, i, size);
		free(i);
	}
}
