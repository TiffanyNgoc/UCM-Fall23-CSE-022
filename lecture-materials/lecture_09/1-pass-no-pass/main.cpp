#include <iostream>
using namespace std;

int main() {

    float grade;
    cin >> grade;

    if (grade >= 70) {
        cout << "PASS" << endl;
    } 
    else {
        cout << "FAIL" << endl;
    }

    return 0;
}