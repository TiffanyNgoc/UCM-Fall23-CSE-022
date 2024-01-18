#include <igloo/igloo.h>
#include "ucm_arrays.h"
#include<iostream>

using namespace igloo;

bool compareFloat(float x, float y, float epsilon = 0.001f){
    if(std::abs(x - y) < epsilon) {
        return true;
    }
      
    return false;
}

bool compareArrays(float a[], float b[], int size) {
    for (int i = 0; i < size; i++) {
        if (!compareFloat(a[i], b[i])) {
            return false;
        }
    }
    return true;
}

Context(TextProgram){
    Spec(Size_0_HotDays){
        const int size = 0;
        float weather[size] = {};
        convertToCelsius(weather, size);
        float weatherC[size] = {};
        Assert::That(compareArrays(weather, weatherC, size), IsTrue());
    }
    Spec(Size_1_HotDays){
        const int size = 1;
        float weather[size] = {100.5};
        convertToCelsius(weather, size);
        float weatherC[size] = {38.0556};
        Assert::That(compareArrays(weather, weatherC, size), IsTrue());
    }
    Spec(Size_7_HotDays){
        const int size = 7;
        float weather[size] = {90.3, 96.5, 106.6, 108.3, 104.4, 98.9, 103.0};
        convertToCelsius(weather, size);
        float weatherC[size] = {32.3889, 35.8333, 41.4444, 42.3889, 40.2222, 37.1667, 39.4444};
        Assert::That(compareArrays(weather, weatherC, size), IsTrue());
    }
    Spec(Size_14_HotDays){
        const int size = 14;
        float weather[size] = {102.9, 95.9, 91.1, 95.9, 95.9, 101.4, 107.4, 106.9, 101.6, 99.8, 97.0, 90.2, 109.3, 95.9};
        convertToCelsius(weather, size);
        float weatherC[size] = {39.3889, 35.5, 32.8333, 35.5, 35.5, 38.5556, 41.8889, 41.6111, 38.6667, 37.6667, 36.1111, 32.3333, 42.9444, 35.5};
        Assert::That(compareArrays(weather, weatherC, size), IsTrue());
    }
    Spec(Size_31_HotDays){
        const int size = 31;
        float weather[size] = {101.0, 99.5, 92.4, 96.1, 103.3, 105.5, 106.5, 109.1, 102.1, 94.0, 109.8, 98.3, 100.9, 98.3, 94.9, 102.1, 94.7, 102.8, 103.2, 108.9, 97.3, 104.4, 107.6, 104.4, 105.9, 107.4, 106.8, 100.3, 107.8, 101.9, 106.0};
        convertToCelsius(weather, size);
        float weatherC[size] = {38.3333, 37.5, 33.5556, 35.6111, 39.6111, 40.8333, 41.3889, 42.8333, 38.9444, 34.4444, 43.2222, 36.8333, 38.2778, 36.8333, 34.9444, 38.9444, 34.8333, 39.3333, 39.5556, 42.7222, 36.2778, 40.2222, 42, 40.2222, 41.0556, 41.8889, 41.5556, 37.9444, 42.1111, 38.8333, 41.1111};
        Assert::That(compareArrays(weather, weatherC, size), IsTrue());
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}