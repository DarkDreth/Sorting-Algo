#include "Sorting.hpp"
#include <stdlib.h>
#include <string.h>

/*
* selectionsort sorts an array of data
* expected O(n^2)
*/
template <class T> void selectionsort(T* data, int size)
{
	int min;
	T temp;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (*(data + j) < *(data + min))
			{
				min = j;
			}
		}

		temp = *(data + i);
		*(data + i) = *(data + min);
		*(data + min) = temp;
	}
}

template <class T> void InsertionSort(T* data, int size)
{
	T temp;
	for (int i = 1; i < size; i++)
	{
		for (int j = i - 1; i > 0; i--)
		{
			if (*(data + i) < *(data + j))
			{
				temp = *(data + i);
				*(data + i) = *(data + j);
				*(data + j) = temp;
			}
		}
	}
}