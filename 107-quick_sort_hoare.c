#include "sort.h"

/**
 * swap_values - swaps
 *
 * @array: array of ints
 * @i1: first value
 * @i2:  2nd value
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
 * partition - partitions
 *
 * @array:  array to sort
 * @lo:  lowest index to sort
 * @hi:  highest index to sort
 * @size: size of array
 *
 * Return: index of partition
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int p;

	p = array[hi];

	while (lo <= hi)
	{
		while (array[lo] < p)
			lo++;
		while (array[hi] > p)
			hi--;
		if (lo <= hi)
		{
			if (lo != hi)
			{
				swap_values(&array, lo, hi);
				print_array(array, size);
			}
			lo++;
			hi--;
		}
	}
	return (hi);
}

/**
 * _quick_sort - partitions
 *
 * @array: array to sort
 * @lo:  lowest index to sort
 * @hi:  highest index to sort
 * @size: size of  array
 */

void _quick_sort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		_quick_sort(array, lo, p, size);
		_quick_sort(array, p + 1, hi, size);
	}
}



/**
 * quick_sort_hoare - sort
 *
 * @array:  array of integers
 * @size:  size of  array
 */

void quick_sort_hoare(int *array, size_t size)
{
	ssize_t low = 0;
	ssize_t hih = (size - 1);

	if (!array || size < 2)
		return;

	_quick_sort(array, low, hih, size);
}
