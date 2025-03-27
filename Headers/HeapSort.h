#ifndef A3EC_HEAPSORT_H
#define A3EC_HEAPSORT_H

#include "DynamicArray.h"

void heapify(int arr[], int n, int i);
void heapSortInternal(int arr[], int n);
void heapSort(DynamicArray& arr);

#endif //A3EC_HEAPSORT_H
