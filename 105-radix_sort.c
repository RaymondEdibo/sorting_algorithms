#include "sort.h"

/**
 * int_array_init - initializes
 *
 * @size:  size of the array
 *
 * Return:  new filled array
 */

int *int_array_init(size_t size)
{
	int *n = NULL;
	size_t i;

	n = malloc(sizeof(int) * size);
	if (n)
	{
		for (i = 0; i < size; i++)
			n[i] = 0;
	}

	return (n);
}

/**
 * count_sort - sorts 
 *
 * @array:  array of integers
 * @size:  size of the array
 * @exp:  exponent of 10
 */

void count_sort(int *array, size_t size, int exp)
{
	int *ct = NULL, *l = NULL;
	size_t i;

	ct = int_array_init(10 + 1);
	if (ct)
	{
		/* Histogram of the number of times a key occurs within the input */
		for (i = 0; i < size; i++)
			ct[(array[i] / exp) % 10] += 1;

		/* Prefix sum computation on ct to determine the position range */
		for (i = 1; i <= 10; i++)
			ct[i] += ct[i - 1];

		l = int_array_init(size);
		if (l)
		{
			/* Moving each item into its sorted position in the l array */
			for (i = size - 1; (int)i >= 0; i--)
			{
				l[ct[(array[i] / exp) % 10] - 1] = array[i];
				ct[(array[i] / exp) % 10] -= 1;
			}

			for (i = 0; i < size; i++)
				array[i] = l[i];

			free(l);
		}
		free(ct);
	}
}

/**
 * radix_sort - sorts an array of integers using LSD radix sort
 *
 * @array: the array of integers
 * @size: the size of the array
 */

void radix_sort(int *array, size_t size)
{
	int k = -1, exp;
	size_t i;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
		k = array[i] > k ? array[i] : k;

	for (exp = 1; k / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}
