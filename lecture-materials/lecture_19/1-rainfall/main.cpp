#include <iostream>
using namespace std;

void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "]: " << arr[i] << endl;
    }
}

int countTarget(float arr[], int size, float target) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }

    return count;
}

int countGreaterThanTarget(float arr[], int size, float target) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > target) {
            count++;
        }
    }

    return count;
}

int countLessThanTarget(float arr[], int size, float target) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < target) {
            count++;
        }
    }

    return count;
}

int countTargetInRange(float arr[], int size, float min, float max) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] >= min && arr[i] <= max) {
            count++;
        }
    }

    return count;
}

float sumOfArray(float arr[], int size) {
    float total = 0;

    for (int i = 0; i < size; i++) {
        total += arr[i];
    }

    return total;
}

// {0, 0.21, 0.37, 0.48, 0, 0, 0};
// count = 3
// max = 1
int countMaxConsecutiveTarget(float arr[], int size, float target) {
    int count = 0;
    int max = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        } else {
            if (count > max) {
                max = count;
            }
            count = 0;
        }
    }

    if (count > max) {
        max = count;
    }

    return max;
}

int main() {
    // Data we want to represent: daily rainfall (in inches)

    // Questions we want to answer:
    // How many days did we have without rain?
    // How many days did we have with rain?
    // How many days did it rain less than 0.3 inches?
    // How many days did it rain between 0.4 and 0.6 inches?
    // How much rainfall did we get in total?
    // What was the longest dry period?

    // string str = "Hello";
    // cout << str << endl;

    // for (int i = 0; i < str.length(); i++){
    //     cout << "str[" << i << "]" << str[i] << endl;
    // }

    const int size = 7;
    float rainfall[size] = {0, 0.21, 0.37, 0.48, 0, 0, 0};

    int daysWithoutRain = countTarget(rainfall, size, 0);
    cout << "Days without rain: " << daysWithoutRain << endl;

    int daysWithRain = countGreaterThanTarget(rainfall, size, 0);
    cout << "Days with rain: " << daysWithRain << endl;

    int daysWithLittleRain = countLessThanTarget(rainfall, size, 0.3);
    cout << "Days with less than 0.3 inches of rain: " << daysWithLittleRain << endl;

    int daysWithMoreRain = countTargetInRange(rainfall, size, 0.4, 0.6);
    cout << "Days with rain between 0.4 and 0.6 inches: " << daysWithMoreRain << endl;

    float totalRainfall = sumOfArray(rainfall, size);
    cout << "Total rainfall: " << totalRainfall << endl;

    int longestDryPeriod = countMaxConsecutiveTarget(rainfall, size, 0);
    cout << "Longest dry period: " << longestDryPeriod << endl;

    return 0;
}