#ifndef __SORTING_HELPER_H
#define __SORTING_HELPER_H

#include <iostream>
using namespace std;

template <class T> void selectionsort(T* data, int size);
template <class T> void insertionsort(T* data, int size);
template <class T> void mergesort(T* data, int size, T* temp);
template <class T> void quicksort(T* data, int size);

#endif