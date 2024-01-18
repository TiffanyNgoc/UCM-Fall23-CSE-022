#include <igloo/igloo.h>
#include "ucm_arrays.h"
#include<iostream>

using namespace igloo;

Context(TextProgram){
    Spec(Size_0_HotDays){
        const int size = 0;
        float max[size] = {};
        float min[size] = {};
        AssertThrows(std::logic_error, largestDailyRange(min, max, size));
    }
    Spec(Size_1_HotDays){
        const int size = 1;
        float max[size] = {100.5};
        float min[size] = {72.5};
        Assert::That(largestDailyRange(min, max, size), EqualsWithDelta(28, 0.001));
    }
    Spec(Size_7_HotDays){
        const int size = 7;
        float max[size] = {90.3, 96.5, 106.6, 108.3, 104.4, 98.9, 103.0};
        float min[size] = {69.0, 72.3, 71.7, 68.4, 68.8, 70.7, 69.5};
        Assert::That(largestDailyRange(min, max, size), EqualsWithDelta(39.9, 0.001));
    }
    Spec(Size_14_HotDays){
        const int size = 14;
        float max[size] = {102.9, 95.9, 91.1, 95.9, 95.9, 101.4, 107.4, 106.9, 101.6, 99.8, 97.0, 90.2, 109.3, 95.9};
        float min[size] = {72.2, 74.5, 74.7, 72.7, 69.2, 74.5, 69.7, 70.3, 68.3, 74.3, 72.8, 74.9, 69.5, 74.6};
        Assert::That(largestDailyRange(min, max, size), EqualsWithDelta(39.8, 0.001));
    }
    Spec(Size_31_HotDays){
        const int size = 31;
        float max[size] = {101.0, 99.5, 92.4, 96.1, 103.3, 105.5, 106.5, 109.1, 102.1, 94.0, 109.8, 98.3, 100.9, 98.3, 94.9, 102.1, 94.7, 102.8, 103.2, 108.9, 97.3, 104.4, 107.6, 104.4, 105.9, 107.4, 106.8, 100.3, 107.8, 101.9, 106.0};
        float min[size] = {72.0, 70.1, 70.4, 70.2, 71.6, 73.1, 70.7, 71.7, 71.1, 72.9, 70.6, 71.9, 71.3, 68.6, 69.5, 68.7, 71.2, 68.1, 69.5, 72.3, 73.6, 70.8, 72.4, 72.9, 74.0, 72.0, 74.1, 74.0, 70.0, 72.4, 74.4};
        Assert::That(largestDailyRange(min, max, size), EqualsWithDelta(39.2, 0.001));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}