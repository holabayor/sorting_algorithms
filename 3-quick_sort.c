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
 * partition - a function that implements the Lomuto partition scheme
 * @arr: array to be partitioned
 * @size: size of the array
 * @lb: lower bound of the array
 * @ub: upper bound of the array
 * Return: the partition pivot
 */

size_t partition(int *arr, const int size, int lb, int ub)
{
	int pivot, i, j;

	pivot = arr[ub];
	i = lb;

	for (j = lb; j < ub; j++)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[i], &arr[j]);
			if (arr[i] != arr[j])
				print_array(arr, size);
			i++;
		}
	}
	swap(&arr[i], &arr[ub]);
	if (arr[i] != arr[ub])
		print_array(arr, size);
	return (i);
}

/**
 * _qsort - a function that implements Quick sort recursively
 * @array: array to be sorted
 * @size: size of the array
 * @lo: lower bound of the array
 * @hi: upper bound of the array
 * Return: void
 */
void _qsort(int *array, const int size, int lo, int hi)
{
	int idx;

	if (lo < hi)
	{
		idx = partition(array, size, lo, hi);
		_qsort(array, size, lo, idx - 1);
		_qsort(array, size, idx + 1, hi);
	}
}
/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	_qsort(array, size, 0, size - 1);
}

