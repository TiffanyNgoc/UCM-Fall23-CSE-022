#include <iostream>
using namespace std;

int main() {

    string subject1, subject2, subject3;
    float grade1, grade2, grade3;

    getline(cin, subject1);
    getline(cin, subject2);
    getline(cin, subject3);

    cin >> grade1 >> grade2 >> grade3;

    string letter1, letter2, letter3;

    if ((grade1 >= 90)) {
        letter1 = "A";
    } 

    if ((grade1 >= 80) && (grade1 < 90)) {
        letter1 = "B";
    } 

    if ((grade1 >= 70) && (grade1 < 80)) {
        letter1 = "C";
    } 

    if ((grade1 >= 60) && (grade1 < 70)) {
        letter1 = "D";
    } 

    if ((grade1 < 60)) {
        letter1 = "F";
    } 

    //

    if ((grade2 >= 90)) {
        letter2 = "A";
    } 

    if ((grade2 >= 80) && (grade2 < 90)) {
        letter2 = "B";
    } 

    if ((grade2 >= 70) && (grade2 < 80)) {
        letter2 = "C";
    } 

    if ((grade2 >= 60) && (grade2 < 70)) {
        letter2 = "D";
    } 

    if ((grade2 < 60)) {
        letter2 = "F";
    } 

    //

    if ((grade3 >= 90)) {
        letter3 = "A";
    } 

    if ((grade3 >= 80) && (grade3 < 90)) {
        letter3= "B";
    } 

    if ((grade3 >= 70) && (grade3 < 80)) {
        letter3 = "C";
    } 

    if ((grade3 >= 60) && (grade3 < 70)) {
        letter3 = "D";
    } 

    if ((grade3 < 60)) {
        letter3 = "F";
    } 

    cout << subject1 << " " << letter1 << endl;
    cout << subject2 << " " << letter2 << endl;
    cout << subject3 << " " << letter3 << endl;
    return 0;
}