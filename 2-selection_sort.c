#include "sort.h"
/**
 * selection_sort - Sorts an array of integers
 * in ascending order using the selection sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * This function sorts an array of integers
 * in ascending order using the selection sort algorithm.
 * It iterates through the array, selecting
 * the smallest element and swapping it with the element
 * at the beginning of the unsorted portion of the array.
 *  This process is repeated until the entire
 * array is sorted.
 *
 * Return: No return value.
 *
 * Authors: AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, k, min_index;

	if (!array)
		return;
	for (i = 0; i < size; i++)
	{
		min_index = i;
		for (k = i + 1; k < size; k++)
		{
			if (array[min_index] > array[k])
				min_index = k;
		}
		if (min_index != i)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
		}
	}
}
