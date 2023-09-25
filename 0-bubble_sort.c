#include "sort.h"

/**
 * swap_values - swap ints
 *
 * @array: ints array
 * @i1: first value index
 * @i2: second value index
 *
 * Return: array
 */

void swap_values(int **array, ssize_t i1, ssize_t i2)
{
	int i;

	i = (*array)[i1];
	(*array)[i1] = (*array)[i2];
	(*array)[i2] = i;
}

/**
 * bubble_sort - sort array
 *
 * @array: integers array
 * @size: size array
 */

void bubble_sort(int *array, size_t size)
{
	size_t j = size, new_n, k;

	while (j > 1)
	{
		new_n = 0;
		for (k = 1; k <= j - 1; k++)
		{
			if (array[k - 1] > array[k])
			{
				swap_values(&array, k - 1, k);
				print_array(array, size);
				new_n = k;
			}
		}
		j = new_n;
	}
}
