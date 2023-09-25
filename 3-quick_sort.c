#include "sort.h"

/**
 * swap_values - swap
 *
 * @array: array of ints
 * @i1: first value
 * @i2: 2nd value
 *
 * Return: array
 */

void swap_values(int **array, ssize_t i1, ssize_t i2)
{
	int k;

	k = (*array)[i1];
	(*array)[i1] = (*array)[i2];
	(*array)[i2] = k;
}

/**
 * partition - selects point in array
 *
 * @array: array to sort
 * @lo: lowest index
 * @hi: highest index
 * @size: size of array
 *
 * Return: index of partition
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int p;
	ssize_t i, k;

	p = array[hi];
	i = lo;
	for (k = lo; k < hi; k++)
	{
		if (array[k] < p)
		{
			if (i != k)
			{
				swap_values(&array, i, k);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[hi] < array[i])
	{
		swap_values(&array, i, hi);
		print_array(array, size);
	}

	return (i);
}

/**
 * _quick_sort - sorts each partition
 *
 * @array: array to sort
 * @lo: the lowest index
 * @hi: the highest index
 * @size: size of the array
 */

void _quick_sort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		_quick_sort(array, lo, p - 1, size);
		_quick_sort(array, p + 1, hi, size);
	}
}



/**
 * quick_sort - sorts an array
 *
 * @array: of integers
 * @size: size
 */

void quick_sort(int *array, size_t size)
{
	ssize_t low = 0;
	ssize_t hih = (size - 1);

	if (!array || size < 2)
		return;

	_quick_sort(array, low, hih, size);
}
