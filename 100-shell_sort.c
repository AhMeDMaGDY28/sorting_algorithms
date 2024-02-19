#include "sort.h"
/**
 * shell_sort - Sorts an array of integers using the shell sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * This function sorts an array of integers in ascending order using the shell
 * sort algorithm. It starts with
 * a large gap and gradually reduces the gap size
 * until the entire array is sorted.
 *  Within each iteration, it performs insertion
 * sort on subarrays defined by the gap size.
 *
 * Return: No return value.
 *
 * Authors: AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	/* Calculate the initial gap using the Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Start the sorting process */
	while (gap > 0)
	{
		/* Perform insertion sort with the current gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			/* Shift elements until the correct position for temp is found */
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

		/* Reduce the gap */
		gap = (gap - 1) / 3;

		/* Print the current state of the array */
		print_array(array, size);
	}
}
