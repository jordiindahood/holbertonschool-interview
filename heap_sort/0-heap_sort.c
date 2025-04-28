#include "sort.h"
/**
* sift_down - Helper function to maintain the heap property.
* @array: The array to be sorted.
* @size: The size of the heap.
* @root: The root index to start sifting down.
* @n: The total number of elements in the array.
*/
void sift_down(int *array, size_t size, size_t root, size_t n)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;
	size_t temp;

	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;
	if (largest != root)
	{
		temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		sift_down(array, size, largest, n);
	}
}

/**
* heap_sort - Function to sort the array using the heap sort algorithm.
* @array: The array to be sorted.
* @size: The size of the array.
*/
void heap_sort(int *array, size_t size)
{
	size_t i, temp;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, i - 1, size);
	sift_down(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}
