#include <iostream>
using namespace std;

int main() {

    float grade;
    cin >> grade;

    // Check if invalid
    // || = or
    if (grade > 100 || grade < 0) {
        cerr << "Invalid input" << endl;
        return 1;
    }

    if ((grade >= 90)) {
        cout << "A" << endl;
    } 

    if ((grade >= 80) && (grade < 90)) {
        cout << "B" << endl;
    } 

    if ((grade >= 70) && (grade < 80)) {
        cout << "C" << endl;
    } 

    if ((grade >= 60) && (grade < 70)) {
        cout << "D" << endl;
    } 

    if ((grade < 60)) {
        cout << "F" << endl;
    } 
    return 0;
}