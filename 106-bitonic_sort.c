#include "sort.h"

/**
 * compare - compare and swap
 *
 * @array:  array to sort
 * @dir:  direction
 * @size:  size of  array
 */

void compare(int *array, int dir, size_t size)
{
	size_t i, gp;
	int tmp;

	gp = size / 2;

	for (i = 0; i < gp; i++)
	{
		if ((array[i] > array[i + gp]) == dir)
		{
			tmp = array[i];
			array[i] = array[i + gp];
			array[i + gp] = tmp;
		}
	}

}

/**
 * merge - recursively merge subarrays
 *
 * @array:  array to sort
 * @dir:  direction
 * @size:  size of  array
 */

void merge(int *array, int dir, size_t size)
{
	size_t mid = size / 2;

	if (size < 2)
		return;

	compare(array, dir, size);
	merge(array, dir, mid);
	merge((array + mid), dir, mid);
}

/**
 * sort - sorts using bitonic
 *
 * @array:  array to sort
 * @dir:  direction
 * @size: size of  array
 * @subsiz:  size of subarray
 */

void sort(int *array, int dir, size_t size, size_t subsiz)
{
	size_t mid = (size / 2);

	if (size < 2)
		return;

	printf("Merging [%lu/%lu] (%s):\n", size, subsiz, (dir == 1) ? "UP" : "DOWN");
	print_array(array, size);
	sort(array, 1, mid, subsiz);
	sort((array + mid), 0, mid, subsiz);
	merge(array, dir, size);
	printf("Result [%lu/%lu] (%s):\n", size, subsiz, (dir == 1) ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_sort - sorts an array of integers using Bitonic sort algorithm
 *
 * @array: array to sort
 * @size: size of array
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, 1, size, size);
}
