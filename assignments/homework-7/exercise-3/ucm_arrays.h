#ifndef UCM_ARRAYS_H
#define UCM_ARRAYS_H

#include <stdexcept>
#include <iostream>

float getMaxChange(float arr[], int size) {
    if (size < 2) {
        throw std::logic_error("Array must be of size 2 or larger.");
    }

    float maxChange = 0.0;
    for (int i = 1; i < size; i++) {
        float change = std::abs(arr[i] - arr[i - 1]);
        if (change > maxChange) {
            maxChange = change;
        }
    }

    return maxChange; 
}

#endif