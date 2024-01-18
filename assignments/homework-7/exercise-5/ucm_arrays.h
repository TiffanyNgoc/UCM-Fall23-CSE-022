#ifndef UCM_ARRAYS_H
#define UCM_ARRAYS_H

#include <iostream>

int countConsecutiveHotDays(float arr[], int size, float hotTemp) {
    if (size <= 0) {
        throw std::logic_error("Array must be of size 1 or larger.");
    }

    int consecutiveHotDays = 0;
    int currentConsecutiveHotDays = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] >= hotTemp) {
            currentConsecutiveHotDays++;
        }
        else {
            if (currentConsecutiveHotDays > consecutiveHotDays) {
                consecutiveHotDays = currentConsecutiveHotDays;
            }
            currentConsecutiveHotDays = 0;
        }
    } 

    // Check for consecutive hot days at the end of array
    if (currentConsecutiveHotDays > consecutiveHotDays) {
        consecutiveHotDays = currentConsecutiveHotDays;
    }

    return consecutiveHotDays;
}

#endif