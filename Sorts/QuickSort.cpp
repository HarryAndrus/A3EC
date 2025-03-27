#include "../Headers/QuickSort.h"

// function to swap elements
static void swap(int* a, int* b) { // Internal, so marked static
    int t = *a;
    *a = *b;
    *b = t;
}

// function to rearrange array (find the partition point)
static int partition(int array[], int low, int high) { // Internal, so marked static
    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // swap pivot with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

void quickSort(DynamicArray& arr) {
    if (arr.data != nullptr && arr.size > 0) {
        quickSort(arr.data, 0, static_cast<int>(arr.size - 1));
    }
}


