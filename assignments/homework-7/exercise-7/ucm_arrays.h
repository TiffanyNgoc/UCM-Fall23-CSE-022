#ifndef UCM_ARRAYS_H
#define UCM_ARRAYS_H

#include <iostream>

float largestDailyRange(float min[], float max[], int size) {
    if (size <= 0) {
        throw std::logic_error("Array must be of size 1 or larger.");
    }


    float maxRange = 0.0;
    for (int i = 0; i < size; i++) {
        float dailyRange = max[i] - min[i];
        if (dailyRange > maxRange) {
        maxRange = dailyRange;
        }
    }

    return maxRange; 
}

#endif