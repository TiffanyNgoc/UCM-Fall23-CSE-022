#ifndef UCM_ARRAYS_H
#define UCM_ARRAYS_H

#include <iostream>
#include <stdexcept>

float findMax(float nums[], int size){
    float maxValue = nums[0];
    int maxPos = 0;

    for (int i = 1; i < size; i++){
        if (nums[i] > maxValue){
            maxValue = nums[i];
        }
    }

    return maxValue;
}

float findMin(float nums[], int size){
    float minValue = nums[0];

    for (int i = 1; i < size; i++){
        if (nums[i] < minValue){
            minValue = nums[i];
        }
    }

    return minValue;
}

float getColdestTemperature(float arr[], int size) {
    if (size <= 0) {
        throw std::logic_error("Array must be of size 1 or larger.");
    }
    return findMin(arr, size);
}

float getHottestTemperature(float arr[], int size) {
    if (size <= 0) {
        throw std::logic_error("Array must be of size 1 or larger.");
    }
    return findMax(arr, size);
}

#endif