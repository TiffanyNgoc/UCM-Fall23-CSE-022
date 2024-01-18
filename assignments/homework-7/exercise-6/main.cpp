#include <iostream>
#include "ucm_arrays.h"
using namespace std;

int main() {
    const int size = 7;
    float weather[size] = {90.3, 96.5, 106.6, 108.3, 104.4, 98.9, 103.0};

    convertToCelsius(weather, size);

    for (int i = 0; i < size; i++) {
        cout << weather[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }

    return 0;
}