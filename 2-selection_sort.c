#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, new;

	for (i = 0; i < size - 1; i++)
	{
		new = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[new])
				new = j;
		}
		if (new != i)
		{
			tmp = array[new];
			array[new] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}

