#include "sort.h"

/**
 * swap_values - swaps
 *
 * @array: array of ints
 * @i1: first value
 * @i2: 2nd value
 *
 * Return: array
 */

void swap_values(int **array, ssize_t i1, ssize_t i2)
{
	int temp;

	temp = (*array)[i1];
	(*array)[i1] = (*array)[i2];
	(*array)[i2] = temp;
}

/**
 * heap_sort_sift_down - applies sift down
 *
 * @array:  array of ints
 * @size: size of array
 * @start:  start index
 * @end:  end index
 */

void heap_sort_sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start, bn, s;

	while (root * 2 + 1 <= end)
	{
		bn = root * 2 + 1;
		s = root;

		if (array[s] < array[bn])
			s = bn;
		if (bn + 1 <= end && array[s] < array[bn + 1])
			s = bn + 1;
		if (s == root)
		{
			return;
		}
		else
		{
			s_values(&array, root, s);
			print_array(array, size);
			root = s;
		}
	}
}

/**
 * heap_sort - sorts in sift-down
 *
 * @array: array of integers
 * @size:  size of array
 */

void heap_sort(int *array, size_t size)
{
	size_t l = size - 1, start;

	if (size < 2)
		return;

	for (start = (size - 2) / 2; (int)start >= 0; start--)
		heap_sort_sift_down(array, size, start, size - 1);

	while (l > 0)
	{
		swap_values(&array, l, 0);
		print_array(array, size);
		l--;
		heap_sort_sift_down(array, size, 0, l);
	}
}
