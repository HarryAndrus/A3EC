#ifndef A3EC_RADIXSORT_H
#define A3EC_RADIXSORT_H

#include "DynamicArray.h"

int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixSortInternal(int arr[], int n);
void radixSort(DynamicArray& arr);

#endif //A3EC_RADIXSORT_H
