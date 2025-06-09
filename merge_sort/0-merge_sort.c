#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays into a sorted one
 * @array: The main array to sort
 * @left: Left index of the subarray
 * @mid: Middle index of the subarray
 * @right: Right index of the subarray
 * @temp: Temporary buffer for merging
 */
void merge(int *array, size_t left, size_t mid, size_t right, int *temp)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
		temp[k++] = array[i++];
	while (j < right)
		temp[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Helper function for recursive merge sort
 * @array: Array to sort
 * @left: Starting index
 * @right: Ending index
 * @temp: Temporary buffer
 */
void merge_sort_recursive(int *array, size_t left, size_t right, int *temp)
{
	if (right - left <= 1)
		return;

	size_t mid = left + (right - left) / 2;

	merge_sort_recursive(array, left, mid, temp);
	merge_sort_recursive(array, mid, right, temp);
	merge(array, left, mid, right, temp);
}

/**
 * merge_sort - Sorts an array of integers using top-down merge sort
 * @array: Array to sort
 * @size: Number of elements in array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int *temp = malloc(sizeof(int) * size);

	if (!temp)
		return;

	merge_sort_recursive(array, 0, size, temp);
	free(temp);
}
