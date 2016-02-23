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

/*
* insertionsort sorts an array of data
* expected O(n^2)
*/
template <class T> void insertionsort(T* data, int size)
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

/*
* mergesort sorts an array of data
* expected O(nlogn)
*/
template <class T> void mergesort(T* data, int size, T* temp)
{
	if (size > 1)
	{
		int mid = (n + 1) / 2;
		T* right = (data + mid);

		//left array to sort
		mergesort(data, mid - 1, temp);
		mergesort(data, size - 1, right);
		int l = r = s = 0; //TODO: Check this
		while (l < mid && r < size - mid)
		{
			if (*(data + l) < *(right + r))
			{
				*(temp + s) = *(data + l);
				l++;
			}

			else
			{
				temp[s] = *(right + r);
				r++;
			}
			
			s++;
		}
		mergecopy(data, mid - 1, temp);
		mergecopy(right, size, temp);
		mergecopy(temp, size, data);
	}
}

template <class T> void quicksort(T* data, int size)
{
	if (size < 1)
	{
		return data;
	}
	int mid = (size + 1) / 2;

}

/*
* Copies on array into another
*/
template <class T> void mergecopy(T* data, int size, T* temp)
{
	for (i = 0; i < size; i++)
	{
		*(temp + i) = *(data + i)
	}
}