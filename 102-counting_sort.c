#include "sort.h"
/**
 * max_finder - Finds the maximum element in an array.
 * @arr: The array to search.
 * @size: The size of the array.
 *
 * This function finds the maximum element in an array.
 *
 * Return: The maximum element in the array.
 *
 * Author: AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
int max_finder(int *arr, size_t size)
{
	int max = arr[0];
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return (max);
}

/**
 * _strcpy - Copies elements from one array to another.
 * @dest: The destination array.
 * @src: The source array.
 * @size: The number of elements to copy.
 *
 * This function copies elements from
 * the source array to the destination array.
 *
 * Return: A pointer to the destination array.
 *
 * Author: AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
int *_strcpy(int *dest, int *src, size_t size)
{
	int i;

	for (i = 0; i < (int)size; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * counting_sort - Sorts an array of integers
 * using the counting sort algorithm.
 * @arr: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * This function sorts an array of integers
 * in ascending order using the counting sort algorithm.
 * It allocates memory for counting array and output array,
 * then sorts the elements based on their count.
 *
 * Return: No return value.
 *
 * Author: AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void counting_sort(int *arr, size_t size)
{
	int max = max_finder(arr, size);
	int *count_arr, *out_arr, curr_elem, sort_post;
	size_t i;

	if (!arr || !size || size == 1)
		return;

	count_arr = calloc(max + 1, sizeof(int));

	for (i = 0; i < size; i++)
	{
		count_arr[arr[i]]++;
	}

	for (i = 1; i <= (size_t)max; i++)
	{
		count_arr[i] += count_arr[i - 1];
	}

	print_array(count_arr, max + 1);

	out_arr = malloc(size * sizeof(int));
	for (i = size - 1; i != SIZE_MAX; i--)
	{
		curr_elem = arr[i];
		sort_post = count_arr[curr_elem] - 1;
		out_arr[sort_post] = curr_elem;
		count_arr[curr_elem]--;
	}

	_strcpy(arr, out_arr, size);
	free(count_arr);
	free(out_arr);
}
