#ifndef UCM_ARRAYS_H
#define UCM_ARRAYS_H

float convertToCelsius(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (arr[i] - 32.0) * 5.0 / 9.0;
    }
} 

#endif