#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t x;
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
