#include "sort.h"

/**
 * knuth_max_gap - Knuth sequence
 *
 * @size: size of array
 *
 * Return: max gap
 */

size_t knuth_max_gap(size_t size)
{
	size_t gp = 1;

	while (gp < size)
		gp = gp * 3 + 1;
	if (gp >= size)
		gp = (gp - 1) / 3;

	return (gp);
}

/**
 * shell_sort - sorts(Knuth sequence)
 *
 * @array: array of integers
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gp = 0, i, k;
	int temp;

	gp = knuth_max_gap(size);
	while (gp > 0)
	{
		for (i = gp; i < size; i++)
		{
			temp = array[i];

			for (k = i; k >= gp && array[k - gp] > temp; k -= gp)
				array[k] = array[k - gp];

			array[k] = temp;
		}
		print_array(array, size);
		gp = (gp - 1) / 3;
	}
}
