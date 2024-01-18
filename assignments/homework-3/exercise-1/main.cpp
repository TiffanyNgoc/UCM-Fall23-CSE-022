#include <iostream>
using namespace std;

int main() {

    float grade;
    cin >> grade;

    if (grade > 100 || grade < 0) {
        cerr << "Invalid grade" << endl;
        return 1;
    }

    if ((grade >= 97) && (grade <= 100)) {
        cout << "A+" << endl;
    } 

    if ((grade >= 93) && (grade < 97)) {
        cout << "A" << endl;
    } 

    if ((grade >= 90) && (grade < 93)) {
        cout << "A-" << endl;
    } 

    if ((grade >= 87) && (grade < 90)) {
        cout << "B+" << endl;
    } 

    if ((grade >= 83) && (grade < 87)) {
        cout << "B" << endl;
    } 

    if ((grade >= 80) && (grade < 83)) {
        cout << "B-" << endl;
    } 

    if ((grade >= 77) && (grade < 80)) {
        cout << "C+" << endl;
    } 

    if ((grade >= 73) && (grade < 77)) {
        cout << "C" << endl;
    } 

    if ((grade >= 70) && (grade < 73)) {
        cout << "C-" << endl;
    } 

    if ((grade >= 67) && (grade < 70)) {
        cout << "D+" << endl;
    } 

    if ((grade >= 63) && (grade < 67)) {
        cout << "D" << endl;
    } 

    if ((grade >= 60) && (grade < 63)) {
        cout << "D-" << endl;
    } 

    if ((grade >= 0) && (grade < 60)) {
        cout << "F" << endl;
    } 
    
    return 0;
}