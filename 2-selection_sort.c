#include "sort.h"

/**
 * swap_values - swaps 2 values in an array of ints
 *
 * @array: array ints
 * @i1: first value
 * @i2: 2nd value
 *
 * Return: array
 */

void swap_values(int **array, ssize_t i1, ssize_t i2)
{
	int j;

	j = (*array)[i1];
	(*array)[i1] = (*array)[i2];
	(*array)[i2] = j;
}

/**
 * selection_sort - sorts array
 *
 * @array: array of integers
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t k, j, time;

	for (k = 0; k < size - 1; k++)
	{
		time = k;
		for (j = k + 1; j < size; j++)
		{
			if (array[j] < array[time])
				time = j;
		}

		if (time != k)
		{
			swap_values(&array, time, k);
			print_array(array, size);
		}
	}
}
