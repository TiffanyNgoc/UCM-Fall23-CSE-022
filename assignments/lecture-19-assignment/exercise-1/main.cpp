#include <iostream>
#include "ucm_arrays.h"
using namespace std;

int main() {
    float grades[8] = {58, 94, 60, 25, 28, 27, 17, 18};

    cout << "The average of the exam is: " << average(grades, 8) << endl;

    return 0;
}

