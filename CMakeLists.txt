cmake_minimum_required(VERSION 3.27)
project(A3EC_new)

set(CMAKE_CXX_STANDARD 23)

add_executable(A3EC
        main.cpp
        Sorts/MergeSort.cpp
        Sorts/QuickSort.cpp
        Sorts/HeapSort.cpp
        Sorts/BubbleSort.cpp
        Sorts/radixSort.cpp
)
