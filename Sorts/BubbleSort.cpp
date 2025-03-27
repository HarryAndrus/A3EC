#include <iostream>
#include "../Headers/DynamicArray.h"

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Flag to optimize if no swapping occurs in a pass
        bool swapped = false;

        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if current element is greater than next
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swapping occurred in this pass, array is sorted
        if (!swapped) {
            break;
        }
    }
}

void bubbleSort(DynamicArray& arr) {
    if (arr.data != nullptr && arr.size > 0) {
        bubbleSort(arr.data, arr.size);
    }
}
