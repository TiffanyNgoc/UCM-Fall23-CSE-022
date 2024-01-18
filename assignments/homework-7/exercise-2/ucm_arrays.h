#ifndef UCM_ARRAYS_H
#define UCM_ARRAYS_H

#include <iostream>
#include <stdexcept>

float getMaxDecrease(float arr[], int size) {
    if (size < 2) {
        throw std::logic_error("Array must be of size 2 or larger.");
    }

    float maxDecrease = 0.0;
    for (int i = 1; i < size; i++) {
        float decrease = arr[i - 1] - arr[i];
        if (decrease > maxDecrease) {
            maxDecrease = decrease;
        }
    }

    return maxDecrease;
}

float getMaxIncrease(float arr[], int size) {
    if (size < 2) {
        throw std::logic_error("Array must of size 2 or larger.");
    }
    float maxIncrease = 0.0;
    for (int i = 1; i < size; i++) {
        float increase = arr[i] - arr[i - 1];
        if (increase > maxIncrease) {
            maxIncrease = increase;
        }
    }

    return maxIncrease;
}

#endif