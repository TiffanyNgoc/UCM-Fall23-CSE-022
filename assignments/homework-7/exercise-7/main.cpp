#include <iostream>
#include "ucm_arrays.h"
using namespace std;

int main() {
    const int size = 7;
    float max[size] = {90.3, 96.5, 106.6, 108.3, 104.4, 98.9, 103.0};
    float min[size] = {69.0, 72.3, 71.7, 68.4, 68.8, 70.7, 69.5};

    float largestRange = largestDailyRange(min, max, size);

    cout << "Largest daily range: " << largestRange << endl;

    return 0;
}