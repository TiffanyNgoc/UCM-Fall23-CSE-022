#include <iostream>
#include "ucm_arrays.h"
using namespace std;

int main() {

    const int size = 7;
    float weather[size] = {90.3, 96.5, 106.6, 108.3, 104.4, 98.9, 103.0};

    float coldest = getColdestTemperature(weather, size);
    float hottest = getHottestTemperature(weather, size);

    cout << "The coldest temperature was: " << coldest << endl;
    cout << "The hottest temperature was: " << hottest << endl;

    return 0;
}