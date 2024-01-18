#include <iostream>
#include "ucm_arrays.h"
using namespace std;

int main() {

    const int size = 7;
    float weather[size] = {90.3, 96.5, 106.6, 108.3, 104.4, 98.9, 103.0};

    float maxDecrease = getMaxDecrease(weather, size);
    float maxIncrease = getMaxIncrease(weather, size);

    cout << "The biggest temperature increase was: " << maxIncrease << endl;
    cout << "The biggest temperature decrease was: " << maxDecrease << endl;

    return 0;
}