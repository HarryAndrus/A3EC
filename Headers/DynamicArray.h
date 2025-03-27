#ifndef A3EC_DYNAMICARRAY_H
#define A3EC_DYNAMICARRAY_H

#include <cstddef>

struct DynamicArray {
    int* data = nullptr;
    size_t size = 0;
};

#endif //A3EC_DYNAMICARRAY_H
