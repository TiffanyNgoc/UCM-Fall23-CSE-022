#ifndef UCM_ARRAYS_H
#define UCM_ARRAYS_H

float average(float arr[], int size) {
    float total = 0;
    float avg;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }

    avg = total / size;

    return avg;
}

#endif