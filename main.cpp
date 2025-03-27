#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <ctime>
#include "Headers/Bubblesort.h"
#include "Headers/QuickSort.h"
#include "Headers/MergeSort.h"
#include "Headers/HeapSort.h"
#include "Headers/DynamicArray.h"
#include "Headers/RadixSort.h"
#include "Headers/tabulate.hpp"

using namespace std;


vector<DynamicArray> Arrays(5);


void initializeArray(DynamicArray& arr,size_t size) {
    arr.size = size;
    arr.data = new int[size];
}

void allocateArray(DynamicArray &arr) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> intDistribution(0, 100);

    for(int i = 0; i < arr.size; i++) {
        arr.data[i] = intDistribution(generator);
    }
}

DynamicArray copy(DynamicArray &original) {
    DynamicArray copy;
    copy.size = original.size;
    copy.data = new int[original.size];

    for(int i = 0; i < original.size; i++) {
        copy.data[i] = original.data[i];
    }

    return copy;
}
string formatTime(double time) {
    stringstream ss;
    ss << fixed << setprecision(3) << time;
    return ss.str();
}

void output(double heapSortTimes[5], double mergeSortTimes[5], double quickSortTimes[5], double bubbleSortTimes[5], double radixSortTimes[5], size_t sizes[]) {
    tabulate::Table formatTable;
    formatTable.add_row(
            {"Data Size", "Heap Sort Time\nIn Seconds", "Merge Sort Time\nIn Seconds", "Quick Sort time\nIn Seconds",
             "Bubble Sort Time\nIn Seconds", "Radix Sort Time\nIn Seconds"});

    for (int i = 0; i < 5; i++) {
        formatTable.add_row({
                                    to_string(sizes[i]),
                                    formatTime(heapSortTimes[i]),
                                    formatTime(mergeSortTimes[i]),
                                    formatTime(quickSortTimes[i]),
                                    formatTime(bubbleSortTimes[i]),
                                    formatTime(radixSortTimes[i])
                            });
    }
    cout << formatTable << endl;
}

int main() {
    size_t sizes[] = {100000, 200000, 300000, 400000, 500000};
    double heapSortTimes[5], mergeSortTimes[5], quickSortTimes[5], bubbleSortTimes[5], radixSortTimes[5];
    clock_t start, finish;

    for (int i = 0; i < 5; i++) {
        initializeArray(Arrays[i], sizes[i]);
        allocateArray(Arrays[i]);
    }

    for (int i = 0; i < 5; i++) {
        DynamicArray heapArray = copy(Arrays[i]);
        start = clock();
        heapSort(heapArray);
        finish = clock();
        heapSortTimes[i] = double(finish - start) / CLOCKS_PER_SEC;
        delete[] heapArray.data;
        heapArray.data = nullptr;

        DynamicArray mergeArray = copy(Arrays[i]);
        start = clock();
        mergeSort(mergeArray);
        finish = clock();
        mergeSortTimes[i] = double(finish - start) / CLOCKS_PER_SEC;
        delete[] mergeArray.data;
        mergeArray.data = nullptr;

        DynamicArray quickArray = copy(Arrays[i]);
        start = clock();
        quickSort(quickArray);
        finish = clock();
        quickSortTimes[i] = double(finish - start) / CLOCKS_PER_SEC;
        delete[] quickArray.data;
        quickArray.data = nullptr;

        DynamicArray radixArray = copy(Arrays[i]);
        start = clock();
        radixSort(radixArray);
        finish = clock();
        radixSortTimes[i] = double(finish - start) / CLOCKS_PER_SEC;
        delete[] radixArray.data;
        radixArray.data = nullptr;


//        DynamicArray bubbleArray = copy(Arrays[i]);
//        start = clock();
//        bubbleSort(bubbleArray);
//        finish = clock();
//        bubbleSortTimes[i] = double(finish - start) / CLOCKS_PER_SEC;
//        delete[] bubbleArray.data;
//        bubbleArray.data = nullptr;
    }

    output(heapSortTimes, mergeSortTimes, quickSortTimes, bubbleSortTimes, radixSortTimes, sizes);


    for (size_t i = 0; i < 5; i++) {
        delete[] Arrays[i].data;
        Arrays[i].data = nullptr;
    }

    return 0;
}

