#ifndef UCM_ARRAYS_H
#define UCM_ARRAYS_H

#include <iostream>

float findMaxPos(float nums[], int size){
    float maxValue = nums[0];
    int maxPos = 0;

    for (int i = 1; i < size; i++){
        if (nums[i] > maxValue){
            maxValue = nums[i];
            maxPos = i;
        }
    }

    return maxPos;
}

float findMinPos(float nums[], int size){
    float maxValue = nums[0];
    int maxPos = 0;

    for (int i = 1; i < size; i++){
        if (nums[i] < maxValue){
            maxValue = nums[i];
            maxPos = i;
        }
    }

    return maxPos;
}

int coldestMonthIndex(float arr[], int size) {
    return findMinPos(arr, size);
}

int hottestMonthIndex(float arr[], int size) {
    return findMaxPos(arr, size);
}

#endif