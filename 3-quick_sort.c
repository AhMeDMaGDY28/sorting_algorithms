#include "sort.h"
/**
 * swap - Swaps two elements in an array and prints the array.
 * @arr: The array.
 * @size: The size of the array.
 * @start: The index of the first element to swap.
 * @end: The index of the second element to swap.
 *
 * This function swaps two elements in an array
 * and prints the array after the swap.
 *
 * Return: No return value.
 *
 * Authors: AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void swap(int *arr, size_t size, int start, int end)
{
	int tmp;

		tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		print_array(arr, size);

}
/**
 * loumto_part - Partitions an array and returns the partition index.
 * @arr: The array to partition.
 * @size: The size of the array.
 * @start: The starting index of the partition.
 * @end: The ending index of the partition.
 *
 * This function partitions an array using the Lomuto partition scheme.
 * It selects the last element as the pivot, places the pivot element
 * at its correct position in the sorted array, and places all smaller
 * elements to the left of the pivot and all greater elements to the right.
 * It returns the index of the pivot element after partitioning.
 *
 * Return: The index of the pivot element after partitioning.
 *
 * Authors: AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
int loumto_part(int *arr, size_t size, int start, int end)
{
	int pavit = arr[end], i, pa_index;

	pa_index = start;
	for (i = start; i <= end - 1; i++)
	{
		if (arr[i] <= pavit)
		{
			swap(arr, size, i, pa_index);
			pa_index++;
		}
	}
	swap(arr, size, end, pa_index);
	return (pa_index);
}
/**
 * quick_sort_recrs - Recursively sorts an array using the quicksort algorithm.
 * @arr: The array to be sorted.
 * @size: The size of the array.
 * @start: The starting index of the sub-array.
 * @end: The ending index of the sub-array.
 *
 * This function recursively sorts a sub-array of integers using the quicksort
 * algorithm. It selects a pivot element and
 * partitions the array around the pivot,
 * then recursively sorts the sub-arrays before and after the pivot.
 *
 * Return: No return value.
 *
 * Authors: AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void quick_sort_recrs(int *arr, size_t size, int start, int end)
{
	int piv;

	if (start < end)
	{
		piv = loumto_part(arr, size, start, end);
		quick_sort_recrs(arr, size, start, (piv - 1));
		quick_sort_recrs(arr, size, (piv + 1), end);
	}
}
/**
 * quick_sort - Sorts an array of integers using the quicksort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * This function sorts an array of integers
 * in ascending order using the quicksort
 * algorithm. It calls the quick_sort_recrs
 * function to recursively sort the entire array.
 *
 * Return: No return value.
 *
 * Authors: AhMeDMaGDY28
 * School: ALX CO 1 BLENDED
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recrs(array, size, 0, (int)size - 1);
}
