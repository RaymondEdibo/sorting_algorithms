#include "sort.h"

/**
 * int_array_init - int array of 0
 *
 * @size: size of array
 *
 * Return: new filled array
 */

int *int_array_init(size_t size)
{
	int *n = NULL;
	size_t k;

	n = malloc(sizeof(int) * size);
	if (n)
	{
		for (k = 0; k < size; k++)
			n[k] = 0;
	}

	return (n);
}

/**
 * counting_sort - sorts array of integer
 *
 * @array: array of integers
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
	int *ct = NULL, *out = NULL, k = -1;
	size_t i;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
		k = array[i] > k ? array[i] : k;

	ct = int_array_init(k + 1);
	if (ct)
	{
		for (i = 0; i < size; i++)
			ct[array[i]] += 1;

		for (i = 1; i <= (size_t)k; i++)
			ct[i] += ct[i - 1];

		print_array(ct, k + 1);

		out = malloc(sizeof(int) * size);
		if (out)
		{
			for (i = 0; i < size; i++)
			{
				out[ct[array[i]] - 1] = array[i];
				ct[array[i]] -= 1;
			}

			for (i = 0; i < size; i++)
				array[i] = out[i];

			free(out);
		}
		free(ct);
	}
}
