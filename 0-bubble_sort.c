#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers using the bubble sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * This function sorts an array of integers in ascending order using the bubble
 * sort algorithm. It iterates through the array
 * and compares adjacent elements,
 * swapping them if they are in the wrong order. This process is repeated until
 * the array is sorted.
 *
 * Return: No return value.
 *
 * Authors: AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, x;
	int tmp;

	for (i = 0; i < size; i++)
	{
		for (x = 0; x < size - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				tmp = array[x + 1];
				array[x + 1] = array[x];
				array[x] = tmp;
				print_array(array, size);
			}
		}
	}
}
