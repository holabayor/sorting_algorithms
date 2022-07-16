#include "sort.h"

/**
 * swap - an helper function to swap elements in an array
 * @x: address of the element
 * @y: address of the element
 * Return: void
 */
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
/**
 * shell_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, gap = 0;

	while (gap < size / 3)
		gap  = gap * 3 + 1;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				if (array[j - gap] > tmp)
					swap(&array[j], &array[j - gap]);
			}
			array[j] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
