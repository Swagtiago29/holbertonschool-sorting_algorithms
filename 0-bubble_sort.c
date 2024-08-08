#include "sort.h"
/**
 * bubble_sort - sorting bubble style
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, o, boo = 0;

	if (!array || !size)
		return;
	while (boo < size)
	{
		boo++;
		for (i = 0; i < size - 1; i++)
		{
			j = i + 1;
			if (array[i] > array[j])
			{
				o = array[i];
				array[i] = array[j];
				array[j] = o;
				print_array(array, size);
			}
		}
	}
}
