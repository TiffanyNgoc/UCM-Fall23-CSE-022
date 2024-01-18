#ifndef UCM_ARRAYS_H
#define UCM_ARRAYS_H

#include <iostream>
#include <stdexcept>

int countHotDays(float arr[], int size, float hotTemp) {
    if (size <= 0) {
        throw std::logic_error("Array must be of size 1 or larger.");
    }

    int hotDays = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= hotTemp) {
            hotDays++;
        }
    }

    return hotDays;
}

#endif