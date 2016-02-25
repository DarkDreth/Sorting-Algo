#include <iostream>
using namespace std;

template <class T> void selectionsort(T* data, int size);
template <class T> void insertionsort(T* data, int size);
template <class T> void mergesort(T* data, int size, T* temp);
template <class T> void quicksort(T* data, int size);

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
		for (int j = i + 1; j < size; j++)
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
	T* min = data; 
	int j = 0;
	for (int i = 1; i < size; i++)
	{
		j = i;
		while (j > 0 && *(data + j - 1) > *(data + j))
		{
			temp = *(data + j);
			*(data + j) = *(data + j - 1);
			*(data + j - 1) = temp;
			j--;
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
		int mid = (size + 1) / 2;
		T* left = (data);
		T* right = (data + mid);


		//left array to sort
		mergesort(left, mid, temp);
		mergesort(right, size - mid, temp);
		int l = 0, r = 0, s = 0;
		while (l < mid && r < size - mid)
		{
			if (*(left + l) < *(right + r))
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
		mergecopy(left + l, mid, temp + s);
		s = s + mid - l;
		mergecopy(right + r, size - mid - 1, temp + s);
		mergecopy(temp, size, data);
	}
}

template <class T> void quicksort(T* data, int size)
{
	if (size < 1)
	{
		return;
	}
	int mid = (size + 1) / 2;
	int pivotPoint = medianof3(data, (data + mid - 1), (data + size - 1));
	T pivot = *data;
	T* pivotPointer = data;
	switch(pivotPoint)
	{
	case 1:
		pivot = *data;
		pivotPointer = data;
		break;
	case 2:
		pivot = *(data + mid - 1);
		pivotPointer = (data + mid - 1);
		break;
	case 3:
		pivot = *(data + size - 1);
		pivotPointer = (data + size - 1);
		break;
	}
	T temp = *(data);
	Swap(pivot, *data);//check
	Swap(temp, *(pivotPointer)); 
	int left = 0;
	int right = size - 1;
	int l = left;
	int r = right;
	do
	{
		while (left < right && *(data + left) <= *(data))
		{
			left++;
		}
		while (left < right && *(data + right) > *(data))
		{
			right--;
		}
		Swap(*(data + left), *(data + right));
	} while (left < right);
	
	if (*(data + left) > *(data))
	{
		left--;
	}
	Swap(*(data), *(data + left));
	if (l < right)
	{
		quicksort(data, left);
	}
	if (left < r)
	{
		quicksort((data + left + 1), size - left - 1);
	}
}

/*
* Copies on array into another
*/
template <class T> void mergecopy(T* data, int size, T* temp)
{
	for (int i = 0; i < size; i++)
	{
		*(temp + i) = *(data + i);
	}
}