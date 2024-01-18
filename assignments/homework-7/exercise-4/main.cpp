#include <iostream>
#include "ucm_arrays.h"
using namespace std;

int main() {

    const int size = 7;
    float weather[size] = {90.3, 96.5, 106.6, 108.3, 104.4, 98.9, 103.0};

    float hotDays = countHotDays(weather, size, 100.3);

    cout << "The number of hot days: " << hotDays << endl;

    return 0;
}