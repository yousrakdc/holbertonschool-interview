#include "sort.h"

/**
 * swap_ints - Swap two integers in an array and print the array
 * @array: The full array (printed after the swap)
 * @size: Number of elements in the full array
 * @a: Index of the first element
 * @b: Index of the second element
 */
static void swap_ints(int *array, size_t size, size_t a, size_t b)
{
	int tmp = array[a];

	array[a] = array[b];
	array[b] = tmp;
	print_array(array, size);
}

/**
 * sift_down - Move a node down the heap until the max-heap property holds
 * @array: The full array
 * @size: Number of elements in the full array (for printing)
 * @root: Index of the node to sift down
 * @end: Number of elements currently in the heap
 */
static void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t child, largest;

	while ((child = 2 * root + 1) < end)
	{
		largest = root;
		if (array[child] > array[largest])
			largest = child;
		if (child + 1 < end && array[child + 1] > array[largest])
			largest = child + 1;
		if (largest == root)
			return;
		swap_ints(array, size, root, largest);
		root = largest;
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order (heap sort)
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, size, 0, i);
		sift_down(array, size, 0, i);
	}
}